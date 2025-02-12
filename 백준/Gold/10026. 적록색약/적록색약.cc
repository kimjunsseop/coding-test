#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> map;
vector<vector<bool>> visited;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N;
int RGarea, Rarea, Garea, Barea;
int A, B;

void RGBFS(int x, int y);
void RBFS(int x, int y);
void GBFS(int x, int y);
void BBFS(int x, int y);


int main()
{
    
    cin >> N;
    map.resize(N + 1);
    visited.resize(N + 1);
    for(int i = 1; i <= N; i++)
    {
        map[i].resize(N + 1);
        visited[i].resize(N + 1);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            char a;
            cin >> a;
            map[i][j] = a;
            visited[i][j] = false;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(map[i][j] == 'R' || map[i][j] == 'G')
            {
                if(visited[i][j] == false)
                {
                    RGBFS(i, j);    
                }
                
            }
            else
            {
                if(visited[i][j] == false)
                {    
                    BBFS(i, j);
                }
            }
        }
    }
    B = RGarea + Barea;
    RGarea = 0;
    Barea = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            visited[i][j] = false;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(map[i][j] == 'R')
            {
                if(visited[i][j] == false)
                {    
                    RBFS(i, j);
                }
            }
            else if(map[i][j] == 'G')
            {
                if(visited[i][j] == false)
                {    
                    GBFS(i, j);
                }
            }
            else
            {
                if(visited[i][j] == false)
                {    
                    BBFS(i, j);
                }
            }
        }
    }
    A = Rarea + Garea + Barea;
    std::cout << A << " " << B << endl;
}

void RGBFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty())
    {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            if(nowx + dx[i] > 0 && nowx + dx[i] <= N && nowy + dy[i] > 0 && nowy + dy[i] <= N)
            {
                if(visited[nowx + dx[i]][nowy + dy[i]] == false)
                {
                    if(map[nowx + dx[i]][nowy + dy[i]] == 'R' || map[nowx + dx[i]][nowy + dy[i]] == 'G')
                    {
                        q.push(make_pair(nowx + dx[i], nowy + dy[i]));
                        visited[nowx + dx[i]][nowy + dy[i]] = true;
                    }
                }
            }
        }
    }
    RGarea++;
}

void RBFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty())
    {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            if(nowx + dx[i] > 0 && nowx + dx[i] <= N && nowy + dy[i] > 0 && nowy + dy[i] <= N)
            {
                if(visited[nowx + dx[i]][nowy + dy[i]] == false)
                {
                    if(map[nowx + dx[i]][nowy + dy[i]] == 'R')
                    {
                        q.push(make_pair(nowx + dx[i], nowy + dy[i]));
                        visited[nowx + dx[i]][nowy + dy[i]] = true;
                    }
                }
            }
        }
    }
    Rarea++;
}

void GBFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty())
    {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            if(nowx + dx[i] > 0 && nowx + dx[i] <= N && nowy + dy[i] > 0 && nowy + dy[i] <= N)
            {
                if(visited[nowx + dx[i]][nowy + dy[i]] == false)
                {
                    if(map[nowx + dx[i]][nowy + dy[i]] == 'G')
                    {
                        q.push(make_pair(nowx + dx[i], nowy + dy[i]));
                        visited[nowx + dx[i]][nowy + dy[i]] = true;
                    }
                }
            }
        }
    }
    Garea++;
}

void BBFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty())
    {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            if(nowx + dx[i] > 0 && nowx + dx[i] <= N && nowy + dy[i] > 0 && nowy + dy[i] <= N)
            {
                if(visited[nowx + dx[i]][nowy + dy[i]] == false)
                {
                    if(map[nowx + dx[i]][nowy + dy[i]] == 'B')
                    {
                        q.push(make_pair(nowx + dx[i], nowy + dy[i]));
                        visited[nowx + dx[i]][nowy + dy[i]] = true;
                    }
                }
            }
        }
    }
    Barea++;
}