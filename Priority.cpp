#include<iostream>
using namespace std;
int main()
{
int n;
int i,j;
cout<<"Enter the no of processes : ";
cin>>n;
int pid[n],arr[n],burst[n],tat[n],waiting[n],comp[n],prior[n];
int dup_burst[n];
int least_arr,high_prior;
for(i=0;i<n;i++)
{
cout<<"Enter Process ID : ";
cin>>pid[i];
}
for(i=0;i<n;i++)
{
cout<<"Enter arrival time of process "<<pid[i]<<" : ";
cin>>arr[i];
}
for(i=0;i<n;i++)
{
cout<<"Enter burst time of process "<<pid[i]<<" : ";
cin>>burst[i];
}
least_arr = arr[0];
for(i=0;i<n;i++)
{
if(least_arr>arr[i])
least_arr = arr[i];
comp[i] = 0; // Setting zero to all Completion Time values
prior[i] = 0; // Assigning value of 0 priority to all the processes
dup_burst[i] = burst[i]; // Creating a duplicate Burst Time Array
}
int time_slice = least_arr;
for(i=0;i<n;i++)
{
if(arr[i] == least_arr)
{
prior[i] = prior[i] + 1;
time_slice = time_slice + 1;
dup_burst[i] = dup_burst[i] - 1;
for(j=0;j<n;j++)
{
if(arr[j]<=time_slice && j!=i)
prior[j] = prior[j] + 2;
}
for(j=0;j<n;j++)
{
if(dup_burst[j]>0)
comp[j] = comp[j] + 1 + least_arr;
}
break;
}
}
high_prior = prior[0];
for(i=0;i<n;i++)
{
if(high_prior<prior[i])
high_prior = prior[i];
}
while(1)
{
int count=0;
for(i=0;i<n;i++)
{
if(dup_burst[i] <= 0)
count++;
}
if(count == n)
break;
else
{
for(i=0;i<n;i++)
{
if(high_prior == prior[i])
{
time_slice = time_slice + 1;
prior[i] = prior[i] + 1;
for(j=0;j<n;j++)
{
if(arr[j]<=time_slice && j!=i && dup_burst[j]>0)
prior[j] = prior[j] + 2;
if(dup_burst[j]>0)
comp[j] = comp[j]+1;
}
if(dup_burst[i]>0)
dup_burst[i] = dup_burst[i] - 1;
}
int cnt = 0;
for(j=0;j<n;j++)
{
if(high_prior<prior[j])
high_prior = prior[j];
if(dup_burst[j] <= 0)
cnt++;
}
if(cnt == n)
break;
}
}
}
for(i=0;i<n;i++)
{
tat[i] = comp[i] - arr[i];
}
for(i=0;i<n;i++)
waiting[i] = tat[i] - burst[i];
cout<<endl;
cout<<"Process ID\tBurst Time\tArrival Time\tCompletion Time\t\tTurn Around Time \t Waiting Time "<<endl<<endl;
for(int i=0;i<n;i++)
cout<<pid[i]<<"\t\t"<<burst[i]<<"\t\t"<<arr[i]<<"\t\t"<<comp[i]<<"\t\t\t"<<tat[i]<<"\t\t\t"<<waiting[i]<<endl<<endl;
cout<<endl;
float avg_wait = 0;
for(i=0;i<n;i++)
avg_wait = avg_wait + waiting[i];
avg_wait = avg_wait/(float)n;
cout<<"The average waiting time is : "<<avg_wait<<endl;
}
