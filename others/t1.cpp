/************************************************************
	> File Name: te.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 17 Jun 2020 05:56:11 PM CST
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
const int N = 1e5+10;
string dict;
string str[N];
int cp[255],n;
bool cmp(const string &a,const string &b){
	int la = SZ(a),lb = SZ(b),len = max(la,lb);
	for(int i = 0;i < len;++i){
		if(i > la) return true;
		else if(i > lb) return false;
		else if(cp[a[i]] == cp[b[i]]) continue;
		else return cp[a[i]] < cp[b[i]];
	}
}
signed main(void){
	cin >> dict;
	for(int i = 0;i < SZ(dict);++i){
		cp[dict[i]] = i;
		cp[dict[i]-32] = i+26;
	}
	cin >> n;
	for(int i = 1;i <= n;++i)
		cin >> str[i];
	sort(str+1,str+1+n,cmp);
	for(int i = 1;i <= n;++i)
		cout << str[i] << endl;
	return 0;
}
