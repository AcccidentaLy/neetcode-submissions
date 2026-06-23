class Solution:
    def trap(self, height: List[int]) -> int:
        left = []
        right = []
        left_max = 0
        right_max = 0

        for i in range(len(height)):
            left.append(max(left_max, height[i]))
            left_max = max(left_max, height[i])

            right.append(max(right_max, height[len(height)-i-1]))
            right_max = max(right_max, height[len(height)-i-1])
        
        cnt = 0
        for i in range(len(height)):
            cnt += min(right[len(height)-i-1], left[i]) - height[i]
        
        return cnt