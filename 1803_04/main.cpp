#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct da{
	int zerocount;
	int qp[3][3];
}qijuzushu[5];

void judgeandprint(int k)
{
	//开局0过多，直接平局 
	if (qijuzushu[k].zerocount >= 7)
	{
		printf("0\n");
		return;
	}
	
	//开局就有结果
	for (int h = 0; h < 3; h++)
	{
		int first = qijuzushu[k].qp[h][0];
		int sec = qijuzushu[k].qp[h][1];
		int third = qijuzushu[k].qp[h][2];
		if (first == sec && sec == third)
		{
			if (first == 1)
			{
				printf("%d\n", qijuzushu[k].zerocount + 1);
				return;
			}
			else if (first == 2)
			{
				printf("%d\n", - (qijuzushu[k].zerocount + 1));
				return;
			}
		}	
	}
	int one =  qijuzushu[k].qp[0][0];
	int two =  qijuzushu[k].qp[1][1];
	int three =  qijuzushu[k].qp[2][2];
	int four =  qijuzushu[k].qp[2][0];
	int five =  qijuzushu[k].qp[0][2];
	if (one == two && two == three) 
	{
		if (one == 1)
		{
			printf("%d\n", qijuzushu[k].zerocount + 1);
			return;
		}
		else if (one == 2)
		{
			printf("%d\n", - (qijuzushu[k].zerocount + 1));
			return;
		}
	}
	
	if (four == two && two == five)
	{
		if (one == 1)
		{
			printf("%d\n", qijuzushu[k].zerocount + 1);
			return;
		}
		else if (one == 2)
		{
			printf("%d\n", - (qijuzushu[k].zerocount + 1));
			return;
		}
	}
	
	//再走一步A获胜 
	for (int h = 0; h < 3; h++)
	{
		int first = qijuzushu[k].qp[h][0];
		int sec = qijuzushu[k].qp[h][1];
		int third = qijuzushu[k].qp[h][2];
		if ((first == sec && third == 0) || (first == third && sec == 0) || (sec == third && first == 0))
		{
			if (first == 1 || sec == 1)
			{
				printf("%d\n", qijuzushu[k].zerocount);
				return;
			}
		}	
	}
	one =  qijuzushu[k].qp[0][0];
	two =  qijuzushu[k].qp[1][1];
	three =  qijuzushu[k].qp[2][2];
	four =  qijuzushu[k].qp[2][0];
	five =  qijuzushu[k].qp[0][2];
	if ((one == two && three == 0) || (one == three && two == 0) || (two == three && one == 0))
	{
		if (one == 1 || two == 1)
		{
			printf("%d\n", qijuzushu[k].zerocount);
			return;
		}
	}
	
	if ((four == two && five == 0) || (four == five && two == 0) || (five == two && four == 0))
	{
		if (two == 1 || four == 1)
		{
			printf("%d\n", qijuzushu[k].zerocount);
			return;
		}
	}
	
	//再走一步A获胜不了，B获胜
	int count = 0;
	for (int h = 0; h < 3; h++)
	{
		int first = qijuzushu[k].qp[h][0];
		int sec = qijuzushu[k].qp[h][1];
		int third = qijuzushu[k].qp[h][2];
		if ((first == sec && third == 0) || (first == third && sec == 0) || (sec == third && first == 0))
		{
			if (first == 2 || sec == 2)
			{
				count++;
			}
		}	
	}
	one =  qijuzushu[k].qp[0][0];
	two =  qijuzushu[k].qp[1][1];
	three =  qijuzushu[k].qp[2][2];
	four =  qijuzushu[k].qp[2][0];
	five =  qijuzushu[k].qp[0][2];
	if ((one == two && three == 0) || (one == three && two == 0) || (two == three && one == 0))
	{
		if (one == 2 || two == 2)
		{
			count++;
		}
	}
	
	if ((four == two && five == 0) || (four == five && two == 0) || (five == two && four == 0))
	{
		if (two == 2 || four == 2)
		{
			count++;
		}
	}
	
	if (count >= 2)
	{
		printf("%d\n", -(qijuzushu[k].zerocount - 1));
		return;
	}	  
	printf("0\n");
	return;
}

int main(int argc, char** argv) {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		qijuzushu[k].zerocount = 0;
		for (int h = 0; h < 3; h++)
		{
			for (int l = 0; l < 3; l++)
			{
				cin >> qijuzushu[k].qp[h][l];
				if (qijuzushu[k].qp[h][l] == 0) qijuzushu[k].zerocount++;
			}
		}
		judgeandprint(k);
	}	
	return 0;
}
