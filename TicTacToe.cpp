class TicTacToe {
	vector<int> rows, cols;
	int diag, rev_diag;
	int N;
public:
	TicTacToe(int n): rows(n), cols(n), N(n), diag(0), rev_diag(0) {}
	int move(int row, int col, int player) {
		int add = plaer == 1 ? 1 : -1;
		rows[row] += add;
		cols[col] += add;
		diag += (row == col ? add : 0);
		rev_diag += (row == N - col - 1 ? add : 0);
		if (abs(rows[row]) == N || abs(cols[col]) == N ||
			abs(diag) == N || abs(rev_diag) == N)
			return player;
		return 0;
	}

	int get_winner() {
		if (rows[row] == N || cols[col] == N ||
			diag == N || rev_diag == N)
			return 1;
		else if (rows[row] == N || cols[col] == N ||
			diag == N || rev_diag == N)
			return 2;
	}
};