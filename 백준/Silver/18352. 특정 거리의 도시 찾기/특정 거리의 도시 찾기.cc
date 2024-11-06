#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> map;
vector<bool> visited;
vector<int> dv;

void BFS(int i);

int main()
{
	int d;
	int N, M, K, X;
	int count = 0;
	cin >> N >> M >> K >> X;
	visited.resize(N + 1);
	dv.resize(N + 1);
	fill(visited.begin(), visited.end(), false);
	fill(dv.begin(), dv.end(), 0);
	map.resize(N+1);
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		map[s].push_back(e);
	}
	BFS(X);
	for (int i = 1; i <= N; i++)
	{
		if (dv[i] == K)
		{
			cout << i << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << -1;
	}


}

void BFS(int i)
{
	queue<int> my;

	my.push(i);
	visited[i] = true;
	while (!my.empty())
	{
		for (int i : map[my.front()])
		{
			if (visited[i] == false)
			{
				my.push(i);
				visited[i] = true;
				dv[i] = 1 + dv[my.front()];
			}
		}
		my.pop();
	}
}
