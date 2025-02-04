#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> lope;
vector<int> result;
bool compare(const int a, const int b);

int main()
{
    int N;
    cin >> N;
    lope.resize(N);
    result.resize(N);
    for(int i = 0; i < N; i++)
    {
        int weight;
        cin >> weight;
        lope[i] = weight;
    }
    sort(lope.begin(), lope.end(), compare);
    int start = 0;
    int end = N - 1;
    while(start <= end)
    {
        result[start] = N * lope[start];
        start++;
        N--;
    }
    sort(result.begin(), result.end(), compare);
    cout << result[end] << endl;
}

bool compare(const int a, const int b)
{
    return b > a;
}