class Solution {
public:
    
    int solve(int index,vector<int> &prices,int buy,vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1) return dp[index][buy];
        int curr;
        if(buy){
            curr=max(-prices[index]+solve(index+1,prices,0,dp),solve(index+1,prices,1,dp));
        }
        else{
            curr=max(prices[index]+solve(index+2,prices,1,dp),solve(index+1,prices,0,dp));
        }
        dp[index][buy]=curr;
        return curr;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans=solve(0,prices,1,dp);
        return ans;
    }
};