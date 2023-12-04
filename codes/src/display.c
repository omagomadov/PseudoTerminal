#include "display.h"
#include "util.h"

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

void display_available_pts() {
	DIR* directory;
	struct dirent *dir;
	regex_t preg;

	if( (directory = opendir("/dev/pts")) == NULL  ) {
		printf("%s""[!] Le répertoire /dev/pts/ est introuvable dans votre système.\n[!!] Ce programme ne fonctionne uniquement pour les distributions Linux (MacOS & Windows sont exclus) ""%s");
	} else {
		prepare_regex_only_number(&preg);
		printf("Voici les pseudo-terminaux esclaves en cours d'utilisation dans votre système: \n");
		while( (dir = readdir(directory)) != NULL  ) {
			if( (regexec(&preg, dir->d_name, 0, NULL, 0)) != REG_NOMATCH  ) {
				printf("┌───────────────────────────────────────────────────┐\n");
				printf("│ - Pseudo-terminal esclave n° %-13s        │\n", dir->d_name);
				printf("│ - Le type de fichier: ");
				switch(dir->d_type) {
					case DT_BLK:
						printf("périphérique de blocs       │\n");
						break;
        				case DT_CHR:
            					printf("périphérique caractère      │\n");
            					break;
        				case DT_DIR:
            					printf("répertoire                  │\n");
            					break;
        				case DT_FIFO:
            					printf("pipe nommé                  │\n");
            					break;
        				case DT_LNK:
            					printf("lien symbolique             │\n");
            					break;
        				case DT_REG:
            					printf("fichier régulier            │\n");
            					break;
        				case DT_SOCK:
            					printf("domaine de socket UNIX      │\n");
            					break;
        				case DT_UNKNOWN:
            					printf("inconnue                    │\n");
            					break;
    					}
    					printf("└───────────────────────────────────────────────────┘\n");
			}
		}
		regfree(&preg);
	}
}
