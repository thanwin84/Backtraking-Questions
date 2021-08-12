class Solution:
    def __init__(self):
        self.flag = False
    def equalPartition(self, N, arr):
        total_sum = sum(arr)
        if total_sum % 2 == 0:
            flag = False
            self.solve(arr, 0, 0, total_sum // 2)
        return self.flag

    def solve(self, arr, currentSum, currentIndex, target):
        if currentSum == target:
            self.flag = True
            return
        for i in range(currentIndex, len(arr)):
            temp = currentSum + arr[i]
            if temp <= target:
                currentSum += arr[i]
                self.solve(arr, currentSum, i + 1, target)
                currentSum -= arr[i]
