/************************************************************
	> File Name: So_Easy.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 21 Apr 2020 01:46:52 PM CST
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
const int N = 1e3+10;
int n;
int a[N][N];
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			scanf("%d",&a[i][j]);
	for(int i = 1;i <= n;i++){
		int Min = INF;
		for(int j = 1;j <= n;j++){
			if(a[i][j] < 0) continue;
			if(a[i][j] < Min) Min = a[i][j];
		}
		if(Min==0) continue;
		for(int j = 1;j <= n;j++) a[i][j] -= Min;
	}
	for(int i = 1;i <= n;i++){
		int Min = INF;
		for(int j = 1;j <= n;j++){
			if(a[j][i] < 0) continue;
			if(a[j][i] < Min) Min = a[j][i];
		}
		if(Min==0) continue;
		for(int j = 1;j <= n;j++) a[j][i] -= Min;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(a[i][j] < 0) ans = -a[i][j]-1;
	printf("%d\n",ans);
	return 0;
}
