#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//1����������û�п��Ǵ������⣩
class Solution1 {
public:
	vector<int> printNumbers(int n) {
		int t = pow(10, n);
		vector<int>res;
		for (int i = 1; i < t; i++)
			res.push_back(i);
		return res;
	}
};

//2�����Ǵ���
class Solution2 {
public:
	vector<int> output;
	vector<int> printNumbers(int n) {
		// ����ע�͵�ǰ�᣺���� n = 3
		if (n <= 0) return vector<int>(0);
		string s(n, '0'); // s�������999����s�ĳ���Ϊn
		while (!overflow(s)) inputNumbers(s);//ֻҪsû��Խ�磬�ͻ�һֱ��ӵ�output��
		return output;
	}
	bool overflow(string& s)
	{
		// ����������ģ�����ֵ��ۼӹ��̣����ж��Ƿ�Խ�磨�� 999 + 1 = 1000������Խ�������
		bool isOverFlow = false;
		int carry = 0; // carry��ʾ��λ
		for (int i = s.length() - 1; i >= 0; --i)
		{
			int current = s[i] - '0' + carry; // current��ʾ��ǰ��εĲ���
			if (i == s.length() - 1) current++; // ���i��ʱ�ڸ�λ��currentִ�� +1 ����
			if (current >= 10)
			{
				// ����i�Ѿ���������һλ�ˣ���current++֮��>=10��˵��ѭ����ͷ�ˣ���999 + 1 = 1000
				if (i == 0) isOverFlow = true;
				else
				{
					// ֻ����ͨ��λ������current��9���10
					carry = 1;
					s[i] = current - 10 + '0';
				}
			}
			else
			{
				// ���û�н�λ������s[i]��ֵ��Ȼ��ֱ������ѭ���������Ϳ��Ի�ȥִ��inputNumbers�����ˣ�����output�����Ԫ��
				s[i] = current + '0';
				break;
			}
		}
		return isOverFlow;
	}
	void inputNumbers(string s)
	{
		// ����������ѭ����output����ӷ��ϴ�ͳ�Ķ�ϰ�ߵ�Ԫ�ء�����001�����ǻ����1������001��
		bool isUnwantedZero = true; // �ж��Ƿ��ǲ���Ҫ��ӵ�0������001ǰ�������0
		string temp = "";
		for (int i = 0; i < s.length(); ++i)
		{
			if (isUnwantedZero && s[i] != '0') isUnwantedZero = false;
			if (!isUnwantedZero) temp += s[i];
		}
		output.push_back(stoi(temp));
	}
};

//3��ȫ����
class Solution3 {
public:
	vector<int> ans;
	int pos = 0;
	vector<int> printNumbers(int n) {
		string s = "0123456789";
		string str = "";
		dfs(s, str, n);
		return ans;
	}
	void dfs(string &s, string &str, int k) {
		if (str.length() == k) {
			if (pos == 0) { pos = 1; return; } //��һ��000��ȥ��
			ans.push_back(stoi(str));
			return;
		}
		for (int i = 0; i < s.length(); ++i) {
			str += s[i];
			dfs(s, str, k);
			str.pop_back();
		}
	}
};



int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}