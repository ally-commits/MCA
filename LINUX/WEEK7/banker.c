include<stdio.h>

int main() {
	int allocation[10][10],max[10][10],need[10][10],available[5],n,m;
	int i,j;	
	int execArr[10],k=0,h=0,completed[10];
	int safe,avail,flag;

	printf("Enter Number of Process:");
	scanf("%d",&n);
	printf("Enter Number of resources:");
	scanf("%d",&m);
	
	printf("Enter Allocation & Max:");
	
	for(i=0;i<n;i++) {
		printf("\nAllocation for Process %d:",i+1);
		for(j=0;j<m;j++) {
			scanf("%d",&allocation[i][j]);
		}
		printf("Max for Process %d:",i+1);
		for(j=0;j<m;j++) {
			scanf("%d",&max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
		}
		completed[i]=0;
	}
	printf("Enter Available Resources:");
	for(i=0;i<m;i++) {
		scanf("%d",&available[i]);
	}
	safe = 1;
	while(k != n) {
		flag = 0;
		for(i=0;i<n;i++) {
			avail = 1;
			for(j=0;j<m;j++) {
				if(need[i][j] > available[j]) {
					avail = 0;
				}	
			}
			if(avail && completed[i] == 0) {
				execArr[k]=i+1;
				k++;
				completed[i] = 1;
				flag = 1;
				for(j=0;j<m;j++) {
					available[j] = available[j] + allocation[i][j];
				}
			}
		}
		if(flag == 0) {
			safe = 0;
			printf("\nSystem is not in safe state");
			break;
		}
	}	
		
	if(safe) {
		printf("\nProcess Execution sequence:");
		for(i=0;i<k;i++) {
			printf("P%d",execArr[i]);
			if(i < k-1)
				printf("->");
		}
	}
	printf("\n");
}

