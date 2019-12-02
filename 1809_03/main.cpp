#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct l{
	int grad;
<<<<<<< HEAD
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
		//ps:如果说word为string，那么用cin>>str, 用下面的写法好像有问题 
		//scanf("%s", &line[i].word[0]);
		
		line[i].grad = 0;
		int len = strlen(line[i].word);
		for (int j = 0; j < len; j++)
=======
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
>>>>>>> be547b42ad9d5c842857aa419f016df485012d35
		{
			if (line[i].word[j] == '.') line[i].grad++;
			else break;
		}
		line[i].grad /= 2;
	}
	
	for (int j = 1; j <= m; j++)
	{
<<<<<<< HEAD
		char s[90];
		gets(s);
		
		int flag = 1;
		for (int i = 0; i < strlen(s); i++)
=======
		string s;
		scanf("%s", &s[0]);
		
		int flag = 1;
		for (int i = 0; i < s.length(); i++)
>>>>>>> be547b42ad9d5c842857aa419f016df485012d35
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
		
<<<<<<< HEAD
		
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
				
=======
		switch(flag)
		{
		case 1:
			int d[100];
			int count = 0;
			for (int i = 1; i <= n; i++)
			{
				//int len = s.length();
				int flag = strnicmp((&line[i].word[0]) + line[i].grad * 2, &s[0], s.size());
>>>>>>> be547b42ad9d5c842857aa419f016df485012d35
				if (flag == 0) 
				{
					d[count] = i;
					count++;
				}
			}
<<<<<<< HEAD
			
			printf("%d", count);
			if (count == 0) printf("\n");
			else printf(" "); 
=======
			printf("%d ", count);
>>>>>>> be547b42ad9d5c842857aa419f016df485012d35
			for (int i = 0; i < count; i++)
			{
				printf("%d", d[i]);
				if (i != count - 1) printf(" ");
				else printf("\n");
			}
<<<<<<< HEAD
			break;
		//case 3: break;
		//default: break;	
=======
			break;	
>>>>>>> be547b42ad9d5c842857aa419f016df485012d35
		}
	}
	
	return 0;
}
