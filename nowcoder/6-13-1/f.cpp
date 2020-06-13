/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 13 Jun 2020 01:58:57 PM CST
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
const int N = 22;
int a[N],p[N];
signed main(void){
	int n;
	double sum = 0;
	cin >> n;
	for(int i = 1;i <= n;++i)
		cin >> a[i];
	for(int i = 1;i <= n;++i){
		cin >> p[i];
		sum += p[i]*a[i];
	}
	sum *= 4;
	sum /= 10000;
	if(fabs(sum-4) < 0.01) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
