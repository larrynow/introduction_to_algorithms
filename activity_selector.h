/*
 * Program to realize Introduction to Algorithms.
 *
 * Capt.15 Greedy algorithm, Activity select.
 *
 * By LongFei Li, 2019-05-10.
 */
#ifndef ACTIVITYSELECTOR
#define ACTIVITYSELECTOR
#include<vector>

namespace IntroductionToAlgorithms
{
	namespace GreedyAlgorithm
	{
		/*!struct Activity*/
		template<class T> 
			struct Activity
			{
				T start;
				T finish;
				Activity<T>(T s, T f) : start(s), finish(f) {};
			};
		/*!recursive_activity_select: a recursive version activity selector to choose compatible activities
		 *\param activities: the activities list(starts from 1, ends at n, add another fake activity 0)
		 *\param indexs: the updated activity index set 
		 *\param begin: the begin 
		 *\param end: the end index
		 */
		template<typename T> void
			recursive_activity_select(std::vector<Activity<T>> &activities, std::vector<std::size_t> &indexs, 
				std::size_t begin, std::size_t end)
		{
			//choose first activity that is compatible with a[begin];
			auto m = begin + 1;
			while (m <= end && activities[m].start < activities[begin].finish)//find a activity begins after first activity ends;
				m++;
			if (m <= end)
			{
				indexs.push_back(m);
				recursive_activity_select(activities, indexs, m, end);
			}
			else
				return;
		}

		/*!greedy_activity_select: a iteratly activity selector
		 *\param activities: the input activities
		 *\param indexs: return indexs
		 */

		template<typename T> void
			greedy_activity_select(std::vector<Activity<T>> &activities, std::vector<std::size_t> &indexs)
		{
			std::size_t begin = 0;
			for (auto m = begin+1; m < activities.size(); m++)
			{
				if (activities[m].start < activities[begin].finish )//if not compatible; 
					continue;
				indexs.push_back(m);
				begin = m;
			}
		}
	}
}
#endif // !ACTIVITYSELECTOR

