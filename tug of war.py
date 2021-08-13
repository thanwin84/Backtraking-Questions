
class Solution:
    def __init__(self):
        self.final_li = []
        self.min_diff = float('inf')
    def helper(self, arr, currentIndex, currentSum, output, total, result):
        if len(output) == len(arr) // 2:
            second_sum = total - currentSum
            if abs(second_sum - currentSum) < self.min_diff:
                self.final_li = output
                self.min_diff = min(abs(second_sum - currentSum), self.min_diff)
            return
        for i in range(currentIndex, len(arr)):
            if len(output) < len(arr) // 2:
                self.helper(arr, i + 1, currentSum + arr[i], output + [arr[i]], total, result + [arr[i]])

    def tug_of_war(self, arr):
        output = []
        total = sum(arr)
        result = []
        self.helper(arr, 0, 0, output, total, result)
        second_arr = []
        seen = {}
        for i in self.final_li:
            seen[i] = 1
        for i in arr:
            if not i in seen:
                second_arr.append(i)
        print(self.final_li)
        print(second_arr)


arr = [23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4]
ob = Solution()
ob.tug_of_war(arr)
