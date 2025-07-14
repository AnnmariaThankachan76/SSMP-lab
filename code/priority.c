#include<stdio.h>
void main(){
 int limit,i,j,temp;
 printf("Enter the no: of processes:");
 scanf("%d",&limit);
 int process[limit],bt[limit],wt[limit],tat[limit],priority[limit];
 printf("Enter the processes and their corressponding burst time with their priority\n");
 for(i=0;i<limit;i++){
   scanf("%d%d%d",&process[i],&bt[i],&priority[i]);
 }
 
 for(i=0;i<limit;i++){
  for(j=i+1;j<limit;j++){
    if(priority[i]>priority[j]){
     temp=priority[i];
     priority[i]=priority[j];
     priority[j]=temp;
     temp=bt[i];
     bt[i]=bt[j];
     bt[j]=temp;
     temp=process[i];
     process[i]=process[j];
     process[j]=temp;
     }
    } 
   }
  
 wt[0]=0;
 tat[0]=bt[0];
 float tot_wt=0;
 float tot_tat=0;
 for(i=1;i<limit;i++){
   wt[i]=wt[i-1]+bt[i-1];
   tat[i]=tat[i-1]+bt[i];
   tot_wt=tot_wt+wt[i];
   tot_tat=tot_tat+tat[i];
 }
 
 printf("Prio\tProcess\tBt\twt\ttat\n");
  for(i=0;i<limit;i++){
    printf("%d\t%d\t%d\t%d\t%d\n",priority[i],process[i],bt[i],wt[i],tat[i]);
  }
  printf("Total wt=%.2f\nTotal tat=%.2f\nAverage wt=%.2f\nAverage tat=%.2f\n",tot_wt,tot_tat,tot_wt/limit,(tot_tat/limit));
 printf("GANTT CHART\n");
 
 for(i=0;i<limit;i++){
 printf("  P%d\t",process[i]);
 }
int x=0;
printf("\n0\t");
for(i=0;i<limit;i++){
 x=x+bt[i];
 printf("%d\t",x);
 }
 printf("\n");
}
 
