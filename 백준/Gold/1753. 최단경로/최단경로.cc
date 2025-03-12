#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> graph;
vector<bool> visited;
vector<int> mindistance;

void digkstra(int s);

int main()
{
    int V, E;
    int start;
    cin >> V >> E;
    cin >> start;
    graph.resize(V + 1);
    visited.resize(V + 1);
    mindistance.resize(V + 1);
    fill(mindistance.begin(), mindistance.end(), INT_MAX);
    for(int i = 0; i < E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e, w));
    }
    digkstra(start);
    for(int i = 1; i <= V; i++)
    {
        if(mindistance[i] == INT_MAX)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << mindistance[i] << endl;
        }
    }

}

void digkstra(int s)
{
    priority_queue<edge, vector<edge>, greater<edge>> q;
    q.push(make_pair(0, s));
    visited[s] = true;
    mindistance[s] = 0;
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