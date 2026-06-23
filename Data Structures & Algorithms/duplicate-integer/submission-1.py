class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        exist = set()
        for val in nums:
            if val in exist:
                return True
            else:
                exist.add(val)
        return False
        