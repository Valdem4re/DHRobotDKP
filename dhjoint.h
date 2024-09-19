#ifndef DHJOINT_H
#define DHJOINT_H

#include <QDebug>
#include <QString>

struct DHParams {
    double theta;
    double a;
    double d;
    double alpha;
};


class DHJoint
{

public:

    DHJoint(const QString& name = "",
            double theta = 0.f,
            double a = 0.f,
            double d = 0.f,
            double alpha = 0.f) :
        m_dhParams{theta, a, d, alpha}
        {   }

    void getInfo() const;

    QString getName() const;

    DHParams getDHParams() const {return m_dhParams;}

    void setName(QString name) {m_sName = name;}

    void setDHTheta(double theta) {m_dhParams.theta = theta;}

    void setDHa(double a) {m_dhParams.a = a;}

    void setDHd(double d) {m_dhParams.d = d;}

    void setDHAlpha(double alpha) {m_dhParams.alpha = alpha;}

    ~DHJoint() {};

private:
    QString m_sName;
    DHParams m_dhParams;
};

#endif // DHJOINT_H
