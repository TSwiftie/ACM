/************************************************************
	> File Name: h.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 18 May 2020 08:32:00 AM CST
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
int cnt[30];
signed main(void){
	char ch;
	while((ch=getchar())!=EOF){
		if(ch==' '||ch=='\n') continue;
		cnt[ch-'a']++;
	}
	int Max = -1;
	char ans;
	for(int i = 0;i < 26;i++){
		if(Max < cnt[i]){
			ans = 'a' + i;
			Max = cnt[i];
		}
	}
	printf("%c\n",ans);
	return 0;
}
