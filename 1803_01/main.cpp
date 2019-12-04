#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int jump;
	int sum = 0, leiji = 0;
	while (1)
	{
		scanf("%d", &jump);
		if (jump == 0) break;
		else if (jump == 1) 
		{
			sum += 1;
			leiji = 0;
		}
		else
		{
			leiji += 2;
			sum += leiji;
		}
	}
	printf("%d", sum);
	return 0;
}
