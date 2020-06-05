#include "SerialPort.h"
#define _CRT_SECURE_NO_WARNINGS

HANDLE OpenSerialPort(int _COMNUMBER){
	char *strCOM = new char[100];
	sprintf(strCOM, "COM%d", _COMNUMBER);
	std::wstring comNum = std::wstring(strCOM, strCOM + strlen(strCOM));
	std::wstring comPrefix = L"\\\\.\\";
	std::wstring comID = comPrefix + comNum;

	HANDLE _hComm = CreateFile(comID.c_str(),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,//FILE_FLAG_OVERLAPPED,
		NULL);
	delete strCOM;

	if (_hComm == INVALID_HANDLE_VALUE){
		//If not success full display an Error
		if (GetLastError() == ERROR_FILE_NOT_FOUND){
			//Print Error if neccessary
			printf("ERROR: Handle was not attached. Reason: COM%d not available.\n", _COMNUMBER);
		}
		else{
			printf("ERROR!!!");
		}
	}
	else{
		DCB	dcb = { 0 };
		GetCommState(_hComm, &dcb);
		dcb.BaudRate = CBR_9600;
		dcb.ByteSize = 8;
		dcb.StopBits = ONESTOPBIT;
		dcb.Parity = NOPARITY;
		SetCommState(_hComm, &dcb);

		COMMTIMEOUTS ctmo = { 0 };
		GetCommTimeouts(_hComm, &ctmo);
		ctmo.ReadIntervalTimeout = MAXDWORD;
		ctmo.ReadTotalTimeoutMultiplier = 0;
		ctmo.ReadTotalTimeoutConstant = 0;
		SetCommTimeouts(_hComm, &ctmo);
	}
	return _hComm;
}

bool WriteToSerialPort(HANDLE hComm, BYTE *_data, int _dataLen){
	bool WriteSeccedFlag = true;
	DWORD bytesWritten;
	for (int i = 0; i < _dataLen; i++){
		if (!WriteFile(hComm, &_data[i], 1, &bytesWritten, NULL)){
			WriteSeccedFlag = false;
			break;
		}
		Sleep(100);
	}
	return WriteSeccedFlag;
}

bool ReadFromSerialPort(HANDLE hComm, BYTE *_data, int _dataLen, DWORD &bytesReader){
	return ReadFile(hComm, _data, _dataLen, &bytesReader, NULL);
}