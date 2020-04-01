/************************************************************
	> File Name: 2776.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 04:40:20 PM CST
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
const int N = 1e7+10;
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int a[N];
queue<int>s,q[303];
signed main(void){
	int n = read(),m = read();
	for(int i = 0;i < n;i++)
		a[i] = read();
	int t = read(),x;
	while(t--){
		string str;
		cin >> str;
		if(str=="push"){
			x = read();
			if(q[a[x]].empty())
				s.push(a[x]);
			q[a[x]].push(x);
		}else{
			printf("%d\n",q[s.front()].front());
			q[s.front()].pop();
			if(q[s.front()].empty())
				s.pop();
		}
	}
	return 0;
}
