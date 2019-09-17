#include <iostream>
#include <cmath>
#include "functions.h"
#include <WS2tcpip.h>
#include <stdio.h>
#include <vector>
#include <string>


std::vector<std::string> mat2str(Eigen::MatrixXd Mat) {
	std::vector<std::string> matvect;

	for (int i = 0; i < Mat.rows(); i++) {
		for (int j = 0; j < Mat.cols(); j++) {
			matvect.push_back(std::to_string(Mat(i, j)));
		}
	}
	

	return matvect;
}

void initialization() {
	WSADATA data;
	WORD version = MAKEWORD(2, 2);

	int wsOK = WSAStartup(version, &data);

	if (wsOK != 0) {
		//Error check
		std::cout << "Can't start Winsock!" << wsOK << std::endl;
		return;
	}

}

void termination(SOCKET out){

	closesocket(out);
	WSACleanup();
}
