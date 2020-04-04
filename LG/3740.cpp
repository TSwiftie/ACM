/************************************************************
	> File Name: 3740.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 03:00:55 PM CST
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
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const ll INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 1e7+10,M = 1005;
int n, m, ans,cur,A[M],B[M];
bool vis[M];
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
void solve(int a,int b,int now){
	if(vis[cur]) return ;
	while(now <= m && (a>=B[now]||b<=A[now]))
		now++;
	if(now > m)
		ans++,vis[cur] = true;
	if(a<A[now]&&A[now]<b) solve(a,A[now],now+1);
	if(b>B[now]&&B[now]>a) solve(B[now],b,now+1);
}
signed main(void){
	n = read();
	m = read();
	for(int i = 1;i <= m;i++)
		A[i] = read(),B[i] = read(),++B[i];
	for(cur = m-1;cur >= 1;cur--)
		solve(A[cur],B[cur],cur+1);
	printf("%d\n",++ans);
	return 0;
}
