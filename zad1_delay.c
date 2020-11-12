#include <stdio.h>
#include <time.h>

int main(void)
{
  struct timespec tim, tim2;
  tim.tv_sec = 0;
  tim.tv_nsec = 1000000; 
  int i=0;
  while(1)
    {
  ++i;
  nanosleep(&tim, &tim2);
    }
  return 0;
}
