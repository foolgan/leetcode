class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        unordered_map<int, int> hash;
        for (int i = nums.size() - 1;i >= 0; hash[nums[i]] = i, i--)
        {
            if (hash.find(target - nums[i]) == hash.end())
                continue;
            v.push_back(i);
            v.push_back(hash[target - nums[i]]);
            return v;
        }
        return v;
    }
};