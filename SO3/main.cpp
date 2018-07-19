#include "SO3.h"
#include <iostream>
#include <cmath>

#define CTHETA 1/sqrt(2)
#define STHETA 1/sqrt(2)


int main(int argc, char* argv[])
{
	RGD::SO3<double> R1({{CTHETA,-STHETA,0},{STHETA,CTHETA,0},{0,0,1}});
	RGD::SO3<double> R2({{1,0,0},{0,1,0},{0,0,1}});
	RGD::SO3<double> R3({{0,0,0},{0,0,0},{0,0,0}});
	RGD::SO3<double> R4({{0,0,0},{0,0,0},{0,0,0}});

	R3 = R2*R1;
	R4 = R1/R3;

	std::cout << R1(2,2) << R1(1,1) << R1(0,0) << std::endl;
	std::cout << R3(2,2) << R3(1,1) << R3(0,0) << std::endl;
	std::cout << R4(2,2) << R4(1,1) << R4(0,0) << std::endl;

	return 0;
}
