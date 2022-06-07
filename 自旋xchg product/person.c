#include <stdio.h>
#include "thread.h"
#include <unistd.h>

int flag[2]={0};
 int volatile turn;
void f()
{
	printf("ok\n");
}
void M()
{
	while(1)
	{
		flag[0]=1;
		turn=B;
		while(flag[1]==1&&turn==B);
		f;
		flag[0]=0;
	}
		
}
void N()
{
	while(1)
	{
		flag[1]=1;
		turn=A;
		while(flag[0]==1&&turn==A);
		f;
		flag[1]=0;
	}
}
int main()
{
	create(M);
	create(N);
	join();
	return 0;
}
