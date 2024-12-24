// -> Bullet power decreases by 1 as it goes ahead after each person. (irrespective of that person being dead or alive.) 

// -> m…m-1…m-2……….

// Now tell me minimum bullets to kill all the people and output -1 if not possible. 

// https://www.jdoodle.com/ia/1vFk 

// -> Minimum number of bullets to kill at least “k” people. 


// Try for bullet = 1 -> now see if it is killing >=k ppl if not 
// Try for bullet =2 -> if it fails; 
// Try for bullet =3 -> if it fails;
// Try for bullet =4-> if it fails;
// Try for bullet =5 -> pass; that is the minimum number of bullets to kill >=k ppl 

// -> https://www.jdoodle.com/ia/1vFC 

// Optimization. -> Binary search. 




#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

bool isValid (int bullets , int power , vector<int>& people,int k){
    int killedPerson = 0;
    int g = 0;
    for(int i=0;i<people.size();i++){
        int killedPower = (people[i]/power-g);
        if(killedPower<= bullets) killedPerson++;
        g++;
    }
    if(killedPerson >= k){
        return true;
    }
    return false;
}
int solve(int n,int power, vector<int>& people,int k){
    int low = 0,high = INT_MAX;
    int result = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(isValid(n,power,people,k)){
            result = mid;
            high = mid-1;
        }
        else{
            low = mid-1;
        }
    }
    return result;
}
int main(){
    int n,power,k;
    cin>> n >> power >> k;
    if(power < n) return -1;
    vector<int> people(n);
    for(int i=0;i<n;i++){
        cin>> people[i];
    }
    int res = solve(n,power,people,k);
    sort(people.begin(), people.end());
    cout<<"Minimum number of bullets required is :" << res << endl;
    return 0;
}