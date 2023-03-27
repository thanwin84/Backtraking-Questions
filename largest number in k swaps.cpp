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

// optimized approach
void swap(string& s, int start, int end) {
	char temp = s[start];
	s[start] = s[end];
	s[end] = temp;
}
class Solution
{
public:
	string _max;
	void solve(string& s, int k, int start) {
		if (k == 0 || start == s.size()) {
			return;
		}
		for (int i = start; i < s.size(); i++) {
		    // keep track of max value index from start to (s.size - 1)
		    int maxIndex = 0;
		    // keep track of max value from (start + 1) to (s.size - 1)
		    char maxNum = '0';
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] > maxNum){
				    maxNum = s[j];
				    maxIndex = j;
				}
			}
			// swap only when maxNum is greater than s[start]
			if (maxNum > s[start]){
			    swap(s, start, maxIndex);
			    if (s > _max) _max = s;
			    solve(s, k - 1, start + 1);
			    swap(s, start, maxIndex);
			}
			// if the max num is equal to s[start] or lesst than s[start]
			// in that case no need to swap
			else {
			    solve(s, k, start + 1);
			}
			
		}
	}
	//Function to find the largest number after k swaps.
	string findMaximumNum(string str, int k)
	{
		// code here.
		_max = str;
		solve(str, k, 0);
		return _max;
	}
};
//The time complexity of this algorithm is O(n^k), where n is the length of the input string and k is
// the maximum number of swaps allowed.
