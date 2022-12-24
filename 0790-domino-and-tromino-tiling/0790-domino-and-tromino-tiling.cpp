class Solution {
public:
    int numTilings(int n) {
        if(n==0 or n==1) return 1;
        vector<int> dp(n+1,0);
        int mod=1e9+7;
        dp[0]=dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=((2*dp[i-1])%mod+dp[i-3]%mod)%mod;
        }
        return dp[n];
    }
};