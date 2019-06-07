#include <iostream>
#include <eigen3/Eigen/Eigen>

int main()
{
	Eigen::MatrixXd m(2,5);
	std::cout << m << std::endl;
	m(1,1)=3;
	m.resize(20,20);
	std::cout << m << std::endl;
}
