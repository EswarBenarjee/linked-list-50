class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<n+1; i++) {
            ans.push_back(ones((uint32_t) i));
        }
        return ans;
    }
    int ones(uint32_t n) {
        int one = 0;
        while(n > 0) {
            if(n%2 == 1)
                one++;
            n/=2;
        }
        return one;
    }
};