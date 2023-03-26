void swap(string& s, int start, int end) {
	char temp = s[start];
	s[start] = s[end];
	s[end] = temp;
}
class Solution
{
public:
	string _max;
	void solve(string& s, int k) {
		if (k == 0) {
			return;
		}
		for (int i = 0; i < s.size() - 1; i++) {
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] > s[i]) {
					swap(s, i, j);
					if (s > _max) {
						_max = s;
					}
					solve(s, k - 1);
					swap(s, i, j);
				}
			}
		}
	}
	//Function to find the largest number after k swaps.
	string findMaximumNum(string str, int k)
	{
		// code here.
		_max = str;
		solve(str, k);
		return _max;
	}
};
