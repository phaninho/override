#include <stdio.h>

int main(int ac, char **av)
{
    if (ac < 2)
        return 1;
    for (int i = 1; i < ac; i++)
    {
        for (int j = 15; j > 0; j = j - 2)
            printf("%c%c", av[i][j- 1],  av[i][j]);
        printf("\n");
    }
    return 0;
}
