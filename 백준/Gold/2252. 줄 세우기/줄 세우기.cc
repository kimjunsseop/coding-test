#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> linked;
vector<int> parent;
queue<int> myqueue;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	linked.resize(N + 1);
	parent.resize(N + 1);
	fill(parent.begin(), parent.end(), 0);
	//인접리스트 생성
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		linked[s].push_back(e);
		parent[e]++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (parent[i] == 0)
		{
			myqueue.push(i);
		}
	}
	while (!myqueue.empty())
	{
		int now = myqueue.front();
		myqueue.pop();
		cout << now << " ";
		for (int i : linked[now])
		{
			parent[i]--;
			if (parent[i] == 0)
			{
				myqueue.push(i);
			}

		}
	}
}