#include<iostream>
#include<vector>
#include<map>

using namespace std;

//1����ϣ��
class Solution1 {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		map<int, int>m;
		int n = nums.size();
		vector<int>res(2, 0);
		for (int i = 0; i < n; i++)
		{
			m[nums[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (m[nums[i]] == 1)
			{
				res.push_back(nums[i]);
			}
		}

		return res;
	}
};

//2��λ����
class Solution2 {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int x = 0, y = 0,n=0,m=1;

		//���������õ�ֻ����һ�ε�������
		for (int num : nums)
		{
			n ^= num;
		}

		//�ҵ�����������ȵ�λ
		while ((n&m) == 0)
		{
			m <<= 1;
		}

		//�������
		for (int num : nums)
		{
			if (num&m)x ^= num;
			else y ^= num;
		}

		return { x,y };
	}
};


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}