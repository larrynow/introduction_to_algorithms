/*
 * Program to realize Introduction to Algorithms.
 *
 * Capt.15 Dynamic Programming, Sign player.
 *
 * By LongFei Li, 2019-05-08.
 */
#ifndef SIGNPLAYER
#define SIGNPLAYER
#include<vector>

namespace IntroductionToAlgorithms
{
	namespace DynamicProgramming
	{
		/*! struct Player*/
		struct Player
		{
			std::string name;
			int vorp;
			int cost;
			Player(std::string s, int v, int c) : name(s), vorp(v), cost(c) {};
		};
		/*! sign_player: from first position to end, choose players with highest vorp under a budget X
		 *\param PLS: players to sign, size:N*P
		 *\param X: the budget(budget/1000,000) to sign player
		 *\param v: to record vorp at each position with budget
		 *\param p_signed: a matrix to store which player to sign
		 */
		void sign_player(const std::vector<std::vector<Player>> PLS, const int X, 
			std::vector<std::vector<int>> &v,
			std::vector<std::vector<int>> &p_signed)
		{
			std::size_t N = PLS.size();
			std::size_t P = PLS[0].size();
			v = std::vector<std::vector<int>>(N, std::vector<int>(X+1, 0));//v[p][x] record vorp at each position p with budget x;
			p_signed = std::vector<std::vector<int>>(N, std::vector<int>(X + 1, -1));

			for (int _p = 0; _p < P; _p++)//for each player at position 0;
			{
				for (int _x = 0; _x <= X; _x++)//for budget;
				{
					if (PLS[0][_p].cost <= _x)//cost should not bigger than budget;
					{
						//vorp at first position initialized as highest vorp of players with cost not bigger than budget;
						if (PLS[0][_p].vorp > v[0][_x])
						{
							v[0][_x] = PLS[0][_p].vorp;
							p_signed[0][_x] = _p;
						}
					}
				}
			}
			for (int _PS = 1; _PS < N; _PS++)//for each rest position;
			{
				for (int _X = 0; _X <= X; _X++)
				{
					//strategy 1, not sign any player at position i;
					v[_PS][_X] = v[_PS - 1][_X];
					p_signed[_PS][_X] = -1;
					//strategy 2, sign a player with highest vorp;
					for (int _PL = 0; _PL < P; _PL++)//for each player at position _PS;
					{
						auto _pl = PLS[_PS][_PL];//player;
						auto _v = _pl.vorp + v[_PS-1][_X - _pl.cost];
						if (_v > v[_PS][_X])
						{
							v[_PS][_X] = _v;
							p_signed[_PS][_X] = _PL;
						}
					}
				}				
			}
		}

		/*!get_players: get players list under budget X
		 *\PLS: the players' info
		 *\param p_signed: the calculated player solutions
		 *\param budget: total budget X
		 \return: signed player at each position, 0 for no player signed
		 */
		std::vector<std::string>
			get_players(const std::vector<std::vector<Player>> &PLS, const std::vector<std::vector<int>> &p_signed, const int budget)
		{
			std::vector<std::string> ret;
			for (int _P = 0; _P < PLS.size(); _P++)
			{
				ret.push_back(PLS[_P][p_signed[_P][budget]].name);
			}

			return ret;
		}
	}
}
#endif // !SIGNPLAYER

