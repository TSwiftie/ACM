/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 16 Mar 2020 01:55:00 PM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define range(x) x.begin(),x.end()
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
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
int d[MAXN],u[MAXN],v[MAXN],n,h,t;
signed main(void){
	scanf("%d",&n);
	h = 0,t = n-1;
	for(int i = 1;i < n;i++){
		scanf("%d%d",u+i,v+i);
		d[u[i]]++;d[v[i]]++;
	}
	for(int i = 1;i < n;i++){
		if(d[u[i]]==1||d[v[i]]==1) printf("%d\n",h++);
		else printf("%d\n",--t);
	}
	return 0;
}
