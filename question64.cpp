#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1����̬�滮��Υ���˲�ʹ��for��
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

//2���ݹ�
class Solution2 {
public:
	int sumNums(int n) {
		return n == 0 ? 0 : n + sumNums(n - 1);
	}
};

//3����&&
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