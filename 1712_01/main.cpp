#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int da[1010];

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> da[i];
	}
	sort(da, da + n);
	int min = 30000;
	for (int i = 0; i < n - 1; i++)
	{
		int chazhi = abs(da[i] - da[i + 1]);
		if (chazhi < min)
		min = chazhi;
	}
	printf("%d\n", min);
	return 0;
}
