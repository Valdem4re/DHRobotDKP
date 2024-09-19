#ifndef ABSTRACTROBOT_H
#define ABSTRACTROBOT_H

#include "abstractjoint.h"

#include <memory>
#include <vector>

class AbstractRobot
{
public:

    virtual ~AbstractRobot() = default;

    virtual void getInfo() const = 0;

    virtual void addJoint(std::unique_ptr<AbstractJoint> joint) = 0;

    virtual AbstractJoint* getJoint(const size_t indx) const = 0;

    virtual size_t getJointCount() const = 0;

protected:

    AbstractRobot(std::vector<std::unique_ptr<AbstractJoint>> joints) :
        m_joints(std::move(joints)) {}

    std::vector<std::unique_ptr<AbstractJoint>> m_joints;

};

#endif // ABSTRACTROBOT_H
