#include <stdio.h>

int main()
{
    float temp[7][4];
    float hottest, coldest, noonTotal = 0, noonAverage;
    int i, j, hotDay, hotTime, coldDay, coldTime;

    for (i = 0; i < 7; i++)
    {
        printf("Enter temperatures for day %d:\n", i + 1);

        for (j = 0; j < 4; j++)
        {
            printf("Time slot %d: ", j + 1);
            scanf("%f", &temp[i][j]);
        }
    }

    hottest = temp[0][0];
    coldest = temp[0][0];

    hotDay = coldDay = 0;
    hotTime = coldTime = 0;

    for (i = 0; i < 7; i++)
    {
        noonTotal += temp[i][1];

        for (j = 0; j < 4; j++)
        {
            if (temp[i][j] > hottest)
            {
                hottest = temp[i][j];
                hotDay = i;
                hotTime = j;
            }

            if (temp[i][j] < coldest)
            {
                coldest = temp[i][j];
                coldDay = i;
                coldTime = j;
            }
        }
    }

    noonAverage = noonTotal / 7.0;

    printf("\nHottest temperature: %.2f on day %d, time slot %d\n",
           hottest, hotDay + 1, hotTime + 1);

    printf("Coldest temperature: %.2f on day %d, time slot %d\n",
           coldest, coldDay + 1, coldTime + 1);

    printf("Weekly noon average: %.2f\n", noonAverage);

    printf("Days with noon temperature above average:\n");

    for (i = 0; i < 7; i++)
    {
        if (temp[i][1] > noonAverage)
        {
            printf("Day %d\n", i + 1);
        }
    }

    return 0;
}s
