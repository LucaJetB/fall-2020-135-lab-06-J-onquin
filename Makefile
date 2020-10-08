

main: main.o funcs.o caesar.o vigenere.o decrypt.o
	g++ -o main main.o funcs.o caesar.o vigenere.o decrypt.o

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o


funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h

caesar.o: caesar.cpp caesar.h

decrypt.o: decrypt.cpp decrypt.h

vigenere.o: vigenere.cpp vigenere.h

tests.o: tests.cpp  doctest.h

clean:
	rm -f main.o tests.o funcs.o

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests

