#ifndef _SIMBUS_H
#define _SIMBUS_H
#include "definition.h"
#define DATA_TYPE_COMMAND_WORD 0
#define DATA_TYPE_DATA_WORD 1
#define DATA_TYPE_STATUS_WORD 2
#define DATA_TYPE_UNDEFINED_WORD 8

// Forward declare classes so they can be used as friend classes?
class SimBC;
class SimRT;
class SimMT;

class Bus  
{
friend class SimRT;
friend class SimMT;
friend class SimBC;
private:
	UINT16 m_busDataType;
	UINT16 m_busData;
	UINT16 m_busDatetime;	
	UINT16 m_busFull;
	UINT32 OnData(UINT32, void *);
	void setBusData(UINT16,UINT16,UINT16,UINT16);

};
//extern UINT32 CheckRecv(UINT32 len,void *recvData);
extern sim61580irq GenIRQ;

// Export a global function to client's of this class that they should call to read data from the bus?
extern pfun_RecvCheck CheckRecv;

#endif