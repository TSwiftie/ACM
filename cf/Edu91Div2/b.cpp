/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月14日 星期二 09时04分27秒
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
signed main(void){
    IOS;
    int t;
    string str;
    for(cin >> t;t--;){
        cin >> str;
        int n = str.size();
        int s = 0,p = 0,r = 0;
        for(int i = 0;i < n;++i){
            if(str[i]=='R') ++r;
            else if(str[i]=='S') ++s;
            else ++p;
        }
        string ans = "";
        if(s >= p && s >= r)
            for(int i = 0;i < n;++i) ans += "R";
        else if(p >= s && p >= r)
            for(int i = 0;i < n;++i) ans += "S";
        else if(r >= s && r >= p)
            for(int i = 0;i < n;++i) ans += "P";
        cout << ans << endl;
    }
    return 0;
}
