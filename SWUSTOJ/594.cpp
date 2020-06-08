/************************************************************
	> File Name: 594.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 08 Jun 2020 07:00:31 PM CST
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
int n,s;
int w[605];
int path[605];
int dp[605][6005][2];
signed main(void){
    int i,j,k;
    while(~scanf("%d%d",&n,&s)){
        for(i=1;i<=n;i++)
            scanf("%d",&w[n+1-i]);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            for(j=0;j<=s;j++){
                if(w[i]<=j && dp[i-1][j][0]<dp[i-1][j-w[i]][0]+1){
                    dp[i][j][0]=dp[i-1][j-w[i]][0]+1;
                    dp[i][j][1]=dp[i-1][j-w[i]][1]+w[i];
                }
                else if(w[i]<=j && dp[i-1][j][0]==dp[i-1][j-w[i]][0]+1){
                    dp[i][j][0]=dp[i-1][j][0];
                    dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-w[i]][1]+w[i]);
                }
                else{
                    dp[i][j][0]=dp[i-1][j][0];
                    dp[i][j][1]=dp[i-1][j][1];
                }
            }
        }
        printf("%d %d\n",dp[n][s][0],dp[n][s][1]);
        i=n,j=dp[n][s][1],k=1;
        while(i){
            if(dp[i][j][0]==dp[i-1][j-w[i]][0]+1 && dp[i][j][1]==dp[i-1][j-w[i]][1]+w[i]){
                j-=w[i];
                path[k++]=w[i];
            }
            i--;
        }
        for(k=1;k<=dp[n][s][0];k++){
            if(k!=1) cout<<' ';
            cout<<path[k];
        }
        cout<<endl;
    }
    return 0;
}
