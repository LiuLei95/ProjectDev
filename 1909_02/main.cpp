/*
	2019.11.17
	time used: 36min
*/
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, start[1000], end[1000] = {0}, dropcount = 0, sum = 0, E = 0;
	bool dropflag[1000] = {false};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int count;
		scanf("%d", &count);
		for (int j = 0; j < count; j++)
		{
			if (j == 0) 
			{
				scanf("%d", &start[i]);
				end[i] = start[i];
			}
			else
			{
				int now;
				scanf("%d", &now);
				if (now > 0) 
				{
					if (end[i] != now) dropflag[i] = true;
					end[i] = now;
				}
				else end[i] += now;
			}			
		}
		
		sum += end[i];
		if (dropflag[i] == true) dropcount++;
		//if (start[i] != end[i]) dropcount++;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int pred, succ;
		
		if (i == 1) pred = n;
		else pred = i - 1;
		
		if (i == n) succ = 1;
		else succ = i + 1;
		
		if (dropflag[pred] == true && dropflag[i] == true && dropflag[succ] == true)
		{
			E++;
		}
	}
	
	printf("%d %d %d", sum, dropcount, E);
	
	return 0;
}
