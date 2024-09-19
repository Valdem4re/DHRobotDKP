#ifndef DHFORWARDKINEMATICS_H
#define DHFORWARDKINEMATICS_H

#include "dhrobot.h"
#include "dhjoint.h"

#include <cmath>
#include <vector>

using Matrix = std::vector<std::vector<double>>;

class DHForwardKinematics
{
public:
    DHForwardKinematics(const DHRobot& robot) : m_robot(&robot) {};

    Matrix computeEndEffectorPose() const;

    Matrix getTransformMatrix(const DHParams& params) const;

    Matrix matrixMul(const Matrix& a, const Matrix& b) const;

private:

    const DHRobot* m_robot;
};

#endif // DHFORWARDKINEMATICS_H
