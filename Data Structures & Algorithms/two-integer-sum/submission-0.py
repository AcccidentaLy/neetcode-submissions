class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complement = {}

        for i in range(len(nums)):
            val = nums[i]
            comp = target - val
            if val in complement:
                return [complement.get(val), i]
            else:
                complement[comp] = i
        return []