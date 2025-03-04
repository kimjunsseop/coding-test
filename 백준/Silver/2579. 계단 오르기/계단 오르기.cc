#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> D;
vector<int> in;

int main()
{
    int N;
    cin >> N;
    D.resize(N + 1);
    in.resize(N + 1);
    for(int i = 1; i <= N; i++)
    {
        cin >> in[i];
    }
    D[1] = in[1];
    D[2] = in[1] + in[2];
    for(int i = 3; i <= N; i++)
    {
        D[i] = in[i] + in[i - 1] + D[i - 3];
        if(D[i] < in[i] + D[i - 2])
        {
            D[i] = in[i] + D[i - 2];
        }
    }
    cout << D[N] << endl;
}