#include <iostream>
using namespace std;

int countSubset(int a[],int target,int n){
    //base condition
    if(target==0)
        return 1;
    if(n==0)
        return 0;
        
    //code for choice diagram
    if(a[n-1]<=target){
        return countSubset(a,target,n-1)+countSubset(a,target-a[n-1],n-1);
    }else
        return countSubset(a,target,n-1);
}

int main() {
	int n, target;
	cin>>n>>target;
	int a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	
	int count = countSubset(a,target,n);
	cout<<"No. of subsets with sum = "<<target<<"  = "<<count<<"\n";
	return 0;
}
