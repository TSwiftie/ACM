/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 28 Mar 2020 09:49:14 AM CST
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
ll res;
int a[N],n,cnt[34];
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",a+i);
	for(int i = 1;i <= n;i++)
		for(int j = 0;j < 30;j++)
			if(a[i]&(1<<j)) cnt[j]++;
	for(int i = 0;i < 30;i++) res += 1ll*cnt[i]*cnt[i]*(1<<i);
	printf("%lld\n",res);
	return 0;
}
