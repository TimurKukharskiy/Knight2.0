#include <iostream>
struct knight_move
{
	int x;
	int y;
};
class knight
{
	char a[5][4];
	knight_move mv[9];
	char r[10];
	int p[10];
	int x,y;
	bool state;
public:
	knight();
	~knight();
	void resetp();
	void resetr();
	void printa();
	bool getstate();
	bool getstartel();
	bool findel(char);
	void knightstart();
	void knightcalc(int);
	bool ispresent(char);
	bool isvowel2();
};