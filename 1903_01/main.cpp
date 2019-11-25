#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, middle1, middle2;
	int max, min, middle;
	float middlef;
	int i = 1;
	int first, second;
	scanf("%d", &n);
	if (n % 2 == 1)
	{
		middle1 = n / 2 + 1;
		for (i = 1; i <= n; i++)
		{
			int data;
			scanf("%d", &data);
			if (i == 1) max = data;
			else if(i == n) min = data;
			else if(i == middle1) middle = data;
		}
		first = middle1;
		second = middle1;
	}
	else
	{
		
		middle1 = n / 2;
		middle2 = n / 2 + 1;
		for (i = 1; i <= n; i++)
		{
			int data;
			scanf("%d", &data);
			if (i == 1) max = data;
			else if(i == n) min = data;
			else if(i == middle1) first = data;
			else if(i == middle2) second = data;
		}
		if ((first + second) % 2 != 0)
		middlef = (first + second) * 1.0 / 2.0;
		else
		middle = (first + second) / 2;
	}
	
	if (min > max)
	{
		int temp;
		temp = min;
		min = max;
		max = temp;
	}
	
	if ((first + second) % 2 != 0)
		printf("%d %.1f %d", max, middlef, min);
	else
		printf("%d %d %d", max, middle, min);
	return 0;
}
