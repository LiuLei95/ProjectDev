/*
	2019.11.17
	time used:25min
*/
#include <iostream>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fruit[1000][1000];
int jianguo[1000] = {0};

int main(int argc, char** argv) {
	//system("pause");
	int n, m, T = 0, max = 0, k = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			scanf("%d", &fruit[i][j]);
			T += fruit[i][j];
			if (j != 0) jianguo[i] -= fruit[i][j];
		}	
			
		if (jianguo[i] > max) 
		{
			max = jianguo[i];
			k = i;
		}
	}
	
	printf("%d %d %d", T, k, max);
	return 0;
}
