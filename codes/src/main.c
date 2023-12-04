#include "display.h"
#include "util.h"

int main(int argc, char* argv[]) {
	if( check_is_root() < 0 ) {
		display_error_user_not_root();
		exit(EXIT_FAILURE);
	}

	if( argc < 2 ) {
		display_error_missing_arguments();
		exit(EXIT_FAILURE);
	}

	if( (check_is_pts_directory(argv[1]) < 0) || (check_pts_exist(argv[1]) < 0)) {
		display_error_pts_not_found();
		display_available_pts();
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
