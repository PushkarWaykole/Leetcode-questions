class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(auto it:s){
            mpp[it]++;
        }
        string ans="";
        vector<pair<int,char>> pp;
        for(auto it:mpp){
            pp.push_back(make_pair(it.second,it.first));
        }
        sort(pp.rbegin(),pp.rend());
        for(auto it:pp){
            for(int i=0;i<it.first;i++){
                ans+=it.second;    
            }
            
        }
        return ans;
    }
};