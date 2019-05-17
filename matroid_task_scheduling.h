/*
 * Program to realize Introduction to Algorithms.
 *
 * Capt.15 Greedy algorithm, Task scheduling.
 *
 * By LongFei Li, 2019-05-16.
 */
#ifndef MATROIDTASKSCHEDULING
#define MATROIDTASKSCHEDULING

#include<vector>
#include<queue>

namespace IntroductionToAlgorithms 
{
	namespace GreedyProgramming 
	{
		/*!struct Task*/
		template<typename Time, typename Weight>
			struct Task
			{
				int id;
				Time finish_time;
				Weight punishment;
				Task(int i, Time t, Weight w) :id(i), finish_time(t), punishment(w) {};
			};
		
		/*!get_task_scheduling: get task scheduling with matroid
		 *\param tasks: input task vector
		 *\return scheduling: output task scheduling id
		 */
		template<typename Time, typename Weight> std::vector<int>
			get_task_scheduling(const std::vector<Task<Time, Weight>> tasks)
		{
				typedef Task<Time, Weight> T;
				auto cmp = [](T t1, T t2) {return t1.finish_time >= t2.finish_time; };
				std::priority_queue<T, std::vector<T>, decltype(cmp)> pq(cmp);
				std::vector<int> refuse_ids;
				int finish = tasks.size();
				std::vector<int> independence(finish+1, 0);
				std::vector<int> ret_ids;
				for (auto t : tasks)
				{
					bool is_independent = true;
					auto temp_independence(independence);
					for (int i = 0; i <= finish; i++)
					{
						if (t.finish_time <= i) temp_independence[i]++;
						if (temp_independence[i] > i) is_independent = false;
					}
					if (is_independent)
					{
						pq.push(t);
						independence = temp_independence;
					}
					else refuse_ids.push_back(t.id);
				}
				while (!pq.empty())
				{
					auto p = pq.top();
					pq.pop();
					ret_ids.push_back(p.id);
				}
				ret_ids.insert(ret_ids.end(), refuse_ids.begin(), refuse_ids.end());

				return ret_ids;
		}
	}
}
#endif // !MATROIDTASKSCHEDULING

