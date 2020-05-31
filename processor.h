#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "cache.h"

class Processor
{
private:
  Cache* cache;

public:
  Processor(Cache* cache);
  void rcvMemRequest(char RW, addr_t address, data_t cnt);
  data_t read_data(addr_t address);
  void write_data(addr_t address, data_t value); 
};


#endif
