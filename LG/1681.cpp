/************************************************************
	> File Name: 1681.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 25 Apr 2020 11:09:09 AM CST
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
const int N = 1503;
int a[N][N],b[N][N];
int n, m, ans;
signed main(void){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			cin >> a[i][j];
			if(j%2==i%2) a[i][j]^=1;
			b[i][j] = a[i][j]^1;
		}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(a[i][j])
				a[i][j] = min(a[i-1][j],min(a[i-1][j-1],a[i][j-1]))+1;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(b[i][j])
				b[i][j] = min(b[i-1][j],min(b[i-1][j-1],b[i][j-1]))+1;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			ans = max(ans,max(b[i][j],a[i][j]));
	cout << ans << endl;
	return 0;
}
