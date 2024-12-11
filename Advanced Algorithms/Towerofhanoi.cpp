//TOWER OF HANOI

#include <iostream>
#include <stack>
using namespace std;
long int num_moves = 0;
class Disk {
public:
	int size = 0;
	Disk(int diskSize) {
		size = diskSize;
	}
};
// Function to move a disk from one stack to another.
void moveDisk(stack<Disk>& from, stack<Disk>& to, char fromPeg, char
	toPeg) {
	if (!from.empty()) {
		Disk movingDisk = from.top();
		from.pop();
		to.push(movingDisk);
		num_moves++;
	}
}
///Recursive function that moves disks between stacks following the
//restricted rules.
//
//The pattern found to solve this problem as follows:
//A -> B -> C
//A -> B or B -> A. Make the valid move
//C -> B -> A
//B -> C or C -> B. Make the valid move
//Repeat...

void restrictedHanoiRecursive(stack<Disk>& a, stack<Disk>& b,
	stack<Disk>& c, int num_disks, char aPeg, char bPeg, char cPeg) {
	if (c.size() == num_disks) return; // Base case: stop when all disks are on peg C.
		// Step 1: Move a disk from A to B, then from B to C.
		moveDisk(a, b, aPeg, bPeg);
		cout << "Move disc from A to B\n";
	    moveDisk(b, c, bPeg, cPeg);
	    cout << "Move disc from A to B\n";
	if (c.size() == num_disks) return; // Check if we've completed the puzzle.
		// Step 2: Move a disk between A and B or vice versa.
		if (a.empty()) {
			moveDisk(b, a, bPeg, aPeg);
			cout << "Move disc from B to A\n";
		}
		else if (b.empty()) {
			moveDisk(a, b, aPeg, bPeg);
			cout << "Move disc from A to B\n";
		}
		else if (a.top().size < b.top().size) {
			moveDisk(a, b, aPeg, bPeg);
			cout << "Move disc from A to B\n";
		}
		else {
			moveDisk(b, a, bPeg, aPeg);
			cout << "Move disc from B to A\n";
		}
	// Step 3: Move a disk from C to B, then from B to A.
	moveDisk(c, b, cPeg, bPeg);
	cout << "Move disc from C to B\n";
	moveDisk(b, a, bPeg, aPeg);
	cout << "Move disc from B to A\n";
	// Step 4: Move a disk between B and C or vice versa.
	if (b.empty()) {
		moveDisk(c, b, cPeg, bPeg);
		cout << "Move disc from C to B\n";
	}
	else if (c.empty()) {
		moveDisk(b, c, bPeg, cPeg);
		cout << "Move disc from B to C\n";
	}
	else if (c.top().size < b.top().size) {
		moveDisk(c, b, cPeg, bPeg);
		cout << "Move disc from C to B\n";
	}
	else {
		moveDisk(b, c, bPeg, cPeg);
		cout << "Move disc from B to C\n";
	}
	// Recursive call to continue the sequence.
	restrictedHanoiRecursive(a, b, c, num_disks, aPeg, bPeg, cPeg);
}
int calculateMoves(int num_disks) {
	stack<Disk> a;
	stack<Disk> b;
	stack<Disk> c;
	if (num_disks > 0) {
		for (int i = num_disks; i > 0; i--) {
			a.push(Disk(i));
		}
		restrictedHanoiRecursive(a, b, c, num_disks, 'A', 'B', 'C');
		return num_moves;
	}
	else {
		cout << "Number of disks must be greater than 0" << endl;
		return 0;
	}
}
	int main() {
		int num_disks = 0;
		cout << "Enter number of disks for this problem: ";
		cin >> num_disks;
		int moves = calculateMoves(num_disks);
		cout << "\nTotal number of moves: " << moves << endl;
		return 0;
	}