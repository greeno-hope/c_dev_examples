typedef struct QUEUE queue_t;

queue_t *QUEUE_Create();

int QUEUE_Enqueue(queue_t *queue, void *data);

void *QUEUE_Dequeue(queue_t *queue);

int QUEUE_Size();

