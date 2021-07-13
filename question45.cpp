#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution1 {
public:
	string minNumber(vector<int>& nums) {

		sort(nums.begin(), nums.end(), cmp);
		string res;

		for (int i = 0; i < nums.size(); i++)
		{
			res += to_string(nums[i]);
		}

		return res;
	}

	static bool cmp(int &x, int &y)
	{
		return to_string(x) + to_string(y) < to_string(y) + to_string(x);
	}
};

class Solution2 {
public:
	string minNumber(vector<int>& nums) {
		if (!nums.size()) return ""; // 判空
		vector<string> vec; // 字符串数组，存放原数组中的数字转成的字符串
		string ret; // 保存最后拼接起来的数
		/*
		*  lambda表达式自定义排序规则：
		*  要排成最小的数，所以要升序排列
		*/
		auto myCompare = [](string& s1, string& s2) {return s1 + s2 < s2 + s1; };
		for (int i : nums) vec.push_back(to_string(i)); // 将所有数字传成字符串存入vec中
		sort(vec.begin(), vec.end(), myCompare); // 排序
		for (string s : vec) ret += s; // 拼接字符串
		return ret; // 返回最小的数
	}

};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}