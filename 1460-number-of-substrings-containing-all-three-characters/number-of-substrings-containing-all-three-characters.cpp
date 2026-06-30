class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3]={0};
        int left=0,ans=0;
        int n=s.size();

        for(int r=0;r<n;r++){
            count[s[r]-'a']++;

            while(count[0]>0 && count[1]>0 && count[2]>0){
                ans+=(n-r);
                count[s[left]-'a']--;
                left++;
            } 


        }
        return ans;
        
    }
};