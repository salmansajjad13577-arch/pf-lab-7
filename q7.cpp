#include <stdio.h>

int main()
{
    int marks[3][4][5];
    int i, j, k, total;
    float average, departmentTotal[3] = {0};
    float departmentAverage[3];
    int topper[3];
    float highestAverage;

    for (i = 0; i < 3; i++)
    {
        printf("Department %d\n", i + 1);

        for (j = 0; j < 4; j++)
        {
            printf("Enter marks for student %d:\n", j + 1);

            for (k = 0; k < 5; k++)
            {
                printf("Subject %d: ", k + 1);
                scanf("%d", &marks[i][j][k]);
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        topper[i] = 0;
        highestAverage = -1;

        for (j = 0; j < 4; j++)
        {
            total = 0;
            int failed = 0;

            for (k = 0; k < 5; k++)
            {
                total += marks[i][j][k];

                if (marks[i][j][k] < 40)
                {
                    failed = 1;
                }
            }

            average = total / 5.0;
            departmentTotal[i] += total;

            printf("Department %d, Student %d: Average = %.2f",
                   i + 1, j + 1, average);

            if (failed)
            {
                printf(" FAIL");
            }

            printf("\n");

            if (average > highestAverage)
            {
                highestAverage = average;
                topper[i] = j;
            }
        }

        departmentAverage[i] = departmentTotal[i] / 20.0;

        printf("Topper of department %d: Student %d\n",
               i + 1, topper[i] + 1);
    }

    int bestDepartment = 0;

    for (i = 0; i < 3; i++)
    {
        printf("Department %d overall average: %.2f\n",
               i + 1, departmentAverage[i]);

        if (departmentAverage[i] > departmentAverage[bestDepartment])
        {
            bestDepartment = i;
        }
    }

    printf("Department with highest overall average: Department %d\n",
           bestDepartment + 1);

    return 0;
}
