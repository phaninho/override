int main()
{
    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");
    printf("Password:");
    scanf(pass);
    if (pass == 5276) 
    {
        puts("\nAuthenticated!");
        system("/bin/sh");
        return 0;
    }
    puts("\nInvalid Password!");
    return 1;
}
