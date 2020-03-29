/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 29 Mar 2020 12:03:54 PM CST
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
const int N = 103;
int bit[N],cnt;
signed main(void){
	int t;
	for(scanf("%d",&t);t;t--){
		int n, k, MaxIndex = 0;
		cnt = 0;
		ll x;
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&x);
			cnt = 0;
			while(x){
				bit[++cnt] += x%k;
				x /= k;
			}
			MaxIndex = max(MaxIndex,cnt);
		}
		bool mark = false;
		for(int i = 1;i <= MaxIndex;i++)
			if(bit[i]!=0&&bit[i]!=1){
				mark = true;
				break;
			}
		if(!mark) printf("YES\n");
		else printf("NO\n");
		memset(bit,0,sizeof bit);
	}
	return 0;
}
