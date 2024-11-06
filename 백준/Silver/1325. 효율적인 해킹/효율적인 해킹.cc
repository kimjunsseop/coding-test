#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> map;
vector<bool> visited;
vector<int> dv;
vector<int> res;

//void BFS(int i);
void DFS(int v, int k);

int main()
{
	int N, M;
	int max = 0;
	cin >> N >> M;
	visited.resize(N + 1);
	map.resize(N + 1);
	res.resize(N + 1);
	fill(res.begin(), res.end(), 0);
	for (int i = 1; i <= M; i++)
	{
		int s, e;
		cin >> e >> s;
		map[s].push_back(e);
	}
	for (int i = 1; i <= N; i++)
	{
		fill(visited.begin(), visited.end(), false);
		DFS(i, i);
	}
	for (int i = 1; i <= N; i++)
	{
		if (res[i] > max)
		{
			max = res[i];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (res[i] == max)
		{
			cout << i << " ";
		}
	}

}

void DFS(int v,int k)
{
	if (visited[v] == true)
	{
		return;
	}
	visited[v] = true;
	res[k]++;
	for (int i : map[v])
	{
		if (visited[i] == false)
		{
			DFS(i,k);
		}
	}
}