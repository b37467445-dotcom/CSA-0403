#include <stdio.h>

int main() {
    int n, i, q, t = 0, done;
    int bt[20], rt[20], wt[20] = {0}, tat[20];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Burst time P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &q);

    if (n <= 0 || n > 20 || q <= 0) {
        printf("Invalid input");
        return 1;
    }

    do {
        done = 1;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;

                if (rt[i] > q) {
                    t += q;
                    rt[i] -= q;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while (!done);

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        awt += wt[i];
        atat += tat[i];

        printf("P%d\t%d\t%d\t%d\n",
               i+1, bt[i], wt[i], tat[i]);
    }

    printf("Average WT = %.2f\n", awt/n);
    printf("Average TAT = %.2f\n", atat/n);

    return 0;
}
