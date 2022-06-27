#This file is licenced under the GNU General Public License v3.0

CC=gcc
FLAGS=-Wall -Wextra -std=c99

all : probas.out

probas.out : obj/main.o
	$(CC) $(FLAGS) -o bin/$@ $^

obj/main.o : src/main.c headers/help.h
	$(CC) $(FLAGS) -c -o $@ $<

obj/help.o : src/help.c headers/help.h
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -r -i -f -v *.out
	rm -r -i -f -v *.o

doc :
	doxygen Doxyfile