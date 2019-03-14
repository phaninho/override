int read_number(int num)
{
    printf(" Index: ");
    Unum = get_unum();
    printf(" Number at data[%u] is %u\n", Unum, *((Unum << 2) + num));
    return 0;
}

int store_number(int num)
{
    printf(" Number: ");
    Unum1 = get_unum();
    printf(" Index: ");
    Unum2 = get_unum();
    if ((Unum2 != (HIDWORD(Unum2 * 2863311531) >> 1) + (HIDWORD(Unum2 * 2863311531) >> 1) + (HIDWORD(Unum2 * 2863311531) >> 1)) && (Unum1 >> 24 != 183))
    {
        *((Unum2 << 2) + num) = Unum1;
        return 0;
    }
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    return 1;
}

int main()
{
    puts("----------------------------------------------------\n  Welcome to wil's crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data sto…");
    printf("Input command: ");
    fgets(0, 20, stdin);
    *(int8_t *)(esp + (!ecx - 0x2) + 0x1b8) = 0x0;
    if (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)) != 0)
    {
        if (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)) != 0)
        {
            if (sign_extend_32((COND_BYTE_SET(G)) - (COND ? 1 : 0)) == 0)
            {
                ret = 0;
                esi = var_10 ^ * 20;
                if (esi != 0)
                    ret = __stack_chk_fail();
            }
        }
    }
    ret = store_number(&num);
    if (ret != 0)
        printf(" Failed to do %s command\n", &cmd);
    else
        printf(" Completed %s command successfully\n", &cmd);
    cmd = 0;
    *(&cmd + 4) = 0;
    *(&cmd + 8) = 0;
    *(&cmd + 12) = 0;
    *(&cmd + 16) = 0;
    ret = read_number(&num);
    return ret;
}
