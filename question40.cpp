#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//1、排序法
class Solution1 {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int>res(k,0);
		int len = arr.size();
		sort(arr.begin(), arr.end());

		for (int i = 0; i < k; i++)
		{
			res.push_back(arr[i]);
		}

		return res;
	}
};

//2、建大顶堆法
class Solution2 {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int>res(k, 0);
		int len = arr.size();
		priority_queue<int>Q;

		if (k == 0) { // 排除 0 的情况
			return res;
		}

		for (int i = 0; i < k; i++)
		{
			Q.push(arr[i]);
		}

		for (int i = k; i < len; i++)
		{
			if (Q.top() > arr[i])
			{
				Q.pop();
				Q.push(arr[i]);
			}
		}

		for (int i = 0; i < k; i++)
		{
			res[i]=Q.top();
			Q.pop();
		}

		return res;
		
	}
};

int main()
{
	vector<int>nums = { 4, 5, 1, 6, 2, 7, 3, 8 };
	Solution2 ns;
	vector<int>res;
	res = ns.getLeastNumbers(nums,4);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}