#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 4
int total=0;
pthread_mutex_t *m;
int A[N][N];
void *func(void *arg)
{
	int i,row,sum=0;
	pthread_t pid=pthread_self();
	row=(int)arg;
	printf("i am [%lu] sum of  %d\n",pid,row);
	for(i=0;i<N;++i)
		sum+=A[row][i];
	printf("thread %d [%lu] update total with %d\n:",row,pid,sum);
	
	pthread_mutex_lock(m);
	total+=sum;
	pthread_mutex_unlock(m);
	printf("sum is %d",total);
}
int main()
{
	pthread_t thread[N];
	int i,j,r;
	void *status;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			A[i][j]=i*N+j+1;
			printf("%4d",A[i][j]);
		}
		printf("\n");
	}
	m=(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(m,NULL);
	printf("Main:create %d threads\n",N);
	for(i=0;i<N;++i)
	{
		 pthread_create(&thread[i],NULL,func,(void*)i);
	}
	printf("%d",total);
	printf("back\n");
	for(int i=0;i<N;++i)
	{
		pthread_join(thread[i],&status);
	}
	pthread_mutex_destroy(m);
	pthread_exit(NULL);
}

