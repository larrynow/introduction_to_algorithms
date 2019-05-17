#ifndef BOTTOMUPRODCUTTINGTEST
#define BOTTOMUPRODCUTTINGTEST
#include"bottom_up_rod_cutting.h"
#include<gtest/gtest.h>
#include<vector>
using IntroductionToAlgorithms::DynamicProgramming::bottom_up_cut_rod;

TEST(test_cut_rod, test_r)
{
	std::vector<int> price{ 0,1,5,8,9,10,17,17,20,24,30 };//to maintain index to be same in price and r, s add 0 to be price[0];
	std::vector<int> r;
	std::vector<int> s;
	bottom_up_cut_rod(price.begin(), price.end(), 10, r, s);
	EXPECT_EQ(r[10], 30);
}
TEST(test_cut_rod, test_s)
{
	std::vector<int> price{ 0,1,5,8,9,10,17,17,20,24,30 };
	std::vector<int> r;
	std::vector<int> s;
	bottom_up_cut_rod(price.begin(), price.end(), 10, r, s);
	EXPECT_EQ(s[7], 1);
}
#endif // !1


