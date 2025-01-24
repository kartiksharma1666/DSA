#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        cin>>b[i];
    }
    //odd and even at any index i for a and b
    //dp_a_even[i] = number of journey ending at a[i] whose sum is even
    vector<int> dp_a_even(n,0);
    vector<int> dp_a_odd(n,0);
    vector<int> dp_b_even(n,0);
    vector<int> dp_b_odd(n,0);
    //base case
    if(a[0]%2==0){
        dp_a_even[0] = 1;
    }
    else{
        dp_b_odd[0]=1;
    }
    if(b[0]%2==0)
}