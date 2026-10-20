#include <stdio.h>

int main()
{
    int marks[6][4];
    int i, j, total;
    float average, subjectTotal[4] = {0};
    float subjectAverage[4];
    int bestSubject = 0;

    for (i = 0; i < 6; i++)
    {
        printf("Enter marks for student %d:\n", i + 1);

        for (j = 0; j < 4; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    printf("\nStudent Results\n");

    for (i = 0; i < 6; i++)
    {
        total = 0;

        for (j = 0; j < 4; j++)
        {
            total += marks[i][j];
            subjectTotal[j] += marks[i][j];
        }

        average = total / 4.0;

        printf("Student %d: Total = %d, Average = %.2f\n",
               i + 1, total, average);
    }

    for (j = 0; j < 4; j++)
    {
        subjectAverage[j] = subjectTotal[j] / 6.0;

        printf("Subject %d class average = %.2f\n",
               j + 1, subjectAverage[j]);

        if (subjectAverage[j] > subjectAverage[bestSubject])
        {
            bestSubject = j;
        }
    }

    printf("Best performing subject: Subject %d\n", bestSubject + 1);

    return 0;
}
