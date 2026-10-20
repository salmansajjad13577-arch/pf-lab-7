#include <stdio.h>

int main()
{
    int sales[3][5];
    int i, j;
    int branchTotal[3] = {0};
    int productTotal[5] = {0};
    int bestBranch = 0;
    int lowestProduct = 0;

    for (i = 0; i < 3; i++)
    {
        printf("Enter sales for branch %d:\n", i + 1);

        for (j = 0; j < 5; j++)
        {
            printf("Product %d: ", j + 1);
            scanf("%d", &sales[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            branchTotal[i] += sales[i][j];
            productTotal[j] += sales[i][j];
        }
    }

    printf("\nBranch Sales\n");

    for (i = 0; i < 3; i++)
    {
        printf("Branch %d: %d\n", i + 1, branchTotal[i]);

        if (branchTotal[i] > branchTotal[bestBranch])
        {
            bestBranch = i;
        }
    }

    printf("\nProduct Sales\n");

    for (j = 0; j < 5; j++)
    {
        printf("Product %d: %d\n", j + 1, productTotal[j]);

        if (productTotal[j] < productTotal[lowestProduct])
        {
            lowestProduct = j;
        }
    }

    printf("Best-selling branch: Branch %d\n", bestBranch + 1);
    printf("Lowest-selling product: Product %d\n", lowestProduct + 1);

    return 0;
}
