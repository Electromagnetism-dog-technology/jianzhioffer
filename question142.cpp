#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//�������Ȼ��14.1���� �������ڴ���������ڣ�ֱ������һ����̬�滮��ȡ�����ִ���
//������������ǿ���֪��ȡ3Խ����ֵԽ�����ֱ����̰���㷨���


//̰���㷨
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