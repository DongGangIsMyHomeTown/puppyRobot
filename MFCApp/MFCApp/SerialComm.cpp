#include "stdafx.h"
#include "serialcomm.h"

CSerialComm::CSerialComm() {}
CSerialComm::~CSerialComm() {}


int CSerialComm::connect(CString _portNum)
{
	if (!serial.OpenPort(_portNum))
		return RETURN_FAIL;

	serial.ConfigurePort(CBR_115200, 8, FALSE, NOPARITY, ONESTOPBIT);
	serial.SetCommunicationTimeouts(0, 0, 0, 0, 0);

	return RETURN_SUCCESS;
}


int CSerialComm::sendCommand(unsigned char pos)
{
	if (serial.WriteByte(pos))
		return RETURN_SUCCESS;
	else
		return RETURN_FAIL;
} 

unsigned char CSerialComm::recvCommand(BYTE &resp) {
	//����
	if (serial.ReadByte(resp))
		return resp;
	else
		return -1;
}

void CSerialComm::disconnect()
{
	serial.ClosePort();
}

