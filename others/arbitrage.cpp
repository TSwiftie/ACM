/************************************************************
	> File Name: arbitrage.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 28 Jun 2020 09:35:35 AM CST
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
int n,m,cnt;
double e[35][35];
map<string,int>dr;
signed main(void){
    while(cin >> n,n){
        bool mark = false;
        memset(e,1,sizeof e);
        double d;
        string ch,sh;
        for(int i = 1;i <= n;++i){
            cin >> ch;
            dr[ch] = i;
        }
        cin >> m;
        for(int i = 1;i <= m;++i){
            cin >> ch >> d >> sh;
            e[dr[ch]][dr[sh]] = d;
        }
        for(int k = 1;k <= n;++k)
            for(int i = 1;i <= n;++i)
                for(int j = 1;j <= n;++j)
                    e[i][j] = max(e[i][j],e[i][k]*e[k][j]);
        for(int i = 1;i <= n;++i)
            if(e[i][i]>1){
                mark = true;
                break;
            }
        cout << "Case " << ++cnt << " " << (mark?"Yes":"No") << endl;
    }
    return 0;
}
