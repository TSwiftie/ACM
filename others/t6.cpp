/************************************************************
	> File Name: t6.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 17 Jun 2020 06:38:02 PM CST
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
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'0'||ch<'9';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
struct Query{
	int l,r,id;
}s[N];
int sum,cnt[1000006];
int ans[N],a[N],belong[N];
bool cmp(const Query &a,const Query &b){
	if(belong[a.l]==belong[b.l]) return a.r < b.r;
	else return belong[a.l] < belong[b.l];
}
signed main(void){
	int n, q;
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;++i){
		scanf("%d",a+i);
	}
	for(int i = 1;i <= q;++i)
		scanf("%d%d",&s[i].l,&s[i].r),s[i].id = i;
	return 0;
}
//dp[i][0] = (dp[i-1][1]+dp[i-k][])
