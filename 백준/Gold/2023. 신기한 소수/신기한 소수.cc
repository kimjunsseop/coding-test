#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(int s, int d);
bool isPrime(int n);

int N;

int main()
{
    cin >> N;
    for(int i = 1; i <= 9; i++)
    {
        if(isPrime(i))
        {
            DFS(i, 1);
        }
    }
}

bool isPrime(int n)
{
    if(n < 2)
    {
        return false;
    }
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void DFS(int s, int d)
{
    if(d == N)
    {
        cout << s << endl;
    }
    if(isPrime(s))
    {
        for(int i = 0; i <= 9; i++)
        {
            if(isPrime(10 * s + i))
            {
                DFS(10 * s + i, d + 1);
            }
        }
    }
}
