
int verify_user_name()
{
    puts("verifying username....\n");
    return (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)));
}

int verify_user_pass(int arg0)
{
    return (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)));
}

int main()
{
    // asm { rep stosd  dword [edi], eax };
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    User_data = *stdin@@GLIBC_2.0;
    len = 256;
    fgets(0x804a040, len, User_data);
    if (verify_user_name() != 0)
    {
        str = "nope, incorrect username...\n";
        puts(str);
        return 1;
    }
    puts("Enter Password: ");
    User_data = *stdin@@GLIBC_2.0;
    len = 100;
    fgets(&dest, len, User_data);
    str = &dest;
    check_pass = verify_user_pass(str);
    if ((check_pass != 0) && (check_pass == 0))
        return 0;
    str = "nope, incorrect password...\n";
    puts(str);
    return 1;
}
