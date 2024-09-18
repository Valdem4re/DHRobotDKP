#ifndef ABSTRACTJOINT_H
#define ABSTRACTJOINT_H

#include <QString>

class AbstractJoint
{
public:

    AbstractJoint(QString name) : m_sName(name) {}
    virtual ~AbstractJoint() = default;

    virtual void getInfo() const = 0;

protected:
    QString m_sName;
};

#endif // ABSTRACTJOINT_H
