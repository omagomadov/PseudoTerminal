#include <stdio.h>

#include "display.h"

void display_error_pts_not_found() {
	printf("%s"
           "┌═════════════════════════════════════════════════════════════════════════════┐\n"
           "█                                                                             █\n"
           "█                 Le pseudo-terminal esclave est introuvable                  █\n"
           "█                                                                             █\n"
           "└═════════════════════════════════════════════════════════════════════════════┘\n"
           "%s", BRED, RESET);
}

void display_error_user_not_root() {
	printf("%s""[!] Veuillez lancer le programme avec les droits root: sudo [exécutable]""%s\n",BRED,RESET);
}

void display_error_missing_arguments() {
	printf("%s""[!] Veuillez fournir le chemin vers le pseudo-terminal esclave en cours d'utilisation: /dev/pts/<N>""%s\n",BRED,RESET);
}
