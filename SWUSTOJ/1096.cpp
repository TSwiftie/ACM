/************************************************************
	> File Name: 1096.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 02:05:01 PM CST
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
int t[N],n;
void solve(){
	int Max = 0;
	for(int i = 0,x;i < n;i++){
		scanf("%d",&x);
		t[x]++;
		Max = Max > x ? Max : x;
	}
	for(int i = 0;i <= Max;i++)
		if(t[i]>10){
			printf("NO\r\n");
			return ;
		}
	printf("YES\r\n");
	return ;
}
signed main(void){
	while(~scanf("%d",&n)){
		solve();
		memset(t,0,sizeof t);
	}
	return 0;
}
