#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

namespace bes {
    template <class T>
    class CircularBuff {
    private:
        unsigned int max_size;  
        unsigned int head;  
        unsigned int tail;  
        T *buffer;
    public:
        CircularBuff(unsigned int size)
        {
            max_size = size;
            buffer = new T[max_size]; 
        }
        ~CircularBuff()
        {
            delete[] buffer;
        }
        void put(T msg)
        {
            buffer[head] = msg;
        }
    };
};

#endif