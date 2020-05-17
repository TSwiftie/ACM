/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 17 May 2020 05:30:52 PM CST
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
char ch[N];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%s",ch+1);
		int len = strlen(ch+1),ans = len;
		bool e1 = false,e2 = false,e3 = false;
		for(int i = 1;i <= len;i++){
			e1 |= ch[i]=='1';
			e2 |= ch[i]=='2';
			e3 |= ch[i]=='3';
		}
		if(e1&&e2&&e3){
			int l = 1,r = 1,s1 = 0,s2 = 0,s3 = 0;
			s1 += ch[1]=='1';
			s2 += ch[1]=='2';
			s3 += ch[1]=='3';
			while(true){
				if(s1&&s2&&s3)
					ans = min(ans,r-l+1);
				if(ch[l]=='1'&&s1>1) l++,s1--;
				else if(ch[l]=='2'&&s2>1) l++,s2--;
				else if(ch[l]=='3'&&s3>1) l++,s3--;
				else if(r+1<=len&&ch[r+1]=='1') s1++,r++;
				else if(r+1<=len&&ch[r+1]=='2') s2++,r++;
				else if(r+1<=len&&ch[r+1]=='3') s3++,r++;
				else break;
			}
			printf("%d\n",ans);
		}else printf("0\n");
	}
	return 0;
}
