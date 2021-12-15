#include <iostream>
#include <stdbool.h>
#include <vector>

using namespace std;
int N;
vector<int> ld(30, 0), rd(30, 0), cl(30, 0);

bool solveNQueen(vector<vector<int>>& board, int col) {
	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1) {
			board[i][col] = 1;
			ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

			if (solveNQueen(board, col + 1))
				return true;

			board[i][col] = 0; 
			ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
		}
	}
	return false;
}

void findNQueenSolution(vector<vector<int>>& board) {

	if (!solveNQueen(board, 0)) {
		printf("Solution does not exist");
		return;
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return;
}

int main() {
	cout << "Enter number of queens: ";
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));
	findNQueenSolution(board);
	return 0;
}
