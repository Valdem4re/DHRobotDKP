#include "dhrobot.h"

#include <QDebug>

void DHRobot::getInfo() const
{
    qDebug() << "DHRobot info:";
    qDebug() << "Count of joints: " << this->getJointCount();
    for(int i = 0; i < this->getJointCount(); ++i) {
        qDebug() << this->getJoint(i)->getName();
    }

}

void DHRobot::addJoint(std::unique_ptr<AbstractJoint> joint)
{
    this->m_joints.push_back(std::move(joint));
}

DHJoint *DHRobot::getJoint(const size_t indx) const
{
    return dynamic_cast<DHJoint*>(m_joints[indx].get());
}

size_t DHRobot::getJointCount() const
{
    return this->m_joints.size();
}
