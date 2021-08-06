/*
 *
 */

#ifndef OBSERVER_H
#define OBSERVER_H

// TODO: c version

typedef struct observer_s observer_t;

struct observer_s
{
    void (*_notify) (observer_s* );

};


#endif