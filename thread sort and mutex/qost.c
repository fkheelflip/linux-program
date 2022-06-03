#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#define N 10
typedef struct
{
	int l;
	int r;
}pram;
int a[N]={5,1,3,6,7,2,9,8,0,3};
int print()
{
	int i=0;
	for(i=0;i<N;++i)
		printf("%4d",a[i]);
	printf("\n");
}
void *qt(void *aptr)
{
	pram *ap,aleft,aright;
	int pivot,pivotIndex,left,right,temp;
	int l,r;
	pthread_t  me,leftthread,rightthread;
	me=pthread_self();
	ap=(pram*)aptr;
	l=ap->l;
	r=ap->r;
	pivot=a[r];
	left=l-1;
	right=r;
	if(left>=right)
	{
		pthread_exit(NULL);
	}
	while(left<right)
	{
		do(left++);while(a[left]<pivot);
		do(right--);while(a[right]>pivot);
		if(left<right)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		}
        }
	printf("%lu is creae\n",pthread_self());
	print();
	pivotIndex=left;
	temp=a[pivotIndex];
	a[pivotIndex]=pivot;
	a[r]=temp;
	aleft.r=pivotIndex-1;
	aleft.l=l;
	aright.r=r;
	aright.l=pivotIndex+1;
	pthread_create(&leftthread,NULL,qt,(void*)&aleft);
	pthread_create(&rightthread,NULL,qt,(void*)&aright);
	pthread_join(leftthread,NULL);
	pthread_join(rightthread,NULL);
}


int main()
{
	pram arg;
	int i,*status;
	pthread_t me,thread;
	me=pthread_self();
	print();
	arg.l=0;
	arg.r=N-1;
	printf("create a thread %d \n",me);
	pthread_create(&thread,NULL,qt,(void*)&arg);
	pthread_join(thread,NULL);
	printf("after \n");
	print();
}
