/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 05 Apr 2020 12:39:30 PM CST
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
const int N = 1e5+10;
int l[N];
ll suf[N];
signed main(void){
	int n, m, sum = 0;
	scanf("%d%d",&n,&m);
	bool mark = false;
	for(int i = 1;i <= m;i++){
		scanf("%d",l+i);
		if(l[i]+i-1 > n) mark = true;
	}
	for(int i = m;i >= 1;i--)
		suf[i] = suf[i+1] + l[i];
	if(suf[1] < n || mark) puts("-1");
	else{
		for(int i = 1;i <= m;i++)
			printf("%lld%c",max((ll)i,n-suf[i]+1)," \n"[i==m]);
	}
	return 0;
}
