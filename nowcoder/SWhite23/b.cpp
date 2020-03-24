/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 24 Mar 2020 08:51:06 PM CST
************************************************************/

#include <cstring>
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define all(x) x.begin(),x.end()
#define pb push_back
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
int p,num[MAXN],prime[MAXN],k;
bool judge(int x){
	for(int i = 1;i <= k;i++){
		int n = x,num_prime = 0;
		while(n){
			num_prime += n/prime[i];
			n /= prime[i];
		}
		if(num_prime < num[i]) return false;
	}
	return true;
}
void solve(){
	int p;
	cin >> p;
	k = 0;
	for(int i = 2;i*i <= p;i++)
		if(p%i==0){
			prime[++k] = i;
			while(p%i==0){
				num[k]++;
				p /= i;
			}
		}
	if(p > 1) prime[++k] = p,num[k]++;
	int l = 1,r = 1e9,ans = 0,mid;
	while(l <= r){
		mid = (l+r)>>1;
		if(judge(mid)){
			r = mid-1;
			ans = mid;
		}else l = mid+1;
	}
	cout << ans << endl;
	memset(num, 0, sizeof num);
}
signed main(void){
	IOS;
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
