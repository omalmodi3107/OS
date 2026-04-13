#include <stdio.h>
  
int main(){
    
    int at[5]={0,1,2,3,4};
    int bt[5]={5,7,6,2,4};
    int ct[5],wt[5],tat[5];
    int i;
    float avg_wt=0, avg_tat=0;

    ct[0] =at[0] + bt[0];

    for(i=1; i<5; i++){
        if(ct[i-1] < at[i])
            ct[i] = at[i]+bt[i]+2;
        else
            ct[i] = ct[i-1]+bt[i]+2;
    }
    for(i=0; i<5; i++){
        tat[i] = ct[i]-at[i];
        wt[i] = tat[i]-bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }
     avg_tat = avg_tat /5;
     avg_wt = avg_wt/5;

    

    printf("PID\tAT\tBT\tCT\tAT\tWT\n");
    for(i=0; i<5; i++){
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n", i,at[i],bt[i],ct[i],tat[i],wt[i]);

    }
    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f", avg_wt);


    return 0;



}