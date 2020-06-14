/************************************************************
	> File Name: j.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 14 Jun 2020 10:58:54 PM CST
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
char ch[N],sh[N];
signed main(void){
	scanf("%s",ch+1);
	scanf("%s",sh+1);
	int n = strlen(ch+1),m = strlen(sh+1);
	if(n > m) printf(">\n");
	else if(n < m) printf("<\n");
	else{
		for(int i = 1;i <= n;++i){
			if(ch[i] > sh[i]){
				printf(">\n");
				return 0;
			}else if(ch[i] < sh[i]){
				printf("<\n");
				return 0;
			}
		}
		printf("=\n");
	}
	return 0;
}
