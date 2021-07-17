#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1、动态规划（违反了不使用for）
class Solution1 {
public:
	int sumNums(int n) {
		vector<int>vec;
		vec[0] = 0;
		vec[1] = 1;
		vec[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			vec[i] = i + vec[i - 1];
		}
		return vec[n];
	}
};

//2、递归
class Solution2 {
public:
	int sumNums(int n) {
		return n == 0 ? 0 : n + sumNums(n - 1);
	}
};

//3、用&&
class Solution3{
public:
	int sumNums(int n) {
		n && (n += sumNums(n - 1));
		return n;
	}
};


int main()
{

}