#include <iostream>
#include <queue>
using namespace std;

//�ַ������������⿴һ�� 
//��Ҫ�����ַ���������
//ͨ��char�������string�����ַ�����string��GitHub���
//������Ҫͨ������queue��һ��queue<int>�����洢x��/���������ֵ��һ��queue<char>�����洢=��-���š�
//ͨ��queue<char>.empty()����ж������Ƿ���� 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int judge(char d[])
{
	int result = 0;
	int i;
	queue<int> number;
	queue<char> fh;
	for (i = 1; i < 7; i+=2)
	{
		int t = d[i - 1] - '0';
		//���ǵ����˷����������� 
		for (; i < 7 && (d[i] == 'x' || d[i] == '/'); i += 2)
		{
			//int t = d[i - 1] - '0';
			if (d[i] == 'x')
			{
				t = t * (d[i + 1] - '0');
			}
			else
			{
				t /= (d[i + 1] - '0');
			}
		}
		number.push(t);	
		
		//��������������Կ��������ÿһ���ַ�����߼���+0�������ַ����������GitHub������� 
		//���ǵ�������˻�������������i����Ϊ7������Ҫ��ֹ�����������š� 
		if (i < 7) fh.push(d[i]);		
		//���ǵ����˵���һ��������+��-�Ļ�����Ҫд����ź�������� 
		if (i == 5) number.push(d[6] - '0');
		
		//��������д�������������޵����⣬��Ϊchar��ʾ���������ޣ�eg 9x9x9�ͻ���������� 
		/*if (d[i] == 'x')
		{
			d[i - 1] = (d[i - 1] - '0') * (d[i + 1] - '0') + '0';
			for (int j = i; d[j] != '\0'; j++)
			{
				d[j] = d[j + 2];
			}
			i--;
		}
		else if (d[i] == '/')
		{
			d[i - 1] = (d[i - 1] - '0') / (d[i + 1] - '0') + '0';
			for (int j = i; d[j] != '\0'; j++)
			{
				d[j] = d[j + 2];
			}
			i--;
			//d[i - 1] = '0';
			//d[i] = '+';
		}*/
	}
	
	/*result = d[0] - '0';
	for (i = 1; d[i] != '\0'; i++)
	{
		if (d[i] == '+')
		{
			result += d[i + 1] - '0';
		}
		else if (d[i] == '-')
		{
			result -= d[i + 1] - '0';
		}
	}*/
	result = number.front();
	number.pop();
	while(!fh.empty())
	{
		char c = fh.front();
		fh.pop();
		c == '+' ? result += number.front() : result -= number.front();
		number.pop();
	}
	
	//result == 24 ? return 1 : return 0; 
	if (result == 24) return 1;
	else return 0;
}

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char d[8];
		int flag;
		scanf("%s", d);
		flag = judge(d);
		flag == 1 ? printf("Yes\n") : printf("No\n");
	}

	return 0;
}
