/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 19 Jul 2020 11:28:28 AM CST
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
const int N = 131100;
char ch[N];
int t, n;
int dfs(int st,int ed,char ap){
    if(st==ed) return ch[st]==ap ? 0 : 1;
    int pre = 0,suf = 0,mid = st + (ed-st+1)/2;
    for(int i = st;i < mid;++i)
        if(ch[i]!=ap) ++pre;
    for(int i = mid;i <= ed;++i)
        if(ch[i]!=ap) ++suf;
    return min(pre+dfs(mid,ed,ap+1),suf+dfs(st,mid-1,ap+1));
}
signed main(void){
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        scanf("%s",ch+1);
        printf("%d\n",dfs(1,n,'a'));
    }
    return 0;
}
