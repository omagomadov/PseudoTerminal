#include <stdio.h>

#ifndef DISPLAY_H
#define DISPLAY_H
#define BRED "\e[1;31m"
#define RESET "\e[0m"

/**
 * @brief Affiche un message d'erreur indiquant que le pseudo-terminal esclave n'est pas trouvé.
 *
*/
void display_error_pts_not_found();

/**
 * @brief Affiche un message d'erreur indiquant que l'utilisateur n'a pas les droits root.
 *
*/
void display_error_user_not_root();

/**
 * @brief Affiche un message d'erreur indiquant que les paramètres sont manquants.
 *
*/
void display_error_missing_arguments();

#endif
