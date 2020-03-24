/************************************************************
	> File Name: i.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 24 Mar 2020 08:26:18 PM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define all(x) x.begin(),x.end()
#define pb push_back
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
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
string str;
string lis[MAXN];
int cnt;
signed main(void){
	IOS;
	cin >> str;
	int len = str.size();
	char Max = str[0];
	for(int i = 1;i < len;i++)
		if(Max < str[i]) 
			Max = str[i];
	for(int i = 0;i < len;i++)
		if(str[i]==Max)
			lis[++cnt] = str.substr(i);
	sort(lis+1,lis+1+cnt);
	cout << lis[cnt] << endl;
	return 0;
}
