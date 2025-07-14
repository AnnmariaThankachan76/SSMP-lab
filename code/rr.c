#include <stdio.h>
void main() {
printf("Enter time quantum\n");
int quantum;
scanf("%d",&quantum);
printf("Enter number of process\n");
int limit;
scanf("%d", &limit);
int p[limit], bt[limit], rem_bt[limit], wt[limit], tat[limit], i;
int array[50],k=1;
int time = 0;
int completed = 0;
printf("Enter processes and their corressponding burst time\n");
for (i = 0; i < limit; i++) {
  scanf("%d%d", &p[i], &bt[i]);
  rem_bt[i] = bt[i];
  }
  printf("\tGANTT CHART\n");
while (completed < limit) {
  for (i = 0; i < limit; i++) {
    if (rem_bt[i] > 0) {
      if (rem_bt[i] > quantum) {
          time += quantum;
          rem_bt[i] -= quantum;
          printf("\tP%d",p[i]);
          array[k]=time;
          k++;
          } 
    else {
      time += rem_bt[i];
      wt[i] = time - bt[i]; 
      rem_bt[i] = 0;
      completed++;
      tat[i] = time;
      printf("\tP%d",p[i]);
      array[k]=time;
      k++;
      }
    }
  }
}
printf("\n");
array[0]=0; 

int tot_wt = 0, tot_tat = 0;

for(i = 0; i < k; i++){
  printf("   %d\t",array[i]);
  }
printf("\nProcess\t\tBT\tWT\tTAT\n");
for (i = 0; i < limit; i++) {
  printf("%d\t\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
  tot_wt=tot_wt + wt[i];
  tot_tat=tot_tat+ tat[i];
 }

printf("\n");
printf("total wt=%d\ntotal tat=%d\naverage wt=%f\naverage tat=%f\n",tot_wt,tot_tat,(float)tot_wt/limit,(float)tot_tat/limit);
}

