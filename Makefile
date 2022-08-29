CXXFLAGS=-Wall -Wextra -Wpedantic -Wfloat-equal

all: strings.exe

strings.exe: main.o size_and_get.o unit_test.o strcpy.o fputs.o
	g++ -g $(CXXFLAGS) main.o size_and_get.o unit_test.o strcpy.o fputs.o -o strings.exe

main.o: main.cpp
	g++ -g $(CXXFLAGS) -c main.cpp	

size_and_get.o: size_and_get.cpp
	g++ -g $(CXXFLAGS) -c size_and_get.cpp

unit_test.o: unit_test.cpp
	g++ -g $(CXXFLAGS) -c unit_test.cpp

strcpy.o: strcpy.cpp
	g++ -g $(CXXFLAGS) -c strcpy.cpp

fputs.o: fputs.cpp
	g++ -g $(CXXFLAGS) -c fputs.cpp

clean:
	rm -rf *.o strings.exe*

.PHONY: clean