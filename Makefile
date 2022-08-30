CC=g++

CFLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: string.exe

string.exe: main.o fputs.o strlen.o strcpy.o strcat.o fgets.o strdup.o strchr.o
	$(CC) $(CFLAGS) main.o strcpy.o strlen.o fputs.o strcat.o fgets.o strdup.o strchr.o -o string.exe

strlen.o: strlen.cpp
	$(CC) $(CFLAGS) strlen.cpp -c

fputs.o: fputs.cpp
	$(CC) $(CFLAGS) fputs.cpp -c

strcpy.o: strcpy.cpp
	$(CC) $(CFLAGS) strcpy.cpp -c

strcat.o: strcat.cpp
	$(CC) $(CFLAGS) strcat.cpp -c

strdup.o: strdup.cpp
	$(CC) $(CFLAGS) strdup.cpp -c

strchr.o: strchr.cpp
	$(CC) $(CFLAGS) strchr.cpp -c

fgets.o: fgets.cpp
	$(CC) $(CFLAGS) fgets.cpp -c

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -c

clean:
	rm -rf *.o *.exe*

.PHONY: clean