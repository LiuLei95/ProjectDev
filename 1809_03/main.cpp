#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct l{
	int grad;
	string word;
}line[110];
int main(int argc, char** argv) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", &line[i].word[0]);
		line[i].grad = 0;
		for (int j = 0; j < line[i].word.size(); j++)
		{
			if (line[i].word[j] == '.') line[i].grad++;
			else break;
		}
		line[i].grad /= 2;
	}
	
	for (int j = 1; j <= m; j++)
	{
		string s;
		scanf("%s", &s[0]);
		
		int flag = 1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[0] == '#') 
			{
				flag = 2;
				break;
			}
			else if (s[i] == ' ')
			{
				flag = 3;
				break;
			}
		}
		
		switch(flag)
		{
		case 1:
			int d[100];
			int count = 0;
			for (int i = 1; i <= n; i++)
			{
				//int len = s.length();
				int flag = strnicmp((&line[i].word[0]) + line[i].grad * 2, &s[0], s.size());
				if (flag == 0) 
				{
					d[count] = i;
					count++;
				}
			}
			printf("%d ", count);
			for (int i = 0; i < count; i++)
			{
				printf("%d", d[i]);
				if (i != count - 1) printf(" ");
				else printf("\n");
			}
			break;	
		}
	}
	
	return 0;
}
