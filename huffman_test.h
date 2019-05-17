#ifndef HUFFMANTEST
#define HUFFMANTEST
#include<gtest/gtest.h>
#include"huffman.h"

using IntroductionToAlgorithms::GreedyAlogrithm::Node;
using IntroductionToAlgorithms::GreedyAlogrithm::make_Huffman_tree;
using IntroductionToAlgorithms::GreedyAlogrithm::Huffman_dfs;

TEST(huffman_test, test_f)
{
	typedef Node<char, int> N;
	std::deque<N*> codes{new N('f', 5), new N('e', 9), new N('c', 12), new N('b', 13), new N('d', 16), new N('a', 45)};
	//std::deque<N> codes{ N('f',5), N('e', 9), N('c', 12), N('b',13), N('d',16), N('a', 45) };
	auto root = make_Huffman_tree(codes);
	auto ret = Huffman_dfs(root);
	EXPECT_EQ(ret['f'], "1100");
}
#endif // !HUFFMANTEST
