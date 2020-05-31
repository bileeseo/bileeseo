#include <iostream>
#include <iomanip> 

#include "memory.h"

/* memory cell 자체는 data_t array로 구현 */

Memory::Memory(int size, clockCycle_t mem_access_time)
{
  // implement here
  data_t *memory_cells = new int[size]();

  for(int i=0 ; i<size ; i++)
  {
    memory_cells[i] = -1;
  }



}


Memory::~Memory()
{
  // implement here
  delete[] memory_cells;
}


// Cache 또는 Processor에서 받은 address의 data를 return
data_t Memory::read_data(addr_t address)
{
  globalClock += mem_access_time;
  // implement here
  return memory_cells[address];
}


// Cache 또는 Processor에서 받은 data를 address에 write
void Memory::write_data(addr_t address, data_t value)
{
  globalClock += mem_access_time;

  // implement here
  memory_cells[address] = value;
}


void Memory::print()
{
  return;
  //std::cout << "// Memory //" << std::endl;
  for(int i = 0; i < this->size; i++)
  {
    std::cout << "[" << std::setw(2) << i << "] :" << std::setw(5) << this->memory_cells[i] << std::endl;
  }
  std::cout << std::endl;
}


