#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

#define MSGSIZE 16

int main() { 
 	int value,readValue,num,result=0,rem,outputValue;
	int p[2];
	int q[2];
	 

	pipe(p);
	pipe(q);
	int pid = fork();

	if(pid > 0) {
		printf("Enter the value:");
		scanf("%d",&value);
		write(p[1], &value, sizeof(int));  
		wait(0);
		close(p[1]);
	
		read(q[0], &outputValue, sizeof(int));
		if(outputValue == 1) 
			printf("ArmStrong Number");	
		else
			printf("Not ArmStrong Number");
		
		
	} else { 
		read(p[0], &readValue, sizeof(int));
		
		num = readValue;
		while (num != 0) { 
			rem = num % 10;
			result += rem * rem * rem;
			num /= 10;
		}

		outputValue = result == readValue ? 1 : 0;
		write(q[1], &outputValue, sizeof(int));  
		
	} 
	printf("\n");
}
