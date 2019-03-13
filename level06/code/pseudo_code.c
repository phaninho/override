int auth(char login, int serial)
{
	*(login + strcspn(login, "\n")) = '\0';
	int len = strnlen(login, 32);
	if (len <= 5)
		return (1);
	if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
	{
		puts("\033[32m.---------------------------.");
		puts ("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
		return (1);
	}
	int i = ((int)login[3] ^ 4919) + 6221293;
	int j = 0;
	while (j < len)
	{
		if (login[2] <= 31)
			return (1);
		i += (((int)login[j] ^ i) * 0x88233b2bL >> 32) - (((((int)login[j] ^ i - (((int)login[j] ^ i) * 0x88233b2bL >> 32)) >> (1 + (((int)login[j] ^ i) * 0x88233b2bL >> 32))) >> 10)) * 1337;
	}
	if (serial == i)
		return (0);
	return (1);
}


int main()
{
    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");
    printf("-> Enter Login: ");
    fgets(&login, 32, stdin);
    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial: ");
    scanf(serial);
    if (auth(login, serial) == 0)
    {
            puts("Authenticated!");
            system("/bin/sh");
            return 0;
    }
    return 1;
}
