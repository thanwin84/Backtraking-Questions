class Solution:
    def __init__(self):
        self.output = []
        self.table = {}
        self.dp = {}
    def helper(self, s, allowed):
        self.dp[s] = 1
        if self.is_valid(s):
            # to check duplicate
            if s not in self.table:
                self.output.append(s)
                self.table[s] = 1
            return
        if allowed == 0:
            return

        for k in range(0, len(s)):
            if s[k] not in ['(', ')']:
                continue
            left = s[:k]
            right = s[k + 1:]
            if left + right in self.dp:
                continue
            self.helper(left + right, allowed - 1)


    def removeInvalidParentheses(self, s: str):
        allowed = self.getMin(s)
        self.helper(s, allowed)
        return self.output
    def getMin(self, s):
        stack = []
        for i in s:
            if i == '(':
                stack.append(i)
            elif i == ')':
                if len(stack) == 0:
                    stack.append(i)
                elif len(stack) > 0 and stack[-1] == '(':
                    stack.pop()
                else:
                    stack.append(i)
        return len(stack)
    def is_valid(self, s):
        stack = []
        for i in s:
            if i == '(':
                stack.append(i)
            elif i == ')':
                if len(stack) > 0 and stack[-1] == '(':
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
