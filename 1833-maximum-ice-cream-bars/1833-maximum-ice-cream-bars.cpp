class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        int curr=coins;
        for(auto it:costs){
            if(it<=curr){
                curr-=it;
                ans++;
            }
        }
        return ans;
            
    }
};