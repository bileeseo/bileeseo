#ifndef MEMORY_H
#define MEMORY_H

#include "defs.h"

class Memory
{
private:
  int size;
  data_t* memory_cells;
  clockCycle_t mem_access_time = 100;

public:
  Memory(int size,clockCycle_t mem_access_time);
  ~Memory();
  data_t read_data(addr_t address);
  void write_data(addr_t address, data_t value);
  void print();
};


#endif
