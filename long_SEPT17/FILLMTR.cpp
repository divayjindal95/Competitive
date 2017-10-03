#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,e) for(int i=s;i<e;i++)
#define repr(i,e,s) for(int i=e;i>s;i--)

bool cmp(std::vector<int> a, std::vector<int> b){
	if(a[0]<b[0])
		return 1;
	if(a[0]==b[0]){
		if(a[1]<b[1])
			return 1;
		return 0;
	}
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	for(int t=0;t<tc;t++){
		int n, m;
		cin>>n>>m;
		std::vector<std::vector<int> > arr(m, std::vector<int>(3));
		rep(i,0,m){
			int l, r, val;
			cin>>l>>r>>val;
			l=l-1;
			r=r-1;
			if(l>r)	swap(l,r);
			arr[i][0]=l;
			arr[i][1]=r;
			arr[i][2]=val;
		}

		sort(arr.begin(),arr.end(),cmp);

		//rep(i,0,m)
		//	cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<endl;

		int res[n];
		rep(i,0,n) res[i]=0;
		int flag=0;
		rep(i,0,m){

			if(arr[i][0]==arr[i][1] && arr[i][2]!=0){
				cout<<"no\n";
				flag=1;
				break;
			}

			if(res[arr[i][0]]==0 && res[arr[i][1]]==0){
				//cout<<"a ";
				if(arr[i][2]==0){
					res[arr[i][0]]=-1;
					res[arr[i][1]]=-1;
				}
				else{
					res[arr[i][0]]=-1;
					res[arr[i][1]]=1;
				}
			}

			else if(res[arr[i][0]]!=0 && res[arr[i][1]]==0){
				//cout<<"b ";
				if(arr[i][2]==0)
					res[arr[i][1]]=res[arr[i][0]];
				
				else
					res[arr[i][1]]=-1*res[arr[i][0]];	
			}

			else if(res[arr[i][0]]==0 && res[arr[i][1]]!=0){
				//cout<<"c ";
				if(arr[i][2]==0)
					res[arr[i][0]]=res[arr[i][1]];
				
				else
					res[arr[i][0]]=-1*res[arr[i][1]];	
			}

			else{
			//if(res[arr[i][0]]!=0 && res[arr[i][1]]!=0){
				//cout<<"d ";
				if(arr[i][2]==0)
					if(res[arr[i][0]]!=res[arr[i][1]]){
						cout<<"no\n";
						flag=1;;
						break;
				}
				if(arr[i][2]==1)
					if(res[arr[i][0]]==res[arr[i][1]]){
						cout<<"no\n";
						flag=1;
						break;
				}
			}

		}

		//rep(i,0,n)	cout<<res[i]<<" ";
		if(flag!=1)
			cout<<"yes\n";
	}
	
	//cout<<"hello";
	return 0;
}