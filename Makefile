all:
	gcc -c log.c -o log.o
	ar rcs liblog.a log.o
clean:
	rm -rf log.o
	rm -rf liblog.a
