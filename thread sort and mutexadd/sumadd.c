#include <stdio.h>
#include <unistd.h>
#include "thread.h"
#define true 1 
#define false 0
int ans=0;
int  lock=false;
void sum()
{
retry:
	if(lock==true)
	{
		goto retry;
	}
	lock=true;
	for(int i=0;i<10000;++i)
	ans++;
	lock=false;
}
int main()
{
	create(sum);
	create(sum);
	join();
	printf("%d",ans);
}
