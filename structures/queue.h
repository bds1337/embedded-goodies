#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_MAX 10

#include <stdlib.h>

typedef struct queue queue_t;

struct queue
{
    char buff[QUEUE_MAX];
    int head;
    int tail;
    int size;

    int (*is_full) (queue_t* q);
    int (*is_empty) (queue_t* q);
    int (*get_size) (queue_t* q);
    void (*put) (queue_t* q, char byte);
    int (*remove) (queue_t* q);
};

void queue_init(queue_t * q,
                int (*module_is_full) (queue_t* q),
                int (*module_is_empty) (queue_t* q),
                int (*module_get_size) (queue_t* q),
                void (*module_put) (queue_t* q, char byte),
                int (*module_remove) (queue_t* q)
                )
{
    if (q == NULL)
        return;
    q->head = 0;
    q->tail = 0;
    q->size = 0;

    q->is_empty = module_is_empty;
    q->is_full = module_is_full;
    q->get_size = module_get_size;
    q->put = module_put;
    q->remove = module_remove;
}

void queue_destroy(queue_t * q)
{
    if (q == NULL)
        return;
    free(q);
}

// methods
int queue_is_full(queue_t * q)
{
    return (q->head+1) % QUEUE_MAX == q->tail;
}

int queue_is_empty(queue_t * q)
{
    return (q->head == q->tail);
}

int queue_get_size(queue_t * q)
{
    return q->size;
}

void queue_put(queue_t * q, char byte)
{
    if (q->is_full(q))
        return;
    q->buff[q->head] = byte;
    q->head = (q->head+1) % QUEUE_MAX;
    q->size += 1;
}

int queue_remove(queue_t * q)
{
    int temp;
    if (q->is_empty(q))
        return 0;
    temp = q->buff[q->tail];
    q->tail = (q->tail+1) % QUEUE_MAX;
    q->size -= 1;
    return temp;
}

queue_t* queue_create(void)
{
    queue_t * q = malloc(sizeof(queue_t));
    if (q != NULL) 
        queue_init(q, queue_is_full, queue_is_empty,
                    queue_get_size, queue_put, queue_remove);
    return q;
}

#endif