#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> graph;
vector<bool> visited;
vector<int> mindistance;

void dijkstra(int s);

int main()
{
    int N, E;
    cin >> N >> E;
    visited.resize(N + 1);
    mindistance.resize(N + 1);
    fill(mindistance.begin(), mindistance.end(), INT_MAX);
    graph.resize(N + 1);
    for(int i = 0; i < E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
        graph[e].push_back(make_pair(s, w));
    }
    int v1, v2;
    cin >> v1 >> v2;
    int result1 = 0, result2 = 0;
    dijkstra(1);
    result1 = mindistance[v1];
    if(mindistance[N] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        fill(mindistance.begin(), mindistance.end(), INT_MAX);
        fill(visited.begin(), visited.end(), false);
        dijkstra(v1);
        result1 += mindistance[v2];
        fill(mindistance.begin(), mindistance.end(), INT_MAX);
        fill(visited.begin(), visited.end(), false);
        dijkstra(v2);
        result1 += mindistance[N];
        fill(mindistance.begin(), mindistance.end(), INT_MAX);
        fill(visited.begin(), visited.end(), false);
        dijkstra(1);
        result2 = mindistance[v2];
        fill(mindistance.begin(), mindistance.end(), INT_MAX);
        fill(visited.begin(), visited.end(), false);
        dijkstra(v2);
        result2 += mindistance[v1];
        fill(mindistance.begin(), mindistance.end(), INT_MAX);
        fill(visited.begin(), visited.end(), false);
        dijkstra(v1);
        result2 += mindistance[N];
        fill(mindistance.begin(), mindistance.end(), INT_MAX);
        fill(visited.begin(), visited.end(), false);
        if(result1 > result2)
        {
            cout << result2 << endl;
        }
        else
        {
            cout << result1 << endl;
        }
    }
}

void dijkstra(int s)
{
    priority_queue<edge, vector<edge>, greater<edge>> q;
    mindistance[s] = 0;
    visited[s] = true;
    q.push(make_pair(0, s));
    while(!q.empty())
    {
        edge now = q.top();
        for(auto n : graph[now.second])
        {
            if(visited[n.first] == false)
            {
                if(mindistance[n.first] > mindistance[now.second] + n.second)
                {
                    mindistance[n.first] = mindistance[now.second] + n.second;
                    q.push(make_pair(mindistance[n.first], n.first));
                }
            }
        }
        visited[now.second] = true;
        q.pop();
    }
}