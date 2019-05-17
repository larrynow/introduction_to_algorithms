/*
 * Program to realize Introduction to Algorithms.
 *
 * Capt.15 Greedy algorithm, Huffman code.
 *
 * By LongFei Li, 2019-05-15.
 */
#ifndef HUFFMAN
#define HUFFMAN
#include<deque>
#include<vector>
#include<map>
#include<string>

namespace IntroductionToAlgorithms
{
	namespace GreedyAlogrithm
	{
		/*!struct Node*/
		template<typename KeyType, typename FreqType>
			struct Node
			{	
				KeyType key;
				FreqType freq;
				Node* child;
				Node* sibling;
				Node<KeyType, FreqType>(KeyType k, FreqType f) : key(k), freq(f), child(NULL), sibling(NULL) {};
				Node<KeyType, FreqType>(FreqType f) : key(NULL), freq(f), child(NULL), sibling(NULL) {};
				bool operator<(Node<KeyType, FreqType> n) const { return freq < n.freq; }
			};

		/*!make_Huffman_tree: get Huffman code tree by greedy algorithm
		 *\param codes: a input deque stores nodes with code and freq, in ascent way
		 *\return: root node of Huffman tree 
		 */
		template<typename KeyType, typename FreqType> Node<KeyType, FreqType>*
			make_Huffman_tree(std::deque<Node<KeyType, FreqType>*> codes)
		{
			typedef Node<KeyType, FreqType> HuffmanNode;
			while (codes.size()>=2)
			{
				auto ch = codes.front();
				codes.pop_front();
				auto ch_si = codes.front();
				codes.pop_front();
				HuffmanNode* node = new HuffmanNode(ch->freq + ch_si->freq);
				ch->sibling = ch_si;
				node->child = ch;
				auto position = codes.begin();
				for (; position!=codes.end() && ((*position)->freq < node->freq); position++);
				//Another way to get position : 	
				/*auto cmp = [](Pointer a, Pointer b) {return *a < *b; };
				 *auto po = std::upper_bound(v.begin(), v.end(), new int(66), cmp);
				 */
				codes.insert(position, node);
			}
			auto root = (codes.front());

			return root;
		}

		template<typename KeyType, typename FreqType> std::map<KeyType, std::string>
			Huffman_dfs(Node<KeyType, FreqType>* root)
		{
			typedef Node<KeyType, FreqType>* HuffmanNode;
			std::deque<HuffmanNode> q;
			std::map<KeyType, std::string> key_code;
			//std::vector<int> code;
			std::string code = "";

			q.push_back(root);
			for (auto cur = root; cur->child != NULL; q.push_back(cur->child), code.push_back('0'), cur = cur->child);

			while (!q.empty())
			{
				auto cur = q.back();
				if(cur->key!=NULL) key_code[cur->key] = code;
				q.pop_back();
				code.pop_back();
				if (cur->sibling != NULL)
				{
					q.push_back(cur->sibling);
					code.push_back('1');
					for (auto si=cur->sibling; si->child != NULL; si = si->child, q.push_back(si), code.push_back('0'));
				}
			}

			return key_code;
		}
	}
}


#endif // !HUFFMAN

