#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define NBUF 5
#define N 10
int buf[NBUF];
int head,tail;
int data;
pthread_mutex_t mutex;
pthread_cond_t empty,full;
int init()
{
	head = tail = data = 0;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&full,NULL);
	pthread_cond_init(&empty,NULL);
}
void *producer()
{
	int i;
	pthread_t me=pthread_self();
	for(i=0;i<N;++i){
		pthread_mutex_lock(&mutex);
		if(data==NBUF)
		{
			printf("producter: %lu:all bufs FULL:wait\n",me);
			pthread_cond_wait(&empty,&mutex);
		}
		buf[head++]=i+1;
		head %= NBUF;
		data++;
		printf("producer :%lu data:%d value=%d\n",me,data,i+1);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&full);
	}
	printf("producer %lu :exit\n",me);
}
void *consumer()
{
	int i,c;
	pthread_t me=pthread_self();
	for(i=0;i<N;++i)
	{
		pthread_mutex_lock(&mutex);
		if(data==0)
		{
			printf("consumer %lu : all bufs EMPTY:wait\n",me);
			pthread_cond_wait(&full,&mutex);
		}
		c=buf[tail++];
		tail%=NBUF;
		data--;
		printf("consumer %lu:value=%d\n",me,c);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&empty);
	}
	printf("consumer : %lu exit\n",me);
}
int main()
{
	pthread_t pro,con;
	init();
	pthread_create(&pro,NULL,producer,NULL);
	pthread_create(&con,NULL,consumer,NULL);
	pthread_join(pro,NULL);
	pthread_join(con,NULL);
}
