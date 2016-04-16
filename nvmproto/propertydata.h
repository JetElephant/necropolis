#ifndef PROPERTYDATA_H
#define PROPERTYDATA_H

#include "observer.h"
#include "rangemanager.h"
#include <QString>

class PropertyData : public Observer, public Observable
{
public:
    PropertyData(const QString &name, NvmRange &range);
    ~PropertyData();

protected:
    NvmRange &_rangeCtrl;
    QString _name;

    uint processNvmData(const QVector<bool> data) const;
};

#endif // PROPERTYDATA_H
