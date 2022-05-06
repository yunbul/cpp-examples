#include<iostream>
#include<list>
#include<vector>

using namespace std;

char whoseTurn;//'X' - > PLAYER, '0' -> COMPUTER

vector< vector<char> > board;

int turnsTaken;

const int WINNING_POSITION = 10;
const int NEUTRAL_POSITION = 0;
const int LOSING_POSITION = -10;

bool CheckLine(char mark, int row, int col, int dRow, int dCol)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[row][col] != mark) return false;
		row += dRow;
		col += dCol;
	}
	return true;
}
bool CheckForWin(char mark)
{
	for (int i = 0; i < 3; i++)
	{
		if (CheckLine(mark, i, 0, 0, 1)) return true;
		if (CheckLine(mark, 0, i, 1, 0)) return true;
	}
	if (CheckLine(mark, 0, 0, 1, 1)) return true;
	return CheckLine(mark, 2, 0, -1, 1);
}
bool gameOver() {
	if (turnsTaken < 5) return false;
	char plyr = 'X';
	char oppont = 'O';
	return (turnsTaken == 9 || CheckForWin(plyr) || CheckForWin(oppont));
}


void newGame() {
	for (int i = 0; i < 3; i++) {
		vector<char> ch;
		for (int j = 0; j < 3; j++) {
			ch.push_back(' ');
		}
		board.push_back(ch);
	}
	whoseTurn = 'X';
	turnsTaken = 0;
}

void DisplayGame() {
	if (turnsTaken == 0) {
		cout << "Squares are numbered between 1-9" << endl;
	}
	if (gameOver()) {
		cout << "Game is over. Result : " << endl;
	}
	else {
		cout << "Game now : " << endl;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << " " << board[i][j] << " ";
			if (j != 2) cout << "|";
		}cout << endl;
		if (i != 2) cout << "---+---+---" << endl;
	}
}
bool isMoveLegal(int move)
{
	if (move < 1 || move > 9) return false;

	int row = (move - 1) / 3;
	int col = (move - 1) % 3;
	return board[row][col] == ' ';
}
void MakeMove(int move)
{
	int row = (move - 1) / 3;
	int col = (move - 1) % 3;
	char mark;
	char opponentMark;
	switch (whoseTurn) {
	case 'X':
		mark = 'X';
		opponentMark = 'O';
		break;
	case 'O':
		mark = 'O';
		opponentMark = 'X';
		break;
	}
	board[row][col] = mark;
	whoseTurn = opponentMark;
	turnsTaken++;
}

void RetractMove(int move)
{
	int row = (move - 1) / 3;
	int col = (move - 1) % 3;
	board[row][col] = ' ';
	char opponentMark;
	switch (whoseTurn) {
	case 'X':
		opponentMark = 'O';
		break;
	case 'O':
		opponentMark = 'X';
		break;
	}
	whoseTurn = opponentMark;
	turnsTaken--;
}
int playerMoves()
{
	cout << "Your turn." << endl;
	int move;
	while (true)
	{
		cout << "Enter square number : ";
		cin >> move;
		if (isMoveLegal(move)) break;
		cout << "Invalid move error..." << endl;
	}
	return move;
}
void GenerateMoveList(vector<int>& moveList)
{
	for (int i = 1; i <= 9; i++)
	{
		int move = int(i);
		if (isMoveLegal(move))
		{
			moveList.push_back(int(i));
		}
	}
}
int EvaluateStaticPosition()
{
	if (CheckForWin('X'))
	{
		return WINNING_POSITION;
	}
	if (CheckForWin('O'))
	{
		return LOSING_POSITION;
	}
	return NEUTRAL_POSITION;
}
int MinMove(int& bestMove);
int MaxMove(int& bestMove)
{
	if (gameOver())
	{
		return EvaluateStaticPosition();
	}
	vector<int> moveList;
	GenerateMoveList(moveList);
	int n = moveList.size(); //number of possible moves
	int v = -1000;
	for (int i = 0; i < n; i++)
	{
		int move = moveList[i];
		MakeMove(move);
		int opponentsBestMove;
		int curRating = MinMove(opponentsBestMove);
		if (curRating > v)
		{
			v = curRating;
			bestMove = move;
		}
		RetractMove(move);
	}
	return v;

}
int MinMove(int& bestMove)
{
	if (gameOver())
	{
		return EvaluateStaticPosition();
	}
	vector<int>moveList;
	GenerateMoveList(moveList);
	int n = moveList.size();
	int v = 1000;
	for (int i = 0; i < n; i++)
	{
		int move = moveList[i];
		MakeMove(move);
		int opponentsBestMove;
		int curRating = MaxMove(opponentsBestMove);
		if (curRating < v)
		{
			v = curRating;
			bestMove = move;
		}
		RetractMove(move);
	}
	return v;
}
int MiniMax() //return best possible move
{
	int bestMove;
	int i = 0;
	if (whoseTurn == 'X') {
		i = MaxMove(bestMove);
	}
	else {
		i = MinMove(bestMove);
	}
	//cout<<"i is "<<i<<endl;
	return bestMove;
}

int computerMoves()
{
	int rating;
	cout << "My turn ." << endl;
	return MiniMax();
}

void result() {
	DisplayGame();

	if (CheckForWin('X'))
		cout << "Player wins." << endl;

	else if (CheckForWin('O'))
		cout << "Computer wins." << endl;

	else
		cout << "Its a draw." << endl;
}

void main()
{
	newGame();
	int move;

	while (!gameOver())
	{
		DisplayGame();
		switch (whoseTurn)
		{
		case 'X':
			move = playerMoves();
			break;
		case 'O':
			move = computerMoves();
			break;
		}
		MakeMove(move);
	}
	result();
	system("pause");
}