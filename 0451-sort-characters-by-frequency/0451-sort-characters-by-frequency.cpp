class Solution {
public:
    
    static bool comp(pair <int,char> a,pair<int,char> b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    }
    
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(auto it:s) mpp[it]++;
        vector<pair<int,char>> pp;
        
        for(auto it:mpp){
            pp.push_back({it.second,it.first});
        }
        
        
        sort(pp.begin(),pp.end(),comp);
        string ans="";
        for(auto it:pp){
            int count=it.first;
            while(count--){
                ans+=it.second;
            }
        }
        return ans;
    }
};