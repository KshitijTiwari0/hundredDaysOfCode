class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()  
        final = []
        for i in range(len(nums)): 
            if nums[i] == target:  
                final.append(i)
        
        return final
