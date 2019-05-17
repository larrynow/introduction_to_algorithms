#ifndef ACTIVITYSELECTORTEST
#define ACTIVITYSELECTORTEST
#include"activity_selector.h"
#include<gtest/gtest.h>
using IntroductionToAlgorithms::GreedyAlgorithm::Activity;
using IntroductionToAlgorithms::GreedyAlgorithm::recursive_activity_select;
using IntroductionToAlgorithms::GreedyAlgorithm::greedy_activity_select;

TEST(activity_selector_test, test_11)
{
	typedef Activity<int> A;
	std::vector<A> activities;
	std::vector<std::size_t> indexs;

	activities = { A(0,0), A(1,4), A(3,5), A(0,6), A(5,7), A(3,9), A(5,9), A(6,10), A(8,11), A(8,12), A(2,14), A(12,16) };
	auto n = activities.size();

	recursive_activity_select(activities, indexs, 0, n);
	EXPECT_EQ(indexs.size(), 4);
	std::vector<std::size_t>().swap(indexs);//clear memory;
	greedy_activity_select(activities, indexs);
	EXPECT_EQ(indexs.size(), 4);
}
#endif // !ACTIVITYSELECTORTEST
