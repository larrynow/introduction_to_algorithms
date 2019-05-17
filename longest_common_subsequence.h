/*
 * Program to realize Introduction to Algorithms.
 * 
 * Capt.15 Dynamic Programming, Longest common subsequence.
 *
 * By LongFei Li, 2019-04-29.
 */
#ifndef LONGESTCOMMONSUBSEQUENCE
#define LONGESTCOMMONSUBSEQUENCE
#include<type_traits>
#include<vector>

namespace IntroductionToAlgorithms 
{
	namespace DynamicProgramming 
	{
		//! make_LCS: Use matrix c(record length of LCS) to get LCS from X;
		/*!
		 *\param begin: begin iter of X
		 *\param end: end iter of X
		 *\param b: mark matrix to indicate recursion
		 *\param seq1_index: current index i from Xi
		 *\param seq2_index: current index j from Yj
		 *\param out_begin: begin iter of LCS
		 *\return length of LCS
		 */
		template<typename InIterator, typename OutIterator> std::size_t
			make_LCS(const InIterator begin, const InIterator end,
				const std::vector<std::vector<int>>& b, typename std::iterator_traits<InIterator>::difference_type seq1_index,
				typename std::iterator_traits<InIterator>::difference_type seq2_index,
				OutIterator& out_begin)
		{
			typedef typename std::iterator_traits<InIterator>::value_type T;
			typedef typename std::iterator_traits<OutIterator>::value_type Out_T;
			static_assert(std::is_same<T, Out_T>::value, "The value type in input and output should be same!");

			std::size_t len = 0;
			if (seq1_index < 0 || seq2_index < 0) return len;
			
			if (b[seq1_index][seq2_index] == 11)//cond.1:Xi = Yj is in LCS;
			{
				len += (make_LCS(begin, end, b, seq1_index - 1, seq2_index - 1, out_begin) + 1);//c[i][j]->c[i-1][j-1];Xi==Yj;=>LCS(Xi-1, Yj-1)
				*out_begin = *(begin + seq1_index);//add Xi to LCS;
				out_begin++;
				return len;
			}
			else if (b[seq1_index][seq2_index] == 10)//cond.2: LCS(Xi)==LCS(Xi-1)
			{
				len += make_LCS(begin, end, b, seq1_index - 1, seq2_index, out_begin);//c[i][j]->c[i-1][j];=>LCS(Xi-1, Yj)
				return len;
			}
			else//cond.3: LCS(Yj)==LCS(Yj-1)
			{
				len += make_LCS(begin, end, b, seq1_index, seq2_index-1, out_begin);//c[i][j]->c[i][j-1];LCS of Yj-1 == LCS of Yj;=>LCS(Xi, Yj-1)
				return len;
			}
		}

		//! longest_common_sequence: get the longest common sequence of X and Y;
		/*!
		 *
		 */
		template<typename IteratorX, typename IteratorY, typename IteratorOut> std::size_t
			longest_common_subsequence(const IteratorX X_begin, const IteratorX X_end, const IteratorY Y_begin, const IteratorY Y_end,
				IteratorOut LCS)
		{
			typedef typename std::iterator_traits<IteratorX>::value_type TX;
			typedef typename std::iterator_traits<IteratorY>::value_type TY;
			typedef typename std::iterator_traits<IteratorOut>::value_type TOut;

			static_assert(std::is_same<TX, TY>::value, "Value types of X and Y should be same!");
			static_assert(std::is_same<TX, TOut>::value, "Value types of input and output should be same!");
			auto len_X = std::distance(X_begin, X_end);
			auto len_Y = std::distance(Y_begin, Y_end);
			if (len_X <= 0 || len_Y <= 0) return 0;

			//Iintialize b, c;
			std::vector<std::vector<int>> c(len_X + 1, std::vector<int>(len_Y + 1, 0));//Matrix c(size m+1 * n+1) to record LCS length;
			std::vector<std::vector<int>> b(len_X, std::vector<int>(len_Y, 0));//Matrix b(size m *n) to point out next LCS recurrison;

			//Calculate b, c;
			for (int _X = 1; _X < len_X+1; _X++)
				for (int _Y = 1; _Y < len_Y+1; _Y++)//skip c[0][0] for c[0][0] is set to 0;
				{
					if (*(X_begin + _X - 1) == *(Y_begin + _Y - 1))// if Xi==Yj 
					{
						c[_X][_Y] = c[_X - 1][_Y - 1] + 1;// length of LCS +=1;
						b[_X-1][_Y-1] = 11;// mark b[i][j] to b[i-1][j-1];
					}
					else if (c[_X - 1][_Y] >= c[_X][_Y - 1])// if Xi!=Yj
					{
						c[_X][_Y] = c[_X - 1][_Y];// connecte with the longer CS;
						b[_X - 1][_Y - 1] = 10;// mark b[i][j] to b[i-1][j];
					}
					else
					{
						c[_X][_Y] = c[_X][_Y - 1];
						b[_X - 1][_Y - 1] = 1;
					}
				}

			return make_LCS(X_begin, X_end, b, len_X - 1, len_Y - 1, LCS);// from back to get the LCS; values could be got from just X;
		}
	}
}


#endif // !LONGESTCOMMONSUBSEQUENCE
