
void	 decrypt(int num)
{
    char *str = "Q}|u`sfg~sf{}|a3n";
    char *buff;
    int len = strlen(str);
    int i = 0;

    while (i < len)
    {
        var = str[i];
		buff[i] = num ^ var;
        i++;
    }
	if (strncmp("Congratulations!", &buff, 17) == 0)
        system("/bin/sh");
    else
        puts("\nInvalid Password");
}

void	test(int a, int b)
{
	int	c;

	c = b - a;
	if (c < 21)
		decrypt(c);
	decrypt(rand());
}

int main()
{
    srand(time(0));
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    scanf(var);
    test(var, 322424845);
    return 0;
}
