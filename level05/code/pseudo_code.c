int main()
{
    fgets(&str, 100, stdin);
    i = 0;
    do
    {
        if (((str[i] & 255) > 64) && (((str[i] & 255) <= 90))
            str[i] = str[i] + 20;
        i++;
    } while (true);
    printf(&str);
    exit(0);
}
