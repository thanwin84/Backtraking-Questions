class Solution:
    def __init__(self):
        self.final_result = []
    def partition(self, s: str):

        output = []
        self.Helper(s, output)
        return self.final_result
    def is_palindrone(self, s):
        i = 0
        j = len(s) -1
        while i <= j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                return False
        return True
    def Helper(self, s, output):
        if len(s) == 0:
            self.final_result.append(output)
            return

        for i in range(1, len(s) + 1):
            if self.is_palindrone(s[:i]):
                self.Helper(s[i:], output + [s[:i]])
                
