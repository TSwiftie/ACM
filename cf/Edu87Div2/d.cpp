/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 10:51:24 AM CST
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
const int N = 1e6+10;
int a[N],k[N],n,q;
int query(int x){
	int ret = 0;
	for(int i = 1;i <= n;i++) if(a[i] <= x) ret++;
	for(int i = 1;i <= q;i++){
		if(k[i] > 0 && k[i] <= x) ret++;
		if(k[i] < 0 && -k[i] <= ret) ret--;
	}
	return ret;
}
signed main(void){
	IOS;
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= q;i++) cin >> k[i];
	int l = 0,r = 1000001;
	while(l < r-1){
		int mid = (l+r)>>1;
		if(query(mid)>0) r = mid;
		else l = mid;
	}
	if(r==1000001) cout << 0 << endl;
	else cout << r << endl;
	return 0;
}
