#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> weight;
vector<int> indegree;
queue<int> myqueue;
vector<int> leastTime;
vector<bool> visited;
typedef pair<int,int> indwleas;
//vector<indwleas> w;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> nq;

int main()
{
    int N;
    cin >> N;
    graph.resize(N+1);
    weight.resize(N+1);
    indegree.resize(N+1);
    leastTime.resize(N+1);
    visited.resize(N+1);
    fill(visited.begin(), visited.end(), false);
    for(int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        weight[i] = a;
        while(1)
        {
            int b;
            cin >> b;
            if(b == -1)
            {
                break;
            }
            else
            {
                graph[b].push_back(i);
                indegree[i]++;
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        if(indegree[i]==0)
        {
            leastTime[i] = weight[i];
            nq.push(make_pair(leastTime[i],i));
        }
    }
    while(!nq.empty())
    {
        indwleas now = nq.top();
        nq.pop();
        for(int i : graph[now.second])
        {
            indegree[i]--;
            if(indegree[i] == 0)
            {
                leastTime[i] = leastTime[now.second] + weight[i];
                nq.push(make_pair(leastTime[i],i));
                
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        cout << leastTime[i] << endl;
    }
}