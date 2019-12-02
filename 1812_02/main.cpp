#include <iostream>
/*
	��������int��Χ�ģ�һ��Ҫ��long long
	������������������10^6�����ݵĸ�������10^5���ܹ��ɴ�10^11,int������
	��long long��ʱ�򣬰��������е���ȫ������Ϊlong long���˷Ѳ��˶��ٿռ䰡 
	��Ȼlong long���Ժ�int�������㣬 ����ֻ��sum��Ҫ��long long  
*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

long long int usetime(int type, int time, long long int sum, int r, int g, int y)
{
	int ys;//= sum % (r + y + g);
	
	if (type == 1) ys = (sum + r - time) % (r + g + y);
	else if (type == 3) ys = (sum + g - time + r) % (r + g + y);
	else ys = (sum + y - time + g + r) % (r + g + y);
	
	if (ys <= r) sum = sum + r - ys;
	else if (ys > r && ys <= r + g)  sum += 0;
	else sum = sum + r + r + g + y - ys;
	return sum;
}

int main(int argc, char** argv) {
	int r, y, g;
	int n;
	long long int sum = 0;
	scanf("%d %d %d", &r, &y, &g);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int type;
		long long int time;
		scanf("%d %d", &type, &time);
		if (type == 0) sum += time;
		else
		{
			sum = usetime(type, time, sum, r, g, y);
		}
	}
	printf("%lld", sum);
	return 0;
}

