#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 300005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2



int32_t main(){ faster
    int n, x, c;
    cin>>n;
    vector<int>esq,dir;
    for(int i=0; i<n; i++){
    cin>>x>>c;
    if(c==0)esq.push_back(x);
    else dir.push_back(x);
    }
    if(esq.size()==0){
        cout<<dir[dir.size()-1]+10<<endl;
        return 0;
    }
    else if(dir.size()==0){
        cout<<esq[esq.size()-1]+10<<endl;
        return 0;
    }
    int ans=0, d=0, e=0;
    bool flag;
    if(dir.size()==0 || esq[e]<dir[d]){
        flag=0;
        ans=esq[e]+10;
        e++;
    }
    else{
        flag=1;
        ans=dir[d]+10;
        d++;
    }
    int cont=0;
    while(d<dir.size() || e<esq.size()){
        if(flag==0){
        while(e<esq.size() && esq[e]<=ans){
            if(esq[e]+10>ans)ans=esq[e]+10;
            e++;
            cont=0;
        }
        bool v=false;
        while(d<dir.size() && dir[d]<=ans){
            d++;
            v=true;
            cont=0;
        }
        if(v)ans+=10;
        flag=1;
        }
        else{
        while(d<dir.size() && dir[d]<=ans){
            if(dir[d]+10>ans)ans=dir[d]+10;
            d++;
            cont=0;
        }
        bool v=false;
        while(e<esq.size() && esq[e]<=ans){
            e++;
            v=true;
            cont=0;
        }
        if(v)ans+=10;
        flag=0;
        }
        cont++;
        if(cont>2){
            if(dir.size()==0 || esq[e]<dir[d]){
            flag=0;
            ans=esq[e]+10;
            e++;
        }
        else{
            flag=1;
            ans=dir[d]+10;
            d++;
        }
        cont=0;   
        }
    }
    cout<<ans<<endl;
}
/*
8
5 0
9 0
7 1
14 1
17 0
25 1
50 0
70 1
*/