/************************************************************
	> File Name: 203.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 27 Mar 2020 11:08:28 AM CST
************************************************************/

#include <iomanip>
#include <ios>
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
double dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
signed main(void){
	double x1,y1,x2,y2,x3,y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		double a = dis(x1,y1,x2,y2);
		double b = dis(x1,y1,x3,y3);
		double c = dis(x2,y2,x3,y3);
		double p = (a+b+c)/2;
		double area = sqrt(p*(p-a)*(p-b)*(p-c));
		cout << fixed << setprecision(1) << area << endl;
	}
	return 0;
}
