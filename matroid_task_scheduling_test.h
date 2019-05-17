#ifndef MATROIDTASKSCHEDULINGTEST
#define MATROIDTASKSCHEDULINGTEST
#include<gtest/gtest.h>
#include"matroid_task_scheduling.h"
using IntroductionToAlgorithms::GreedyProgramming::Task;
using IntroductionToAlgorithms::GreedyProgramming::get_task_scheduling;
TEST(matroid_task_scheduling_test, test_7)
{
	typedef Task<int, int> T;
	std::vector<T> tasks = {T(1, 4, 70), T(2, 2, 60), T(3, 4, 50), T(4, 3, 40), T(5, 1, 30), T(6, 4, 20), T(7, 6, 10)};
	std::vector<int> ans = { 2, 4, 1, 3, 7, 5, 6 };
	auto ids = get_task_scheduling(tasks);
	EXPECT_EQ(ids, ans);
}
#endif // !MATROIDTASKSCHEDULING
