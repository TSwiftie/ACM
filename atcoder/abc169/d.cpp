/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 08:11:26 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
const int N = 1e5+10;
int fac[N][2],cnt;
signed main(void){
	IOS;
	int n;
	cin >> n;
	for(int i = 2;i*i <= n;++i)
		if(n%i==0){
			++cnt;
			fac[cnt][0] = i;
			while(n%i==0) ++fac[cnt][1],n/=i;
		}
	if(n!=1){
		++cnt;
		fac[cnt][0] = n;
		fac[cnt][1] = 1;
	}
	int ans = 0;
	for(int i = 1;i <= cnt;++i){
		int st = 0;
		while(st*(st+1)/2 <= fac[i][1]) ++st;
		--st;
		ans += st;
	}
	cout << ans << endl;
	return 0;
}
