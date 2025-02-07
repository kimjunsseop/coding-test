#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> D;

int main()
{
    long long N, K;
    cin >> N >> K;
    D.resize(N + 1);
    for(int i = 1; i <= N ; i++)
    {
        D[i].resize(N + 1);
    }
    for(int i = 1; i <= N; i++)
    {
        D[i][0] = 1;
        D[i][i] = 1;
        D[i][1] = i;
    }
    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j < i; j++)
        {
            D[i][j] = (D[i-1][j] + D[i-1][j-1]) % 10007;
        }
    }
    cout << D[N][K] << endl;
}