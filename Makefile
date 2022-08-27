CXXFLAGS=-Wall -Wextra -Wpedantic -Wfloat-equal

all: strings.exe

strings.exe: main.o funcs.o
	g++ -g $(CXXFLAGS) main.o funcs.o -o strings.exe

main.o: main.cpp
	g++ -g $(CXXFLAGS) -c main.cpp

functions.o: funcs.cpp
	g++ -g $(CXXFLAGS) -c funcs.cpp

clean:
	rm -rf *.o strings.exe*

.PHONY: clean