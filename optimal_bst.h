/*
 * Program to realize Introduction to Algorithms.
 *
 * Capt.15 Dynamic Programming, Optimal BST.
 *
 * By LongFei Li, 2019-05-07.
 */
#ifndef OPTIMALBST
#define OPTIMALBST
#include<type_traits>
#include<vector>

namespace IntroductionToAlgorithms 
{
	namespace DynamicProgramming 
	{
		template<typename InIterator, typename ValueType> void
			construct_optimal_bst(const InIterator p_begin, const InIterator p_end,
				const InIterator q_begin, const InIterator q_end, std::size_t n,
				std::vector<std::vector<ValueType>> &e, std::vector<std::vector<ValueType>> &w,
				std::vector<std::vector<int>> &root)
		{
			typedef typename std::iterator_traits<InIterator>::value_type T;
			static_assert(std::is_same<T, ValueType>::value, "Value type should be same!");
			e = std::vector<std::vector<ValueType>>(n + 2, std::vector<ValueType>(n + 1, 0));//e[1...n+1][0...n], w[1...n, 0...n], root[1...n, 1...n];
			w = std::vector<std::vector<ValueType>>(n + 2, std::vector<ValueType>(n + 1, 0));
			root = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, 0));

			for (int i = 1; i <= n + 1; i++)//if j = i-1, means only have fake child at node i;
			{
				e[i][i - 1] = *(q_begin + i - 1);//probs of fake node is expect cost;
				w[i][i - 1] = *(q_begin + i - 1);
			}
			for (int l = 1; l <= n; l++)//l is length of sub-bst;
			{
				for (int i = 1; i <= n - l + 1; i++)
				{
					int j = i + l - 1;
					e[i][j] = INT_MAX;
					auto add_cost = (*(p_begin + j)) + (*(q_begin + j));//as a sub tree, cost adds as(pj+qj) cause depth +1;
					w[i][j] = w[i][j - 1] + add_cost;
					for (int r = i; r <= j; r++)
					{
						auto temp = e[i][r - 1] + e[r + 1][j] + w[i][j];
						if (temp < e[i][j])
						{
							e[i][j] = temp;
							root[i][j] = r;
						}
					}
				}
			}


		}
	}
}
#endif // !OPTIMALBAST

