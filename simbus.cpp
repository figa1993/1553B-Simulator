#include "stdafx.h"
#include "simbus.h"
#include "definition.h"
#include "log.h"

// Populates data's memory with the last contents that were simulated to be sent on the bus
UINT32 Bus::OnData(UINT32 len, void * data) 
{
	// Validate that len is smaller than the maximum amount of data that can be sent on the bus.
	if(len < (4 + 32) * sizeof(UINT16)) {
		return 2;//Insufficient Buffer size
	}

	if(m_busFull == 1) {
		*((UINT16 *)data)  = m_busDataType;
		*(((UINT16 *)data) + 1) = m_busData;
		*(((UINT16 *)data) + 1 + 32) = m_busDatetime;
		*(((UINT16 *)data) + 2 +32) = m_busFull;
		*(((UINT16 *)data) + 3 +32) = 1;
		m_busFull = 0;
		llogDebug("OnData Call","Has Data 0x%x, type %d",m_busDataType,m_busDataType);
		return 1;
	}
	
	llogDebug("OnData Call","No Data");
	
	return 0;
}

void Bus::setBusData(UINT16 dataType,UINT16 datetime,UINT16 data,UINT16 isFull) {
	m_busDataType = dataType;
	m_busData = data;
	m_busDatetime = datetime;
	m_busFull = isFull;
}