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

    void getInfo() const override;

    QString getName() const override;

    DHParams getDHParams() const {return m_dhParams;}

private:
    DHParams m_dhParams;
};

#endif // DHJOINT_H
