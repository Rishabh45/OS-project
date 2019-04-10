#include<stdio.h>
int main()
{
int i,n,a[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int Burst_t[10],Arrival_t[10],Wating_t[10],Ta_time[10],ta=0,sum=0;
int temp,j;
float Wating_avg=0,turn_avg=0,tsum=0,wsum=0;
printf("Enter the No. of processes :");
scanf("%d",&n);
 
for(i=0;i<n;i++) // take the input in the Arrival time & Burst time.
{
printf("\tEnter the burst time of %d process :",i+1);
scanf(" %d",&Burst_t[i]);
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&Arrival_t[i]);
}

for(i=0;i<n;i++) // sort the Arrival time.
{
for(j=0;j<n;j++)
{
if(Arrival_t[i]<Arrival_t[j])
{
temp=a[j];
a[j]=a[i];
a[i]=temp;
temp=Arrival_t[j];
Arrival_t[j]=Arrival_t[i];
Arrival_t[i]=temp;
temp=Burst_t[j];
Burst_t[j]=Burst_t[i];
Burst_t[i]=temp;
}
}
}

for(j=0;j<n;j++)
{
btime=btime+Burst_t[j];
min=Burst_t[k];
for(i=k;i<n;i++)
{
if (btime>=Arrival_t[i] && Burst_t[i]<min)
{
temp=a[k];
a[k]=a[i];
a[i]=temp;
temp=Arrival_t[k];
Arrival_t[k]=Arrival_t[i];
Arrival_t[i]=temp;
temp=Burst_t[k];
Burst_t[k]=Burst_t[i];
Burst_t[i]=temp;
}
}
k++;
}
Wating_t[0]=0;

for(i=1;i<n;i++) // Claculate a wating time and a average wating time.
{
sum=sum+Burst_t[i-1];
Wating_t[i]=sum-Arrival_t[i];
wsum=wsum+Wating_t[i];
}

Wating_avg=(wsum/n);
for(i=0;i<n;i++) // Calculate a turnaround time and average turnaround time.  
{
ta=ta+Burst_t[i];
Ta_time[i]=ta-Arrival_t[i];
tsum=tsum+Ta_time[i];
}
 
turn_avg=(tsum/n);
printf("\nProcess\t| Burst\t | Arrival\t | Waiting\t | Turn-around\n" );
for(i=0;i<n;i++)
{
printf("\n p%d\t| %d\t | %d\t\t |   %d\t\t | \t%d\n",a[i],Burst_t[i],Arrival_t[i],Wating_t[i],Ta_time[i]);
}
printf("\n\nAverage Wating time = %f",Wating_avg);
printf("\nAverage turn around time = %f",turn_avg);
return 0;
}  
