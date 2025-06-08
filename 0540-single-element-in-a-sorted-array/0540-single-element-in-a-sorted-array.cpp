class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // for(int i = 0; i< nums.size()-2; i++){
        //     if(i==0 && (nums[0]!=nums[1])) {
        //         return nums[0];
        //     } else if ( i!= 0 && (nums[i]!=nums[i+1]) && (nums[i]!=nums[i-1])) {
        //         return nums[i];
        //     }
        // }
        unordered_map <int,int> count;
        for(auto i: nums){
            count[i]++;
        }
        for (auto& pair : count) {
        if (pair.second != 2) {
            return pair.first;
        }
    }
        return 1;
    }
};