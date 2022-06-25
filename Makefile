#This file is licenced under the GNU General Public License v3.0

CC=gcc
FLAGS=-Wall -Wextra -std=c++2a

all : probas.out

probas.out : main.o
	$(CC) $(FLAGS) -o $@ $^

main.o : main.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o
	rm -f *.out

doc :
	doxygen Doxyfile