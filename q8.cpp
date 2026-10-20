#include <stdio.h>

int main()
{
    int stock[3][4][5];
    int i, j, k;
    int buildingTotal;
    int shelfTotal;
    int fullestBuilding = 0;
    int fullestShelf = 0;
    int maxShelfTotal = -1;

    for (i = 0; i < 3; i++)
    {
        printf("Building %d\n", i + 1);

        for (j = 0; j < 4; j++)
        {
            printf("Shelf %d\n", j + 1);

            for (k = 0; k < 5; k++)
            {
                printf("Slot %d: ", k + 1);
                scanf("%d", &stock[i][j][k]);
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        buildingTotal = 0;

        for (j = 0; j < 4; j++)
        {
            shelfTotal = 0;

            for (k = 0; k < 5; k++)
            {
                shelfTotal += stock[i][j][k];
                buildingTotal += stock[i][j][k];

                if (stock[i][j][k] < 5)
                {
                    printf("Needs restock: [%d][%d][%d]\n",
                           i + 1, j + 1, k + 1);
                }
            }

            if (shelfTotal > maxShelfTotal)
            {
                maxShelfTotal = shelfTotal;
                fullestBuilding = i;
                fullestShelf = j;
            }
        }

        printf("Total stock in building %d: %d\n",
               i + 1, buildingTotal);
    }

    printf("Fullest shelf: Building %d, Shelf %d, Total items = %d\n",
           fullestBuilding + 1, fullestShelf + 1, maxShelfTotal);

    return 0;
}
