#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//1、递归（超时）
class Solution1 {
public:
	int fib(int n) {
		while (n == 0)
			return 0;
		while (n == 1)
			return 1;
		return (fib(n - 1) + fib(n - 2)) % 1000000007;
	}
};

//2、改进版递归
class Solution2 {
public:
	unordered_map<int, int> mp;
	int fib(int n) {
		while (n == 0)
			return 0;
		while (n == 1)
			return 1;
		//先检查下，这个n是不是之前就算过，如果算过直接返回
	    if (mp.count(n))
		    return mp[n];
		//哈希表中没有，先算出来，再存在哈希表中，下次用到就不用重复计算
		int a = fib(n - 1) % 1000000007;
		mp[n - 1] = a;
		int b = fib(n - 2) % 1000000007;
		mp[n - 2] = b;
		mp[n] = (a + b) % 1000000007;
		return mp[n];

	}
};

//3、递归
class Solution3 {
public:
	int fib(int n) {
		vector<int>res;
		for (int i = 0; i <= n; i++)
		{
			if (i == 0)
				res.push_back(0);
			else if (i == 1)
				res.push_back(1);
			else
				res.push_back((res[i - 1] + res[i - 2]) % 1000000007);

		}

		return (res[n]);
	}
};


int main()
{
	Solution3 newsolution;
	int n = 5;
	int res = newsolution.fib(n);
	cout << res << endl;
	system("puase");
	return EXIT_SUCCESS;
}