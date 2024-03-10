class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin() , happiness.end()); // 1 , 2, 3
        int n= happiness.size()-1; // n points to 3
        
        int d =0 ;
        long long int ans =0;
        while(k--) // k is 2
        {
            if(happiness[n]-d <0) break;
            ans+=happiness[n]-d; // ans+= 3-0 = 3 , ans = 3+3-1
            d++; 
            n--;
        }
        return ans;
    }
};