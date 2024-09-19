#ifndef DHROBOT_H
#define DHROBOT_H

#include "abstractrobot.h"
#include "dhjoint.h".h"

#include <memory>
#include <vector>

class DHRobot : public AbstractRobot
{
public:
    DHRobot();

    void getInfo() const override;

    void addJoint(std::unique_ptr<AbstractJoint> joint) override;

    DHJoint* getJoint(const size_t indx) const override;

    size_t getJointCount() const override;

};

#endif // DHROBOT_H
