int secret_backdoor()
{
    fgets(&buf, 128, **qword_201fb8);
    rax = system(&buf);
    return rax;
}

int set_msg(int ptr)
{
    puts(">: Msg @Unix-Dude");
    printf(">>:");
    fgets(&buf, 1024, **qword_201fb8);
    len = *(int32_t *)(ptr + 180);
    ret = strncpy(ptr, &buf, len);
    return ret;
}

int set_username(int ptr)
{
    puts(">: Enter your username");
    printf(">>:");
    fgets(&buf, 128, **qword_201fb8);
    for (i = 0; i <= 40; i++)
    {
        if ((*(int8_t *)(rbp + (sign_extend_32(i) - 144)) & 255) == 0)
            break;
        *(int8_t *)(ptr + sign_extend_32(i) + 140) = *(int8_t *)(rbp + (sign_extend_32(i) - 144)) & 255;
    }
    printf(">: Welcome, %s", ptr + 140);
    return 0;
}

int handle_msg()
{
    set_username(&ptr);
    set_msg(&ptr);
    puts(">: Msg sent!");
    return 0;
}

int main()
{
    puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
    handle_msg();
    return 0;
}
