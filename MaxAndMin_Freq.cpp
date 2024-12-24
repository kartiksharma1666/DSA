// ///*We are given an Array of Numbers. We have to find and print any Number with Maximum Frequency and Minimum Frequency.

// Example Testcase:-

// Arr = [3, 2, 3, 2, 4, 3]

// Frequencies of Elements of Array are:-

// 3 - 3
// 2 - 2
// 4 - 1

// Maximum Frequency:- Element is 3, Frequency is 3
// Minimum Frequency:- Element is 4, Frequency is 1 

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

void MaxAndMin(vector<int>& arr){
    unordered_map<int,int> mp;
    int MaxFreqElement = -1;
    int MinFreqElement = -1;
    int MinFrequency = INT_MAX;
    int MaxFrequency = INT_MIN;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    for(auto& m : mp){
        if(m.second > MaxFrequency){
            MaxFrequency = m.second;
            MaxFreqElement = m.first;
        }
        if(m.second < MinFrequency){
            MinFrequency = m.second;
            MinFreqElement = m.first;
        }
    }
    cout<<"Max Frequency of " << MaxFreqElement<< "is"<< MaxFrequency<<endl;
    cout<<"Min Frequency of" << MinFreqElement << "is" << MinFrequency<<endl;
}
int main(){
    vector<int> arr = {3, 2, 3, 2, 4, 3};
    MaxAndMin(arr);
    return 0;
}