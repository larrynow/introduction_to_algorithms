#ifndef SIGNPLAYERTEST
#define SIGNPLAYERTEST
#include"sign_player.h"
#include<gtest/gtest.h>
#include<vector>
using IntroductionToAlgorithms::DynamicProgramming::sign_player;
using IntroductionToAlgorithms::DynamicProgramming::get_players;
using IntroductionToAlgorithms::DynamicProgramming::Player;


TEST(test_sign_player, test)
{
	std::vector<std::vector<Player>>PLS;
	PLS = { {Player("CR", 20, 10), Player("Hazard", 15, 10)},{Player("Bale", 10, 10),Player("Sarah", 18, 10)} };
	int budget = 20;//20,000,000;
	std::vector<std::vector<int>> v;
	std::vector<std::vector<int>> p_signed;
	sign_player(PLS, budget, v, p_signed);
	auto pls_list = get_players(PLS, p_signed, 20);
	std::vector<std::string>ans = std::vector<std::string>{ "CR", "Sarah" };
	EXPECT_EQ(pls_list, ans);
}
#endif // !SIGNPLAYERTEST
