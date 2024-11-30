// <!-- Understanding -> Given a binary matrix; find the row with maximum frequency - print that maximum frequency 

// https://docs.google.com/document/d/1ZCCWy2qKpUqkEqHRJ1PdzxNHyXejRFWFsHG9hSMwdj0/edit?tab=t.0


// -> You can change the rows <= K -> in 1 operation you can flip the row. 

// -> If you do it optimally now what will be the maximum frequency of a particular row? 

// -> Make hashmap of string storing each row with its frequency 

// -> Each string in the hashmap try to make it the maximum answer and see what maximum answer you can achieve. 

// -> https://www.jdoodle.com/ia/1wRK 

// TC - O(N*M.) 

// Takes O(N*M.) size. Space.  -->
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

string flip(const string g){
    string flipped = g;
    for(char& c : flipped){
        c = (c=='0') ? '1' : '0';
    }
    return flipped;
    
}
int main(){

    int n,m,k;

    cin>>n>>m>>k;
    unordered_map<string,int> mp;
    int result=0;
    for(int i=0;i<n;i++){
        string g = "";
        for(int j=0;j<m;j++){
            int input;
            cin >> input;
            g += (input=='0') ? '0' : '1';
        }
        mp[g]++;
    }
    for(auto& pair : mp){
        string g = pair.first;
        int freq = pair.second;
        string flipped = flip(g);

        int f2 = mp[flipped];
        int total;
        if(k<= f2){
            total = freq + k;
            result = max(result, total);

        }
        else {
            total = freq + f2;
            result = max(result, total);
        }
        

    }
    cout<<"result = "<<result<<endl;

    return 0;
}
