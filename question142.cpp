#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//这道题虽然和14.1相似 但是由于大数问题存在，直接在上一个动态规划上取余会出现错误。
//根据这道题我们可以知道取3越多数值越大，因此直接用贪心算法解决


//贪心算法
class Solution2 {
public:
	int cuttingRope(int n) {
		if (n < 4)
		{
			return n - 1;
		}
		else if (n == 4)
		{
			return n;
		}

		long res = 1;
		while (n > 4)
		{
			n -= 3;
			res = (res * 3) % 1000000007;
		}

		return (res * n) % 1000000007;
	}
};

int main()
{
	Solution2 newsolution;
	int n = 5;
	int res = newsolution.cuttingRope(n);
	cout << res << endl;

}