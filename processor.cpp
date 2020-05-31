#include <iostream>

#include "processor.h"

Processor::Processor(Cache* cache)
{
  // implement here
  this->cache = cache;

}

//main함수에서 받은 memory request를 read/write로 구분
void Processor::rcvMemRequest(char RW, addr_t address, data_t cnt)
{
  // implement here
  if(RW == 'R')
  {
    this->read_data(address);
  }
  else
  {
    this->write_data(address,cnt);
  }
  cache->print();
}

//Cache의 read를 호출
data_t Processor::read_data(addr_t address)
{
  // implement here
  return this->cache->read_data(address);
}

//Cache의 write를 호출
void Processor::write_data(addr_t address, data_t value) 
{
  // implement here
  this->cache->write_data(address ,value);
}
