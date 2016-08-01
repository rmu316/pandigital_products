pandigital: pandigital.o
	gcc -o pandigital -g pandigital.o
pandigital.o: pandigital.c
	gcc -g -c -Wall pandigital.c
clean:
	rm -f *.o pandigital  
