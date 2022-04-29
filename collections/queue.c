#include <stdio.h>
#include <stdlib.h>

/**
 * Hidden struct for a node in the queue
 */
typedef struct QNODE {
	struct QNODE *next;
	struct QNODE *prev;
	void *data;
} qnode_t;

/**
 * Hidden struct for a queue
 */
typedef struct QUEUE {
	qnode_t *head;
	qnode_t *tail;
} queue_t;

/**
 * c'tor for a queue
 * @return
 */
queue_t *QUEUE_Create() {
	queue_t *ret = malloc(sizeof(queue_t));
	ret->head = NULL;
	ret->tail = NULL;
	return ret;
}

/**
 *
 * @return
 */
qnode_t *make_node() {
	qnode_t *node =  malloc(sizeof(qnode_t));
	node->next = NULL;
	node->prev = NULL;
	node->data = NULL;
	return node;
}

/**
 *
 * @param queue
 * @param data
 * @return
 */
int QUEUE_Enqueue(queue_t *queue, void *data) {

	qnode_t *node = make_node();
	node->data = data;

	if(queue->head == NULL) {
		queue->head = queue->tail = node;
	} else {
		node->next = queue->head;
		queue->head->prev = node;
		queue->head = node;
	}
	return 0;
}

void *Queue_Dequeue() {
	void *ret = NULL;




	return ret;
}

int QUEUE_Size() {
    return 0;
}