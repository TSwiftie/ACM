/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 01:27:09 PM CST
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
const int N = 2e5+10;
int p[N];
int ans[N][2];
int cnt;
bool vis[N];
bool judge(int *a,int n){
	for(int i = 1;i <= n;i++) vis[i] = false;
	for(int i = 0;i < n;i++) vis[a[i]] = true;
	for(int i = 1;i <= n;i++)
		if(!vis[i]) return false;
	return true;
}
bool judge(int len1,int n){
	return judge(p,len1) && judge(p+len1,n-len1);
}
signed main(void){
	int t;
	for(scanf("%d",&t);t;t--){
		int n;
		scanf("%d",&n);
		int Max = 0;
		cnt = 0;
		for(int i = 0;i < n;i++)
			scanf("%d",p+i),Max = max(Max,p[i]);
		if(judge(n-Max,n)){
			ans[cnt][0] = n-Max;
			ans[cnt++][1] = Max;
		}
		if(Max<<1!=n && judge(Max,n)){
			ans[cnt][0] = Max;
			ans[cnt++][1] = n-Max;
		}
		printf("%d\n",cnt);
		for(int i = 0;i < cnt;i++)
			printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
