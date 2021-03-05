#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//1¡¢µü´ú
class Solution1 {
public:
	int numWays(int n) {
		vector<int>res;
		for (int i = 0; i <= n; i++)
		{
			if (i == 0)
				res.push_back(1);
			else if (i == 1)
				res.push_back(1);
			else
				res.push_back((res[i-1] + res[i-2]) % 1000000007);
		}

		return res[n];
	}
};

//2¡¢µÝ¹é+¹þÏ£
class Solution2 {
public:
	unordered_map<int, int>mp;
	int numWays(int n) {
		vector<int>res;
		if (n == 0)
			return 1;
		else if (n == 1)
			return 1;
		else if (mp.count(n))
			return mp[n];
		int a = numWays(n - 1) % 1000000007;
		mp[n - 1] = a;
		int b = numWays(n - 2) % 1000000007;
		mp[n - 2] = b;
		return (a + b) % 1000000007;

	}
};


int main()
{
	Solution2 newsolution;
	int res = newsolution.numWays(7);
	cout << res << endl;
	system("puase");
	return EXIT_SUCCESS;
}

