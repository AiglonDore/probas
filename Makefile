#This file is licenced under the GNU General Public License v3.0

CC=g++
FLAGS=-Wall -Wextra -std=c++2a

all : probas.out

probas.out : obj/main.o obj/help.o obj/discretelaw.o obj/bernoulli.o obj/binomial.o
	$(CC) $(FLAGS) -o bin/$@ $^

obj/main.o : src/main.cpp headers/help.h headers/law.h
	$(CC) $(FLAGS) -c -o $@ $<

obj/help.o : src/help.cpp headers/help.h
	$(CC) $(FLAGS) -c -o $@ $<

obj/bernoulli.o : src/bernoulli.cpp headers/discretelaw.h headers/bernoulli.h headers/law.h
	$(CC) $(FLAGS) -c -o $@ $<

obj/discretelaw.o : src/discretelaw.cpp headers/law.h headers/discretelaw.h
	$(CC) $(FLAGS) -c -o $@ $<

obj/binomial.o : src/binomial.cpp headers/law.h headers/discretelaw.h headers/discretelaw.h
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	cd obj
	rm -f *.o
	cd ../bin
	rm -f *.out
	cd ..

doc :
	doxygen Doxyfile