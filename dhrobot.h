#ifndef DHROBOT_H
#define DHROBOT_H

#include "dhjoint.h"

#include <memory>
#include <vector>

class DHRobot
{
public:
    DHRobot(std::vector<std::shared_ptr<DHJoint>> joints = {}) : m_joints(joints) {}

    void getInfo() const;

    void addJoint(std::shared_ptr<DHJoint> joint);

    std::shared_ptr<DHJoint> getJoint(const size_t indx) const;

    size_t getJointCount() const;

    ~DHRobot();

private:
    std::vector<std::shared_ptr<DHJoint>> m_joints;
};

#endif // DHROBOT_H
