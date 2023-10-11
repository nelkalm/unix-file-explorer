#include <stdio.h>
#include "../include/file_operations.h"

void read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);
}

void write_file(const char *filename, const char *content)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
}