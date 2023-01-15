#include<stdio.h>
#include<stdlib.h>

int mutex=1,x=0,full=0;
int arr[10],empty=2;


void signalFunc() {
	mutex = 1;
}

void waitFunc() {
	mutex = 0;
}

void producer() {
	waitFunc();
	empty--;
	printf("\nProducer value:");
	scanf("%d",&arr[full]);
	full++;
	signalFunc();
}

void consumer() {
	waitFunc();
	full--;
	empty++;
	printf("\nConsumer Consumed: %d",arr[full]);
	signalFunc();
}

int main() {
	int choice;

	do {
		printf("\n1.Producer");
		printf("\n2.Consumer");
		printf("\n3.Exit..");

		printf("\nEnter choice value:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				if(mutex == 1 && empty != 0)
					producer();
				else
					printf("\nBuffer is full");

				break;
			case 2:
				if(mutex == 1 && full > 0)
					consumer();		
				else
					printf("\nBuffer is empty");
				
				break;
			case 3:
				printf("\nExit");
			
		}		
			
	} while(choice != 3);
	return 0;
}


