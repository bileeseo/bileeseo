#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "defs.h"
#include "processor.h"

#define INST_NUM            1000000

#define MEM_SIZE            1<<16
#define CACHE_SIZE          3
#define MEM_ACCESS_TIME     100
#define CACHE_ACCESS_TIME   5

clockCycle_t globalClock = 0;       //We will measure globalClock to simulate overall memory access time.
                                    //In a cache access, globalClock increases 5
                                    //In a Memory access, global Clock increases 100

int main()
{

  // Make components
  Memory memory(MEM_SIZE, MEM_ACCESS_TIME);
  
  Cache cache(&memory, CACHE_SIZE, CACHE_ACCESS_TIME);
                                        
  Processor processor(&cache);

  std::ifstream traceFile("short_trace.txt"); // open traceFile and parse address and Read/Write command
  if(traceFile.is_open()){
    std::string line;
    int cnt=1;
    while(getline(traceFile,line) && cnt < INST_NUM)
    {
      std::string RW, addr;
      std::stringstream ss;
      ss.str(line);
      ss>>addr;
      ss>>RW;
      processor.rcvMemRequest(RW.at(0),stoi(addr)%(1<<16),cnt);     // call rcvMemRequest to execute instruction
      cnt++;
      cache.print();
    }
    traceFile.close();
  }

  // Check cache and memory
  //cache.print();
  //memory.print();

  std::cout << "Total execution time is " << globalClock << '\n' << '\n';

  return 0;
}
