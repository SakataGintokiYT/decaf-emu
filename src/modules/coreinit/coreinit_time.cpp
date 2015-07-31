#include "coreinit.h"
#include "coreinit_time.h"
#include "coreinit_systeminfo.h"

// Time since epoch
OSTime
OSGetTime()
{
   auto now = std::chrono::system_clock::now();
   auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(now - gEpochTime);
   return ns.count();
}

// Time since system start up
OSTime
OSGetSystemTime()
{
   return OSGetTime() - OSGetSystemInfo()->baseTime;
}

// Ticks since epoch
OSTick
OSGetTick()
{
   return OSGetTime() & 0xFFFFFFFF;
}

// Ticks since system start up
OSTick
OSGetSystemTick()
{
   return OSGetSystemTime() & 0xFFFFFFFF;
}

void
CoreInit::registerTimeFunctions()
{
   RegisterKernelFunction(OSGetTime);
   RegisterKernelFunction(OSGetTick);
   RegisterKernelFunction(OSGetSystemTime);
   RegisterKernelFunction(OSGetSystemTick);
}
