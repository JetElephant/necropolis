#include "property.h"

Property::Property(const QString &name)
    : _name(name)
{

}

QString Property::name() const
{
    return _name;
}

void Property::setName(const QString &name)
{
    _name = name;
}
