/************************************************************
	> File Name: 2866.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 09 Apr 2020 09:35:15 PM CST
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
const int N = 1e6;
bool judge(int x){
	for(int i = 2;i*i <= x;i++)
		if(x%i==0) return false;
	return true;
}
signed main(void){
	int L,ans;
	while(~scanf("%d",&L)){
		ans = 0;
		for(int i = 1;3*i*i+3*i+1 <= L;i++)
			if(judge(3*i*i+3*i+1)) ans++;
		if(ans==0) printf("No Special Prime!\n");
		else printf("%d\n",ans);
	}
	return 0;
}
