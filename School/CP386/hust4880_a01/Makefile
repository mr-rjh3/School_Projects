# Do not edit the contents of this file.
all: z_creator z_terminator warnings_OK assignment_average

warnings_BAD: process_management.c
	gcc -Werror -Wall -g -std=gnu99 -o process_management process_management.c -lrt

warnings_OK: process_management.c
	gcc -Wall -g -std=gnu99 -o process_management process_management.c -lrt

z_creator: z_creator.c
	gcc -Wall -g -std=gnu99  -o z_creator z_creator.c

z_terminator: z_terminator.c
	gcc -Wall -g -std=gnu99  -o z_terminator z_terminator.c

assignment_average: assignment_average.c
	gcc -Wall -g -std=gnu99  -o assignment_average  assignment_average.c
	
runq1: z_creator z_terminator
	./z_terminator

runq2: assignment_average
	./assignment_average sample_in_grades.txt
	
runq3: warnings_OK
	./process_management sample_in_process.txt | cat output.txt

clean: *.c
	rm -f assignment_average process_management z_creator z_terminator 