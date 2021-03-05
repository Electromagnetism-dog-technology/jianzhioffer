#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1����򵥵ķ���
class Solution1 {
public:
	int minArray(vector<int>& numbers) {
		return *min_element(numbers.begin(), numbers.end());
	}
};

//2�����ַ�
class Solution2 {
public:
	int minArray(vector<int> &numbers) {
		int size = numbers.size();
		if (size == 0) {
			return 0;
		}

		int left = 0;
		int right = size - 1;

		while (left < right) {
			int mid = left + (right - left) / 2;
			// int mid = left + ((right - left) >> 1);
			if (numbers[mid] > numbers[right]) {
				// [3, 4, 5, 1, 2]��mid �Լ� mid �����һ��������С����
				// ��һ������������ [mid + 1, right]
				left = mid + 1;
			}
			else if (numbers[mid] == numbers[right]) {
				// ֻ�ܰ� right �ų�������һ������������ [left, right - 1]
				right--;
			}
			else {
				// ��ʱ numbers[mid] < numbers[right]
				// mid ���ұ�һ��������С���֣�mid �п����ǣ���һ������������ [left, mid]
				right = mid;
			}
		}
		return numbers[left];
	}
};


int main()
{
	Solution1 newsolution;
	vector<int>numbers = {1,2,4,3,5};
	int res = newsolution.minArray(numbers);
	cout << res << endl;
}