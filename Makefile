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