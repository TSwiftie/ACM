#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N = 1e6+7;
const int inf = 0x3f3f3f3f;
int tb[30];
int bm(char str[], char text[])
{
    int ls = strlen(str), lt = strlen(text);
    for(int i = 0; i < ls - 1; i++)
    {
        tb[str[i] - 'A'] = ls - i - 1;
    }
    int p = ls - 1;
    while(p < lt)
    {
        int k = 0;
        while(str[ls - k - 1] == text[p - k] && k <= ls)
        {
            k++;
        }
        if(k == ls)
        {
            return p - ls + 1;
        }
        else p += tb[text[p] - 'A'];
    }
    return -1;
}
int main()
{
    char str[N], text[N];
    cin >> str >> text;
    cout << bm(str, text) << endl;
    return 0;
}

