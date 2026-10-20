#include <stdio.h>
#include <ctype.h>

int main()
{
    char titles[5][50];
    int copies[5];
    int i, j, vowels;
    char letter;
    int mostCopies = 0;

    for (i = 0; i < 5; i++)
    {
        printf("Enter title of book %d: ", i + 1);
        scanf(" %[^\n]", titles[i]);

        printf("Enter number of copies: ");
        scanf("%d", &copies[i]);
    }

    printf("\nLibrary Catalog\n");
    printf("Book Title\t\tCopies\tVowels\n");

    for (i = 0; i < 5; i++)
    {
        vowels = 0;

        for (j = 0; titles[i][j] != '\0'; j++)
        {
            char ch = tolower(titles[i][j]);

            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
            {
                vowels++;
            }
        }

        printf("%s\t\t%d\t%d\n", titles[i], copies[i], vowels);

        if (copies[i] > copies[mostCopies])
        {
            mostCopies = i;
        }
    }

    printf("\nEnter a letter to search titles: ");
    scanf(" %c", &letter);

    letter = tolower(letter);

    printf("Titles starting with %c:\n", letter);

    for (i = 0; i < 5; i++)
    {
        if (tolower(titles[i][0]) == letter)
        {
            printf("%s\n", titles[i]);
        }
    }

    printf("Title with the most copies: %s\n", titles[mostCopies]);

    return 0;
}
