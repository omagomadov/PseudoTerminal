#include "util.h"

int check_is_pts_directory(char *path) {
	regex_t preg;
	prepare_regex(&preg);

	if( regexec(&preg, path, 0, NULL, 0) == REG_NOMATCH) {
		regfree(&preg);
		return -1;
	}
	regfree(&preg);
	return 1;
}

int check_pts_exist(char *path) {
	return access(path, F_OK);
}

int check_is_root() {
	if(geteuid() != 0) {
		return -1;
	}
	return 1;
}

void prepare_regex(regex_t *preg) {
	if( regcomp(preg, "/dev/pts/[0-9]+$", REG_EXTENDED | REG_ICASE) < 0) {
		exit(EXIT_FAILURE);
	}
}

void prepare_regex_only_number(regex_t *preg) {
	if( regcomp(preg, "[0-9]$", REG_EXTENDED | REG_ICASE) < 0 ) {
		exit(EXIT_FAILURE);
	}
}
