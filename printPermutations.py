# O(n*n!) Note that there are n! permutations and it requires O(n) time to print a permutation.
def swap(S, i, j):
    S[i], S[j] = S[j], S[i]
def permutation(S, left, right):
    if left == right:
        print(S)
        return
    for i in range(left, right + 1):
        # do
        swap(S, left, i)
        # recurse
        permutation(S, left + 1, right)
        # undo
        swap(S, left, i)

permutation(['a', 'b', 'c'], 0, 2)
