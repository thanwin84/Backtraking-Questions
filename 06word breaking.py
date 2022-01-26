# word break using backtracking
# time: O(2^n)
class Solution:
    def __init__(self):
        self.output = []
        self.dp = {}
    def helper(self, start, end,  n, result, table, s):
        if end == n:
            self.output.append(result[:len(result)-1])
            return result

        for index in range(start, n+1):
            # partion only when the string is valid
            if s[start:index] in table:
                self.helper(index, index,  n, result + s[start: index] + ' ',table,  s)
        return 
    def wordBreak(self, s: str, wordDict: List[str]) ->List[str]:
        table = {}
        for word in wordDict:
            table[word] = 1
        self.helper(0, 0,  len(s), "", table, s)
        return self.output
