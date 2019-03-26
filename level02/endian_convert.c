#include <stdio.h>

int main(int ac, char **av)
{
    if (ac < 2)
        return 1;
    for (int i = 1; i < ac; i++)
    {
        for (int j = 17; j > 0; j = j - 2)
			if (av[i][j - 1] != '0' && av[i][j] != 'x')
				printf("%c%c", av[i][j- 1],  av[i][j]);
        printf("\n");
    }
    return 0;
}
