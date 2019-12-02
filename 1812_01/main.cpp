#include <iostream>
/*
	最后答案输出的时候，不管有没有\n都对
	说明输出答案仅一个的时候，不用换行
	而输出答案有多个的时候，因为不同答案区分，所以必须换行 
*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int r, y, g, n;
	int sum = 0;
	scanf("%d %d %d", &r, &y, &g);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int type, time;
		scanf("%d %d", &type, &time);
		switch(type)
		{
			case 0: sum += time;break;
			case 1: sum += time;break;
			case 2: sum  = sum + time + r;break;
			default: break;			
		}
	}
	printf("%d", sum);
	return 0;
}
