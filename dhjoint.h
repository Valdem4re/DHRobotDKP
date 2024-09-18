#ifndef DHJOINT_H
#define DHJOINT_H

#include "abstractjoint.h"

#include <QDebug>

struct DHParams {
    double theta;
    double a;
    double d;
    double alpha;
};


class DHJoint : public AbstractJoint
{

public:

    DHJoint(const QString& name = "",
            double theta = 0.f,
            double a = 0.f,
            double d = 0.f,
            double alpha = 0.f) :
        AbstractJoint(name),
        m_dhParams{theta, a, d, alpha}
        {   }

    void getInfo() const override {
        qDebug() << QString("Joint; %1: theta: %2 | a: %3 | d: %4 | alpha: %5")
            .arg(m_sName)
            .arg(m_dhParams.theta)
            .arg(m_dhParams.a)
            .arg(m_dhParams.d)
            .arg(m_dhParams.alpha);
    }


private:
    DHParams m_dhParams;
};

#endif // DHJOINT_H
