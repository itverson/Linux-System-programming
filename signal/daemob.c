#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
   pid_t pid;
   pid=fork(); 
   if(pid>0)
		   return;
   else if(pid<0)
   {
     perror("use fork()");
	 exit(1); 
   } 
   //子进程的部分
   setsid();//创建会话
   int ret=chdir("/home/lishuai");
   if(ret==-1)
   {
      perror("use chdir");
	  exit(1); 
   }
   close(STDIN_FILENO);//关闭0号位置 
   open("/dev/null",O_RDWR); //打开空洞文件占有0号位置
   dup2(0,STDOUT_FILENO);
   dup2(0,STDERR_FILENO); 
   while(1)
   {
     ;
   } 
   return 0;
} 
