/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 24 Mar 2020 10:28:01 AM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
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
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
int a[MAXN],b[MAXN];
signed main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,lim = -1;
		scanf("%d",&n);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		for(int i = 0;i < n;i++){
			int k, d = 0,p = 0;
			scanf("%d",&k);
			for(int j = 0;j < k;j++){
				int x;
				scanf("%d",&x);
				if(b[x-1]==0&&p==0){
					b[x-1]++;
					p++;
					d++;
				}
			}
			if(!d){
				a[i]++;
				lim = i;
			}
		}
		if(lim==-1) printf("OPTIMAL\n");
		else {
			printf("IMPROVE\n%d ",lim+1);
			for(int i = 0;i < n;i++){
				if(b[i]==0){
					printf("%d\n",i+1);
					break;
				}
			}
		}
	}
	return 0;
}
