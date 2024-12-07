class Solution
{
public:
    int minimumSize(std::vector<int>& nums, int maxOperations)
    {
        std::sort(nums.begin(), nums.end()); 
        int low = 1; 
        int high = nums[nums.size() - 1]; 

        int result = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canDistribute(nums, maxOperations, mid))
            {
                result = mid; 
                high = mid - 1; 
            }
            else
            {
                low = mid + 1; 
            }
        }

        return result;
    }

private:
    bool canDistribute(const std::vector<int>& nums, int maxOperations, int maxBalls)
    {
        int operations = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] <= maxBalls)
            {
                break;
            } 
            operations += (nums[i] - 1) / maxBalls;
            if (operations > maxOperations)
            {
                return false;
            } 
        }

        return true;
    }
};
