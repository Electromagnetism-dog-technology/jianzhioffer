#include<iostream>
#include<string>
#include<vector>
#include<stack>


using namespace std;


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s1.push(x);

		if (s2.empty() || x < s2.top())
		{
			s2.push(x);
		}


		if (x >= s2.top())
		{
			s2.push(s2.top());
		}
	}

	void pop() {
		s1.pop();
		s2.pop();
	}

	int top() {
		return s1.top();
	}

	int min() {
		return s2.top();
	}

	stack<int>s1, s2;

};



int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}