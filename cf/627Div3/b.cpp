/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 27 Mar 2020 09:51:10 AM CST
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
const int N = 5006;
int a[N],n;
vi pos[N];
void solve(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i),pos[a[i]].push_back(i);
	for(int i = 1;i <= n;i++){
		int Size = SZ(pos[a[i]]);
		if(Size >= 3){
			printf("YES\n");
			return ;
		}
		for(int j = 0;j < SZ(pos[a[i]])-1;j++)
			if(pos[a[i]][j+1]-pos[a[i]][j]>=2){
				printf("YES\n");
				return ;
			}
	}
	printf("NO\n");
	return ;
}
signed main(void){
	int _;
	for(scanf("%d",&_);_;_--){
		solve();
		for(int i = 1;i <= n;i++)
			pos[i].clear();
	}
	return 0;
}
