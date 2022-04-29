#include <stdio.h>
#include <stdlib.h>

#include "./queue.h"

typedef struct DATA {
	int data1;
	int data2;
} data_t;

int main(int argc, char *argv[]) {

	queue_t *queue = QUEUE_Create();

	data_t *d1 = malloc(sizeof(data_t));
	d1->data1 = 22;
	d1->data2 = 33;
	QUEUE_Enqueue(queue, d1);

	data_t *d2 = malloc(sizeof(data_t));
	d2->data1 = 44;
	d2->data2 = 11;
	QUEUE_Enqueue(queue, d2);

	return 0;
}