#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//1、BFS
class Solution1 {
public:
	int movingCount(int m, int n, int k) {
		if (!k)return 1;
		//标记已访问的格子
		vector<vector<int>>visit(m, vector<int>(n, 0));
		visit[0][0] = 1;

		//存储刚访问过的格子
		queue<pair<int, int>>Q;
		Q.push(make_pair(0, 0));

		//创立方向矩阵
		int dx[2] = { 0,1 };
		int dy[2] = { 1,0 };

		int ans = 1;

		while (!Q.empty())
		{
			pair<int, int> t = Q.front();
			Q.pop();

			for (int i = 0; i < 2; i++)
			{
				int tx = t.first + dx[i];
				int ty = t.second + dy[i];
				

				if (tx < 0 || tx >= m || ty < 0 || ty >= n || visit[tx][ty] || get(tx) + get(ty) > k)continue;

				Q.push(make_pair(tx, ty));
				visit[tx][ty] = 1;

				ans++;

			}
			

		}

		return ans;

	}

	// 计算 x 的数位之和
	int get(int x) {
		int s = 0;
		while (x != 0) {
			s += x % 10;
			x = x / 10;
		}
		return s;

		
	}

	
};

//2、DFS
class Solution2 {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> visited(m, vector<bool>(n, 0));
		return dfs(0, 0, visited, m, n, k);
	}
private:
	int dfs(int i, int j,  vector<vector<bool>> &visited, int m, int n, int k) {
		
		if (i >= m || j >= n || k < get(i) + get(j) || visited[i][j]) return 0;
		visited[i][j] = true;
		return 1 + dfs(i + 1, j,  visited, m, n, k) + dfs(i, j + 1,visited, m, n, k);
	}

	int get(int x) {
		int s = 0;
		while (x != 0) {
			s += x % 10;
			x = x / 10;
		}
		return s;


	}


};

int main()
{
	Solution2 newsolution;
	int m = 2;
	int n = 3;
	int k = 1;
	int res = newsolution.movingCount(m, n, k);
	cout << res << endl;
}