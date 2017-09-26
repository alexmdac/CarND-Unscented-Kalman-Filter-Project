#include <iostream>
#include "tools.h"

using namespace std;
using Eigen::VectorXd;

VectorXd CalculateRMSE(
    const vector<VectorXd> &estimations,
    const vector<VectorXd> &ground_truth) {
  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;

  if (estimations.size() != ground_truth.size()
      || estimations.size() == 0) {
    cerr << "Invalid estimation or ground_truth data" << endl;
    return rmse;
  }

  for (int i = 0; i < estimations.size(); ++i) {
    VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array() * residual.array();
    rmse += residual;
  }

  rmse = rmse / estimations.size();
  rmse = rmse.array().sqrt();

  return rmse;
}
