all: exe lib

exe: hello.h main.c lib
	gcc main.c -fPIC -ldl -Wl,-rpath=. -o hello

lib: hello.h hello.c
	gcc -shared hello.c -fPIC -o libHello.so

debug: 
	gcc -g3 main.c -fPIC  -ldl -Wl,-rpath=. -o hello
	gcc -shared -g3 hello.c  -fPIC -o libHello.so

clean:
	-rm hello libHello.so 2>/dev/null
