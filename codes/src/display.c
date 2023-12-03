#include <stdio.h>

#include "display.h"

void displayErrorInvalidPTS(char* message) {
	printf("%s"
           "┌═════════════════════════════════════════════════════════════════════════════┐\n"
           "█                                                                             █\n"
           "█                 Le pseudo-terminal esclave est introuvable                  █\n"
           "█                                                                             █\n"
           "└═════════════════════════════════════════════════════════════════════════════┘\n"
           "%s", BRED, RESET);
	printf("%s""[!] Veuillez exécuter la commande 'tty' dans votre terminal bash pour afficher le terminal de contrôle en cours.""%s\n",BRED,RESET);
}
