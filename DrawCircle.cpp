#ifdef _DRAW_CIRCLE_

/*
Problem

Solution

*/

#include "Header.h"

void DrawPoint(int x, int y)
{
	cout << "x : " << x << " y : " << y << endl;
}

void DrawCircle(int rx, int ry, int r)
{
	for (int i = rx - r; i <= rx + r; ++i)
		for (int j = ry - r; j <= ry + r; ++j)
			if ( (i * i) + (j * j) == (r * r) )
				DrawPoint(i, j);
}

void main()
{
	DrawCircle(0, 0, 5);
}

#endif
