#include<stdio.h>

void main() 
{

int head, a[20], j,i, distance, n, seektime, size,temp,above[20],below[20],k=0,m=0,direction;


	printf("\nEnter Head position: ");
	scanf("%d", &head);
	printf("\nEnter number of disk requests: ");
	scanf("%d", &n);
	printf("\nEnter the disk size: ");
	scanf("%d", &size);
	printf("\nEnter the disk requests: ");
	for (i = 0; i < n; i++) {
    		scanf("%d", &a[i]);
	}
	
a[n]=head;
n++;
//sorting
for (i = 0; i < n ; i++) {
    	for ( j = 0; j < n - i - 1; j++) {
        	if (a[j] > a[j + 1]) {
            	temp = a[j];
            	a[j] = a[j + 1];
            	a[j + 1] = temp;
        	}
    	}
	}
	
	
a[n]=size-1;
n++;
for (i = 0; i < n ; i++) {
printf(" %d ",a[i]);
}



	
	  
	 for (i = 0; i < n; i++) {
        if (a[i] < head)
            below[m++] = a[i];
        else if (a[i] > head)
            above[k++] = a[i];
    }

    printf("\nEnter direction of head movement (1 for high end, 0 for low end): ");
    scanf("%d", &direction);

    printf("\nOrder of service:\n");

printf("%d->  ",head);
    // SCAN (Elevator) logic
    if (direction == 1) { 
        // Move toward higher end first
        // Serve above[] first
        for (i = 0; i < k; i++) {
            printf("%d -> ", above[i]);
        }

        // Then reverse direction and serve below[] (in reverse)
        for (i = m - 1; i >= 0; i--) {
            printf("%d -> ", below[i]);
        }

        // Calculate seek time
        distance = (size - 1 - head) + (size - 1 - below[0]);
    } 
    else { 
        // Move toward lower end first
        // Serve below[] first (in reverse)
        for (i = m - 1; i >= 0; i--) {
            printf("%d -> ", below[i]);
        }

        // Then reverse direction and serve above[]
        for (i = 0; i < k; i++) {
            printf("%d -> ", above[i]);
        }

        // Calculate seek time
        distance = (head - 0) + (above[k - 1] - 0);
    }

    seektime = distance;
    printf("\n\nTotal Seek Time: %d", seektime);
    printf("\nAverage Seek Time: %.2f\n", (float)seektime / (n - 1));
}
 
	  


