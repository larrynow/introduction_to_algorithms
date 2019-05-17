/*
 * Program to realize Introduction to Algorithms.
 *
 * Capt.15 Dynamic Programming, Matrix chain order.
 *
 * By LongFei Li, 2019-05-05.
 */
#ifndef MATRIXCHAINORDER
#define MATRIXCHAINORDER
#include<vector>
#include<string>
#include<type_traits>

namespace IntroductionToAlgorithms
{
	namespace DynamicProgramming
	{
		//! matrix chain order: get the best solutions;
		/*!
		 *\param p_begin: begin iter of matrix size input;
		 *\param p_end: end iter of matrix size input;
		 *\param m: multiplication cost of two maxtrixs;
		 *\param s: spilt point to get min cost in matrixs Ai...j;
		 */
		template<typename InIterator> void
			maxtrix_chain_order(const InIterator p_begin, const InIterator p_end,
				std::vector<std::vector<int>> &m, std::vector<std::vector<int>> &s)
		{
			typedef typename std::iterator_traits<InIterator>::value_type T;
			auto N = std::distance(p_begin, p_end)-1;//the num of p is n+1 for A[n] has a shape pn-1 * pn;

			m = std::vector<std::vector<int>>(N+1, std::vector<int>(N+1, 0));//add m[0][0];
			s = std::vector<std::vector<int>>(m);
			auto p = [p_begin](typename std::iterator_traits<InIterator>::difference_type index) {return *(p_begin + index); };
			for (int l = 2; l <= N; l++)//l is chain length of matixs:A1...N=>A1...l * Al+1...A2l...* AN-l+1...AN;
			{
				for (int i = 1; i <= N - l + 1; i++)//i is start point of each chain;
				{
					int j = i + l - 1;//j is end point of each chain;
					m[i][j] = INT_MAX;//initialize as max;
					for (int k = i; k <= j-1; k++)//find a best split point among i,j => Ai...k, Ak+1...j;
					{
						auto cost = p(i - 1)*p(k)*p(j);//shape of Ai is pi-1 * pi;
						auto q = m[i][k] + m[k + 1][j] + cost;
						if (q < m[i][j])
						{
							m[i][j] = q;
							s[i][j] = k;
						}
					}
				}
			}

		}

		std::string 
			print_optimal_parens(const std::vector<std::vector<int>> &s,
				const int i, const int j)
		{
			std::string ret;
			if (i == j) ret = "A" + std::to_string(i);
			else
				ret = "(" + print_optimal_parens(s, i, s[i][j]) + print_optimal_parens(s, s[i][j] + 1, j) + ")";
			return ret;
		}

	}
}

#endif // !MATRIXCHAINORDER
