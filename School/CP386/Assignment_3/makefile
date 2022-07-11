#Do not edit the contents of this file.
CC = gcc
CFLAGS = -Werror -Wall -g -std=gnu99
LDFLAGS = -lrt -lpthread
TARGET = Question2 Question3 
OBJFILES = Question2.o Question3.o 
all: $(TARGET)
Question2: Question2.c
	$(CC) $(CFLAGS) -o Question2 Question2.c $(LDFLAGS)
Question3: Question3.c
	$(CC) $(CFLAGS) -o Question3 Question3.c $(LDFLAGS)
runq2: Question2
	./Question2
runq3: Question3
	./Question3 sample3_in.txt
clean:
	rm -f $(OBJFILES) $(TARGET) *~ 
