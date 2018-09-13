#include<stdio.h>
#include<malloc.h>


int n,*a;

struct pro
{
	int name,at,bt,tt,wt,left,status;
}*p;


void create(int num){
	a=(int*)malloc(num*sizeof(int));
}


int smallers(int num){
	int c=0,i;
	for(i=0;i<n;i++)
		{
			if((p+i)->bt<num && (p+i)->status==0)
				{
					*(a+c)=(p+i)->bt;
					c++;
				}
		}
return c;
}


int search(int num){
	int i;
	for(i=0;i<n;i++)
	{
		if((p+i)->bt==num && (p+i)->status==0)
	return i;
	}
}


int main(){

int i, c_time=0 , b, s_nums, j, pro_num, p_time;
float att=0, awt=0;

printf("Enter no. of processes- ");
scanf("%d",&n);
create(n);

p=(struct pro *)malloc(n*sizeof(struct pro));

for(i=0;i<n;i++){
	(p+i)->status=0;
}

printf("---Enter Process Name, Arrival Time & CPU Burst Time---\n");

for(i=0;i<n;i++){
	scanf("%d %d %d",&(p+i)->name,&(p+i)->at,&(p+i)->bt);
}

for(i=0;i<n;i++)
{
if((p+i)->status==0)
{
b=(p+i)->bt;
s_nums=smallers(b);
if(s_nums>0)
{
(p+i)->left=(p+i)->bt;
for(j=0;j<s_nums;j++)
{
p_time=c_time;
pro_num=search(*(a+j));
if(c_time<(p+pro_num)->at)
{
if((p+i)->left>(p+pro_num)->at)
{
c_time=(p+pro_num)->at;
(p+i)->left=(p+i)->bt-(c_time-p_time);
c_time=c_time+(p+pro_num)->bt;
(p+pro_num)->status=1;
}
else
{
c_time=c_time+(p+i)->bt;
(p+i)->tt=c_time-(p+i)->at;
(p+i)->status=1;
if(c_time<(p+pro_num)->at)
break;
}
}
else
{
c_time=c_time+(p+pro_num)->bt;
}
(p+pro_num)->tt=c_time-(p+pro_num)->at;
(p+pro_num)->status=1;
}
if((p+i)->status==0)
{
c_time=c_time+(p+i)->left;
(p+i)->tt=c_time-(p+i)->at;
(p+i)->status=1;
}
}
else
{	
c_time=c_time+(p+i)->bt;
(p+i)->tt=c_time-(p+i)->at;
(p+i)->status=1;
}
}
}


printf("\nProcess\t\tArrival Time\t\tCPU Burst Time\t\tTurnAround Time\t\tWaiting Time\n");

for(i=0;i<n;i++)
{
	(p+i)->wt=(p+i)->tt-(p+i)->bt;
	awt=awt+(p+i)->wt;
	att=att+(p+i)->tt;
}

for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",(p+i)->name,(p+i)->at,(p+i)->bt,(p+i)->tt,(p+i)->wt);
	}

printf("\nAverage Turnaround Time :  %f\n",att/n);

printf("Average Waiting Time :  %f\n\n",awt/n);

return 0;
}