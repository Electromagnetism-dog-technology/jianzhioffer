#include<iostream>
#include<algorithm>

using namespace std;

//1、与运算  0&0=0;0&1=0;1&0=0;1&1=1
class Solution1 {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;

		while (n)
		{
			if (n & 1)
				res++;
			n >>= 1;
		}

		return res;
	}
};

//2、n&(n−1)法
class Solution2 {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;

		while (n)
		{
			res++;
			n = n & (n-1);
		}

		return res;
	}
};

int main()
{
	Solution2 newsolution;
	uint32_t n = 00000000000000000000000000001011;
	int res = newsolution.hammingWeight(n);
	cout << res << endl;
	system("pause");
	return EXIT_SUCCESS;
}