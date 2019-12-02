#include <iostream>
//卖菜这道题也很是让我懵逼啊 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[2010], b[2010], c[2010], d[2010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &c[i], &d[i]);
	}
	
	int i = 0, j = 0, sum = 0;
	while (i < n && j < n)
	{
		if (c[j] > b[i]) i++;
		else if (a[i] > d[j]) j++;
		else
		{
			int start, end, time;
			a[i] <= c[j] ? start = c[j] : start = a[i];
			//b[i] <= d[j] ? start = b[i] : start = d[j];
			if (b[i] <= d[j])
			{
				end = b[i];
				i++;
			}
			else
			{
				end = d[j];
				j++;
			}
			time = end - start;
			sum += time;
		}
	}
	
	printf("%d", sum);
	return 0;
}
