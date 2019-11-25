/*
	2019.11.24
	6.30
*/

#include <iostream>
#include <algorithm>

#define LITTLE -1000000000 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//int d[51][30001];
//int len[51];
//bool flag[51][30001] = {false};
/*struct da{
	int type;
	int id;
	int score;
}dat[3001];*/
long long priout[5010][101];
int p = 0, q = 0;

struct da{
	//int len;
	long long id;
	long long score;
}; 

struct lei{
	int len;
	da dat[30001];
}leibie[51];

bool cmp(da a, da b)
{
	return a.score > b.score;
}

void insert()
{
	int type;
	long long commodity, score;
	scanf("%d %lld %lld", &type, &commodity, &score);
	leibie[type].dat[leibie[type].len].id = commodity;
	leibie[type].dat[leibie[type].len].score = score;
	leibie[type].len++;
	//dat[type].id[dat[type].len] = commodity;
	//dat[type].score[dat[type].len] = score;
	//dat[type].len++;
}

void move()
{
	int type;
	long long commodity;
	scanf("%d %lld", &type, &commodity);//如果%lld不匹配longlong变量，%d不匹配int变量，可能会出现读入的值有问题 
	//d[type][commodity] = LITTLE;
	for (int i = 0; i < leibie[type].len; i++)
	{
		if (leibie[type].dat[i].id == commodity)
		{
			leibie[type].dat[i].id = -1;
			leibie[type].dat[i].score = LITTLE;
			break;
		}
	}
	//dat[type].id[commodity] = -1;
	//dat[type].score[commodity] = LITTLE;
}

void print(int m)
{
	int k, i, count = 0;
	//bool flag[3001] = {false};
	//bool flag[51][30001] = {false};
	scanf("%d", &k);
	for (i = 0; i < m; i++)
	{
		int out, j;
		scanf("%d", &out);
	//	for (j = 0; j < out; j++)
	//	{
			if (count < k)
			{
				/*int a, max = LITTLE, maxk, maxcount;
				for (a = 0; a < dat[i].len; a++)
				{
					if (max < dat[i].score[a] && flag[i][a] == false)
					{
						max = dat[i].score[a];
						maxk = dat[i].id[a];
						maxcount = a;
					}
				}
				printf("%d", maxk);
				flag[i][maxcount] = true;
				count++;
				if (j == out - 1) printf("\n");
				else if (count == k) printf("\n");
				else printf(" ");*/
				sort(&leibie[i].dat[0], &leibie[i].dat[leibie[i].len], cmp);//sort中必须是地址，数组的话数组名称就是地址（ps：不带括号） 
				for (int a = 0; a < out; a++)
				{
					priout[p][q] = leibie[i].dat[a].id;
					//printf("%d", leibie[i].dat[a].id);
					q++;
					count++;
					if (count >= k)
					{
						//printf("\n");
						priout[p][q] = -2;
						p++;
						q = 0;
						break;
					}
					else if (a == out - 1) 
					{
						priout[p][q] = -2;
						p++;
						q = 0;	
					}//printf("\n");
					//else printf(" ");
				}
				//sort(dat[i].score[0], dat[i].score[dat[i].len], cmp);
			}
			else
			{
				priout[p][q] = -1;
				q++;
				priout[p][q] = -2;
				p++;
				q = 0;
				//printf("-1\n");
			}
	//	}		
	}
	//p++;
}

int main(int argc, char** argv) {
	int m, n, i, cz;
	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++)
	{
		int j;
		long long id, score;
		scanf("%lld %lld", &id, &score);
		for (j = 0; j < m; j++)
		{
			leibie[j].dat[i].id = id;
			leibie[j].dat[i].score = score;
			//dat[j].id[i] = id;
			//dat[j].score[i] = score;
			//dat[j].len++;
			if (i == 0) leibie[j].len = 0;
			leibie[j].len++;
		}
	}
	
	scanf("%d", &cz);
	for (i = 0; i < cz; i++)
	{
		int k;
		scanf("%d", &k);
		switch(k)
		{
			case 1: insert(); break;
			case 2: move(); break;
			case 3: print(m); break;
			default:break;
		}
	}
	
	for (i = 0; i < p; i++)
	{
		int j = 0;
		while (priout[i][j] > -2)
		{
			printf("%lld", priout[i][j]);
			j++;
			if (priout[i][j] != -2) printf(" ");
			else if (i != p - 1)printf("\n");
		}
	}
	
	return 0;
}
