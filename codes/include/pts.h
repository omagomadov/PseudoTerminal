#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/times.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>

#ifndef PTS_H
#define PTS_H

/**
 * @brief Lit depuis le pseudo-terminal esclave.
 *
 * @param path Le chemin vers le répertoire pseudo-terminal esclave.
 */
void read_from_pts(char *path);

/**
 * @brief Ecrit vers le pseudo-terminal esclave.
 *
 * @param path Le chemin vers le répertoire pseudo-terminal esclave.
 */
void write_to_pts(char *path);

#endif
