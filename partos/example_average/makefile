CFLAGS := -std=c99 -Wall -Werror -c
ifeq ($(mode), debug)
	CFLAGS += -g3
endif
ifeq ($(mode), release)
	CFLAGS += -g0
endif

%.o : %.c
	gcc $(CFLAGS) $^

app.exe : main.o io.o list.o
	gcc $^ -o $@

run : app.exe
	./app.exe

clean :
	rm *.o *.exe
