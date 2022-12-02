class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> m1(26,0),m2(26,0);
        set<char> s1,s2; 
        for(auto it:word1){
            m1[it-'a']++;
            s1.insert(it);
        }
        for(auto it:word2){
            m2[it-'a']++;
            s2.insert(it);
        }
        int c1=0,c2=0;
        sort(m1.begin(),m1.end());
        sort(m2.begin(),m2.end());
        
        if(m1==m2 and s1==s2){
            return true;
        }
        return false;
        
    }
};