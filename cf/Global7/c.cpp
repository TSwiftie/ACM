/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 22 Mar 2020 11:11:38 AM CST
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
const int MAXN = 2e5+5;
const int MAXM = 2e5+5;
const int MOD = 998244353;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
int p[MAXN],n,k;
int pos[MAXN],cnt;
signed main(void){
	scanf("%d%d",&n,&k);
	ll sum = 0,ans = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d",p+i);
		if(p[i] > n-k) pos[++cnt] = i,sum += p[i];
	}
	for(int i = 1;i < cnt;i++)
		ans = ans*(pos[i+1]-pos[i])%MOD;
	printf("%lld %lld\n",sum,ans);
	return 0;
}
