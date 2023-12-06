GCC = gcc
INCLUDE_DIRS = -I./include

compile: src/main.c src/util.c src/display.c src/pts.c
	$(GCC) $(INCLUDE_DIRS) -o run src/main.c src/util.c src/display.c src/pts.c

clean:
	rm run

