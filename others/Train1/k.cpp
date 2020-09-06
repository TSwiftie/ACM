#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<vector>
#include<cstdlib>
#define QAQ int
#define TAT long long
#define OwO bool
#define ORZ double
#define F(i,j,n) for(QAQ i=j;i<=n;++i)
#define E(i,j,n) for(QAQ i=j;i>=n;--i)
#define MES(i,j) memset(i,j,sizeof(i))
#define MEC(i,j) memcpy(i,j,sizeof(j))

using namespace std;
const QAQ N=305,M=30000;

QAQ n,m,s,t;
struct Link{
    QAQ to,last,val,id;
}a[M];
QAQ head[N],js=1;
QAQ dis[N],use[N],ans[M];
QAQ low[M],flow[N];
OwO vis[N];
queue<QAQ> q;

void add(QAQ x,QAQ y,QAQ z,QAQ p){
    a[++js].to=y;a[js].id=p;a[js].val=z;
    a[js].last=head[x];head[x]=js;
}

OwO bfs(){
    F(i,s,t) dis[i]=vis[i]=0;
    dis[s]=vis[s]=1;
    q.push(s);
    while(!q.empty()){
        QAQ x=q.front();q.pop();
        for(QAQ i=head[x];i;i=a[i].last) if(a[i].val&&!vis[a[i].to]){
            vis[a[i].to]=1;
            dis[a[i].to]=dis[x]+1;
            q.push(a[i].to);
        }
    }
    return vis[t];
}

QAQ dfs(QAQ x,QAQ want){
    if(x==t||!want) return want;
    QAQ f=0,ans=0;
    for(QAQ i=use[x];i;i=a[i].last) if(dis[a[i].to]==dis[x]+1){
        f=dfs(a[i].to,min(a[i].val,want));
        if(!f) continue;
        ans+=f;
        want-=f;
        a[i].val-=f;
        a[i^1].val+=f;
        if(!want) break;
        use[x]=i;
    }
    if(!ans) dis[x]=-1;
    return ans;
}

QAQ dinic(){
    QAQ ans=0;
    while(bfs()){
        MEC(use,head);
        ans+=dfs(s,1e9);
    }
    return ans;
}

QAQ main(){
    scanf("%d%d",&n,&m);
    s=0;t=2*n+2*m+1;
    for(int i = 1;i <= m;++i){
        QAQ u,v,w;char uu,vv,ww;
        scanf("%d %c %d %c %d %c",&u,&uu,&v,&vv,&w,&ww);
        if(uu=='R'){
            add(u, 2*n+i, 1e9, i);
            add(2*n+i,u,0,i);
            //--flow[u];++flow[2*n+i];
        }else if(uu=='B'){
            add(n+u, 2*n+i, 1e9, i);
            add(2*n+i, n+u, 0, i);
            //--flow[n+u];++flow[2*n+i];
        }
        if(vv=='R'){
            add(v, 2*n+i, 1e9, m+i);
            add(2*n+i, v, 0, m+i);
            ///--flow[v];++flow[2*n+i];
        }else if(vv=='B'){
            add(n+v, 2*n+i, 1e9, m+i);
            add(2*n+i, n+v, 0, m+i);
            //--flow[n+v];++flow[2*n+i];
        }
        if(ww=='R'){
            add(w, 2*n+i, 1e9, 2*m+i);
            add(2*n+i, w, 0, 2*m+i);
            //--flow[w];++flow[2*n+i];
        }else if(ww=='B'){
            add(n+w, 2*n+i, 1e9, 2*m+i);
            add(2*n+i, n+w, 0, 2*m+i);
            //--flow[n+w];++flow[2*n+i];
        }
        //scanf("%d%d%d%d",&u,&v,&low[i],&w);
        /*
         * add(u,v,w-low[i],i);
         * add(v,u,0,i);
         * flow[v]+=low[i];
         * flow[u]-=low[i];
         */
    }
    for(int i = 1;i <= m;++i){
        add(2*n+i, 2*n+m+i, 1, 3*m+i);
        add(2*n+m+i, 2*n+i, 0, 3*m+i);
        flow[2*n+i]-=2;flow[2*n+m+i]+=2;
    }
    QAQ sum=0;
    F(i,1,2*n+2*m) if(flow[i]<0){
        add(i,t,-flow[i],0);
        add(t,i,0,0);
    }
    else {
        sum+=flow[i];
        add(s,i,flow[i],0);
        add(i,s,0,0);
    }
    if(dinic()==sum){
        printf("YES\n");
        F(x,1,2*m+2*n) for(QAQ i=head[x];i;i=a[i].last) if(a[i].id==0||i%2==0) continue;
        else {
            ans[a[i].id]=a[i].val+low[a[i].id];
        }
        F(i,1,2*n+2*m) printf("%d\n",ans[i]);
    }else printf("-1\n");
    return 0;
}
