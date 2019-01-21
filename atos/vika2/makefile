CFLAGS := -std=c99 -Wall -Werror -c

ifeq ($(mode), debug)
	CFLAGS += -g3
endif
ifeq ($(mode), release)
	CFLAGS += -g0
endif

main.o : main.c
	gcc $(CFLAGS) main.c

list.o : list.c
	gcc $(CFLAGS) $^

input.o : input.c
	gcc $(CFLAGS) $^

output.o : output.c
	gcc $(CFLAGS) $^

app.exe : main.o list.o input.o output.o
	gcc $^ -o $@

clean :
	rm *.o *.exe

memory : app.exe
	drmemory -brief -- app.exe in_1.txt out_1.txt
