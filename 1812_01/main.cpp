#include <iostream>
/*
	���������ʱ�򣬲�����û��\n����
	˵������𰸽�һ����ʱ�򣬲��û���
	��������ж����ʱ����Ϊ��ͬ�����֣����Ա��뻻�� 
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
