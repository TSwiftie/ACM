/************************************************************
	> File Name: 601.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 30 Mar 2020 05:55:54 PM CST
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
const int N = 1e5+10;
char ch[N];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%s",ch+1);
		int len = strlen(ch+1);
		for(int i = 1;i <= len;i++){
			if(isupper(ch[i]))
				printf("%c",tolower(ch[i]));
			else if(islower(ch[i]))
				printf("%c",toupper(ch[i]));
			else printf("@");
		}
		printf("\n");
	}
	return 0;
}
