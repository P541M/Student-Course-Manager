courseUtils: courseUtils.o main.o
	gcc -Wall -std=c99 courseUtils.o main.c -o courseUtils -lm

courseUtils.o: courseUtils.c functionHeaders.h
	gcc -Wall -std=c99 -c courseUtils.c

main.o: main.c functionHeaders.h
	gcc -Wall -std=c99 -c main.c

clean:
	rm *.o courseUtils