#include<iostream>
#include<algorithm>

using namespace std;

//1、暴力法：总是超时
class Solution {
public:
	double myPow(double x, int n) {
		double res = 1;
		long b = long(n);
		if (b == 0)
			res = 1;
		else if (b > 0)
		{
			while (b > 0)
			{
				res = res * x;
				b--;
			}
		}

		else
		{
			b = -b;
			while (b > 0)
			{
				res = res * x;
				b--;
			}
			res = 1 / res;
		}

		return res;
	}

	
};

//2、快速幂法
class Solution1 {
public:
	double myPow(double x, int n) {
		double res = 1;
		
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		
		// 考虑溢出的情况
		long b = (long)n;

		if (b < 0)
		{
			x = 1 / x;
			b = -b;
		}

		while (b> 0)
		{
			if (b & 1 == 1)
			{
				res = res * x;
				
			}
			x = x * x;
			b >>= 1;
		}

		return res;
	}


};


int main()
{
	double res;
	Solution1 newsolution;
	res = newsolution.myPow(2, -2);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}