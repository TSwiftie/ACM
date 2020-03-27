/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 27 Mar 2020 09:58:15 AM CST
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
const int N = 2e5+10;
char ch[N];
vi pos;
void solve(){
	scanf("%s",ch+1);
	int len = strlen(ch+1);
	pos.push_back(0);
	for(int i = 1;i <= len;i++)
		if(ch[i]=='R')
			pos.push_back(i);
	pos.push_back(len+1);
	int Max = 1;
	for(int i = 0;i < SZ(pos)-1;i++)
		if(Max < pos[i+1]-pos[i])
			Max = pos[i+1]-pos[i];
	printf("%d\n",Max);
	pos.clear();
}
signed main(void){
	int _;
	for(scanf("%d",&_);_;_--)
		solve();
	return 0;
}
