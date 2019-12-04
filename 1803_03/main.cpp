#include <iostream>
/*
	notice : <string.h> must have ".h", else strcmp, strlen will don't work
*/
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct u{
	int len;
	char guize[110][110];
	char name[110];
}url[110];

char pipei[110][110];

void dayin(int n, int len)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		int startnumber = 0;
		for (int j = 0; j < len; j++)
		{
			if (len != url[i].len) break;
			
			if (strcmp(pipei[j], url[i].guize[j]) == 0)
			{
				flag = true;
				startnumber = j + 1;
			} 
			else
			{
				bool isNumber = true;
				for (int k = 0; k < strlen(pipei[j]); k++)
				{
					if(pipei[j][k] > '9' || pipei[j][k] < '0')
					{
						isNumber = false;
						break;
					}
				}
				
				char strint[10] = "<int>";
				char strchar[10] = "<char>";
				char strpath[10] = "<path>";
				
				if (isNumber == true)
				{
					if (strcmp(url[i].guize[j], strint) == 0) flag = true;
					else 
					{
						flag = false;
						break;
					}
				}
				else
				{
					if (strcmp(url[i].guize[j], strchar) == 0) flag = true;
					else 
					{
						flag = false;
						break;
					}	
				}
			}
		}
		
		if(flag == true)
		{
			printf("%s ", url[i].name);
			for (int j = startnumber; j < len; j++)
			{
				//int start = 0;
				int k = 0;
				for (k = 0; k < strlen(pipei[j]) - 1; k++)
				{
					if (pipei[j][k] != '0') break;
					//start
				}
				printf("%s", &pipei[j][k]);
				if (j != len - 1) printf(" ");
				//else printf("\n");
			}
			printf("\n");
			break;
		}		
	}
	if (flag == false) printf("404\n");
}

int toword(char rule[], int count)
{
	int h = 0, l = 0, i = 0;
	for (i = 1; i < strlen(rule); i++)
	{
		if (rule[i] == '/')
		{
			url[count].guize[h][l] = '\0';
			h++;
			l = 0;
		}
		else
		{
			url[count].guize[h][l++] = rule[i];	
		}	
	}
	
	if (rule[strlen(rule) - 1] != '/')
	{
		url[count].guize[h][l] = '\0';
		h++;
	}
	return h;
}

int toword2(char rule[], int count)
{
	int h = 0, l = 0, i = 0;
	for (i = 1; i < strlen(rule); i++)
	{
		if (rule[i] == '/')
		{
			pipei[h][l] = '\0';
			h++;
			l = 0;
		}
		else
		{
			pipei[h][l++] = rule[i];	
		}	
	}
	
	if (rule[strlen(rule) - 1] != '/')
	{
		pipei[h][l] = '\0';
		h++;
	}
	return h;
}

int main(int argc, char** argv) {
	int n, m, i;
	char rule[110], road[110];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%s %s", rule, url[i].name);
		url[i].len = toword(rule, i);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%s", road);
		int len = toword2(road, i);
		dayin(n, len);
	}
	return 0;
}
