/************************************************************
	> File Name: 7.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 28 Mar 2020 01:42:23 PM CST
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
const int N = 1e6;
ll prime[N+4];
bool vis[N+5];
void init(){
	for(ll i = 2;i <= N;i++){
		if(!vis[i]) prime[++prime[0]] = i;
		for(ll j = 1;j <= prime[0] && i*prime[j] <= N;j++){
			vis[i*prime[j]] = true;
			if(i%prime[j]==0) break;
		}
	}
}
signed main(void){
	init();
	printf("%lld\n",prime[10001]);
	return 0;
}
