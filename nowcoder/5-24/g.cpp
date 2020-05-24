/************************************************************
	> File Name: g.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 24 May 2020 02:35:51 PM CST
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
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int fac[13];
signed main(void){
	IOS;
	ll n;
	while(cin >> n){
		if(n%10==n){
			cout << n+10 << endl;
			continue;
		}
		for(int i = 9;i >= 2;i--){
			if(n%i==0){
				while(n%i==0){
					n /= i;
					fac[i]++;
				}
			}
		}
		if(n!=1) cout << -1 << endl;
		else{
			for(int i = 2;i <= 9;i++)
				while(fac[i]--) cout << i;
			cout << endl;
		}
		memset(fac,0,sizeof fac);
	}
	return 0;
}
