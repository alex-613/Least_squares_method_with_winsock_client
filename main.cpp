#include <iostream>
#include <WS2tcpip.h>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <stdio.h>
#include <vector>
#include <string>
#include "functions.h"

// Include the Winsock library (lib) file
#pragma comment (lib, "ws2_32.lib")


int main()
{


	/////////////////////////////////////////////////// Testing with random matrix

	Eigen::Matrix3d R1;
	R1 << 0.3, 0.5, 0.7,
		0.1, 0.9, 0.4,
		0.3, 0.6, 0.1;

	Eigen::Matrix3d R2;
	R2 << 0.8, 0.1, 0.2,
		0.1, 0.4, 0.3,
		0.5, 0.5, 0.2;

	std::cout << R1 << std::endl;
	std::cout << "\n" << R2 << std::endl;

	std::vector<std::string> strvect1 = mat2str(R1);
	std::vector<std::string> strvect2 = mat2str(R2);


	//Turn it into a single string
	std::string bufstr1= "";
	std::string bufstr2 = "";

	for (int i = 0; i < strvect1.size(); i++) {
		bufstr1.append(strvect1[i]);
		bufstr1.append(",");
		bufstr2.append(strvect2[i]);
		bufstr2.append(",");

	}

	//std::cout << bufstr1<< std::endl;
	//std::cout << bufstr2 << std::endl;
	
	char buf1[512];
	char buf2[512];
	int buflen = 512;
	memset(buf1, NULL, 512);
	memset(buf2, NULL, 512);

	for (int i = 0; i < 512;i++){
		buf1[i] = bufstr1[i];
		buf2[i] = bufstr2[i];
	}
	////////////////////////////////////////////////////////////
	// INITIALIZE WINSOCK
	////////////////////////////////////////////////////////////

	initialization();

	////////////////////////////////////////////////////////////
	// CONNECT TO THE SERVER
	////////////////////////////////////////////////////////////

	// Create a hint structure for the server

	sockaddr_in server;

	server.sin_family = AF_INET; // AF_INET = IPv4 addresses
	server.sin_port = htons(54000); // Little to big endian conversion
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr); // Convert from string to byte array

	// Socket creation, note that the socket type is datagram
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);

	// Send
		sendto(out, buf1, buflen + 1, 0, (sockaddr*)& server, sizeof(server));
		sendto(out, buf2, buflen + 1, 0, (sockaddr*)& server, sizeof(server));


		termination(out);
}