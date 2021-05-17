#include<iostream>
#include<algorithm>

using namespace std;

//1�������������ǳ�ʱ
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

//2�������ݷ�
class Solution1 {
public:
	double myPow(double x, int n) {
		double res = 1;
		
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		
		// ������������
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