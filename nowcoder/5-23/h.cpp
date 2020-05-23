/************************************************************
	> File Name: h.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 23 May 2020 04:09:02 PM CST
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
signed main(void){
	/*
	 * int t;
	 * for(scanf("%d",&t);t--;){
	 *     ll x,ans = 0;
	 *     scanf("%lld",&x);
	 *     for(ll i = 1;i <= x;i++){
	 *         for(ll j = sqrt(i);j >= 1;j--){
	 *             if(x%j==0){
	 *                 ans += (j+i/j)/2;
	 *                 break;
	 *             }
	 *         }
	 *     }
	 *     printf("%lld\n",ans);
	 * }
	 */
	for(int i = 1;i <= 30;i++){
		for(int j = sqrt(i);j >= 1;j--){
			if(i%j==0){
				if(j*j==i) printf("f(%d) = %d\n",i,j);
				else printf("f(%d) = %d\n",i,(j+i/j)/2);
				break;
			}
		}
	}
	return 0;
}
