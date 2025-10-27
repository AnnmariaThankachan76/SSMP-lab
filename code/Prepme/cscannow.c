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
a[n]=0;
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

   
printf("%d->  ",head);
    
        for (i = 0; i < k; i++) {
            printf("%d -> ", above[i]);
            
        }

        // Then reverse direction and serve below[] (in reverse)
        for (i = 0; i <m; i++) {
            printf("%d -> ", below[i]);
        }

        // Calculate seek time
   //     distance = (size - 1 - head) + (size - 1 - below[0]);
   /* } 
    else { 
    printf("\n\nTotal Seek Time: %d", seektime);
    printf("\nAverage Seek Time: %.2f\n", (float)seektime / (n - 1));*/
}
 
	  


