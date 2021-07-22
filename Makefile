#Makefile
all: add-nbo

add-nbo:
		g++ -c -o add-nbo.o add-nbo.cpp
		g++ -o add-nbo add-nbo.o

clean:
		rm -f add-nbo
		rm -f *.o


