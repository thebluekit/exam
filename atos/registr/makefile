FILE_LIST := funcs.o main.o
HEADER:= funcs.h
CC:= gcc
RM:= rm -rf
CFLAGS:= -std=c99 -Wall -Werror 

main.o: main.c 
	$(CC) $(CFLAGS) -c $<
	
funcs.o: funcs.c $(HEADER)
	$(CC) $(CFLAGS) -c $<
	
app.exe: $(FILE_LIST)
	$(CC) -o app.exe $^
		
clean: 
	$(RM) *.o *.exe 

