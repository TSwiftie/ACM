/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 06 Jun 2020 11:30:10 AM CST
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
const int N = 2e5+10;
int n;
struct Node{
	int a,b;
}s[N];
bool cmp(Node &x,Node &y){
	return x.a-x.b > y.a-y.b;
}
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;++i) scanf("%d",&s[i].a);
	for(int i = 1;i <= n;++i) scanf("%d",&s[i].b);
	sort(s+1,s+1+n,cmp);
	int x = s[1].b;
	int ans = 0;
	for(int i = 2;i <= n;++i){
		ans = max(ans,x+s[i].a);
		x = max(x,s[i].b);
	}
	printf("%d\n",ans);
	return 0;
}
