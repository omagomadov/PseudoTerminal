#include "pts.h"

void write_to_pts(char *path) {
	int fd;
	fd_set writefds;
	char bytes[1];

	if( (fd = open(path, O_RDWR)) < 0 ) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("Ecriture vers le buffer d'entrée du pseudo-terminal esclave (%s). . .\n",  path);
	printf("(Entrer 'q' pour quitter)\n");
	FD_ZERO(&writefds);
	FD_SET(fd, &writefds);
	scanf("%s", bytes);

	while( (select(fd + 1, NULL, &writefds, NULL, NULL)) > 0 && strncmp("q", bytes, 1) != 0 ) {
		if (ioctl(fd, TIOCSTI, bytes)) {
			perror("ioctl");
			exit(EXIT_FAILURE);
		}
		scanf("%s", bytes);
		FD_ZERO(&writefds);
		FD_SET(fd, &writefds);
	}

	close(fd);
}

void read_from_pts(char *path) {
        int fd;
        fd_set readfds;
        char bytes[1];

        if( (fd = open(path, O_RDONLY)) < 0 ) {
                perror("open");
                exit(EXIT_FAILURE);
        }

        printf("Lecture depuis le buffer d'entrée du pseudo-terminal esclave (%s). . .\n", path);
	printf("(Entrer 'q' depuis le pseudo-terminal esclave pour quitter)\n");
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        while( (select(fd + 1, &readfds, NULL, NULL, NULL)) > 0 && strncmp("q", bytes, 1) != 0) {
		read(fd, bytes, 1);
		write(1, bytes, sizeof(bytes));
                FD_ZERO(&readfds);
                FD_SET(fd, &readfds);
        }

        close(fd);
}
