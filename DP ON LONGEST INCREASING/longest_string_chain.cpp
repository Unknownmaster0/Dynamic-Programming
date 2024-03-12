#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string &curr, string &prev){

    // now curr should have more length than prev to become the chain.  
    if(curr.size() != prev.size() + 1)  return false;

// two pointer traversing on both the string.
    int first = 0, second = 0;
    while(first < curr.size()){
        if(second < prev.size() && curr[first] == prev[second]){
            first ++, second ++;
        }
        else{
            first ++; // if not equal then increment the iterator of the curr string, i.e. first.
        }
    }

    if(first == curr.size() && second == prev.size())   return true;
    return false;
}


bool comparator(string &s, string &t){
    return s.size() < t.size();
}

int longestStrChain(vector<string> &arr){
    
    // we need to sort according to their length.

    // earlier string -> xyx, xy, y, x
    sort(arr.begin(), arr.end(), comparator);
    // after sorting -> x, y, xy, xyx [sort on the basis of the size of the string.]

    int n = arr.size();
    vector<int> dp(n, 1);
    int maxLengh = 0;

    for(int i=0; i<n; i++){
        for(int j = 0; j<i; j++){

            string curr = arr[i], prev = arr[j]; 
            if( compare(curr, prev) && dp[j] + 1 > dp[i] ){
                dp[i] = 1 + dp[j];
            }
        }
        maxLengh = max(maxLengh, dp[i]);
    }
    
    return maxLengh;
}

int main()
{
    
    return 0;
}