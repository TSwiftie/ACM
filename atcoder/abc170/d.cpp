/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 19 Jun 2020 10:15:34 AM CST
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
const int N = 2e5+10;
int a[N],n,ans,t[1000010];
bool ton[1000010];
signed main(void){
	IOS;
	cin >> n;
	for(int i = 1;i <= n;++i)
		cin >> a[i],++t[a[i]];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;++i){
		if(!ton[a[i]]){
			if(t[a[i]]==1) ++ans;
			for(int j = a[i];j <= 1000010;j+=a[i])
				ton[j] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}

