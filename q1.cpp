#include <stdio.h>

int main()
{
    int seats[5][8];
    int i, j, freeSeats, totalFree = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("Enter seat status for row %d, seat %d (0/1): ", i + 1, j + 1);
            scanf("%d", &seats[i][j]);
        }
    }

    printf("\nSeating Map\n");

    for (i = 0; i < 5; i++)
    {
        freeSeats = 0;

        for (j = 0; j < 8; j++)
        {
            if (seats[i][j] == 0)
            {
                printf(". ");
                freeSeats++;
            }
            else
            {
                printf("X ");
            }
        }

        totalFree += freeSeats;
        printf("\nFree seats in row %d: %d\n", i + 1, freeSeats);
    }

    printf("Total free seats: %d\n", totalFree);

    return 0;
}
