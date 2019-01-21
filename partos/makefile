CC := gcc
MODE := release
FLAGS := -std=c99 -Werror -Wall -pedantic -c

ifeq ($(MODE), release)
	FLAGS += -g0
endif

main.o: main.c
	$(CC) $(FLAGS) $< 

func.o: func.c
	$(CC) $(FLAGS) $<

app.exe: main.o func.o
	$(CC) -o $@ $^

test.o: test.c
	$(CC) $(FLAGS) $<

test.exe : func.o test.o
	$(CC) func.o test.o -o test.exe

timer.o : timer.c
	$(CC) $(FLAGS) $<

timer.exe : func.o timer.o
	$(CC) func.o timer.o -o timer.exe

clean:
	rm *.o *.exe

