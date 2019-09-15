#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pidA, pidB, pidC, pidD, pidE, pidF, pidG, pidI;
	
	pidB = fork();
	if (pidB == 0)
	{
		pidE = fork();
		if (pidE > 0)
			pidF = fork();	
	}
	else if (pidB > 0)
	{
		pidC = fork();
		if (pidC == 0)
		{
			pidG = fork();
			if (pidG == 0)
			{
				pidI = fork();
			}
		}
		else
		{
			pidD = fork();
		}
	}
	while(1){}
	return 0;
}
