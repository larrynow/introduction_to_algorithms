#ifndef BITONICTOURTEST
#define BITONICTOURTEST
#include"bitonic_tour.h"
#include<gtest/gtest.h>

using IntroductionToAlgorithms::DynamicProgramming::make_bitonic_tour;
using IntroductionToAlgorithms::DynamicProgramming::print_points_in_path;

TEST(bitonic_tour_tset, test_length)
{
	typedef std::pair<float, float> coord;
	std::vector<coord> points;
	points = { coord(0,6), coord(1,0), coord(2,3), coord(5, 4), coord(6, 1), coord(7, 5), coord(8,2) };
	std::vector<std::vector<int>> points_in_path;
	auto length = make_bitonic_tour(points, points_in_path);
	float ans = 25.584f;
	EXPECT_NEAR(length, ans, 0.001);
}
TEST(bitonic_tour_test, test_points)
{
	typedef std::pair<float, float> coord;
	std::vector<coord> points;
	points = { coord(0,6), coord(1,0), coord(2,3), coord(5, 4), coord(6, 1), coord(7, 5), coord(8,2) };
	std::vector<std::vector<int>> points_in_path;
	auto length = make_bitonic_tour(points, points_in_path);
	std::vector<int> points_index;
	std::vector<int> ans_v{ 5,3,2,0,1,4 };
	print_points_in_path(points_in_path, points_index, points.size() - 1, points.size() - 1);
	EXPECT_EQ(points_index, ans_v);
}
#endif // !BITONICTOURTEST
