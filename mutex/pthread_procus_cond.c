#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
struct ListNode
{
    struct ListNode* next;
	int data;
};

    struct ListNode* head;//头指针
    struct ListNode* p;//创建结点的指针
pthread_mutex_t mutex;//互斥锁变量
pthread_cond_t cond;//条件变量
void* pthread_cus(void* arg)
{
   srand(time(NULL)); 
	  while(1)
	  {
		pthread_mutex_lock(&mutex);//首先上锁 	  
	       while(head==NULL)
		   pthread_cond_wait(&cond,&mutex); //看看是否满足条件变量即是否有产品，没有则阻塞
	     p=head;
		 head=p->next;//消费，头删
		 pthread_mutex_unlock(&mutex);
		 printf("customer data=%d\n",p->data);
		 free(p);
		 sleep(rand()%5); 
	  } 
} 
void* pthread_pro(void* arg)
{
   srand(time(NULL)); 
      while(1)
	  {
	     p=(struct ListNode*)malloc(sizeof(struct ListNode));//创建结点即生产产品
		 p->data=rand()%100;
		 printf("productor data=%d\n",p->data);
		 //下面开始操作共享区域
		 //首先上锁
		 pthread_mutex_lock(&mutex);
		 p->next=head;
		 head=p;
		 pthread_mutex_unlock(&mutex);
		 //解锁即生产完成，然后需要唤醒阻塞的消费者
		 pthread_cond_signal(&cond);//唤醒阻塞在条件变量上面的线程
		 sleep(rand()%5); 
	  } 
} 
int main() 
{		
   pthread_t pro,cus;//定义生产者和消费者
   pthread_mutex_init(&mutex,NULL);//初始化锁
   pthread_cond_init(&cond,NULL);//初始化条件变量

   pthread_create(&cus,NULL,pthread_cus,NULL);//创建消费者线程 
   pthread_create(&pro,NULL,pthread_pro,NULL);//创建生产者模型

   pthread_join(cus,NULL);//回收消费者
   pthread_join(pro,NULL);//回收生产者

   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&cond); 
   return 0;
} 
