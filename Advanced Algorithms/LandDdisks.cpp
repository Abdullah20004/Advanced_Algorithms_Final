
//LIGHT AND DARK DESKS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function that swaps light and dark discs
void sortDisks(vector<char>& disks, int& moveCount) {
	int n = disks.size();
	bool swapped = true;
	while (swapped) {
		swapped = false;
		// if there is any light disc 'L' before dark disc 'D' we swap
		//both of them and increase the moveCount by one to calculate number of
			//moves
			for (int i = 0; i < n - 1; i++) {
				if (disks[i] == 'L' && disks[i + 1] == 'D') {
					swap(disks[i], disks[i + 1]);
					moveCount++;
					swapped = true;
					cout << "Configuration after swapping: ";
					for (char disk : disks) {
						cout << disk << " ";
					}
					cout << endl;
				}
			}
	}
}
int main() {
	int n;
	cout << "Enter the number of disks (n): ";
	cin >> n;
	if (n <= 0) {
		cout << "Number of disks must be positive." << endl;
		return 1;
	}
	vector<char> disks(2 * n);
	//inserting the light and dark discs in the vector one dark and then
	//one light
		for (int i = 0; i < n; i++) {
			disks[i * 2] = 'D';
			disks[i * 2 + 1] = 'L';
		}
	// printing the initial vector without sorting
	cout << "Initial configuration: ";
	for (char disk : disks) {
		cout << disk << " ";
	}
	cout << endl;
	int moveCount = 0;
	//calling the function sortDiscs
	sortDisks(disks, moveCount);
	//printing the vector after sorting
	cout << "Sorted configuration: ";
	for (char disk : disks) {
		cout << disk << " ";
	}
	cout << endl;
	//printign the number of moves
	cout << "Number of moves: " << moveCount << endl;
	return 0;
}
