class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=capacity[i]-rocks[i];
        }
        for(auto it:diff){
            cout<<it<<" ";
        }cout<<endl;
        sort(diff.begin(),diff.end());
        int temp=additionalRocks;
        int bags=0;
        
        for(auto it:diff){
            if(it==0){
                bags++;
            }
            else if(temp==0){
                break;
            }
            else if(it!=0){
                if(temp>=it){
                    temp-=it;
                    bags++;
                    cout<<temp<<endl;
                }
            }
        }
        return bags;
    }
};