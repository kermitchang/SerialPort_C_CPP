#include <stdio.h>

#include "SerialPort.h"

#pragma comment(lib, "Winmm.lib")

int main(){

	HANDLE mHANDLE = OpenSerialPort(5);

	if (mHANDLE == NULL){
		printf("no serial port\n");
		system("timeout 5");
		return -1;
	}

	while (true){

		// 0X49 Power on
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x70)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0x49;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			//PlaySound(L"JELLY JELLY.wav", NULL, SND_FILENAME);
			Sleep(1);
		}

		// 0X50 Play
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x71)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0x50;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			//PlaySound(L"JELLY JELLY.wav", NULL, SND_FILENAME);
			Sleep(1);
		}
		// 0X51 Pause
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x72)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0x51;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);

		}
		// 0X52 Next
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x44)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0x52;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);
		}
		// 0X53 Prev
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x41)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0x53;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);

		}
		// 0X54 Volume Up
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x57)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0x54;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);
		}
		// 0X55 Volume Down
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x53)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0x55;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);

		}

		// 0X56 Rainbow
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x73)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0x56;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);

		}

		// 0X57 Close Light
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x74)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0X57;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);

		}

		// 0X58 Close Light
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x75)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0X58;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);

		}

		// 0X59 Fire Light
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x76)){
			BYTE *bSENDDATA = new BYTE[1];
			bSENDDATA[0] = 0X59;
			bool bSucceed = WriteToSerialPort(mHANDLE, bSENDDATA, 1);
			printf("Send:%d\t%d\ttrue:%d\tfalse:%d\n", bSENDDATA[0], bSucceed, true, false);
			delete bSENDDATA;
			Sleep(1);

		}
		if (GetAsyncKeyState(0xA2) && GetAsyncKeyState(0x7A))
			break;
	}
	
	return 0;
}