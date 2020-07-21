/************************************************************
	> File Name: 1009.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 21 Jul 2020 04:47:59 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 5e4+10;
struct node{
    int p,a;
    bool operator < (const node &x) const{
        if(p!=x.p) return p < x.p;
        return a < x.a;
    }
}s[N];
map<node,int>mp;
int sta[N];
bool judge(node x,node y,node z){
    return (x.p-y.p) * (z.a-x.a) <= (x.p-z.p) * (y.a-x.a);
}
signed main(void){
    int t,n;
    for(scanf("%lld",&t);t--;){
        scanf("%lld",&n);
        for(int i = 1;i <= n;++i){
            scanf("%lld%lld",&s[i].p,&s[i].a);
            ++mp[s[i]];
        }
        int top = 0;
        sort(s+1,s+1+n);
        for(int i = 1;i <= n;++i){
            while((top > 0 && s[sta[top]].a <= s[i].a)||(top >= 2 && judge(s[sta[top-1]],s[sta[top]],s[i]))) --top;
            sta[++top] = i;
        }
        int ans = top;
        for(int i = 1;i <= top;++i){
            if(mp[s[sta[i]]] > 1) --ans;
        }
        printf("%lld\n",ans);
        mp.clear();
    }
    return 0;
}
