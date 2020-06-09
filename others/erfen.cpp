/************************************************************
	> File Name: erfen.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 09 Jun 2020 04:26:59 PM CST
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
int a[N],n;
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;++i)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	int t;
	scanf("%d",&t);
	while(t--){
		int k;
		scanf("%d",&k);
		int l = 1,r = n;
		while(l < r){
			int mid = (l+r)>>1;
			if(a[mid] >= k) r = mid;
			else l = mid+1;
		}
		printf("%d\n",a[l]);
	}
	return 0;
}
