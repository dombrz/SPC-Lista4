#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void handler1 (int signum)
{
  printf("Odebrano sygnal nr %d \nKoncze prace programu \n", signum);
  exit(0);
}

void handler2 (int signum)
{
  printf("Przechwycono sygnal %d \n", signum);
}

void handler3_1(int signum)
{
  printf("Otrzymano sygnał %d z opoznieniem\n", signum);
  exit(0);
}

void handler3 (int signum)
{

  timer_t blocking_timer;
  struct itimerspec tim_block;
  struct sigevent sev;
 
  
  
  sev.sigev_notify=SIGEV_SIGNAL;
  sev.sigev_signo=SIGUSR1;
  sev.sigev_value.sival_ptr=&blocking_timer;
  tim_block.it_value.tv_sec=5;
  tim_block.it_value.tv_nsec=0;
  tim_block.it_interval.tv_sec=0;
  tim_block.it_interval.tv_sec=0;
  timer_create(CLOCK_REALTIME, &sev, &blocking_timer);
  timer_settime(blocking_timer, 0, &tim_block, NULL);
  signal(SIGUSR1, handler3_1);
}




void handler4 (int signum)
{
  ;
}



int main(void)
{
  struct timespec tim, tim2;
  signal(SIGTERM, handler1);
  signal(SIGALRM, handler2);
  signal(SIGUSR1, handler3);
  signal(SIGUSR2, handler4);
  

  tim.tv_sec = 0;
  tim.tv_nsec = 1000000; 
  int i =0;
  while(1)
    {
      
  ++i;
  // printf("%d \n", i);
  nanosleep(&tim, &tim2);
    }
  return 0;
}
