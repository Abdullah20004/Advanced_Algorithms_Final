#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
//This is the compare function and it takes the two given names by
//the user(parameters) and first it convert each word to lower case
//so that we will be able to compare it if they are the same the
//function will return TRUE else it will return FALSE.
bool compare(std::string word1, std::string word2) {
	transform(word1.begin(), word1.end(), word1.begin(),::tolower);
	transform(word2.begin(), word2.end(), word2.begin(),::tolower);
	sort(word1.begin(), word1.end());
	sort(word2.begin(), word2.end());
	return word1 == word2;
}
int main() {
	string word1, word2;
	cout << "Enter the first word\n";
	cin >> word1;
	cout << "Enter the second word\n";
	cin >> word2;
	//recalls the compare function if TRUE the program outputs
	//that the words are anagrams//
		if (compare(word1, word2)) {
			cout << "The words are anagrams (same when sorted)." <<
				endl;
		}
		else {
			//If the compare functions return false the program output
			//would be that they are not anagrams
				cout << "The words are not anagrams." << endl;
		}
	return 0;
}