/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 19 Jul 2020 07:28:30 PM CST
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
int da[110][110];
int n;
ll res;
bool vis[50];
void dfs(int a,int b,ll val = 0){
    if(b==n/2){
        res = max(res,val);
        return ;
    }
    for(int i = a;i <= n/2+b+1;++i){
        ll inc = 0;
        if(b==0&&i!=1) return ;
        for(int j = 1;j <= n;++j){
            if(vis[j]) inc -= da[i][j];
            else inc += da[i][j];
        }
        vis[i] = true;
        dfs(i+1,b+1,val+inc);
        vis[i] = false;
    }
}
signed main(void){
    scanf("%d",&n);
    n <<= 1;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            scanf("%d",&da[i][j]);
    memset(vis,false,sizeof vis);
    dfs(1,0);
    cout << res << endl;
    return 0;
}
