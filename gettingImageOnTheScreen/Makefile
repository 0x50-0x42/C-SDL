files=main.c init.c loadMedia.c _close.c

run: $(files)
	gcc -g $(files) -w -lSDL2 -o run

.PHONY: clean

clean:
	-rm run
