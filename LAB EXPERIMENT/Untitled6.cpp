#include <stdio.h>

int main() {
    int n, i, t = 0, done = 0, k;
    int at[20], bt[20], rt[20], pr[20], ct[20];
    int wt[20], tat[20];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival, burst and priority P%d: ", i+1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        k = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0) {
                if (k == -1 || pr[i] < pr[k])
                    k = i;
            }
        }

        if (k == -1) {
            t++;
            continue;
        }

        rt[k]--;
        t++;

        if (rt[k] == 0) {
            ct[k] = t;
            done++;
        }
    }

    printf("\nProcess\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];

        printf("P%d\t%d\t%d\n", i+1, wt[i], tat[i]);
    }

    printf("Average WT = %.2f\n", awt/n);
    printf("Average TAT = %.2f\n", atat/n);

    return 0;
}
