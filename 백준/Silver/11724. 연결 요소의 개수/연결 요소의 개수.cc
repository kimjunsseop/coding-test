#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int totalCount = 0;

void DFS(int s);

int main()
{
    int N, M;
    cin >> N >> M;
    graph.resize(N + 1);
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), false);
    visited[0] = true;
    for(int i  =  1; i <= M; i++)
    {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for(int i = 1; i <= N; i++)
    {
        if(visited[i] == false)
        {
            DFS(i);
            totalCount++;
        }
    }
    cout << totalCount << endl;
}

void DFS(int s)
{
    if(visited[s] == true)
    {
        return;
    }
    else
    {
        visited[s] = true;
        for(int c : graph[s])
        {
            if(visited[c] == false)
            {
                DFS(c);
            }
        }
    }
}