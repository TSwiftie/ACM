/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 12 Apr 2020 11:50:03 PM CST
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
ll solve(ll pos,ll n){
	vi res;
	n--;
	while(n){
		res.push_back(n%4);
		n /= 4;
	}
	while(SZ(res) < pos) res.push_back(0);
	for(int i = 0;i < SZ(res);i++){
		if(res[i]==0) res[i] = 0;
		else if(res[i]==1) res[i] = 2;
		else if(res[i]==2) res[i] = 3;
		else if(res[i]==3) res[i] = 1;
	}
	ll t = 0;
	for(int i = 0;i < SZ(res);i++)
		t += (1LL<<(i<<1))*res[i];
	pos = pos*2+1;
	return (1LL<<pos) + t;
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		ll n;
		scanf("%lld",&n);
		if(n%3==1){
			n = n/3 + 1;
			ll cnt = 0;
			for(int i = 0;i <= 62;i+=2){
				cnt += (1LL<<i);
				if(cnt >= n){
					cnt -= (1LL<<i);
					n -= cnt;
					printf("%lld\n",(1LL<<i)+n-1);
					break;
				}
			}
		}else if(n%3==2){
			n = n/3 + 1;
			ll cnt = 0;
			for(int i = 0;i <= 62;i+=2){
				cnt += (1LL<<i);
				if(cnt>=n){
					cnt-=(1LL<<i);
					n -= cnt;
					printf("%lld\n",solve(i>>1,n));
					break;
				}
			}
		}else{
			ll t1,t2;
			n = n/3;
			ll tmp = n;
			ll cnt = 0;
			for(int i = 0;i <= 62;i+=2){
				cnt += (1LL<<i);
				if(cnt>=tmp){
					cnt -= (1LL<<i);
					tmp -= cnt;
					t1 = (1LL<<i) + tmp -1;
					break;
				}
			}
			cnt = 0;
			for(int i = 0;i <= 62;i+=2){
				cnt += (1LL<<i);
				if(cnt >= n){
					cnt -= (1LL<<i);
					n -= cnt;
					t2 = solve(i>>1,n);
					break;
				}
			}
			printf("%lld\n",t1^t2);
		}
	}
	return 0;
}
