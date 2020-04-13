/************************************************************
	> File Name: 2301.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 13 Apr 2020 03:23:11 PM CST
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
const int N = 50000;
int mu[N+5],p[N+5];
bool vis[N+5];
void init(){
	int tot = 0;
	mu[1] = 1;
	for(int i = 2;i <= N;i++){
		if(!vis[i]){
			p[++tot] = i;
			mu[i] = -1;
		}
		for(int j = 1;j <= tot&&i*p[j] <= N;j++){
			vis[i*p[j]] = 1;
			if(i%p[j]==0){
				mu[i*p[j]] = 0;
				break;
			}
			mu[i*p[j]] = -mu[i];
		}
	}
	for(int i = 1;i <= N;i++) mu[i] += mu[i-1];
}
int solve(int n,int m){
	int res = 0;
	for(int l = 1,r;l <= min(n,m);l = r+1){
		r = min(n/(n/l),m/(m/l));
		res += (mu[r]-mu[l-1])*(n/l)*(m/l);
	}
	return res;
}
signed main(void){
	int T,a,b,c,d,k;
	init();
	for(scanf("%d",&T);T;T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("%d\n",solve(b/k,d/k)-solve(b/k,(c-1)/k)-solve((a-1)/k,d/k)+solve((a-1)/k,(c-1)/k));
	}
	return 0;
}
