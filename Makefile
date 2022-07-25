#This file is licenced under the GNU General Public License v3.0

LCC=g++#Linux G++ compiler
WCC=x86_64-w64-mingw32-g++ -m64 -static#Windows G++ compiler

ifeq ($(RELEASE),TRUE)
	FLAGS=-Wall -Wextra -std=c++2a -O2 -s
else
	FLAGS=-Wall -Wextra -std=c++2a
endif

all : probas.out probas.exe

addon : doc docker

#Linux
probas.out : obj/main.o obj/help.o obj/discretelaw.o obj/bernoulli.o obj/binomial.o obj/interface.o obj/geometric.o obj/utils.o obj/poisson.o obj/benford.o obj/continuouslaw.o obj/normallaw.o obj/cauchylaw.o
	$(LCC) $(FLAGS) -o bin/$@ $^

obj/normallaw.o : src/normallaw.cpp headers/continuouslaw.h headers/utils.h headers/exn.hpp headers/normallaw.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/continuouslaw.o : src/continuouslaw.cpp headers/continuouslaw.h headers/utils.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/poisson.o : src/poisson.cpp headers/poisson.h headers/utils.h headers/discretelaw.h headers/exn.hpp
	$(LCC) $(FLAGS) -c -o $@ $<

obj/main.o : src/main.cpp headers/help.h headers/law.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/help.o : src/help.cpp headers/help.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/bernoulli.o : src/bernoulli.cpp headers/discretelaw.h headers/bernoulli.h headers/law.h headers/exn.hpp
	$(LCC) $(FLAGS) -c -o $@ $<

obj/discretelaw.o : src/discretelaw.cpp headers/law.h headers/discretelaw.h headers/exn.hpp
	$(LCC) $(FLAGS) -c -o $@ $<

obj/binomial.o : src/binomial.cpp headers/law.h headers/discretelaw.h headers/discretelaw.h headers/utils.h headers/exn.hpp
	$(LCC) $(FLAGS) -c -o $@ $<

obj/interface.o : src/interface.cpp headers/interface.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/geometric.o : src/geometric.cpp headers/law.h headers/discretelaw.h headers/discretelaw.h headers/geometric.h headers/exn.hpp
	$(LCC) $(FLAGS) -c -o $@ $<

obj/utils.o : src/utils.cpp headers/utils.h headers/exn.hpp
	$(LCC) $(FLAGS) -c -o $@ $<

obj/benford.o : src/benford.cpp headers/benford.h headers/discretelaw.h headers/exn.hpp
	$(LCC) $(FLAGS) -c -o $@ $<

obj/cauchylaw.o : src/cauchylaw.cpp headers/cauchylaw.h headers/continuouslaw.h headers/utils.h
	$(LCC) $(FLAGS) -c -o $@ $<

#Windows
probas.exe : obj/main.obj obj/help.obj obj/discretelaw.obj obj/bernoulli.obj obj/binomial.obj obj/interface.obj obj/geometric.obj obj/utils.obj obj/poisson.obj obj/benford.obj obj/continuouslaw.obj obj/normallaw.obj obj/cauchylaw.obj
	$(WCC) $(FLAGS) -o bin/$@ $^

obj/continuouslaw.obj : src/continuouslaw.cpp headers/continuouslaw.h headers/utils.h
	$(LCC) $(FLAGS) -c -o $@ $<

obj/poisson.obj : src/poisson.cpp headers/poisson.h headers/utils.h headers/discretelaw.h headers/exn.hpp
	$(WCC) $(FLAGS) -c -o $@ $<

obj/main.obj : src/main.cpp headers/help.h headers/law.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/help.obj : src/help.cpp headers/help.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/bernoulli.obj : src/bernoulli.cpp headers/discretelaw.h headers/bernoulli.h headers/law.h headers/exn.hpp
	$(WCC) $(FLAGS) -c -o $@ $<

obj/discretelaw.obj : src/discretelaw.cpp headers/law.h headers/discretelaw.h headers/exn.hpp
	$(WCC) $(FLAGS) -c -o $@ $<

obj/binomial.obj : src/binomial.cpp headers/law.h headers/discretelaw.h headers/discretelaw.h headers/utils.h headers/exn.hpp
	$(WCC) $(FLAGS) -c -o $@ $<

obj/interface.obj : src/interface.cpp headers/interface.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/geometric.obj : src/geometric.cpp headers/law.h headers/discretelaw.h headers/discretelaw.h headers/geometric.h headers/exn.hpp
	$(WCC) $(FLAGS) -c -o $@ $<

obj/utils.obj : src/utils.cpp headers/utils.h headers/exn.hpp
	$(WCC) $(FLAGS) -c -o $@ $<

obj/benford.obj : src/benford.cpp headers/benford.h headers/discretelaw.h headers/exn.hpp
	$(WCC) $(FLAGS) -c -o $@ $<

obj/normallaw.obj : src/normallaw.cpp headers/continuouslaw.h headers/utils.h headers/exn.hpp headers/normallaw.h
	$(WCC) $(FLAGS) -c -o $@ $<

obj/cauchylaw.obj : src/cauchylaw.cpp headers/cauchylaw.h headers/continuouslaw.h headers/utils.h
	$(WCC) $(FLAGS) -c -o $@ $<

clean :
	rm -f -v bin/*.out bin/*.exe
	rm -f -v obj/*.o*
	@echo "Clean done"

#Addon
doc :
	doxygen Doxyfile

docker :
	docker build -t probas:latest .