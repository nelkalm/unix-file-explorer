#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

/**
 * @brief Read file contents and display them
 * @param filename Name (or path) of file to be read
 * @pre File specified by filename should exit and be readable
 * @post File content displayed to standard output
 * @return None
 */
void read_file(const char *filename);

/**
 * @brief Write content to0 file. Overwrites if file already exists
 * @param filename Name (or path) of file to be written to
 * @param content The string content to write to file
 * @pre None
 * @post Content written to specified file. If file already exists, its
 *       previous content is overwritten
 * @return None.
 */

void write_file(const char *filename, const char *content);

#endif // FILE_OPERATIONS_H
