/************************************************************
	> File Name: td.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 11 Jun 2020 10:59:34 PM CST
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
signed main(void){
	for(int n = 1;n <= 1000;++n){
		int tmp = n;
		for(int i = 2;i*i <= tmp;++i){
			if(tmp%i==0){
				while(tmp%i==0) tmp /= i;
				break;
			}
		}
		int ot = n / tmp;
		if(__gcd(ot+tmp,n)==1&&tmp!=n&&tmp!=1)
			cout << n << ":" << "Yes " << ot << " " << tmp << endl;
		else cout << n << ":" << "No" << endl;
	}
	return 0;
}
