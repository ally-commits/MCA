#include<stdio.h>

int main() {
	int temp,i,j,burstTime[10],n,wTime[10],tTime[10],pId[10];
	printf("enter n:");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&burstTime[i]);
		pId[i] = i+1;
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(burstTime[i] < burstTime[j]) {
				temp = burstTime[i];
				burstTime[i] = burstTime[j];
				burstTime[j] = temp;

				temp = pId[i];
				pId[i] = pId[j];
				pId[j] = temp;
			}
		}
	}
	for(i=0;i<n;i++) {
		if( i== 0 ) {
			wTime[i] = 0;
			tTime[i] = burstTime[i];
		} else {
			wTime[i] = tTime[i-1];
			tTime[i] = wTime[i] + burstTime[i];
		}
	} 
	
	printf("\n------------------------------------");
	for(i=0;i<n;i++) {
		printf("\nP%d ",pId[i]);
		printf("%d ",burstTime[i]);
		printf("%d ",wTime[i]);
		printf("%d ",tTime[i]);
	}
	printf("\n");
}
