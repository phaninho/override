int main()
{
    ps = fork();
    var = 0;
    if (ps != 0)
    {
        prctl(1);
        ptrace(0, 0, NULL, NULL);
        puts("Give me some shellcode, k");
        gets(str);
        return 0;
    }
    wait(&var);
    if (((var & 127) == 0) || (SAR((var & 127) + 1, 1) > 0))
    {
        str = "child is exiting...";
        puts(str);
        return 0;
    }
    if (ptrace(3, ps, 44, NULL) == 11)
    {
        puts("no exec() for you");
        kill(ps, 9);
        return 0;
    }
    return 0;
}
