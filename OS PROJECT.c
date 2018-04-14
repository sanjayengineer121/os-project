#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<sys/types.h>
#include<pthread.h>
#define user "11602079"
// BLINK 128
void Fpps()
{
	system("COLOR 5");
	printf("--------------------------------------------------------------------------------\n");
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("\nEnter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
    	sleep(2);
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time= \t\t\t\t %d \n",avg_wt);
    printf("Average Turnaround Time= \t\t\t %d\n",avg_tat);
}

void roundrobin()
{ 
      int i, n, total = 0, x, counter = 0, time_q; 
      int wt = 0, tat = 0, at[10], bt[10], temp[10]; 
      float avg_wt, avg_tat;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &n); 
      x = n; 
      for(i = 0; i < n; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &at[i]);
            printf("Burst Time:\t");
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_q); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_q && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_q; 
                  total = total + time_q; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
                  wt = wt + total - at[i] - bt[i]; 
                  tat = tat + total - at[i]; 
                  counter = 0; 
            } 
            if(i == n - 1) 
            {
                  i = 0; 
            }
            else if(at[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      avg_wt = wt * 1.0 / n;
      avg_tat = tat * 1.0 / n;
      printf("\n\nAverage Waiting Time:\t%f", avg_wt); 
      printf("\nAvg Turnaround Time:\t%f\n", avg_tat); 
}

void CLEAR()
{
	system("cls");
}

int main()
{
	int option;
	int choice;
	printf("\n ----------------------------------------------------------\n");
	printf("NAME-\t\t\tSANJAY KUMAR YADAV\n");
	printf("COURSE-\t\t\tCOMPUTER SCIENCE(b.tech)\n");
	printf("SECTION-\t\tk1632\nROLLNO-\t\t\tB-30\n");
	printf("REG NO-\t\t\t11602079\n\n");
	
	{		
		system("COLOR FA");
		printf("--------------------------------LOGIN PAGE--------------------------------------------\n");
    	
		int username;
		char password[20];

    	printf("Please Enter username:");
    	scanf("%d", &username);

    	printf("\nPlease enter password:");
    	scanf("%s", &password);
    	do
    	{

        	printf("Wrong username or password try again!\n");

        	printf("\nPlease Enter username:");
        	scanf("%d", &username);

        	printf("\nPlease enter password:");
        	scanf("%s", &password);

    	}
    	while ((username, user) != "11602079" && (password) != "mylife@143");
    	
    	system("COLOR B");
    	printf("Correct username and password.\n\nWelcome Mr SANJAY YADAV!\n");
    	
        sleep(3);
		printf("=============================================\n");
		printf("\t\t       Welcome To Program    \n");
		printf("================================================\n");
		
}

	
	printf("\n===========================================================\n");
	printf("-----------\n");
	printf("1-Fixed priority preemptive Scheduling\n");
	printf("--------------------------------------\n");
	printf("2-Round Robin Scheduling\n");
	printf("-------------------------\n");
		
	printf("===================================================\n");
	printf("Enter OpTion...");
	scanf("%d",&option);
	if(option==1)
	{
		Fpps();
		printf("1-WANT to CLEAR.\n");
	    printf("-----------------\n");
		printf("2-WANT to RETRY.\n");
		printf("-----------------\n");
		printf("3-WANT to END.\n");
		printf("---------------\n");
		printf("ENTER CHOICE\n");
		scanf("%d,&choice");
		if(choice==1);
		{
			CLEAR();
		}
		if(choice==2)
		{
			Fpps();
		}
		if(choice==3)
		{
			system("PAUSE");
		}
	}
	if(option==2)
	{
	roundrobin();
		printf("1-WANT to CLEAR.\n");
	    printf("-----------------\n");
		printf("2-WANT to RETRY.\n");
		printf("-----------------\n");
		printf("3-WANT to END.\n");
		printf("---------------\n");
		printf("ENTER CHOICE\n");
		scanf("%d,&choice");
		if(choice==1);
		{
			CLEAR();
		}
		if(choice==2)
		{
			roundrobin();
		}
		if(choice==3)
		{
			system("PAUSE");
		}
    }

}
