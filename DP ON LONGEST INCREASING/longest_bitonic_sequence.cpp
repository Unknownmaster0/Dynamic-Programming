#include <iostream>
#include <vector>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// increasing as well as decreasing -> thus apply the same code for both the increasing and decreasign separately.
    vector<int> dpfront(n, 1), dpback(n, 1);
    int maxLengthf = 0; // maxLength front
    int maxLengthb= 0;	// maxLength back

// filling the dp table for longest increasing sequence from start.
    for(int i=0; i<n; i++){
        for(int j = 0; j<i; j++){

            if( arr[i] > arr[j] && dpfront[j] + 1 > dpfront[i] ){
                dpfront[i] = 1 + dpfront[j];
            }
        }
    }

// filling the dp table for longest increasing sequence from back.
	for(int curr=n-1; curr>=0; curr--){
		for(int prev=curr+1; prev<n; prev++){

			if(arr[curr] > arr[prev] && dpback[prev] + 1 > dpback[curr]){
				dpback[curr] = dpback[prev] + 1;
			}
		}
	}

	int ans = 0;
	for(int i=0; i<n; i++){
		ans = max(ans, dpfront[i] + dpback[i] - 1);
	}

	return ans;
}


int main()
{

    return 0;
}