#ifndef PROPERTY_H
#define PROPERTY_H

#include "observer.h"
#include <QString>

class Property : public Observer
{
public:
    Property(const QString &name);
    QString name() const;
    void setName(const QString &name);

private:
    QString _name;
};

#endif // PROPERTY_H
