#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <= 1)
		{
			return 0;
		}
		int curr = prices[1] - prices[0];
		int profit = prices[1] - prices[0];
		for (int i = 2; i < n; i++)
		{
			int temp = prices[i] - prices[i - 1];
			curr = max(temp, curr + temp);
			profit = max(profit, curr);
		}

		return profit > 0 ? profit : 0;

	}
};

int main()
{

}