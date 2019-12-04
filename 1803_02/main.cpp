/*
	2019.12.01
	time used : 1h
	knowledge : struct sort
*/

#include <iostream>
#include <algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct b{
	int in;
	int LorR;//1 right, -1 left
	int location;
}ball[110];

bool cmp (b one, b two)
{
	return one.location < two.location;
}

bool cmp2 (b one, b two)
{
	return one.in < two.in;
}

int main(int argc, char** argv) {
	int L, n, t;
	int min = 1001, max = -1;
	int mink = -1, maxk = -1;
	scanf("%d %d %d", &n, &L, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ball[i].location);
		ball[i].in = i;
		/*if (ball[i].location > max)
		{
			max = ball[i].location;
			maxk = i;
		}
		if (ball[i].location < min)
		{
			min = ball[i].location;
			mink = i;
		}*/
	}
	
	for (int i = 0; i < n; i++)
	{
		ball[i].LorR = 1;
	}
	
	sort(ball, ball + n, cmp);
	
	for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//judge right or left
			//the most left ball
			if (j == 0)
			{
				if (ball[j].location == 0) ball[j].LorR = -ball[j].LorR;
				if (ball[j].location == ball[j + 1].location) 
				{
					ball[j].LorR = -ball[j].LorR;
					ball[j + 1].LorR = -ball[j + 1].LorR;
				}
			}
			//the most right ball
			else if (j == n - 1)
			{
				if (ball[j].location == L) ball[j].LorR = -ball[j].LorR;
				if (ball[j].location == ball[j - 1].location) 
				{
					ball[j].LorR = -ball[j].LorR;
					ball[j - 1].LorR = -ball[j - 1].LorR;
				}
			}
			//other's ball
			else
			{
				if (ball[j].location == ball[j + 1].location) 
				{
					ball[j].LorR = -ball[j].LorR;
					ball[j + 1].LorR = -ball[j + 1].LorR;
				}
				if (ball[j].location == ball[j - 1].location) 
				{
					ball[j].LorR = -ball[j].LorR;
					ball[j - 1].LorR = -ball[j - 1].LorR;
				}
			}
		
			//run
			if (ball[j].LorR == 1) ball[j].location++;
			else if (ball[j].LorR == -1) ball[j].location--;
		}
	}
	
	sort (ball, ball + n, cmp2);
	
	for (int i = 0; i < n; i++)
	{
		printf("%d", ball[i].location);
		if (i != n - 1) printf(" ");
	}
	return 0;
}
