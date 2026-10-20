#include <stdio.h>

int main()
{
    int rooms[4][6];
    int i, j, vacancies;
    int maxVacancies = -1;
    int bestFloor = 0;
    int found = 0;

    for (i = 0; i < 4; i++)
    {
        printf("Enter room status for floor %d (1 occupied, 0 vacant):\n",
               i + 1);

        for (j = 0; j < 6; j++)
        {
            printf("Room %d: ", j + 1);
            scanf("%d", &rooms[i][j]);
        }
    }

    for (i = 0; i < 4; i++)
    {
        vacancies = 0;

        for (j = 0; j < 6; j++)
        {
            if (rooms[i][j] == 0)
            {
                vacancies++;
            }
        }

        printf("Vacancies on floor %d: %d\n", i + 1, vacancies);

        if (vacancies > maxVacancies)
        {
            maxVacancies = vacancies;
            bestFloor = i;
        }
    }

    printf("Floor with most vacancies: Floor %d\n", bestFloor + 1);

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            if (rooms[i][j] == 0 &&
                rooms[i][j + 1] == 0 &&
                rooms[i][j + 2] == 0)
            {
                printf("Floor %d has 3 consecutive vacant rooms starting at room %d\n",
                       i + 1, j + 1);
                found = 1;
            }
        }
    }

    if (found == 0)
    {
        printf("No floor has 3 consecutive vacant rooms.\n");
    }

    return 0;
}
