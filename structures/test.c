#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "cachequeue.h"

int main() 
{
    int i,j;
    queue_t* myq;
    myq = queue_create();

    char h;
    for (i=0; i< QUEUE_MAX; i++)
    {
        h = myq->head;
        myq->put(myq, i);
        printf("put 0x%02x, size %u\n", i, myq->get_size(myq));
    }

    char t;
    for (i=0; i< QUEUE_MAX; i++)
    {
        t = myq->tail;
        myq->remove(myq);
        printf("remove 0x%02x, size %u\n", t, myq->get_size(myq));
    }

    cachequeue_t* mycq;
    mycq = cachequeue_create();

    return 0;
}
