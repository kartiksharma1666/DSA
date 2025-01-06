#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long getMaxThroughtput(vector<int>& host_throughput){
    long result=0;
    int n = host_throughput.size();
    sort(host_throughput.begin(), host_throughput.end());
    int count = 0;
    int cluster = n/3;
    for(int i=n-2; i>=0; i-=2){
        result += host_throughput[i];
        count++;
        if(count == cluster){
            break;
        }


    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<int> host_throughput(n);
    for(int i=0; i<n; i++){
        cin>>host_throughput[i];
    }
    cout<<getMaxThroughtput(host_throughput)<<endl;
    return 0;
}