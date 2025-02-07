#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> D;
int N, M;

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> N >> M;
        D.resize(31);
        for(int i = 0; i <= 30; i++)
        {
            D[i].resize(31);
        }
        for(int i = 1; i <= 30; i++)
        {
            D[i][0] = 1;
            D[i][i] = 1;
            D[i][1] = i;
        }
        for(int i = 1; i <= 30; i++)
        {
            for(int j = 2; j < i; j++)
            {
                D[i][j] = D[i-1][j] + D[i-1][j-1];
            }
        }
        cout << D[M][N] << endl;
    }
}