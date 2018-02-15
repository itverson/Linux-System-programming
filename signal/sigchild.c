#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
void catch_child(int num)
{
	 int status; 	
			 pid_t pida;
  while((pida=waitpid(0,&status,WNOHANG))>0)
	  {
		if(WIFEXITED(status))
		{
		    printf("---------------catch child pid=%d,,,,,%d\n",pida,WEXITSTATUS(status)); 
		} else if(WIFSIGNALED(status)) 
		{
	         printf("child pid%d    %d",pida,WTERMSIG(status)); 
		} 
		sleep(1); 
	 } 
} 
int main()
{
	int i;	
   pid_t pid;
   for( i=0;i<10;i++)
   {
       pid=fork();
	   if(pid==0)
		   break;//跳出子进程的循环
	   else if(pid<0)
	   {
	   perror("fork() ");
	     exit(1);
	   } 
   } 
   if(pid==0)
   {
	int n=1;	   
	while(n--) 	   
	{
			printf("i am child %d  pid=%d\n",i+1,getpid());
			sleep(1); 
	}
	return i+1;
   } 
   if(pid>0)
   {
     struct sigaction old;
	 sigemptyset(&old.sa_mask);
	 old.sa_flags=0;
	 old.sa_handler=catch_child;
     sigaction(SIGCHLD,&old,NULL);
	 while(1)
	 {
	    printf("i am parent pid=%d\n",getpid());
		sleep(1); 
	 } 
   } 
   return 0;
} 
