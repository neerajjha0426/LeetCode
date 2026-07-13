class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int num=1;num<=9;num++){
            int curr=num;
            int next=num;
            while(curr<=high && next<10){
                if(curr>=low) ans.push_back(curr);

                curr=curr*10 + (++next);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};