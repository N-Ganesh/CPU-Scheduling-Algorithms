//Non Preemptive Shortest Job First Algorithm where arrival time of all processes is same
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int index_compare(string s1,string c);
string to_string(string s,int t);
int main()
{
int n;
string s = "";
cout<<"Enter the no of Processes : ";
cin>>n;
int p[n],burst[n];
int i;
for(int i=0;i<n;i++)
{
cout<<"Enter Process ID : ";
cin>>p[i];
}
for(i=0;i<n;i++)
{
cout<<"Enter Burst time of Process "<<p[i]<<" : ";
cin>>burst[i];
}
int comp[n],tat[n],waiting[n];
int sum = 0;
int dup[n],count = 0;
int pos;
int match = burst[0];
for(i=0;i<n;i++)
{
if(burst[i]<match)
match = burst[i];
}
for(i=0;i<n;i++)
dup[i] = burst[i];
while(true)
{
for(i=0;i<n;i++ )
{
if(burst[i] == match && index_compare(s,to_string("",i)) != 0)
{
comp[i] = sum + burst[i];
sum = sum + burst[i];
s = to_string(s,i);
for(i=0;dup[i]!='\0';i++)
{
if(dup[i] == match)
pos = i;
}
int length=0;
for(i=0;dup[i]!='\0';i++)
length++;
for(i=pos+1;dup[i]!='\0';i++)
dup[i-1] = dup[i];
dup[length-1] = '\0';
match = dup[0];
for(i=0;dup[i]!='\0';i++)
{
if(match>dup[i])
match = dup[i];
}
count++;
}
if(count == n)
break;
}
if(count == n)
break;
}
for(i=0;i<n;i++)
tat[i] = comp[i]; // Turn Around Time = CT - AT and AT is 0 for all Processes
for(i=0;i<n;i++)
waiting[i] = tat[i] - burst[i];
cout<<endl;
cout<<"Process ID\tBurst Time\tCompletion Time \t\tTurn Around Time \t Waiting Time "<<endl<<endl;
for(int i=0;i<n;i++)
cout<<p[i]<<"\t\t\t"<<burst[i]<<"\t\t\t"<<comp[i]<<"\t\t\t"<<tat[i]<<"\t\t\t"<<waiting[i]<<endl<<endl;
cout<<endl;
float avg_wait=0;
for(i=0;i<n;i++)
avg_wait = avg_wait + waiting[i];
avg_wait = avg_wait/(float)n;
cout<<"\nAverage Waiting Time of Each Process is "<<avg_wait<<endl;
cout<<endl;
cout<<"Gantt Chart -"<<endl<<endl;
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
cout<<0<<"__";
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
cout<<"__";
else
cout<<val;
}
}
cout<<endl;
}
int index_compare(string s,string c) //Index Matching
{
int found;
found = s.find(c);
return found;
}
string to_string(string s,int t) //Index type conversion from int to string
{
stringstream ss;
ss<<s<<t;
return ss.str();

}
