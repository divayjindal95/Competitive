#include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int arr[n];
		int start=0,end=n-1;
		int k=1,flag=0;
		for(int j=0;j<n;j++){
			cin>>arr[j];
			if(arr[j]>7)
				flag=1;
		}
		if(n<13)
			flag=1;
		while(start<=end){
			//cout<<k<<" "<<arr[start]<<" "<<arr[end]<<"\n";
			if(arr[start]!=k || arr[end]!=k)
				flag=1;
			while(arr[start]==k)
				start++;
			while(arr[end]==k)
				end--;
			if((start+end)!=(n-1))
				flag=1;
			k++;
			if(flag==1)
				break;
		}
		k--;
		if(k!=7)
			flag=1;
		if(flag==0)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	//cout<<"hello";
	return 0;
}