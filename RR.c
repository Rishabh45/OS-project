#include<stdio.h>
int main()
{
    int Arrival_t[10],Burst_t[10],rt[10],endTime,i,smallest;
    int remain=0,n,time,sum_wait=0,sum_turnaround=0;
    printf("Enter no of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for Process P%d : ",i+1);
        scanf("%d",&Arrival_t[i]);
        printf("Enter burst time for Process P%d : ",i+1);
        scanf("%d",&Burst_t[i]);
        rt[i]=Arrival_t[i];
    }
    printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
    rt[9]=9999;
    for(time=0;remain!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(Burst_t[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }
		rt[smallest]--;	
        if(rt[smallest]==0)
        {
            remain++;
            endTime=time+1;	
            printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-Arrival_t[smallest],endTime-Burst_t[smallest]-Arrival_t[smallest]);
            sum_wait+=endTime-Burst_t[smallest]-Arrival_t[smallest];
            sum_turnaround+=endTime-Arrival_t[smallest];
        }
    }
    printf("\n\nAverage waiting time = %f\n",sum_wait*1.0/n);
    printf("Average Turnaround time = %f",sum_turnaround*1.0/n);
    return 0;
}
