#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct passenger {
	char passenger_name[20];
	char pClass[10];
	char pNo[10];
} passenger_a;

typedef struct queue_node {
	passenger_a pas;
	struct queue_node *restp;
} queue_node_t;

typedef struct {
	queue_node_t *frontp, *rearp;
	int size;
} queue_t;

// Create the following functions:
void scan_passenger(passenger_a *passp);
void print_passenger(passenger_a pass);
void add_to_q(queue_t *qp, passenger_a ele);
passenger_a remove_from_q(queue_t *qp);
void display_q(queue_t q);

int main(void) {

	// passenger queue - initialized to empty state
	queue_t pass_q = { NULL, NULL, 0 };
	passenger_a next_pass, fst_pass;

	char choice;

	// Processes requests
	do {
		printf("Enter A(dd), R(emove), D(isplay), or Q(uit)> ");
		scanf(" %c", &choice);

		switch (toupper(choice)) {
		case 'A':
			printf("Enter passenger data> ");
			scan_passenger(&next_pass);
			add_to_q(&pass_q, next_pass);
			break;

		case 'R':
			if (pass_q.size > 0) {
				fst_pass = remove_from_q(&pass_q);
				printf("Passenger removed from queue: \n");
				print_passenger(fst_pass);
			} else {
				printf("Queue empty - no one to delete\n");
			}
			break;

		case 'D':
			if (pass_q.size > 0)
				display_q(pass_q);
			else
				printf("Queue is empty\n");
			break;

		case 'Q':
			printf("Leaving passenger queue program with %d \n", pass_q.size);
			printf("passengers in the queue\n");
			break;

		default:
			printf("Invalid choice -- try again\n");
		}
	} while (toupper(choice) != 'Q');

	return 0;
}

void add_to_q(queue_t *qp, passenger_a ele) {

	queue_node_t *new_pas;
	new_pas = (queue_node_t*) malloc(sizeof(queue_node_t));
	new_pas->pas = ele;
	new_pas->restp = NULL;

	if (qp->size <= 0) {
		qp->frontp = new_pas;
		qp->rearp = new_pas;
	} else {
		qp->rearp->restp = new_pas;
		qp->rearp = new_pas;
	}

	qp->size++;
}

// Removes and frees first node of queue, returning value stored there.
// Pre-condition: queue is not empty
passenger_a remove_from_q(queue_t *qp) {

	//initial queue value which is to be returned
	passenger_a ans;

	ans = qp->frontp->pas;
	queue_node_t *temp = qp->frontp;
	qp->frontp = qp->frontp->restp;
	free(temp);
	qp->size--;
	if (qp->size <= 0) {
		qp->rearp = NULL;
	}

	return ans;
}

// display all passengers info. in the queue
void display_q(queue_t q) {

	queue_node_t *current = q.frontp;
	int i = 1;
	printf("-----------------------------------------\n");
	while (current != NULL) {
		printf("PASSENGER %d", i);
		printf("\n");
		printf("-----------------------------------------\n");
		printf("  Name: %s", current->pas.passenger_name);
		printf("\n");
		printf(" Class: %s", current->pas.pClass);
		printf("\n");
		printf("Number: %s", current->pas.pNo);
		printf("\n");
		printf("-----------------------------------------\n");
		current = current->restp;
		i++;
	}
}

// load passenger data
void scan_passenger(passenger_a *passp) {
	printf("\n");
	printf("\tPassenger Name: ");
	scanf("%s", passp->passenger_name);

	printf("\tPassenger Class: ");
	scanf("%s", passp->pClass);

	printf("\tPassenger Number: ");
	scanf("%s", passp->pNo);
	printf("\n");
}

// print the info. of the removed passenger from the queue
void print_passenger(passenger_a pass) {
	printf("-----------------------------------------\n");
	printf("Passenger Name: %s", pass.passenger_name);
	printf("\n");
	printf("Passenger Class: %s", pass.pClass);
	printf("\n");
	printf("Passenger Number: %s", pass.pNo);
	printf("\n");
	printf("-----------------------------------------\n");

}
