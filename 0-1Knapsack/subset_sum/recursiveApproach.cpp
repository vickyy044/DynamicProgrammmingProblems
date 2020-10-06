#include <iostream>
using namespace std;

bool subset_sum(int a[],int sum,int n){
    if(sum==0)
        return true;
    if(n==0)
        return false;
    if(a[n-1]<=sum){
        return subset_sum(a,sum-a[n-1],n-1)||subset_sum(a,sum,n-1);
    }else
        return subset_sum(a,sum,n-1);
}

int main() {
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(subset_sum(a,sum,n))
         cout<<"yes subset is present"<<"\n";
	return 0;
}
