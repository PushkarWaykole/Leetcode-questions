class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        // if len(pattern) != len(words) or len(set(pattern)) != len(set(words)):
        
        
        
        
        unordered_map<char,string> mpp;
        int n=pattern.size();
        vector<string> words;
        istringstream ss(s);
        unordered_set<string> st;
        string temp;
        while(ss>>temp){
            words.push_back(temp);
        }
        set<char> st1;
        set<string> st2;
        
        for(auto it:pattern) {st1.insert(it);}
        
        for(auto it:words) {st2.insert(it);}
        
        
        if(pattern.size()!=words.size() or st1.size()!=st2.size()){
            return false;
        }
        for(int i=0;i<n;i++){
            char c=pattern[i];
            string word=words[i];
            if(mpp.find(c)!=mpp.end()){
                if(mpp[c]!=word){
                    return false;
                }
            }
            else{
                
                mpp[c]=word;
            }
        }
        return true;
    }
};