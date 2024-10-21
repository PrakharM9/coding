#include <iostream>
using namespace std;

int countMoves(int n, char source, char target, char auxiliary) {
    static int moves = 0;
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        moves++;
        return moves;
    } else {
        countMoves(n - 1, source, auxiliary, target);
        cout << "Move disk " << n << " from " << source << " to " << target << endl;
        moves++;
        countMoves(n - 1, auxiliary, target, source);
        return moves;
    }
}

int main() {
    int n;
    cin >> n;
    int total_moves = countMoves(n, 'A', 'C', 'B');
    cout << "Total number of moves: " << total_moves << endl;
    return 0;
}