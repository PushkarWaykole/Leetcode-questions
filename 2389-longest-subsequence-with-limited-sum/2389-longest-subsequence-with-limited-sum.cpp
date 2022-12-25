class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        // for(auto it:prefix){
        //     cout<<it<<" ";
        // }cout<<endl;
        
        vector<int> ans;
        for(auto q:queries){
            auto index=lower_bound(prefix.begin(),prefix.end(),q)-prefix.begin();
            if(index==n){
                ans.push_back(n);
            }
            else if(prefix[index]==q){
                ans.push_back(index+1);
            }
            else{
                ans.push_back(index);
            }
        }
        return ans;
        
    }
};