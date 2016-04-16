#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"
#include <QSet>

class Observable
{
public:
    void addObserver(Observer *item);
    void removeObserver(Observer *item);
    virtual ~Observable() {}

protected:
    void notify() const;
private:
    QSet<Observer*> _observers;
};

#endif // OBSERVABLE_H
