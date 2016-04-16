#include "observable.h"

void Observable::addObserver(Observer *item)
{
//        qDebug(Q_FUNC_INFO);
    _observers.insert(item);
}

void Observable::removeObserver(Observer *item)
{
//        qDebug(Q_FUNC_INFO);
    _observers.remove(item);
}

void Observable::notify() const
{
    foreach(Observer *observer, _observers)
        observer->update();
}
