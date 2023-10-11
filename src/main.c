#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/navigation.h"
#include "../include/file_operations.h"

/**
 * @brief The entry point of the Unix-like File Explorer program.
 *
 * Allows users to execute specific commands related to directory navigation, file
 * operations directly from the shell prompt. Currently supports changing directories and
 * fetching the current directory, reading files and writing contents to file.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv An array of strings representing each argument.
 *
 * @pre The program expects at least one argument (i.e., the command to execute).
 *      For the "-cd" command, a subsequent directory path argument is expected.
 *
 * @post Depending on the command provided:
 *      - "-cd": Changes the working directory to the provided path.
 *      - "-pwd": Prints the current working directory to the standard output.
 *      - "-read": Reading file content.
 *      - "-write": Writing content that was read to a specific file.
 *      - No recognized command: Prints usage help.
 *
 * @return Returns 0 if the program executed successfully.
 *         Returns 1 if there's an error or if input arguments are incorrect.
 */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide an argument. Use --help for usage information.\n");
        return 1;
    }

    // Conditionals related to directory navigation
    if (strcmp(argv[1], "-cd") == 0)
    {
        if (argc < 3)
        {
            printf("Please provide a path to change to.\n");
        }
        if (change_directory(argv[2]) == 0)
        {
            printf("Changed directory to: %s\n", argv[2]);
        }
    }
    else if (strcmp(argv[1], "-pwd") == 0)
    {
        char *path = get_present_directory();
        if (path)
        {
            printf("Current Directory: %s\n", path);
            free(path);
        }
    }

    // Conditionals related to reading and writing files
    if (strcmp(argv[1], "-read") == 0)
    {
        if (argc < 3)
        {
            printf("Please provide a filename to read.\n");
            return 1;
        }
        read_file(argv[2]);
    }
    else if (strcmp(argv[1], "-write") == 0)
    {
        if (argc < 4)
        {
            printf("Please provide a filename and content to write.\n");
            return 1;
        }
        write_file(argv[2], argv[3]);
    }
    else
    {
        printf("Unknown argument. Use --help for usage information.\n");
    }

    return 0;
}