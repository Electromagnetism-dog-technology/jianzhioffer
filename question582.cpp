#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int len = s.size();
		s += s;
		string res = s.substr(n, len);
		return res;

	}
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}