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
	  sigset_t newmask,oldmask,supmask;
	  act.sa_handler=catch_fun;
	  sigemptyset(&act.sa_mask);
	  act.sa_flags=0;
	  sigaction(SIGALRM,&act,&old); 
//设置自己的信号集
	  sigemptyset(&newmask);
	  sigemptyset(&supmask); 
	  sigaddset(&newmask,SIGALRM);//添加alarm
	  sigprocmask(SIG_BLOCK,&newmask,&oldmask);//影响信号屏蔽字，屏蔽信号alarm	  
		 alarm(second); 
		 supmask=oldmask;//将最开始系统的信号屏蔽集赋值给新的
		 sigdelset(&supmask,SIGALRM); 
	
         sigsuspend(&supmask); 
		 n=alarm(0); 
		 sigaction(SIGALRM,&old,NULL);
         return n;  
}
//先屏蔽
//解屏蔽
int main() 
{
    my_sleep(1);
	return 0;
} 
