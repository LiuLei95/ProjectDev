#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct l{
	int grad;
	char word[90];
}line[110];

int main(int argc, char** argv) {
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		//scanf("%s", line[i].word);
		gets(line[i].word);		
		//ps:���˵wordΪstring����ô��cin>>str, �������д������������ 
		//scanf("%s", &line[i].word[0]);
		
		line[i].grad = 0;
		int len = strlen(line[i].word);
		for (int j = 0; j < len; j++)
		{
			if (line[i].word[j] == '.') line[i].grad++;
			else break;
		}
		line[i].grad /= 2;
	}
	
	for (int j = 1; j <= m; j++)
	{
		char s[90];
		gets(s);
		
		int flag = 1;
		for (int i = 0; i < strlen(s); i++)
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
		
		
		int d[100];
		int count = 0;
		switch(flag)
		{
		case 1:
			count = 0;
			for (int i = 1; i <= n; i++)
			{
				//int len = s.length();
				//int flag = strnicmp(line[i].word + line[i].grad * 2, s, strlen(s));
				char lab[90];
				int k;
				for (k = 0; k < strlen(line[i].word); k++)
				{
					if (line[i].word[k] == ' ' || line[i].word[k] == '\0')
					{
						k++;
						break;
					}
					lab[k] = line[i].word[k];
				}
				lab[k] = '\0';
				int flag = strnicmp(line[i].word + line[i].grad * 2, s, strlen(s));
				
				if (flag == 0) 
				{
					d[count] = i;
					count++;
				}
			}
			
			
			printf("%d", count);
			if (count == 0) printf("\n");
			else printf(" "); 
			for (int i = 0; i < count; i++)
			{
				printf("%d", d[i]);
				if (i != count - 1) printf(" ");
				else printf("\n");
			}
			break;
			
		case 2:
			count = 0;
			for (int i = 1; i <= n; i++)
			{
				char lab[90];
				int k;
				bool copyornot = false;
				int labcount = 0;
				for (k = 0; k < strlen(line[i].word); k++)
				{
					if (copyornot == true) lab[labcount++] = line[i].word[k];
					if (line[i].word[k] == '#')
					{
						copyornot = true;
					}					
				}
				lab[labcount] = '\0';
				int flag = strcmp(lab, &s[1]);
				
				if (flag == 0) 
				{
					d[count] = i;
					count++;
				}
			}
			
			printf("%d", count);
			if (count == 0) printf("\n");
			else printf(" "); 
			for (int i = 0; i < count; i++)
			{
				printf("%d", d[i]);
				if (i != count - 1) printf(" ");
				else printf("\n");
			}
			break;
		//case 3: break;
		//default: break;	
		}
	}
	
	return 0;
}
