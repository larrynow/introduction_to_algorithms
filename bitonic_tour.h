/*
 * Program to realize Introduction to Algorithms.
 *
 * Capt.15 Dynamic Programming, Bitonic Euclidean traveling.
 *
 * By LongFei Li, 2019-05-08.
 */
#ifndef BITONICTOUR
#define BITONICTOUR
#include<vector>
#include<deque>

namespace IntroductionToAlgorithms
{
	namespace DynamicProgramming
	{
		/*!make_bitonic_tour: get a shortest path in the bitonic condition
		 *\param pionts: the input point coordinates (std::pair)
		 *\param points_in_path: record the point connect with right point 
		 *\return total path length
		 */
		template<typename ValueType> ValueType
			make_bitonic_tour(const std::vector<std::pair<ValueType, ValueType>> points,
				std::vector<std::vector<int>> &points_in_path)
		{
				typedef std::pair<ValueType, ValueType> Coord;
				std::size_t N = points.size();
				std::vector<std::vector<ValueType>> path(N, std::vector<ValueType>(N, INT_MAX));
				points_in_path = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
				auto dist = [points](Coord x, Coord y) {return sqrt(((y.first - x.first)*(y.first - x.first))
					+ ((y.second - x.second)*(y.second - x.second))); };
				//let i always bigger than j;
				path[1][0] = dist(points[0], points[1]);
				points_in_path[1][0] = 0;
				for (int i = 2; i < N; i++)//the second point, from 2 to N-1;
				{
					for (int j = 0; j < i - 1; j++)
					{
						//if j<i-1, i can only connect with i-1;(or i-1 can't in both 0--i, and 0--j);
						path[i][j] = path[i - 1][j] + dist(points[i], points[i-1]);
						points_in_path[i][j] = i - 1;
					}
					//for j=i-1;
					auto temp_point = 0;
					for (int k = 0; k <= i - 2; k++)
					{
						if ((path[i-1][k] + dist(points[k], points[i])) < path[i][i - 1])
						{
							path[i][i - 1] = path[i-1][k] + dist(points[k], points[i]);
							temp_point = k;
						}
					}
					points_in_path[i][i - 1] = temp_point;
				}
				path[N - 1][N - 1] = path[N - 1][N - 2] + dist(points[N - 1], points[N - 2]);//for last point;
				points_in_path[N - 1][N - 1] = (int)N-2;

				return path[N - 1][N - 1];
		}

		void print_points_in_path(const std::vector<std::vector<int>> &points_in_path,
			std::vector<int> &points,
			const int i, const int j)
		{
			if (i >= j)//if i is on right of j, collect i's direct connection first;
			{
				if (i == 1 && j == 0)
					return;
				points.push_back(points_in_path[i][j]);
				print_points_in_path(points_in_path, points, points_in_path[i][j], j);
			}
			else//if i is on left of j, collect j's direct connection after recurision over;
			{
				if (i == 0 && j == 1)
					return;
				print_points_in_path(points_in_path, points, i, points_in_path[j][i]);
				points.push_back(points_in_path[j][i]);
			}
		}
	}
}
#endif // !BITONICTOUR
