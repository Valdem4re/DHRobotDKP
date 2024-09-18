#include "abstractrobot.h"

void AbstractRobot::addJoint(std::unique_ptr<AbstractJoint> joint)
{
    m_joints.push_back(std::move(joint));
}
