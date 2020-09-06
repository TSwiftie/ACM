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
string str;int n;
signed main(void){
    IOS;
    while(cin >> n){
        cin >> str;
        int len = str.length();
        if(str[len-1]=='a') { cout << str+"a" << endl; }
        else if(str[len-1]=='i'||str[len-1]=='y') { cout << str.substr(0,len-1) + "ios" << endl; }
        else if(str[len-1]=='l') { cout << str.substr(0,len-1)+"les" << endl; }
        else if(str[len-1]=='n') { cout << str.substr(0,len-1) + "anes" << endl; }
        else if(str[len-2]=='n'||str[len-1]=='e') { cout << str.substr(0,len-2)+"anes" << endl; }
        else if(str[len-1]=='o')
    }
    return 0;
}
