#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int price[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &price[i]);
	}
	
	for (int i = 0; i < n; i++)
	{
		int newprice;
		if (i == 0) newprice = (price[i + 1] + price[i]) / 2;
		else if(i == n - 1) newprice = (price[i - 1] + price[i]) / 2;
		else
		{
			newprice = (price[i - 1] + price[i] + price[i + 1]) / 3;
		}
		
		printf("%d", newprice);
		if (i != n - 1) printf(" ");
	}
	return 0;
}
