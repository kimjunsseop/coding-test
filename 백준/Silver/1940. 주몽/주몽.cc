#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
    int N, M;
    cin >> N;
    cin >> M;
    arr.resize(N + 1);
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int start = 1;
    int end = N;
    int count = 0;
    while(start < end)
    {
        if(arr[start] + arr[end] < M)
        {
            start++;
        }
        else if(arr[start] + arr[end] > M)
        {
            end--;
        }
        else
        {
            start++;
            end--;
            count++;
        }

    }
    cout << count << endl;
}
