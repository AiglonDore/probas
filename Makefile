#This file is licenced under the GNU General Public License v3.0

LCC=g++#Linux G++ compiler
WCC=x86_64-w64-mingw32-g++ -m64 -static#Windows G++ compiler

ifeq ($(RELEASE),TRUE)
	FLAGS=-Wall -Wextra -std=c++2a -O2 -s
else
	FLAGS=-Wall -Wextra -std=c++2a
endif

all : probas.out

probas.out : obj/main.o obj/help.o obj/discretelaw.o obj/bernoulli.o obj/binomial.o obj/interface.o
	$(LCC) $(FLAGS) -o bin/$@ $^

obj/main.o : src/main.cpp headers/help.h headers/law.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/help.o : src/help.cpp headers/help.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/bernoulli.o : src/bernoulli.cpp headers/discretelaw.h headers/bernoulli.h headers/law.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/discretelaw.o : src/discretelaw.cpp headers/law.h headers/discretelaw.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/binomial.o : src/binomial.cpp headers/law.h headers/discretelaw.h headers/discretelaw.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/interface.o : src/interface.cpp headers/interface.h
	$(LCC) $(FLAGS) -c -o $@ $<

probas.exe : obj/main.obj obj/help.obj obj/discretelaw.obj obj/bernoulli.obj obj/binomial.obj obj/interface.obj
	$(LCC) $(FLAGS) -o bin/$@ $^

obj/main.obj : src/main.cpp headers/help.h headers/law.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/help.obj : src/help.cpp headers/help.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/bernoulli.obj : src/bernoulli.cpp headers/discretelaw.h headers/bernoulli.h headers/law.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/discretelaw.obj : src/discretelaw.cpp headers/law.h headers/discretelaw.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/binomial.obj : src/binomial.cpp headers/law.h headers/discretelaw.h headers/discretelaw.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/interface.obj : src/interface.cpp headers/interface.h
	$(WCC) $(FLAGS) -c -o $@ $<

clean:
	rm -r -f -v obj
	mkdir obj
	touch obj/.gitkeep
	rm -r -f -v bin
	mkdir bin
	touch bin/.gitkeep

doc :
	doxygen Doxyfile