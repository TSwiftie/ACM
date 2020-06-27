/************************************************************
	> File Name: string.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 27 Jun 2020 07:34:04 AM CST
************************************************************/
#include <cctype>
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
mt19937 rnd(time(0));
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
char ch[N];
double ans;
int cnt;
bool neg = false,isU = false;
signed main(void){
    scanf("%s",ch+1);
    int len = strlen(ch+1);
    for(int i = 1;i <= len;++i){
        if(ch[i]=='-') neg = true;
        else if(ch[i]=='.'&&i>1&&i<len&&isdigit(ch[i-1])&&isdigit(ch[i+1])) ++cnt;
        else if(isdigit(ch[i])&&!cnt) ans = ans * 10 + (ch[i]-'0');
        else if(isdigit(ch[i])&&cnt) ans += pow(0.1,cnt)*(ch[i]-'0'),cnt++;
        else if(ch[i]=='%'&&i>1&&isdigit(ch[i-1])) ans *= 0.01,isU = true;
        else if(i>1&&(isdigit(ch[i-1])||(ch[i-1]=='%'&&isU))){
            printf("%lf\n",ans);
            ans = cnt = neg = isU = 0;
        }
    }
    if(isdigit(ch[len])||(ch[len]=='%'&&isU)) printf("%lf\n",ans);
    return 0;
}
