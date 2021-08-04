#ifndef OBSERVER_H
#define OBSERVER_H

typedef unsigned int size_t;

namespace bes {
    class IObserver {
        virtual void notify() = 0;
    };

    class ISubject {
        virtual void accept() = 0;
    };

    //template <typename T, const size_t MAX_OBSERVERS>
    //Client 
    class Observer: public IObserver {
    public:
        virtual void notify();
    };

    class Subject: public ISubject {
    private:
        size_t max_observers;
        size_t observers[3];
    public:
        virtual void accept(IObserver& obs);
        void notify_observers();
    };
};

#endif
