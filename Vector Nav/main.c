#include<stdio.h>
#include<windows.h>


int main()
{
/* HANDLE hSerial;

hSerial = CreateFile("COM22", GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

DCB dcbSerialParams = {0};

dcbSerialParams.DCBlength=sizeof(dcbSerialParams);

dcbSerialParams.BaudRate=CBR_115200;

dcbSerialParams.ByteSize=8;

dcbSerialParams.StopBits=ONESTOPBIT;

dcbSerialParams.Parity=NOPARITY;

SetCommState(hSerial, &dcbSerialParams);

COMMTIMEOUTS timeouts={0};

timeouts.ReadIntervalTimeout=100;

timeouts.ReadTotalTimeoutConstant=100;

timeouts.ReadTotalTimeoutMultiplier=20;

SetCommTimeouts(hSerial, &timeouts);

char szBuff[13 + 1] = {0};

DWORD myBytesRead = 0;

ReadFile(hSerial, szBuff, 13, &myBytesRead, NULL);

printf("it worked and the data is %s \n",szBuff);

CloseHandle(hSerial);

*/
    
  
    HANDLE hComm;
    hComm = CreateFile( gszPort,
    GENERIC_READ | GENERIC_WRITE,
    0,
    0,
    OPEN_EXISTING,
    FILE_FLAG_OVERLAPPED,
    0);
    if (hComm == INVALID_HANDLE_VALUE)
    /* error opening port; abort
    */


    DWORD dwRead;
    BOOL fWaitingOnRead = FALSE;
    OVERLAPPED osReader = {0};
    /* Create the overlapped event. Must be closed before exiting
    /* to avoid a handle leak. */
    osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (osReader.hEvent == NULL)
    /* Error creating overlapped event; abort. */
    if (!fWaitingOnRead) {
    /* Issue read operation. */
    if (!ReadFile(hComm, lpBuf, READ_BUF_SIZE, &dwRead, &osReader)) {
    if (GetLastError() != ERROR_IO_PENDING) /* read not delayed?
    // Error in communications; report it. */
    else
    fWaitingOnRead = TRUE;
    }
    else {
    /*  read completed immediately */
    HandleASuccessfulRead(lpBuf, dwRead);
    }
    }
    
 
     
       
    
getch();
}