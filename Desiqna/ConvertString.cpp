#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    string s ,r;
    cin >> s;
    cin >> r;
    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;
    for(auto ch : r){
        mp2[ch]++;
    }
    for(auto ch : s){
        mp1[ch]++;
    }
    int cost = 0;
    for(int i=0;i<26;i++){
        if(mp1[s[i]] > mp2[r[i]]){
            cost += abs(mp1[s[i]]-mp2[r[i]]);
        }
    }
    cout<< cost;

    return 0;
}