f1.o: f1.c
			gcc -c -o f1.o f1.c
f2.o: f2.c
			gcc -c -o f2.o f2.c
main.o: main.c
			gcc -c -o main.o main.c
static: main.o f1.o f2.o
			ar rc libstat.a f1.o f2.o
			ranlib libstat.a
			gcc main.o -L. -lstat -o result
dynamic: main.o f1.o f2.o
			gcc -fPIC -c f1.c f2.c
			gcc -shared -o libdyn.so f1.o f2.o
			gcc main.o -L. -ldyn -o resultdyn
			#Please, add in /etc/ld.so.conf a line with the path to this program and write in Terminal "ldconfig" OR write in Terminal "LD_LIBRARY_PATH=/path/to/prog	export LD_LIBRARY_PATH"
clean:
			rm -rf result* *.o *.a *.so
