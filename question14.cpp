#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1����̬�滮
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

//2��̰���㷨
//8 ���Ϊ 3+3+2����ʱ�˻������ġ�Ȼ����Ʋ����һ��������Ҫ��ɶ�� 2 �� 3 �ĺͣ���֤�˻����ԭ���������⣬��Ϊ 2 �� 3 ���Ժϳ��κ����֣�����5=2+3������5 < 2*3������6=3+3������6<3*3�����Ը���̰���㷨���;�����ԭ����ɸ���� 3��Ȼ���ٲ�ɸ���� 2����֤������������ĳ˻�������
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

//3��̰���㷨
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