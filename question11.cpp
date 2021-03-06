#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1、最简单的方法
class Solution1 {
public:
	int minArray(vector<int>& numbers) {
		return *min_element(numbers.begin(), numbers.end());
	}
};

//2、二分法
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
				// [3, 4, 5, 1, 2]，mid 以及 mid 的左边一定不是最小数字
				// 下一轮搜索区间是 [mid + 1, right]
				left = mid + 1;
			}
			else if (numbers[mid] == numbers[right]) {
				// 只能把 right 排除掉，下一轮搜索区间是 [left, right - 1]
				right--;
			}
			else {
				// 此时 numbers[mid] < numbers[right]
				// mid 的右边一定不是最小数字，mid 有可能是，下一轮搜索区间是 [left, mid]
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