/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 02 Jun 2020 09:27:42 AM CST
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
int n,a[N],b[N];
signed main(void){
	while(~scanf("%d",&n)){
		for(int i = 1;i <= n;++i) scanf("%d",a+i);
		for(int i = 1;i <= n;++i) scanf("%d",b+i);
		stack<int>sa,sb;
		sa.push(1);sb.push(1);
		int ans = n;
		for(int i = 2;i <= n;++i){
			while(!sa.empty() && a[sa.top()] > a[i]) sa.pop();
			sa.push(i);
			while(!sb.empty() && b[sb.top()] > b[i]) sb.pop();
			sb.push(i);
			if(sa.size()!=sb.size()){
				ans = i-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
