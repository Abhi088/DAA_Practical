#include <iostream>

using namespace std;

int lcs(string str1, string str2, int l1, int l2 ) {
	if (l1 == 0 || l2 == 0)
		return 0;
	if (str1[l1 - 1] == str2[l2 - 1])
		return 1 + lcs(str1, str2, l1 - 1, l2 - 1);
	else
		return max(lcs(str1, str2, l1, l2 - 1), lcs(str1, str2, l1 - 1, l2));
}

int main() {
	string str1 = "HUMAN";
	string str2 = "CHIMPANZEE";
	
	int l1 = str1.length();
	int l2 = str2.length();
	
	cout << "Length of the longest common subsequence in " << str1 << " and " << str2 << " is " << lcs(str1, str2, l1, l2) << "\n";
	
	return 0;
}