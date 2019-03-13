int read_number(int arg0) {
    printf(" Index: ");
    eax = get_unum();
    printf(" Number at data[%u] is %u\n", eax, *((eax << 0x2) + arg0));
    return 0x0;
}

int store_number(int arg0)
{
    var_4 = arg0;
    printf(" Number: ");
    var_10 = get_unum();
    printf(" Index: ");
    var_C = get_unum();
    if ((var_C != (HIDWORD(var_C * 0xaaaaaaab) >> 0x1) + (HIDWORD(var_C * 0xaaaaaaab) >> 0x1) + (HIDWORD(var_C * 0xaaaaaaab) >> 0x1)) && (var_10 >> 0x18 != 0xb7)) {
            *((var_C << 0x2) + var_4) = var_10;
            eax = 0x0;
    }
    else {
            puts(" *** ERROR! ***");
            puts("   This index is reserved for wil!");
            puts(" *** ERROR! ***");
            eax = 0x1;
    }
    return eax;
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
    return sotre_ret;
}
