#include <QCoreApplication>

#include "nvm.h"
#include "rangemanager.h"
#include "onebitpropertydata.h"
#include "twobitpropertydata.h"
#include "properties/boolproperty.h"

#include <QDebug>

void oneBitPropTest(NvmRangeManager &manager, Nvm &nvm)
{
    OneBitPropertyData data(QString("Test property data"), manager.addNvmRange(Range(5)));
    qDebug() << "Property state: " << data.currentState();
    nvm.setBit(5, true);
    qDebug() << "Property state: " << data.currentState();
    qDebug(" ");
}

void twoBitPropTest(NvmRangeManager &manager, Nvm &nvm)
{
    TwoBitPropertyData data2(QString("Test property data"), manager.addNvmRange(Range(7,6)));
    qDebug() << "Property2 state: " << data2.currentState();
    nvm.setRange(Range(7,6), QVector<bool>() << true << true);
    qDebug() << "Property2 state: " << data2.currentState();
    qDebug(" ");
}

void boolPropTest(NvmRangeManager &manager, Nvm &nvm)
{
    OneBitPropertyData data1(QString("Test property data"), manager.addNvmRange(Range(8)));
    BoolProperty property("Big button", data1);
    qDebug() << property.name() << " is " << property.currentStateName();
    nvm.setBit(8, true);
    qDebug() << property.name() << " is " << property.currentStateName();
    qDebug(" ");
    //TODO: change nvm by through property
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)
    Nvm nvm(20);
    NvmRangeManager manager(nvm);

    oneBitPropTest(manager, nvm);
    twoBitPropTest(manager, nvm);
    boolPropTest(manager, nvm);

    return 0;
}
