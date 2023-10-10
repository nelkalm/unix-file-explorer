#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/navigation.h"

/**
 * @brief Change the current directory.
 * @param path Path to the desired directory.
 * @pre The given path should be a valid system path.
 * @post The application's working directory will change to the given path if valid.
 * @return 0 on success, -1 on failure.
 */
int change_directory(const char *path)
{
    if (chdir(path) != 0)
    {
        perror("Error changing directory");
        return -1;
    }
    return 0;
}

/**
 * @brief Fetch current working directory
 * @pre Application must have appropriate permissions to read the directory.
 * @post Returns a pointer to a dynamically allocated string containing the current directory.
 *       The caller is responsible for freeing this memory
 * @return Pointer to the string containing the current directory, or NULL on failure.
 */
char *get_present_directory(void)
{
    char *buffer = NULL;
    buffer = getcwd(buffer, 0); // buffer dynamic allocation
    if (buffer == NULL)
    {
        perror("Error getting current directory");
    }
    return buffer;
}