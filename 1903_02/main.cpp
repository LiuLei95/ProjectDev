#include <iostream>
#include <queue>
using namespace std;

//字符串的运算问题看一下 
//主要考察字符串的运算
//通过char数组或者string读入字符串，string见GitHub题解
//运算主要通过两个queue，一个queue<int>用来存储x、/计算完的数值，一个queue<char>用来存储=、-符号。
//通过queue<char>.empty()最后判断运算是否完成 
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
		//考虑到连乘法或者连除法 
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
		
		//下面两个问题可以靠在输入的每一个字符串后边加上+0这两个字符避免掉。见GitHub上面题解 
		//考虑到最后连乘或者连除结束后，i可能为7，则需要防止读入非运算符号。 
		if (i < 7) fh.push(d[i]);		
		//考虑到如果说最后一个符号是+、-的话，需要写入符号后面的数字 
		if (i == 5) number.push(d[6] - '0');
		
		//下面这种写法会有数据上限的问题，因为char表示的数据有限，eg 9x9x9就会输出错误结果 
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
