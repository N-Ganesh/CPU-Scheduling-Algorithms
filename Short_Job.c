// (Non Preemptive Shortest Job First)
#include<stdio.h>
#include<string.h>
int main()
{
int n;
printf("Enter the no of Processes : ");
scanf("%d",&n);
int p[n],burst[n];
int i;
for(int i=0;i<n;i++)
{
printf("Enter Process ID : ");
scanf("%d",&p[i]);
}
for(i=0;i<n;i++)
{
printf("Enter the Burst time of Process %d : ",p[i]);
scanf("%d",&burst[i]);
}
int comp[n],tat[n],waiting[n];
static int sum = 0;
int dup[n];
static int count = 0;
int pos;
int match = burst[0];
for(i=0;i<n;i++)
{
if(burst[i]<match)
match = burst[i];
}
for(i=0;i<n;i++)
dup[i] = burst[i];
while(1)//while true
{
for(i=0;i<n;i++)
{
if(match == burst[i])
{
comp[i] = sum + burst[i];
sum = sum + burst[i];
count++;
}
}
if(count == n)
break;
int new_match;
for(int j=0;burst[j]!='\0';j++)
{
if(burst[j]>match)
{
new_match = burst[j];
break;
}
}
for(int j=0;burst[j]!='\0';j++)
{
if(new_match>burst[j]&&burst[j]>match)
new_match = burst[j];
}
match = new_match;
}
for(i=0;i<n;i++)
tat[i] = comp[i]; // Turn Around Time = CT - AT and AT is 0 for all Processes
for(i=0;i<n;i++)
waiting[i] = tat[i] - burst[i];
printf("\n");
printf("Process ID \t Burst Time \t Completion Time \t\t Turn Around Time \t Waiting Time\n");
for(int i=0;i<n;i++)
{
printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t",p[i],burst[i],comp[i],tat[i],waiting[i]);
printf("\n");
}
printf("\n");
float avg_time =0;
for(i=0;i<n;i++)
avg_time+=(float)waiting[i];
avg_time = (float) avg_time/((float)n);
printf("The average waiting time of each process is %f",avg_time);
printf("\n");
printf("Gant Chart - ");
printf("\n");
sum = comp[0];
for(i=0;i<n;i++)
{
if(sum<comp[i])
sum = comp[i];
}
//Gantt Chart
int val;
for(i=0;i<=sum;i++)
{
if(i==0)
printf("0__");
else
{
for(int j=0;j<n;j++)
{
if(comp[j] == i)
{
val = comp[j];
break;
}
else
val = -1;
}
if(val == -1)
printf("__");
else
printf("%d",val);
}
}
printf("\n");
}
