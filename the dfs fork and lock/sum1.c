#include "thread.h"
long sum=0;
void Tsum()
{
	for(int i=0;i<100000;++i)
	{
	asm volatile("lock add $1,%0":"+m"(sum));
	}
}
int main()
{
	create(Tsum);
	create(Tsum);
	join();
	printf("%ld\n",sum);

	return 0;
}

