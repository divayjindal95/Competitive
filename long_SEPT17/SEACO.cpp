#include <bits/stdc++.h>
using namespace std;

#define  rep(i,s,e) for(int i=s;i<e;i++)
#define  repr(i,e,s) for(int i=e;i>s;i--)

int main(){
	//std::ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++){
    int n,m;
    cin>>n>>m;
    int arr[n];
    memset(arr,0,sizeof(arr));
    int comm[m][3];
    for(int i=0;i<m;i++){
      int type,l,r;
      cin>>type>>l>>r;
      comm[i][0]=type;
      comm[i][1]=l-1;
      comm[i][2]=r-1;
    }
    int rep[m];
    rep(i,0,m) rep[i]=1;
    /*
    for(int i=m-1;i>-1;i--){
      if(comm[i][0]==2){
        for(int j=comm[i][1];j<=comm[i][2];j++){
          rep[j]+=rep[i];
        }
      }
    }
    */
    int arrrep[m];
    rep(i,0,m) arrrep[i]=1;
    arrrep[m-1]=1;
    repr(i,m-1,-1){
      if(comm[i][0]==2){
        arrrep[comm[i][1]]+=arrrep[i];
        arrrep[comm[i][2]+1]-=arrrep[i];
      }
    }

    int repcounter=0;
    rep(i,0,m){
      repcounter+=arrrep[i];
      rep[i]=repcounter;
    }
    for(int i=0;i<m;i++)
      cout<<rep[i]<<" ";
    return 0;
    for(int i=0;i<m;i++){
      if(comm[i][0]==1){
        arr[comm[i][1]]+=rep[i];
        arr[comm[i][2]+1]-=rep[i];
      }
    }

    int counter=0;
    for(int i=0;i<n;i++){
      counter+=arr[i];
      arr[i]=counter;
    }
    rep(i,0,n) cout<<arr[i]<<" ";
    cout<<"\n";
	}

	//cout<<"hello";
	return 0;
}
