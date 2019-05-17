/*
 * Program to realize Introduction to Algorithms.
 *
 * Capt.15 Dynamic Programming, Rod cutting.
 *
 * By LongFei Li, 2019-05-05.
 */
#ifndef BOTTOMUPRODCUTTING
#define BOTTOMUPRODCUTTING
#include<type_traits>
#include<vector>

namespace IntroductionToAlgorithms
{
	namespace DynamicProgramming
	{
		//! bottom_up_cut_rod: cut a rod to get best benifit;
		/*!
		 *\param price_begin: begin iter of price input;
		 *\param price_end: end iter of price input;
		 *\param rod_length: the length of rod;
		 *\param r: to record resolve of sub problems;
		 *\param s: to record the length of first piece rod in each best cutting;
		 */
		template<typename InIterator, typename PriceType> void
			bottom_up_cut_rod(const InIterator price_begin, const InIterator price_end, const int rod_length,
				std::vector<PriceType> &r, std::vector<int> &s)
		{
			typedef typename std::iterator_traits<InIterator>::value_type T;
			static_assert(std::is_same<T, PriceType>::value, "The value type of price should be same!");
			if (rod_length <= 0 || (rod_length+1) != (price_end-price_begin)) return;//to maintain index to be same in price and r, s add 0 to be price[0];

			//initialize
			r = std::vector<T>(rod_length + 1, 0);
			s = std::vector<int>(rod_length + 1, 0);

			for (int j = 1; j <= rod_length; j++) 
			{
				T max_price = -1;
				for (int i = 1; i <= j; i++)
				{
					auto _p = r[j - i] + (*(price_begin + i));//cut at i of length-j rod got price _p;
					if (max_price < _p)
					{
						max_price = _p;
						s[j] = i;//if cut at i of j is best solution, record the cut position ;
					}
				}
				r[j] = max_price;
			}

			//print_cut_rod_solution(s);
		}
		void print_cut_rod_solution(const std::vector<int> s)
		{
			std::size_t n = s.size();
			while (n > 0)
			{
				std::cout<<s[n]<<std::endl;
				n = n - s[n];
			}
		}
	}
}

#endif // !BOTTOMUPCUTROD
