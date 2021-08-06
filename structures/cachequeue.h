#ifndef CACHEQUEUE_H
#define CACHEQUEUE_H

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cachequeue_s cachequeue_t;

struct cachequeue_s
{
    // базовый класс
    queue_t* queue;
    // новые аттрибуты
    char filename[70];
    int elements_on_disk;
    // ??? агрегация в подкласс ???
    queue_t* output_queue;
    // унаследованые виртуальные функции
    int (*is_full)  (cachequeue_t* cq);
    int (*is_empty) (cachequeue_t* cq);
    int (*get_size) (cachequeue_t* cq);
    void (*put)     (cachequeue_t* cq, char byte);
    int (*remove)   (cachequeue_t* cq);
    // новые виртуальные функции
    void (*flush)   (cachequeue_t* cq);
    void (*load)    (cachequeue_t* cq);
};

// Констуктор и деструктор
void cachequeue_init(cachequeue_t* cq
                    , char* file
                    , int (*module_is_full)     (cachequeue_t* cq)
                    , int (*module_is_empty)    (cachequeue_t* cq)
                    , int (*module_get_size)    (cachequeue_t* cq)
                    , void (*module_put)        (cachequeue_t* cq, char byte)
                    , int (*module_remove)      (cachequeue_t* cq)
                    , void (*module_flush)      (cachequeue_t* cq)
                    , void (*module_load)       (cachequeue_t* cq)
                    )
{
    // Инициализация базового класса
    cq->queue = queue_create();
    cq->elements_on_disk = 0;
    strcpy(cq->filename, file);

    // ?? initialize aggregates
    cq->output_queue = queue_create();

    // инициализация виртуальных операции подкласса
    cq->is_full = module_is_full;
    cq->is_empty = module_is_empty;
    cq->get_size = module_get_size;
    cq->put = module_put;
    cq->remove = module_remove;

    cq->flush = module_flush;
    cq->load = module_load;
}

void cachequeue_cleanup(cachequeue_t* cq)
{
    queue_cleanup(cq->queue);
}

// методы
int cachequeue_is_full(cachequeue_t* cq)
{
    return (cq->queue->is_full(cq->queue) &&
            cq->output_queue->is_full(cq->output_queue));
}

int cachequeue_get_size(cachequeue_t* cq)
{
    return (  cq->queue->get_size(cq->queue)
            + cq->output_queue->get_size(cq->output_queue)
            + cq->elements_on_disk
           );
}

int cachequeue_is_empty(cachequeue_t* cq)
{
    return 0;
}

void cachequeue_put(cachequeue_t* cq, char byte)
{
}

int cachequeue_remove(cachequeue_t* cq)
{
    return 0;
}

void cachequeue_flush(cachequeue_t* cq)
{
}

void cachequeue_load(cachequeue_t* cq)
{
}

cachequeue_t* cachequeue_create(void)
{
    cachequeue_t* cq = (cachequeue_t*)malloc(sizeof(cachequeue_t));
    if (cq != NULL)
    {
        cachequeue_init(cq, "file.txt" 
                        , cachequeue_is_full
                        , cachequeue_is_empty
                        , cachequeue_get_size
                        , cachequeue_put
                        , cachequeue_remove
                        , cachequeue_flush
                        , cachequeue_load
                        );
    }
    return cq;
}

void cachequeue_destroy(cachequeue_t* cq)
{
    if (cq != NULL)
        cachequeue_cleanup(cq);
    free(cq);
}

#endif