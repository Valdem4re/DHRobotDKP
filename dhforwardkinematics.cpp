#include "dhforwardkinematics.h"


Matrix DHForwardKinematics::computeEndEffectorPose() const
{
    Matrix endEffectorPose(4, std::vector<double>(4, 1));

    for(int i = 0; i < m_robot->getJointCount(); ++i) {
        std::shared_ptr<DHJoint> joint(m_robot->getJoint(i));
        DHParams params = joint->getDHParams();

        Matrix T = getTransformMatrix(params);

        endEffectorPose = matrixMul(endEffectorPose, T);
    }

    return endEffectorPose;
}

Matrix DHForwardKinematics::getTransformMatrix(const DHParams &params) const
{
    Matrix T(4, std::vector<double>(4, 0));

    T[0][0] = cos(params.theta);
    T[0][1] = -sin(params.theta) * cos(params.alpha);
    T[0][2] = sin(params.theta) * sin(params.alpha);
    T[0][3] = params.a * cos(params.theta);

    T[1][0] = sin(params.theta);
    T[1][1] = cos(params.theta) * cos(params.alpha);
    T[1][2] = -cos(params.theta) * sin(params.alpha);
    T[1][3] = params.a * sin(params.theta);

    T[2][1] = sin(params.alpha);
    T[2][2] = cos(params.alpha);
    T[2][3] = params.d;

    T[3][3] = 1;

    return T;
}

Matrix DHForwardKinematics::matrixMul(const Matrix &a, const Matrix &b) const
{
    size_t rowsA = a.size();
    size_t colsA = a[0].size();
    size_t rowsB = b.size();
    size_t colsB = b.size();

    Matrix res(rowsA, std::vector<double>(colsB, 0));

    for(size_t i = 0; i < rowsA; ++i) {
        for(size_t j = 0; j < colsB; ++j) {
            for(size_t k = 0; k < colsA; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}
