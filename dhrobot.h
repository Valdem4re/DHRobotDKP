#ifndef DHROBOT_H
#define DHROBOT_H

#include "abstractrobot.h"
#include "abstractjoint.h"

#include <memory>
#include <vector>

class DHRobot : public AbstractRobot
{
public:
    DHRobot();

    void getInfo() const override;

};

#endif // DHROBOT_H
