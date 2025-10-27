#include <stdio.h>

int main() {
    int n,i, quantum;
    float wavg = 0.0, tavg = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int btime[n], wait[n], tat[n], remainingtime[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for P%d: ", i + 1);
        scanf("%d", &btime[i]);
        remainingtime[i] = btime[i];
        wait[i] = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);


int done,gantt[100],ganttime[100],time=0,gantindex=0;

do {
done=1;

for(i=0;i<n;i++){
while(remainingtime[i]>0){

done=0;
gantt[gantindex]=i;
ganttime[gantindex++]=time;

if(remainingtime[i]>quantum){
  time+=quantum;
  remainingtime[i]-=quantum;}
  else{
  time+=remainingtime[i];
  wait[i]=time-btime[i];
  remainingtime[i]=0;
}
}
}
}while(!done);
 for (int i = 0; i < n; i++) {
        tat[i] = btime[i] + wait[i];
        wavg += wait[i];
        tavg += tat[i];
    }

    
    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, btime[i], wait[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", wavg / n);
    printf("\nAverage Turnaround Time = %.2f\n", tavg / n);


for(i=0;i<gantindex;i++)
printf("-------");
printf("\n");
for(i=0;i<gantindex;i++)
printf("|  P%d ",gantt[i]+1);
printf("\n");
for(i=0;i<gantindex;i++)
printf("-------");
printf("\n");
for(i=0;i<gantindex;i++)
printf("  %d  ",ganttime[i]);
printf("%d",time);
}

