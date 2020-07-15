/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月15日 星期三 10时49分24秒
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
const int N = 1e5+10;
stack<int>st;
int n, m, a[N];
bool vis[N];
vi ans;
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i) scanf("%d",a+i);
    for(int i = 1,x;i <= m;++i){
        scanf("%d",&x);
        st.push(x);
    }
    while(st.size()){
        if(!vis[st.top()]){
            ans.push_back(st.top());
            vis[st.top()] = true;
        }
        st.pop();
    }
    for(int i = 1;i <= n;++i)
        if(!vis[i]) ans.push_back(i);
    for(int i = 0;i < SZ(ans);++i)
        printf("%d ",ans[i]);
    return 0;
}
