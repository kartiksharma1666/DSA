#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int maximumSumSubarray(vector<int>& arr,int x,int n){
    vector<vector<int>> dp(n,vector<int>(2,0));
    vector<int> k(n,0);
    dp[0][0]= max(0,arr[0]);
    dp[0][1]= max(0,arr[0]*x);
    k[0]=max(0,arr[0]);
    int result = max({k[0], dp[0][0], dp[0][1]});
    for(int i=1;i<n;i++){
        k[i] = max(0, k[i - 1] + arr[i]);

        
        dp[i][1] = max({
            arr[i] * x,             
            k[i - 1] + arr[i] * x,  
            dp[i - 1][1] + arr[i]*x,  
            0                       
        });

        
        dp[i][0] = max({
            dp[i - 1][0] + arr[i],  
            dp[i - 1][1] + arr[i],  
            k[i],                   
            0                       
        });

        
        result = max({result, k[i], dp[i][0], dp[i][1]});
    }

    return result;


}

int main(){
    int n,x;
    cin >> n;
    cin>>x;

    vector<int> arr(n,0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout<<maximumSumSubarray(arr,x,n);

    return 0;
}