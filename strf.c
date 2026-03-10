#include <stdio.h>

int main() {
    int n,i,time=0,smallest,count=0;
    int at[10],bt[10],rt[10],finish;
    int wt[10],tat[10];
    float avg_wt=0,avg_tat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(count!=n){
        smallest=-1;
        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1){
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0){
            count++;
            finish=time;

            tat[smallest]=finish-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];

            avg_wt+=wt[smallest];
            avg_tat+=tat[smallest];
        }
    }

    printf("\nWaiting Time:\n");
    for(i=0;i<n;i++)
        printf("P%d %d\n",i+1,wt[i]);

    printf("\nTurnaround Time:\n");
    for(i=0;i<n;i++)
        printf("P%d %d\n",i+1,tat[i]);

    printf("\nAverage Waiting Time: %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n",avg_tat/n);

    return 0;
}
