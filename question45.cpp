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
		if (!nums.size()) return ""; // �п�
		vector<string> vec; // �ַ������飬���ԭ�����е�����ת�ɵ��ַ���
		string ret; // �������ƴ����������
		/*
		*  lambda���ʽ�Զ����������
		*  Ҫ�ų���С����������Ҫ��������
		*/
		auto myCompare = [](string& s1, string& s2) {return s1 + s2 < s2 + s1; };
		for (int i : nums) vec.push_back(to_string(i)); // ���������ִ����ַ�������vec��
		sort(vec.begin(), vec.end(), myCompare); // ����
		for (string s : vec) ret += s; // ƴ���ַ���
		return ret; // ������С����
	}

};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}