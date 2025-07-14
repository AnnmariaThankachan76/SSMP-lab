#include<stdio.h>

void main(){
int i,n,j,temp,temp1;
float avg_wt=0.0,avg_tat=0.0;
int total_wt=0,total_tat=0;
printf("Enter the number of processes:");
scanf("%d",&n);
int waiting_time[n],tatime[n];
int burst_time[n],p[n];
for(i=0;i<n;i++){
p[i]=(i+1);
}

for(i=0;i<n;i++){
 printf("Enter the burst time for P%d:",(i+1));
 scanf("%d",&burst_time[i]);
 }
 // sorting
 for(i=0;i<n;i++){
  for(j=0;i<(n-i-1);i++){
   if(burst_time[j]>burst_time[j+1]){
   
    temp=burst_time[j];
    temp1=p[j];
    burst_time[j]=burst_time[j+1];
    p[j]=p[j+1];
    burst_time[j+1]=temp;
    p[j+1]=temp1;
     }
   }
  }
  
 for(i=0;i<n;i++){
 printf(" p%d :%d",p[i],burst_time[i]);
 }
 
 
 
 //calcutaing the waiting time
  waiting_time[0]=0;
 for(i=1;i<n;i++){
 waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
 total_wt+=waiting_time[i];
 }
 avg_wt=total_wt/n;
 
 //calculating turn around time
 tatime[0]=0;
 for(i=0;i<n;i++){
 tatime[i]=burst_time[i]+waiting_time[i];
 total_tat+=tatime[i];
 }
 avg_tat=total_tat/n;
 
 //Display in table
 printf("Process\tburst time\twaiting time\tturnaround time\t");
 printf("\n");
 for(i=0;i<n;i++){
 printf("P%d\t\t%d\t\t%d\t\t%d\t\t",p[i],burst_time[i],waiting_time[i],tatime[i]);
 printf("\n");
 }
 printf("The average waiting time is %.2f",avg_wt);
 printf("\n");
 printf("The average turn around time  is %.2f",avg_tat);
 printf("\n");
 //print gantt chart
 for(i=0;i<n;i++){
 printf("-------");
 }
 printf("\n");
 for(i=0;i<n;i++){
 printf("| P%d  ",p[i]);
 }
 printf("|");
 printf("\n");
 for(i=0;i<n;i++){
 printf("-------");
 }
 printf("\n");
 int current_time=0;
 printf("0");
 for(i=0;i<n;i++){
 current_time=current_time + burst_time[i];
 printf("     %d",current_time);
 }
 
 }
 
 
