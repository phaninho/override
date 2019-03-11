int main()
{
    fd = fopen("/home/users/level03/.pass", 0x400bb0);
    if (fd == 0)
    {
        fwrite("ERROR: failed to open password file\n", 1, 36, *stderr@@GLIBC_2.2.5);
        exit(1);
    }
    len = fread(&ptr, 1, 41, fd);
    rax = strcspn(&ptr, 0x400bf5);
    // *(int8_t *)(rbp + (rax - 160)) = 0;
    if (len != 41)
    {
        fwrite("ERROR: failed to read password file\n", 1, 36, *stderr@@GLIBC_2.2.5);
        exit(1);
    }
    fclose(fd);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\");
    puts("| You must login to access this system. |");
    puts("\**************************************/");
    printf("--[ Username: ");
    fgets(&Username, 100, *stdin@@GLIBC_2.2.5);
    rax = strcspn(&Username, 0x400bf5);
    // *(int8_t *)(rbp + (rax - 112)) = 0;
    printf("--[ Password: ");
    fgets(&password, 100, *stdin@@GLIBC_2.2.5);
    rax = strcspn(&password, 0x400bf5);
    // *(int8_t *)(rbp + (rax - 272)) = 0;
    puts("*****************************************");
    if (strncmp(&ptr, &password, 41) == 0)
    {
        printf("Greetings, %s!\n", &Username);
        system("/bin/sh");
        return 0;
    }
    printf(&Username);
    puts(" does not have access!");
    return 0;
}
