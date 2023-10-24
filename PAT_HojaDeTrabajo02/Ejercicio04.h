
#ifndef EJERCICIO04_H
#define EJERCICIO04_H

#include <list>

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue();

    void pushFront(int value);

    void pushMiddle(int value);

    void pushBack(int value);

    int popFront();

    int popMiddle();
    int popBack();

private:
    std::list<int> data;
};

#endif