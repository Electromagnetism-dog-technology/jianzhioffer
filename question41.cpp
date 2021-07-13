#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	
	priority_queue<int>q1;
	priority_queue<int, vector<int>, greater<int> > q2;

	MedianFinder() {
		
	}

	void addNum(int num) {
		if (q1.size() == q2.size())
		{
			q1.push(num);
			q2.push(q1.top());
			q1.pop();
		}
		else
		{
			q2.push(num);
			q1.push(q2.top());
			q2.pop();
		}
	}

	double findMedian() {
		
		int len1 = q1.size(), len2 = q2.size();
		return len1 == len2 ? (q1.top() + q2.top()) *0.5 : q2.top();

	}
};

int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}