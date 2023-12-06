#include "display.h"
#include "util.h"
#include "pts.h"

int main(int argc, char* argv[]) {
	if( check_is_root() < 0 ) {
		display_error_user_not_root();
		exit(EXIT_FAILURE);
	}

	if( argc < 3 ) {
		display_error_missing_arguments();
		exit(EXIT_FAILURE);
	}

	if( (check_is_pts_directory(argv[1]) < 0) || (check_pts_exist(argv[1]) < 0)) {
		display_error_pts_not_found();
		display_available_pts();
		exit(EXIT_FAILURE);
	} else {
		display_pts_found();
	}

	if( strcmp("input", argv[2]) == 0) {
		write_to_pts(argv[1]);
	} else if( strcmp("output", argv[2]) == 0) {
		read_from_pts(argv[1]);
	} else {
		display_error_invalid_command();
	}

	exit(EXIT_SUCCESS);
}
