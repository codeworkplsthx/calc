


calc: asciiToInt.o intToAscii.o  utility.o calc.c
	gcc -Wall asciiToInt.o intToAscii.o utility.o calc.c -o calc

intToAscii.o: intToAscii.c intToAscii.h
	gcc -Wall -c intToAscii.c intToAscii.h
asciiToInt.o: asciiToInt.c asciiToInt.h
	gcc -Wall -c asciiToInt.c asciiToInt.h

utility.o: utility.c utility.h
	gcc -Wall -c utility.c utility.h
 
test: asciiToInt.o test.c
	gcc -Wall asciiToInt.o test.c -o test
clean:
	rm calc;
	rm asciiToInt.o;
	rm intToAscii.o;
	rm utility.o;
