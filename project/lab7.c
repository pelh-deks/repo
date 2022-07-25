#include <stdio.h>
#include <stdlib.h>
struct J
{
    int id, bt, tat, wt, at, ft;
} job[100];
void scheduler(struct J job[], int n, int q, int c)
{
    int burst[100], x, t = 0, done = 0, curr = 0, diff = q, i = 0;
    float tat_sum = 0, wt_sum = 0;
    for (i = 0; i < n; i++)
        burst[i] = job[i].bt;
    if (c == 0)
        curr = -1;
    while (done < n)
    {
        if (c == 1)
        {
            for (x = 0; x < n; x++)
            {
                if (job[curr].bt == 0)
                    curr = x;
                if (job[x].bt, job[curr].bt && job[x].bt > 0 && job[x].at <= t)
                    curr = x;
            }
            diff = 1;
        }
        else
        {
            while (1)
            {
                curr = (curr + 1) % n;
                if (job[curr].bt != 0)
                    break;
            }
            diff = (q <= job[curr].bt) ? q : job[curr].bt;
        }
        job[curr].bt -= diff;
        t += diff;
        if (job[curr].bt == 0)
        {
            done++;
            job[curr].ft = t;
        }
    }
    if (c == 1)
        printf("SRJF Details are\n");
    else
        printf("RR Scheduling Details Are\n");
    for (i = 0; i < n; i++)
    {
        job[i].bt = burst[i];
        job[i].tat = job[i].ft - job[i].at;
        job[i].wt = job[i].tat - job[i].bt;
        tat_sum += job[i].at;
        wt_sum += job[i].wt;
    }
    printf("JOB\tBT\tAT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", i + 1, job[i].bt, job[i].at, job[i].tat, job[i].wt);
    printf("AVG TAT=%f\nAVG WT=%f\n", tat_sum / n, wt_sum / n);
}
int main()
{
    int n, q, c, i;
    printf("Enter The Number of Processes:\n");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time\n");
    for (i = 0; i < n; i++)
    {
        printf("job%d:", i + 1);
        scanf("%d%d", &job[i].at, &job[i].bt);
    }
    while (1)
    {
        printf("1.RR\n2.SRJf\n3.Exit\n");
        printf("Select One Option\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter time quantum\n");
            scanf("%d", &q);
            scheduler(job, n, q, 0);
            break;
        case 2:
            scheduler(job, n, 1, 1);
            break;
        case 3:
            exit(0);
        }
    }
}
