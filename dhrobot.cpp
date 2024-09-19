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

void DHRobot::addJoint(std::shared_ptr<DHJoint>joint)
{
    m_joints.push_back(joint);
}

std::shared_ptr<DHJoint> DHRobot::getJoint(const size_t indx) const
{
    if (indx >= 0 && indx < m_joints.size()) {
        return m_joints[indx];
    }
    return nullptr;
}

size_t DHRobot::getJointCount() const
{
    return this->m_joints.size();
}

DHRobot::~DHRobot()
{

}
