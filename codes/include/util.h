#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


#ifndef UTIL_H
#define UTIL_H

#include "display.h"

/**
 * @brief Vérifie que le chemin correspond bien à un répertoire pseudo-terminal esclave.
 *
 * @param path Le chemin du répertoire à vérifier.
 *
 * @return 1 si le répertoire est valide, -1 sinon.
*/
int check_is_pts_directory(char *path);

/**
 * @brief Vérifie que le chemin correspond bel est bien vers un fichier spécial de pseudo-terminal esclave.
 *
 * @param path Le chemin vers le fichier spécial pseudo-terminal esclave.
 *
 * @return le descripteur de fichier du pseudo-terminal esclave, -1 sinon
 */
int check_pts_exist(char *path);

/**
 * @brief Vérifie que les droits root sont utiliser.
 *
 * @return 1 si les droits root sont utiliser, -1 sinon.
 *
 */
int check_is_root();

/**
 * @brief Prépare le pattern pour le regex.
 *
 * @param preg Le pattern regex.
 *
*/
void prepare_regex(regex_t *preg);

#endif
