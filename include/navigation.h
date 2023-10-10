#ifndef NAVIGATION_H
#define NAVIGATION_H

/**
 * @brief Change the current directory.
 * @param path Path to the desired directory.
 * @pre The given path should be a valid system path.
 * @post The application's working directory will change to the given path if valid.
 * @return 0 on success, -1 on failure.
 */
int change_directory(const char *path);

/**
 * @brief Fetch current working directory
 * @pre Application must have appropriate permissions to read the directory.
 * @post Returns a pointer to a dynamically allocated string containing the current directory.
 *       The caller is responsible for freeing this memory
 * @return Pointer to the string containing the current directory, or NULL on failure.
 */
char *get_present_directory(void);

#endif