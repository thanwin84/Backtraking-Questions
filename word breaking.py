# word break using backtracking
class Solution:
    def __init__(self):
        self.output = []
    def helper(self, start, end,  n, result, table, s):
        if end == n:
            self.output.append(result)
            return

        for index in range(start, n+1):
            if s[start:index] in table:
                self.helper(index, index,  n, result + s[start: index] + ' ',table,  s)
        return False
    def wordBreak(self, n, dict, s):
        table = {}
        for word in dict:
            table[word] = 1
        self.helper(0, 0,  n, "", table, s)
        return self.output
s = "catsanddog"
di = ["cats", "cat", "and", "sand", "dog"]
obj = Solution()
print(obj.wordBreak(len(s), di, s))
