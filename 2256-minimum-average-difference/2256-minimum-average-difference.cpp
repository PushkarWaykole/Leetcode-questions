class Solution {
public:
    
    static bool comp(const pair<int,int> p1,const pair<int,int> p2){
        
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        
        return p1.first<p2.first;
    }
    
    
    int minimumAverageDifference(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return 0;
        vector<long long int> prefix(n),suffix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]+=nums[i]+prefix[i-1];
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]+=nums[i]+suffix[i+1];
        }
        int start=1,end=n-1;
        vector<pair<long long int,long long int>> pp;
        for(int i=0;i<n-1;i++){
            long long int adiff=abs((prefix[i]/start)-(suffix[i+1]/end));
            pp.push_back(make_pair(adiff,i));
            start++;
            end--;
        }
        long long int last=prefix[n-1]/n;
        
        pp.push_back(make_pair(last,n-1));
        
        sort(pp.begin(),pp.end(),comp);
        int ans=pp[0].second;
        return ans;
    }
};