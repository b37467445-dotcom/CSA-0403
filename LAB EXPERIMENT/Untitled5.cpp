#include <stdio.h>

int main() {
    int n, i, j, bt[20], p[20], pr[20];
    int wt[20], tat[20], t;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter burst time and priority P%d: ", p[i]);
        scanf("%d%d", &bt[i], &pr[i]);
    }

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (pr[i] > pr[j]) {
                t = pr[i]; pr[i] = pr[j]; pr[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
        }
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];

        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("Average WT = %.2f\n", awt/n);
    printf("Average TAT = %.2f\n", atat/n);

    return 0;
}
