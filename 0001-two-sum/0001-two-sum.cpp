class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size(); 
        vector<int> answer; 
        int idx = 0; 
        while(idx < size - 1){
            int jdx = idx + 1; 
            while(jdx < size){
                if(nums[idx] + nums[jdx] == target){ 
                    answer.push_back(idx); 
                    answer.push_back(jdx); 
                    break; 
                }
                jdx++;
            }
            idx++;
        }
        return answer; 
    }
};