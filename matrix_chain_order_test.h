#ifndef MATRIXCHAINORDERTEST
#define MATRIXCHAINORDERTEST
#include "matrix_chain_order.h"
#include<gtest/gtest.h>
#include<vector>
using IntroductionToAlgorithms::DynamicProgramming::maxtrix_chain_order;
using IntroductionToAlgorithms::DynamicProgramming::print_optimal_parens;

TEST(test_matrix_chain, test_all)
{
	std::vector<int> shapes{ 30, 35, 15, 5, 10, 20, 25 };
	std::vector<std::vector<int>> m;
	std::vector<std::vector<int>> s;
	maxtrix_chain_order(shapes.begin(), shapes.end(), m, s);
	auto ans = print_optimal_parens(s, 1, 6);
	EXPECT_EQ(ans, "((A1(A2A3))((A4A5)A6))");
}
#endif // !MATRIXCHAINORDERTEST
