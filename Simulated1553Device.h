#ifndef SIMULATED1553DEVICE_H
#define SIMULATED1553DEVICE_H

#include "reg.h"
#include "mem.h"
#include "simbus.h"
#include "transException.h"

class Simulated1553Device:public Reg, public Mem, public Exception1553B
{
    // Simulated1553Device* m_backup = nullptr;
public:
    // Functions related to saving and storing state
    virtual void restore() = 0;
	virtual void save() = 0;

    // ~~~ Functions for performing simulation ~~~ //
    
    // step:
    // Reads latest word from the bus and uses it to execute simulation logic which might write to the bus
    virtual UINT16 step(void) = 0;
    
    // on_data
    // Getter for the last data sent by the device on the bus accounting for channel selection logic
    virtual UINT32 on_data(UINT32, void *) = 0;

    // ~~~ Functions related to device hardware ~~~ //

    // dump
    // Reads raw register file and memory contents into the provided buffer
	virtual UINT16 dump(int len, void * buffAddr) = 0;
	virtual INT16 init_reg_address(void);
	virtual void gen_IRQ(void);

	struct TransException checkIfException();
private:
    // CheckRecvHook
    // Utility function used to read data that was sent to the bus
    UINT32 CheckRecvHook(UINT32 len,void *recvData);
};

#endif SIMULATED1553DEVICE_H