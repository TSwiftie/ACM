#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 1e6+5;
char str[N],mo[N];int Next[N];
void getNext(){
    Next[0] = -1;int len = strlen(mo),k = -1;
    for(int i = 1;i < len;++i){
        while(k > -1 && mo[k+1]!=mo[i]) k = Next[k];
        if(mo[k+1]==mo[i]) ++k;
        Next[i] = k;
    }
}
int kmp(){
    getNext();int len1 = strlen(str),len2 = strlen(mo),k = -1,ans = 0;
    for(int i = 0;i < len1;++i){
        while(k > -1 && mo[k+1]!=str[i]) k = Next[k];
        if(mo[k+1]==str[i]) ++k;
        if(k==len2-1){ k = Next[k];++ans; }
    }
    return ans;
}
signed main(void){
    scanf("%s%s",str,mo);
    printf("%d\n",kmp());
    return 0;
}
