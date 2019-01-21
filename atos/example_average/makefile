CFLAGS := -std=c99 -Wall -Werror -c
ifeq ($(mode), debug)
	CFLAGS += -g3
endif
ifeq ($(mode), release)
	CFLAGS += -g0
endif

main.o : main.c
	gcc $(CFLAGS) main.c

test.o : test.c
	gcc $(CFLAGS) test.c

test.exe : test.o
	gcc test.o -o test.exe

build : main.o
	gcc main.o -o app.exe

run : build
	./app.exe

clean :
	rm *.o *.exe

test : test.exe
	./test.exe

memory : test.exe
	drmemory -brief -- test.exe
