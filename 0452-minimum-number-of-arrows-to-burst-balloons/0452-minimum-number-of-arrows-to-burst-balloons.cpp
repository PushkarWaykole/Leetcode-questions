class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        
         int end=points[0][1];
        
        int balloons=1;
        for(auto it:points){
            if(it[0]>end){
                balloons++;
                end=it[1];
            }
            else{
                end=min(end,it[1]);
            }
        }
        
        return balloons;
    }
};