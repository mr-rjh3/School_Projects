# Do not edit the contents of this file.
CC = gcc
CFLAGS = -Werror -Wall -g -std=gnu99
LDFLAGS = -lrt -lpthread
TARGET = Question1 Question2 Question3
OBJFILES = Question1.o Question2.o Question3.o
all: $(TARGET)
Question1: threads.c
	$(CC) $(CFLAGS) -o Question1 threads.c $(LDFLAGS)
Question2: sudoku.c
	$(CC) $(CFLAGS) -o Question2 sudoku.c $(LDFLAGS)
Question3: thread_timing.c
	$(CC) $(CFLAGS) -o Question3 thread_timing.c $(LDFLAGS)

runq1: Question1
	./Question1
runq2: Question2
	./Question2 sample1_in.txt
runq3: Question3
	./Question3 sample2_in.txt
clean:
	rm -rf $(OBJFILES) $(TARGET) *~ 
	rm -rf *.exe
	rm -rf *.out