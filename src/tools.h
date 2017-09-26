#ifndef TOOLS_H_
#define TOOLS_H_
#include <vector>
#include "Eigen/Dense"

// Returns the root mean squared error of the vectors in estimations, computed
// by comparing them with the vectors in ground_truth.
Eigen::VectorXd CalculateRMSE(
    const std::vector<Eigen::VectorXd> &estimations,
    const std::vector<Eigen::VectorXd> &ground_truth);

#endif /* TOOLS_H_ */
