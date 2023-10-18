#include <bits/stdc++.h>

using namespace std;

bool Algo_dynamic_knapsack(vector<int> &profit , vector<int> &weight, int pro , int capacity ){
    int n = profit.size() ;
    int dp[n+1][n+1] ;
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0 ;
    }
    for(int i = 0 ; i <= n ; i++){
        dp[0][i] = 0 ;
    }
    
    for(int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(weight[i] < capacity){
                dp[i][j] = max(profit[i-1]+dp[i-1][j-weight[i]],dp[i-1][j]) ; 
            }
            else{
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    if(dp[pro][capacity] >= pro){
        return true ;
    }
    else{
        return false ;
    }
}

int main()
{
    int n ,value ;
    cout << "enter the number of elements in set: " ;
    cin >> n ;
    
    vector<int> nums ;
    // this is the sum of subset problem
    cout << "enter set elements one by one: " ;
    for(int i = 0 ; i < n ; i++){
        cin >> value ;
        nums.push_back(value) ;
    }
    
    int s ;
    cout << "enter the sum which we should get: " ;
    cin >> s ;
    
    // now we are trying to reduce this problem into 0/1 knapsack problem
    vector<int> profit = nums , capacity = nums ;
    int pro = s, weight = s ;
    
    if(Algo_dynamic_knapsack(profit , capacity , pro , weight)) {
        cout << "solution for sum of subset is possible" << endl ;
    }
    else{
        cout << "solution for sum of subset is not possible" << endl ;
    }
    
    return 0;
}
