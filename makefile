all: info.c
	gcc -o info info.c

run: all
	./info

clean:
	rm *.o
	rm *~
	rm infox
