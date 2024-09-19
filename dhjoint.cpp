#include "dhjoint.h"

void DHJoint::getInfo() const
{
    qDebug() << QString("Joint; %1: theta: %2 | a: %3 | d: %4 | alpha: %5")
                    .arg(m_sName)
                    .arg(m_dhParams.theta)
                    .arg(m_dhParams.a)
                    .arg(m_dhParams.d)
                    .arg(m_dhParams.alpha);
}

QString DHJoint::getName() const
{
    return this->m_sName;
}
