#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <regex.h>

#ifndef DISPLAY_H
#define DISPLAY_H
#define BRED "\e[1;31m"
#define BGREEN "\e[1;32m"
#define RESET "\e[0m"

/**
 * @brief Affiche un message d'erreur indiquant que le pseudo-terminal esclave n'est pas trouvé.
 *
*/
void display_error_pts_not_found();

/**
 * @brief Affiche un message indiquant que le pseudo-terminal esclave est trouvé.
 *
 */
void display_pts_found();

/**
 * @brief Affiche un message d'erreur indiquant que l'utilisateur n'a pas les droits root.
 *
*/
void display_error_user_not_root();


/**
 * @brief Affiche un message d'erreur indiquant que la commande entrer est incorrect.
 *
 * @note(commande doit être soit 'input', soit 'output')
 *
*/
void display_error_invalid_command();

/**
 * @brief Affiche un message d'erreur indiquant que les paramètres sont manquants.
 *
*/
void display_error_missing_arguments();

/**
 * @brief Affiche la liste des pseudo-terminaux esclaves disponible.
 *
*/
void display_available_pts();

#endif
