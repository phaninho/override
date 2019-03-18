void clear_stdin()
{
    do
    {
        char c = getchar();
        if (c == 10)
            break;
        if (c == 255)
            break;
    } while (true);
    return;
}

int get_unum()
{
    fflush(*stdout@@GLIBC_2.0);
    scanf(var);
    clear_stdin();
    return var;
}


int read_number(int array)
{
    printf(" Index: ");
    index = get_unum();
    printf(" Number at data[%u] is %u\n", index, *((index * 4) + array));
    return 0;
}

int store_number(int *array)
{
    printf(" Number: ");
    number = get_unum();
    printf(" Index: ");
    index = get_unum();
    if ((index != (index * 2863311531) / 2) && (number / 16777216 != 183))
    {
        *((index * 4) + array) = number;
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
    while (true)
    {
        ret = 0;
        printf("Input command: ");
        fgets(buf, 20, stdin);
        if (!strcmp(buf, "store"))
            ret = store_number(&array);
        else if (!strcmp(buf, "read"))
            ret = read_number(&array);
        else if (strcmp(buf, "quit"))
            return 0;
        if (ret != 0)
            printf(" Failed to do %s command\n", &cmd);
        else
            printf(" Completed %s command successfully\n", &cmd);
    }
    return ret;
}
