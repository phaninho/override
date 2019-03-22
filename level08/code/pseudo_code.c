int log_wrapper(int log_fd, int src, int format)
{
    strcpy(str, src);
    size = (254 - !rcx) + 1;
    snprintf(str + (!rcx - 1), size, format); //ecris dans str
    rax = strcspn(str, "\n");       //return len de str sans \n
    *(int8_t *)(rbp + (rax - 272)) = 0;
    fprintf(log_fd, "LOG: %s\n", str); //ecris dans log_fd file
    return rax;
}

int main(int ac, int av)
{
    if (ac != 2)
        printf("Usage: %s filename\n", av[1]);
    log_fd = fopen("./backups/.log", w);
    if (log_fd == 0)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }
    else
    {
        log_wrapper(log_fd, "Starting back up: ", av[1]);
        av_fd = fopen(av[1], r);
        if (av_fd == 0)
        {
            printf("ERROR: Failed to open %s\n", av[1]);
            exit(1);
        }
        else
        {
            path = "./backups/";
            strncat(&path, av[1], (99 - !rcx) + 1); // strcat de /backup + ar[1]
            path_fd = open(&path, 'w');
            if (path_fd < 0)
            {
                printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
                exit(1);
            }
            else
            {
                do
                {
                    char_to_cmp = fgetc(av_fd);
                    if ((char_to_cmp & 255) == 255)
                        break;
                    write(path_fd, &char_to_cmp, 1);
                } while (true);
                log_wrapper(log_fd, "Finished back up ", av[1]);
                fclose(fd);
                close(path_fd);
            }
        }
    }
    return 0;
}
