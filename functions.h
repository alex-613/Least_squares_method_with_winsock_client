#include <Eigen/Dense>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <WS2tcpip.h>

std::vector<std::string> mat2str(Eigen::MatrixXd Mat);
void initialization();
void termination(SOCKET out);