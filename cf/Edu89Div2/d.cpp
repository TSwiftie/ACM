/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 13 Jun 2020 10:48:19 AM CST
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
const int N = 1e7;
int p[N+10],n,a[500005],b[500005];
signed main(void){
	IOS;
	p[1] = 1;
	for(int i = 2;i <= N;++i)
		if(!p[i]){
			p[i] = i;
			for(int j = i*i;j <= N;j+=i)
				if(!p[j])
					p[j] = i;
		}
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		int tmp = p[a[i]],t = a[i];
		if(tmp==a[i])
			a[i] = b[i] = -1;
		else{
			while(a[i]%tmp==0) a[i] /= tmp;
			if(a[i]==1) a[i] = b[i] = -1;
			else b[i] = t / a[i];
		}
	}
	for(int i = 1;i <= n;++i)
		cout << a[i] << " ";
	cout << endl;
	for(int i = 1;i <= n;++i)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}
