CC := gcc

CFLAGS := -std=c99 -Wall -Werror -pedantic 

app.exe : funcs.o main.o
	$(CC) $^ -o $@
	
%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.exe
