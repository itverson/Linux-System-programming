#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<errno.h>
void catch_fun(int num)
{
		;
} 
unsigned int my_sleep(unsigned int second)
{   
	  int n;	
	  struct  sigaction act,old;
	  act.sa_handler=catch_fun;
	  sigemptyset(&act.sa_mask);
	  act.sa_flags=0;
		sigaction(SIGALRM,&act,&old); 
		 alarm(second); 
         int ret=pause(); 
		 if(ret==-1&&errno==EINTR)
		 {
		     printf("pause success\n");       
		 } 
		 n=alarm(0); 
		 sigaction(SIGALRM,&old,NULL);
		 return n;
} 
int main()
{
	while(1) 	
	{
			my_sleep(1);
	}
	return 0;
} 
