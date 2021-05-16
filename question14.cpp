#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1、动态规划
class Solution1 {
public:
	int cuttingRope(int n) {
		
		if (n < 4) return n - 1;
		
		vector<int>res(n+1, 0);
		res[0] = 0;
		res[1] = 1;
		res[2] = 2;
		res[3] = 3;

		for (int i = 4; i <= n; i++)
		{
			int max_val = 0;

			for (int j = 1; j <= i / 2; j++)
			{
				max_val = max(max_val, res[i - j] * res[j]) ;
			}

			res[i] = max_val ;
		}

		return res[n] ;
	}
};

//2、贪心算法
//8 拆分为 3+3+2，此时乘积是最大的。然后就推测出来一个整数，要拆成多个 2 和 3 的和，保证乘积最大。原理很容易理解，因为 2 和 3 可以合成任何数字，例如5=2+3，但是5 < 2*3；例如6=3+3，但是6<3*3。所以根据贪心算法，就尽量将原数拆成更多的 3，然后再拆成更多的 2，保证拆出来的整数的乘积结果最大。
class Solution2 {
public:
	int cuttingRope(int n) {
		if (n < 4) return n - 1;

		int t1 = n / 3;
		int t2 = n % 3;

		if (t2 == 0)
			return pow(3 , t1);
		else if (t2 == 1)
			return pow(3, t1-1)* 4;
		else
			return pow(3, t1) * 2;


	}


};

//3、贪心算法
class Solution3 {
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
			res = (res * 3) ;
		}

		return (res * n) ;
	}
};


int main()
{
	Solution2 newsolution;
	int n = 5;
	int res = newsolution.cuttingRope(n);
	cout << res << endl;
	
}