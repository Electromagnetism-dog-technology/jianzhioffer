#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//1¡¢»ØËÝ·¨
class Solution1 {
public:
	bool getCombinations(vector<vector<char>>& board, int i, int j, string word,int digit)
	{
		if (board[i][j] != word[digit])
		{
			return false;
		}

		if (digit == word.size() - 1)
		{
			return true;
		}

		char tmp = board[i][j];
		board[i][j] = 0;
		digit++;

		if ((i<board.size()-1 &&getCombinations(board,i+1,j,word,digit))|| (j < board[0].size()-1 && getCombinations(board, i, j+1, word, digit)) ||
			(i >0 && getCombinations(board, i - 1, j, word, digit)) || (j>0 && getCombinations(board, i, j-1, word, digit)))
		{
			return true;
		}

		board[i][j] = tmp;
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (getCombinations(board, i, j, word, 0))
				{
					return true;
				}

			}
		}

		return false;
	}
};


int main()
{
	Solution1 newsolution;
	vector<vector<char>>numbers = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	string word = "ABCCED";
	bool res = newsolution.exist(numbers,word);
	cout << res << endl;
}