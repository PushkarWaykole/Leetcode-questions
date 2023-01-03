class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        vector<string> temp;
        int count=0;
        for(int i=0;i<n;i++){
            string t="";
            for(auto it:strs){
                t+=it[i];
            }
            string t2=t;
            sort(t2.begin(),t2.end());
            if(t2!=t){
                count++;
            }
        }
        return count;
    }
};