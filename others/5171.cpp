/************************************************************
	> File Name: 5171.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 28 Jun 2020 06:15:39 PM CST
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
int n,m,num[30][30],seq[30*30],t[30][30],cnt[30],last[30];
bool used[30][8000];
bool check(int st,int len,int mac){
    for(int i = st;i < st+len;++i) if(used[mac][i]) return false;
    return true;
}
signed main(void){
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= n*m;++i) scanf("%d",seq+i);
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j) scanf("%d",&num[i][j]);
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j) scanf("%d",&t[i][j]);
    for(int i = 1;i <= n*m;++i){
        ++cnt[seq[i]];
        int x = seq[i],y = cnt[seq[i]],z = num[x][y];
        for(int j = last[x];;++j){
            if(check(j,t[x][y],z)){
                for(int k = j;k < j+t[x][y];++k) used[z][k] = true;
                last[x] = j+t[x][y];
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;++i) ans = max(ans,last[i]);
    printf("%d\n",ans);
    return 0;
}
