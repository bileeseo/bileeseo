#ifndef CACHE_H
#define CACHE_H

#include "memory.h"


struct CacheData
{
  addr_t address;
  int value;
  bool valid = false;
  bool dirty = false; // for write_back
};


class Cache
{
private:
  int size;
  CacheData* cache_cells;
  clockCycle_t cache_access_time = 5;
#ifdef FIFO
  int fifo_head_idx = 0; 
#endif
  Memory* mem; // address of dedicated Memory

public:
  Cache(Memory* mem, int size, int cache_access_time);
  ~Cache();
  data_t read_data(addr_t address);
  void write_data(addr_t address, int value);
  void print();
};


#endif
