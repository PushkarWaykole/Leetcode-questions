class Solution {
public:
    bool detectCapitalUse(string word) {
        string original=word;
        string s1=word,s2=word;
        
        
        // first case
        transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
        if(s1==word){
            return true;
        }
        
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if(s2==word){
            return true;
        }
        
        int index=-1;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])){
                index=i;
            }
        }
        if(index==0){
            return true;
        }
        return false;
    }
};