#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

static int dx[] = {1, 0, -1, 0};
static int dy[] = {0, 1, 0, -1};
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<vector<int>> dis;
int N, M;

void BFS(int a, int b);

int main()
{
    cin >> N >> M;
    maze.resize(N + 1);
    visited.resize(N + 1);
    dis.resize(N + 1);
    for(int i = 1; i <= N; i++)
    {
        maze[i].resize(M + 1);
        visited[i].resize(M + 1);
        dis[i].resize(M + 1);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            visited[i][j] = false;
            dis[i][j] = 0;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        string number;
        cin >> number;
        for(int j = 1; j <= M; j++)
        {
            maze[i][j] = number[j-1] - '0';
        }
    }
    BFS(1,1);
    cout << dis[N][M] << endl;
}

void BFS(int a, int b)
{
    queue<pair<int, int>> q;
    visited[a][b] = true;
    q.push(make_pair(a,b));
    dis[a][b] = 1;
    while(!q.empty())
    {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            if(nowx + dx[i] > 0 && nowx + dx[i] <= N && nowy + dy[i] > 0 && nowy + dy[i] <= M)
            {
                if(maze[nowx + dx[i]][nowy + dy[i]] == 1)
                {
                    if(visited[nowx + dx[i]][nowy + dy[i]] == false)
                    {
                        q.push(make_pair(nowx+dx[i], nowy+dy[i]));
                        visited[nowx+dx[i]][nowy+dy[i]] = true;
                        dis[nowx + dx[i]][nowy + dy[i]] = dis[nowx][nowy] + 1;
                    }
                }
            }
        }
    }
}