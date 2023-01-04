class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mpp;
        for(auto it:tasks){
            mpp[it]++;
        }
        int rounds=0;
        for(auto it:mpp){
            int num=it.first;
            int freq=it.second;
            if(freq==1){
                return -1;
            }
            if(freq%3==0){
                rounds+=freq/3;
            }
            else{
                rounds+=freq/3+1;
            }
        }
        return rounds;
    }
};