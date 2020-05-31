#include <iostream>
#include <iomanip> 

#include "cache.h"


Cache::Cache(Memory* mem, int size, clockCycle_t cache_access_time)
  :mem{mem}, size{size}, cache_access_time{cache_access_time} 
{
  this->cache_cells = new CacheData[size];
}


Cache::~Cache()
{
  delete [] cache_cells;
}

/* Cache Read의 기본적인 구현은 다음과 같다. 
 * 1. Cache에서 내가 원하는 address의 데이터가 있는지 먼저 찾아본다. 있으면, 즉 cache hit이면 cache에 저장된 데이터를 읽고 read 성공. 
 * 2. 내가 원하는 address의 데이터가 없는 경우 (cache miss이면) 비어있는 cell이 있는지 찾아본다. 즉, invalid한 cell들이 있는지 찾아본다.
 *    Invalid한 데이터가 있는 경우 memory에서 데이터를 읽어서 cache에 저장한다.
 * 3. Cache에서 Invalid한 data가 없는 경우, cache가 가득 차 있는 상태이고 cache cell의 데이터 중 하나를 evict해야 한다. LRU, FIFO policy에 따라
 *    evict할 cell을 찾고, (write back - allocate), (write through - no-allocate) Policy에 따라 evict를 해준다. 그리고나서 memory에서 데이터를
 *    읽어서 cache에 저장한다.
 */

/********************** FIFO Read *****************************/
#ifdef FIFO
data_t Cache::read_data(addr_t address)
{ 
  globalClock += cache_access_time;

  // Cache read hit? : Check if target is in cache

  // Cache read miss : 
  // 1. Check if there is invalid cell
  // 2. if not, evict a cell and replace
  

#ifdef WRITE_BACK
  //check dirty before evict
#endif

}
#endif  //end FIFO

/*************************************************************/

/********************** LRU Read *****************************/
#ifdef LRU
data_t Cache::read_data(addr_t address)
{ 
  globalClock += cache_access_time;
 
  // Cache read hit? : Check if target is in cache
      
      // LRU : rearrange array to find least recently used data???

  // Cache read miss : 
  // 1. Check if there is invalid cell
  // 2. if not, evict a cell and replace
  
  // If not, then evict

#ifdef WRITE_BACK
  //check dirty before evict
#endif

}
#endif  //end LRU

/*************************************************************/
/* cache write의 기본적인 구현은 다음과 같다.
 * 1. write hit이 난 경우, write back / write through에 따라 cache 또는 메모리를 업데이트한다.
 * 2. write miss가 난 경우, write allocate / write no allocate에 따라 cache 또는 메모리를 업데이트한다. 이때, invalid한 cell이 있으면
 *    invalid한 cell에 업데이트하고, 없다면 cache가 꽉 찬것이므로 FIFO와 LRU에 따라 업데이트한다.
 */
/********************** FIFO write ***************************/
#ifdef FIFO
void Cache::write_data(addr_t address, data_t value)
{
  globalClock += cache_access_time;

  // Cache write hit? : Check if target is in cache
      
#ifdef WRITE_THROUGH
  //write hit on write through policy
#endif

#ifdef WRITE_BACK
  //write hit on write back policy
#endif


  // Cache write miss : 
  // 1. Check if there is invalid cell
  // 2. if not, evict a cell and replace according to FIFO


#ifdef WRITE_THROUGH
  // write miss on write no-allocate policy
#endif

#ifdef WRITE_BACK
  // write miss on write allocate policy
  
  // evict and replace
#endif  //end write back
}
#endif  //end FIFO
/*************************************************************/

/********************** LRU write ****************************/
#ifdef LRU
void Cache::write_data(addr_t address, data_t value)
{
  globalClock += cache_access_time;

  // Cache write hit? : Check if target is in cache
#ifdef WRITE_THROUGH
  // write hit on write through policy
#endif

#ifdef WRITE_BACK
 // write hit on write back policy
#endif



 // Cache write miss - write through - no_allocate

#ifdef WRITE_THROUGH
  //implement here
#endif

  /* Cache write miss - write back - allocate
   1. Check if there is invalid cell
   2. if not, evict a cell and replace according to LRU
   */
#ifdef WRITE_BACK
  //implement here
#endif  //end write_back

}
#endif  //end LRU
void Cache::print()
{
  std::cout << "// Cache //" << std::endl;
  for(int i = 0; i < this->size; i++)
  {
std::cout << "[" << std::setw(2) << i << "] : (" << std::setw(3) << cache_cells[i].address << ", " << std::setw(5) << cache_cells[i].value << ")" << std::endl;
  }
  std::cout << std::endl;
}


