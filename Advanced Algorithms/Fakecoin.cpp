
//FAKE COIN
#include <iostream>
#include <vector>
using namespace std;
//Creating a function called find_fake_coin that takes the coins vector as a
//parameter
void find_fake_coin(vector<int>& coins) {
	//we need at least 3 coins for this proplem so we make sure n which is the size
	//of coins greater than 3
		int n = coins.size();
	if (n < 3) {
		cout << "You need at least 3 coins for this algorithm\n";
	}
	//This is the best case senario if we had only 3 coins then we will compare them
	//one by one and check which one is fake and is it lighter or heavier than the other
		//two
		if (n == 3) {
			if (coins[0] == coins[1]) {
				if (coins[2] > coins[1]) {
					cout << "The fake coin is heavier than the others\n";
				}
				else if (coins[2] < coins[1]) {
					cout << "The fake coin is lighter than the others\n";
				}
			}
			else if (coins[0] > coins[1]) {
				if (coins[0] == coins[2]) {
					cout << "The fake coin is lighter than the others\n";
				}
				else {
					cout << "The fake coin is heavier than the others\n";
				}
			}
			else {
				if (coins[0] == coins[2]) {
					cout << "The fake coin is heavier than the others\n";
				}
				else if (coins[0] < coins[1]) {
					cout << "The fake coin is lighter than the others\n";
				}
			}
			return;
		}
	// If we have more than 3 coins then we are going to do the number of coins modulus
	//3:
	// 1- If it is 0 then we are going to divide them into 3 groups and then
	/*calculate the total weigth of each group and compare them and find which group has
		diffrent wiegth than the others if it is heavier thn the fake coin is heavier, if it
		lighter then the fake coin is lighter*/
		// 2- If the remainder is 1 then we are going to create a vector called
		/*extra_coins and we are going to move the last coin in the coins to the extra_coins
		and then for coins we are going to divide them to three groups and compare them if
		they all have the same weigth then the fake coin is the coin in the extra_coins so
		we are going to compare it to any coin in any group of the three groups*/
		//3- If the remainder is 2 then we are going to create a vector called
		/*extra_coins and we are going to move the last 2 coin in the coins to the extra_coins
		and then for coins we are going to divide them to three groups and compare them if
		they all have the same weigth then the fake coin is one of the two coins in the
		extra_coins so we are going to compare each one to any coin in any group of the
		three groups*/
		int remainder = n % 3;
	vector<int> extra_coins(coins.end() - remainder, coins.end()); // Store
	/*remainder coins in a separate list*/
		coins.resize(n - remainder); // Resize the main coins list to only contain
	/*multiples of 3*/
		// Divide the remaining coins into 3 groups
		int group_size = coins.size() / 3;
	vector<int> groupA(coins.begin(), coins.begin() + group_size);
	vector<int> groupB(coins.begin() + group_size, coins.begin() + 2 * group_size);
	vector<int> groupC(coins.begin() + 2 * group_size, coins.end());
	// Calculate the total weight of each group
	int weightA = 0, weightB = 0, weightC = 0;
	for (int w : groupA) weightA += w;
	for (int w : groupB) weightB += w;
	for (int w : groupC) weightC += w;
	if (weightA == weightB && weightA == weightC) {
		if (extra_coins.size() == 1) {
			if (extra_coins[0] > groupA[0]) {
				cout << "The fake coin is heavier than the others\n";
			}
			else if (extra_coins[0] < groupA[0]) {
				cout << "The fake coin is lighter than the others\n";
			}
			else {
				cout << "All coins are real\n";
			}
		}
		else if (extra_coins.size() == 2) {
			// If there are two coins in the extra list, compare them with one of
			/*the group coins*/
				if (extra_coins[0] > groupA[0]) {
					cout << "The fake coin is heavier than others.\n";
				}
				else if (extra_coins[0] < groupA[0]) {
					cout << "The fake coin is lighter than others.\n";
				}
				else if (extra_coins[1] > groupA[0]) {
					cout << "The fake coin is heavier than the others\n";
				}
				else if (extra_coins[1] < groupA[0]) {
					cout << "The fake coin is lighter than the others\n";
				}
				else {
					cout << "All coins are real\n";
				}
		}
	}
	else {
		if (weightA != weightB && weightA != weightC) {
			if (weightA > weightB) {
				cout << "The fake coin is heavier\n";
			}
			else {
				cout << "The fake coin is lighter than the others\n";
			}
		}
		else if (weightB != weightC) {
			if (weightB > weightC) {
				cout << "The fake coin is heavier than the others\n";
			}
			else {
				cout << "The fake coin is lighter than the others\n";
			}
		}
	}
}
int main() {
	vector<int> coins = { 1,1,1,1,0 };
	find_fake_coin(coins);
	return 0;
}