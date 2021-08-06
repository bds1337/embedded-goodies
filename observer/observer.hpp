#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <stdio.h>
#include <string.h>
#include <list>
//TODO: Cpp example

namespace bes
{
typedef unsigned int size_t;

class IObserver
{
public:
    virtual ~IObserver()
    {}
    virtual void update(const char *str) = 0;
};

class ISubject
{
public:
    virtual ~ISubject()
    {}
    virtual void attach(IObserver *observer) = 0;
    virtual void detach(IObserver *observer) = 0;
    virtual void notify() = 0;
};

class Subject: public ISubject
{
private:
    std::list<IObserver*> observers; 
    //IObserver **observers;
    //IObserver *observers[10];
    int array_size;
    char *message;
public:
    virtual ~Subject() {
        printf("Subject is dead\n");
    }

    virtual void attach(IObserver *observer) override {
        //observers[array_size] = observer;
        observers.push_back(observer);
    }

    virtual void detach(IObserver *observer) override {
        observers.remove(observer);
    }

    virtual void notify() override {
    }

    void create_message(char* str)
    {
        message = (char*)malloc(sizeof(char) * strlen(str) + 1);
        strcpy(message, str);
        printf("created message: %s\n", message);
    }

};
}

#endif
