#include<stdio.h>
void main()
{
int i,n,total_wt,total_tat;
float avg_wt=0.0,avg_tat=0.0;
printf("Enter the number of processes:");
scanf("%d",&n);
int bursttime[n],waiting_time[n],tat[n];
for(i=0;i<n;i++){

printf("Enter the burst time of P%d :",i);
scanf("%d",&bursttime[i]);
}
//calculating waiting time

waiting_time[0]=0;
for(i=1;i<n;i++){
waiting_time[i]=waiting_time[i-1]+bursttime[i];
total_wt+=waiting_time[i];
}
avg_wt=total_wt/2;

//calculating the turnaround time
//tat[0]=0;
for(i=0;i<n;i++){
tat[i]=bursttime[i]+waiting_time[i];
total_tat+=tat[i];
}
avg_tat=total_tat/2;


//display
printf("Processes\tburst time\twaiting time\tturnaround time\t");
printf("\n");
for(i=0;i<n;i++){
printf("P%i\t\t%d\t\t%d\t\t%d",(i+1),bursttime[i],waiting_time[i],tat[i]);
printf("\n");
}
printf("Avg waiting time is %.2f",avg_wt);
printf("\n");
printf("Avg turnaround time is %.2f",avg_tat);
printf("\n");
//gantt chart
for(i=0;i<n;i++)
printf("-------");
printf("\n");
for(i=0;i<n;i++)
{
printf("|  P%d  ",(i+1));
}
printf("|");
printf("\n");
for(i=0;i<n;i++)
printf("-------");
printf("\n");
int curent_time=0;
printf("0");
for(i=0;i<n;i++)
{
curent_time=curent_time+ bursttime[i];
printf("      %d",curent_time);
}

}
