class Solution {
public:
   vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](auto&a,auto&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<vector<int>>sol(people.size(),vector<int>(2,-1));
        int positions=0,index=0;
        for(auto& person:people){
            positions=0;
            index=0;
            while(sol[index][0]!=-1)index++;
            while(positions<person[1]){
                if(sol[index][0]==-1)positions++;
                index++;
            }
            while(sol[index][0]!=-1)index++;
            sol[index]=person;
        }
        return sol;
    }
};