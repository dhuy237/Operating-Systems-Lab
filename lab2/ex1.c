#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int divideTwo(char* str)
{
	int n = strlen(str);
        return (((str[n-1] - '0') == 0) || ((str[n-1] - '0') == 2) || ((str[n-1] - '0') == 4) || ((str[n-1] - '0') == 6) || ((str[n-1] - '0') == 8));
}

int divideThree(char* str)
{
	int n = strlen(str);
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += (str[i] - '0');
	}
	return (sum % 3 == 0);	
}

int divideFive(char* str)
{
	int n = strlen(str);
	return ( ((str[n-1] - '0') == 0) || ((str[n-1] - '0') == 5) );
}

int main() {
	FILE *fp = NULL;
	char str[10][100];
    	int i = 0;
    	int countTwo = 0;
    	int countThree = 0;
    	int countFive = 0;
		
    	char* filename = "./numbers.txt";
	
	fp = fopen(filename, "r");
	while(fgets(str[i], 100, fp))
	{
		str[i][strlen(str[i]) - 1] = '\0';
		i++;
	}	
	fclose(fp);
 
	pid_t pid;
	pid = fork();

	if (pid == 0)
	{
		pid_t c_pid;
		c_pid = fork();
		if (c_pid == 0)
		{
			for (int j = 0; j < i; j++)
				if (divideFive(str[j]) == 1) countFive++;
			printf("Five: %d\n", countFive);
		}
		else if (c_pid > 0)
		{
			for (int j = 0; j < i; j++)
				if (divideThree(str[j]) == 1) countThree++;
			printf("Three: %d\n", countThree);
		}
	}
	else if (pid > 0)
	{
		for (int j = 0; j < i; j++)
			if (divideTwo(str[j]) == 1) countTwo++;
		printf("Two: %d\n", countTwo);
	}
	while(1){};
	return 0;
}
