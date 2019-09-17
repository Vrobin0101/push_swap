#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int main(int ac, char **av)
{
	int u;

	u = 1;
	(void)ac;
	int n=atoi(av[1]),i;
	bool arr[1000000]={0};
	time_t t;
	srand((unsigned)time(&t));
	for(i=0;i<n;++i)
	{
		u++;
		int r=rand()%1000000;
		if(!arr[r])
		{
			if (u % 2 == 0)
				printf("%d ",r);
			else
				printf("%d ",r * -1);
		}
		else
			i--;
		arr[r]=1;    
	}
}
