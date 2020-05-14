/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 14 May 2020 02:28:08 PM CST
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
const int N = 1e3+10;
char ch[N];
vi ap[30];
signed main(void){
	int t;
	scanf("%d",&t);
	for(int cas = 1;cas <= t;cas++){
		scanf("%s",ch);
		int n = strlen(ch);
		for(int i = 0;i < n;i++)
			ap[ch[i]-'a'].push_back(i);
		int ans = n-1;
		for(int i = 0;i < 26;i++){
			if(SZ(ap[i]) <= 1) continue;
			for(int j = 0;j < SZ(ap[i])-1;j++)
				ans = min(ans,ap[i][j+1]-ap[i][j]);
		}
		printf("Case #%d: %d\n",cas,ans==n-1?-1:ans);
		for(int i = 0;i < 26;i++) ap[i].clear();
	}
	return 0;
}
