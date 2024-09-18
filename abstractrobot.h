#ifndef ABSTRACTROBOT_H
#define ABSTRACTROBOT_H

#include "abstractjoint.h"

#include <memory>
#include <vector>

class AbstractRobot
{
public:

    AbstractRobot(std::vector<std::unique_ptr<AbstractJoint>> joints) :
        m_joints(std::move(joints)) {}

    virtual ~AbstractRobot() = default;

    virtual void getInfo() const = 0;

    void addJoint(std::unique_ptr<AbstractJoint> joint);

    size_t getJointCount() const {return m_joints.size();}

private:

    std::vector<std::unique_ptr<AbstractJoint>> m_joints;

};

#endif // ABSTRACTROBOT_H
