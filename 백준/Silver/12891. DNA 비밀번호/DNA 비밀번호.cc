#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<char> dna;

int main()
{
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    int count = 0;
    for(char a : s)
    {
        dna.push_back(a);
    }
    int A, C, G, T;
    cin >> A >> C >> G >> T;
    int a = A;
    int c = C;
    int g = G;
    int t = T;
    int start = 0;
    int end = M - 1;
    int i = start;
    while(end <= N - 1)
    {
        if(dna[i] == 'A')
        {
            a--;
        }
        else if(dna[i] == 'C')
        {
            c--;
        }
        else if(dna[i] == 'G')
        {
            g--;
        }
        else if(dna[i] == 'T')
        {
            t--;
        }
        if(i == end)
        {
            if(a <= 0 && c <= 0 && g <= 0 && t <= 0)
            {
                count++;
            }
            if(dna[start] == 'A')
            {
                a++;
            }
            else if(dna[start] == 'C')
            {
                c++;
            }
            else if(dna[start] == 'G')
            {
                g++;
            }
            else if(dna[start] == 'T')
            {
                t++;
            }
            end++;
            start++;
        }
        i++;
    }
    std::cout << count << endl;
}