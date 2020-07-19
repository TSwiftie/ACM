/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 19 Jul 2020 08:40:09 PM CST
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
const int N = 40;
map<ll,string>mp1,mp2;
int n;
bool vis[N];
ll k[N],sum;
void dfs(int now,int ed,ll ans){
    if(now==ed){
        string res = "";
        if(ed==n){
            for(int i = n/2;i < n;++i) res += (vis[i]+'0');
            mp2[ans] = res;
        }else{
            for(int i = 0;i < n/2;++i) res += (vis[i]+'0');
            mp1[ans] = res;
        }
        return ;
    }
    vis[now] = true;
    dfs(now+1,ed,ans+k[now]);
    vis[now] = false;
    dfs(now+1,ed,ans);
}
signed main(void){
    scanf("%d%lld",&n,&sum);
    for(int i = 0;i < n;++i) scanf("%lld",k+i);
    dfs(0,n/2,0);
    memset(vis,false,sizeof vis);
    dfs(n/2,n,0);
    for(auto it : mp1)
        if(mp2[sum-it.first]!="")
            cout << it.second << mp2[sum-it.first];
    return 0;
}
