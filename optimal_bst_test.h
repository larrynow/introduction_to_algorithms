#ifndef OPTIMALBSTTEST
#define OPTIMALBSTTEST
#include"optimal_bst.h"
#include<gtest/gtest.h>

using IntroductionToAlgorithms::DynamicProgramming::construct_optimal_bst;

TEST(test_optimal_bst, test_1_5)
{
	std::vector<double> p{ 0, 0.15, 0.10, 0.05, 0.10, 0.20 };
	std::vector<double> q{ 0.05, 0.10, 0.05, 0.05, 0.05, 0.10 };
	std::size_t siz = 5;

	std::vector<std::vector<double>> e;
	std::vector<std::vector<double>> w;
	std::vector<std::vector<int>> root;
	
	construct_optimal_bst(p.begin(), p.end(), q.begin(), q.end(), siz, e, w, root);

	EXPECT_EQ(root[1][5], 2);
	EXPECT_EQ(root[2][5], 4);
}
#endif // !OPTIMALBSTTEST

