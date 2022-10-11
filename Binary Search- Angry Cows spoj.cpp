#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPoss(ll dist,int cows,vector<ll> &pos){
    int count=1;
    int n=pos.size();
    bool flag=0;
    ll last=0;
    for(int i=1;i<n;i++){
        if(pos[i]-pos[last]>=dist){
            count++;
            last=i;
            if(count>=cows)
            {
                flag=true;
                break;
            }
        }

    }
    return flag;
}

ll minDist(int n,int c,vector<ll> pos){
    sort(pos.begin(),pos.end()); //NlogN
    ll ans=-1;
    int i=pos[0],j=pos[n-1];
    while(i<=j){ //logDist*N
        ll mid=(i/2+j/2)+(i%2+j%2)/2;
        if(isPoss(mid,c,pos)){
            ans=mid;
            i=mid+1;
        }
        else{
            j=mid-1;
        }
            
    }

    return ans;
}

int main() {
    int t,n,c;
    cin>>t;
    while(t--){
        cin>>n>>c;
        vector<ll> pos(n);
        for(int i=0;i<n;i++){
            cin>>pos[i];
        }
        cout<<minDist(n,c,pos)<<"\n";
    }
}
