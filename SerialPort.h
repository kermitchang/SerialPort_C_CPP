#include <stdio.h>
#include <iostream>
#include <string>
#include <Windows.h>

HANDLE OpenSerialPort(int _COMNUMBER);

bool WriteToSerialPort(HANDLE hComm, BYTE *_data, int _dataLen);

bool ReadFromSerialPort(HANDLE hComm, BYTE *_data, int _dataLen, DWORD &bytesReader);