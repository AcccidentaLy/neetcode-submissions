class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_v = 0
        left = 0
        right = len(heights) -  1

        while(left < right):
            max_v = max(max_v, min(heights[left], heights[right]) * (right - left))
            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1
        
        return max_v