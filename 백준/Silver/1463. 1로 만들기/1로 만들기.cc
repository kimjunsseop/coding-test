#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<int> D;

int main()
{
    int N;
    cin >> N;
    D.resize(N + 1);
    D[1] = 0;
    fill(D.begin(), D.end(), 0);
    for (int i = 2; i <= N; i++)
    {
        D[i] = D[i - 1] + 1;
        if (i % 2 == 0)
        {
            if (D[i] > D[i / 2] + 1)
            {
                D[i] = D[i / 2] + 1;
            }
        }
        if (i % 3 == 0)
        {
            if (D[i] > D[i / 3] + 1)
            {
                D[i] = D[i / 3] + 1;
            }
        }
    }
    cout << D[N] << endl;
}