class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char> vowels={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count=0;
        for(int i=0;i<s.size();i++){
            if(i<s.size()/2){
                if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end())
                    count++;
            }
            else{
                if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end())
                    count--;
            }
        }
        return count==0;
    }
};