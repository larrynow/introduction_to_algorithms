#ifndef LONGESTCOMMONSUBSEQUENCE_TEST
#define LONGESTCOMMONSUBSEQUENCE_TEST
#include"longest_common_subsequence.h"
#include<string>
#include<gtest/gtest.h>
using IntroductionToAlgorithms::DynamicProgramming::longest_common_subsequence;
//!longest_common_subsequence_test: for testing longest_common_subsequence
TEST(test_longest_common_subsequence, test_empty_sequence)
{
	std::string X;
	std::string Y("ABCDEFG");
	std::string LCS(Y);
	auto length = longest_common_subsequence(X.begin(), X.end(), Y.begin(), Y.end(), LCS.begin());
	EXPECT_EQ(length, 0);
}
TEST(test_longest_common_subsequence, test_diff_sequences)
{
	std::string X("ABDCBDDAB");
	std::string Y("BDCABABD");
	std::string LCS(Y);
	auto length = longest_common_subsequence(X.begin(), X.end(), Y.begin(), Y.end(), LCS.begin());
	LCS.resize(length);
	EXPECT_EQ(LCS, std::string("BDCBAB"));
	//EXPECT_EQ(length, 6);
}
TEST(test_longest_common_subsequence, test_same_sequences)
{
	std::string X("ABDCBDDAB");
	std::string Y("ABDCBDDAB");
	std::string LCS(Y);
	auto length = longest_common_subsequence(X.begin(), X.end(), Y.begin(), Y.end(), LCS.begin());
	LCS.resize(length);
	EXPECT_EQ(LCS, std::string("ABDCBDDAB"));
}
#endif // !LONGESTCOMMONSUBSEQUENCE_TEST
