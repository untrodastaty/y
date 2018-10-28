
#include "stdafx.h";

#include <stdio.h>;

#include <iostream>;

#include <conio.h>;


using namespace std;

int main(int argc, _TCHAR* argv[])
{
	int n;
	bool t = 0;
	int k = 0;
	printf("Enter the number of marked points (no more than 10 000): \n");
	cin >> n;
	int xy[2][10000];
	//entering points
	for (int i = 0; i <= n-1; i++)
	{
		printf("\nEnter the coordinate x of the %d point: \n",i+1);
		cin >> xy[0][i];
		printf("\nEnter the coordinate y of the %d point: \n", i+1);
		cin >> xy[1][i];
	}
	int maxx;
	int minx;
	int maxy;
	int miny;
	while (n>0)
	{
		maxx = xy[0][0];
		minx = xy[0][0];
		maxy = xy[1][0];
		miny = xy[1][0];
		//finding minimum and maximum points
		for (int i = 0; i <= n - 1; i++)
		{
			if (minx >= xy[0][i])
			{
				minx = xy[0][i];
			}
			if (maxx < xy[0][i])
			{
				maxx = xy[0][i];
			}
			if (miny > xy[1][i])
			{
				miny = xy[1][i];
			}
			if (maxy <  xy[1][i])
			{
				maxy = xy[1][i];
			}
		}
		//if 1 point in array
		if ((minx == maxx) && (miny == maxy))
		{
			n--;
			k++;
		}
		else
		{
			for (int x1 = minx; x1 <= maxx; x1++)
			{
				for (int i = 0; i <= n - 1; i++)
				{
					if (((xy[0][i] == x1) && (xy[1][i] == miny)) || ((xy[0][i] == x1) && (xy[1][i] == maxy)))
					{
						n--;
						for (int i1 = i; i1 <= n - 1; i1++)
						{
							xy[0][i1] = xy[0][i1 + 1];
							xy[1][i1] = xy[1][i1 + 1];
						}
					}
				}
			}
			for (int y1 = minx; y1 <= maxx; y1++)
			{
				for (int i = 0; i <= n - 1; i++)
				{
					if (((xy[0][i] == minx) && (xy[1][i] == y1)) || ((xy[0][i] == maxx) && (xy[1][i] == y1)))
					{
						n--;
						for (int i1 = i; i1 <= n - 1; i1++)
						{
							xy[0][i1] = xy[0][i1 + 1];
							xy[1][i1] = xy[1][i1 + 1];
						}
					}
				}
			}
			k++;
		}		
	}
	printf("\nUnpainted cells  will not remain after %d steps\nEnter any symbol for exit:\n", k);
	char s;
	cin >> s;
	return 0;
}

