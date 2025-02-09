#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> edge;

vector<edge> graph;
vector<int> parent;

bool unifnc(int a, int b);
int find(int a);
bool compare(const edge& a, const edge& b)
{
    return get<2>(a) < get<2>(b);
}

int main()
{
    int V, E;
    int sum = 0;
    cin >> V >> E;
    for(int i=0; i<E; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        graph.push_back(make_tuple(s,e,w));
    }
    parent.resize(V+1);
    for(int i=0; i<V+1; i++)
    {
        parent[i] = i;
    }
    sort(graph.begin(), graph.end(), compare);
    int link = 0;
    int i = 0;
    while(link < V-1)
    {
        if(unifnc(get<0>(graph[i]),get<1>(graph[i])))
        {
            i++;
        }
        else
        {
            sum += get<2>(graph[i]);
            i++;
            link++;
        }
    }
    cout << sum << endl;
}

int find(int a)
{
    if(a==parent[a])
    {
        return a;
    }
    else
    {
        return parent[a] = find(parent[a]);
    }
}

bool unifnc(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a==b)
    {
        return true;
    }
    else
    {
        parent[b] = a;
        return false;
    }
}