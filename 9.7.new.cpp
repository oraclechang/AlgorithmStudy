#ifdef _9_7_NEW_

/*
Problem

Solution

*/

#include "Header.h"

bool PaintFill(vector< vector < int > >& vvScreen, int x, int y, int nOldColor, int nNewColor)
{
	if (x < 0 || 
		y < 0 || 
		x >= vvScreen[0].size() || 
		y >= vvScreen.size())
		return false;

	if (vvScreen[y][x] == nOldColor)
	{
		vvScreen[y][x] = nNewColor;

		PaintFill(vvScreen, x - 1, y, nOldColor, nNewColor);
		PaintFill(vvScreen, x + 1, y, nOldColor, nNewColor);
		PaintFill(vvScreen, x, y - 1, nOldColor, nNewColor);
		PaintFill(vvScreen, x, y + 1, nOldColor, nNewColor);
	}

	return true;
}

template< typename T >
void PrintResult(T vvArr)
{
	for (auto x : vvArr)
	{
		for (auto y : x)
			cout << y << " ";
		
		cout << endl;
	}
}

void main()
{
	vector< vector< int > > vvScreen(4, vector< int >(4, 0));
	vvScreen[1][1] = 1;
	vvScreen[1][2] = 1;
	vvScreen[2][1] = 1;
	vvScreen[2][2] = 1;

	PrintResult(vvScreen);

	PaintFill(vvScreen, 1, 1, 1, 2);

	PrintResult(vvScreen);
}

#endif
