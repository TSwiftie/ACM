/************************************************************
	> File Name: 2141.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 02:48:47 PM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) (x.begin(),x.end())
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
const int N = 105;
int a[N],vis[N*10000],t[N*10000];
signed main(void){
	int n,ans = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i),vis[a[i]] = 1;
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			t[a[i]+a[j]]++;
	for(int i = 1;i <= n;i++)
		if(t[a[i]]) ans++;
	printf("%d\n",ans);
	return 0;
}
