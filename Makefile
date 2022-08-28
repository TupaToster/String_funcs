CXXFLAGS=-Wall -Wextra -Wpedantic -Wfloat-equal

all: strings.exe

strings.exe: main.o funcs.o unit_test.o strcpy_family.o
	g++ -g $(CXXFLAGS) main.o funcs.o unit_test.o -o strings.exe

main.o: main.cpp
	g++ -g $(CXXFLAGS) -c main.cpp

functions.o: funcs.cpp
	g++ -g $(CXXFLAGS) -c funcs.cpp

unit_test.o: unit_test.cpp
	g++ -g $(CXXFLAGS) -c unit_test.cpp

strcpy_family.o: strcpy_family.cpp
	g++ -g $(CXXFLAGS) -c strcpy_family.cpp

clean:
	rm -rf *.o strings.exe*

.PHONY: clean