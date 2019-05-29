#include<iostream>
#include<cstring> 
using namespace std;

//这里仅用作例子，没有动态声明，可改进
int p[100];//p 存储每个矩阵的维数
int m[100][100], s[100][100];//m存储子列的最小计算数，s存储对应子列的分割点


void matrixchain(int dim)
{
	int begin, Length, end, mid, tmp;
	memset(m, 0, sizeof(m));
	memset(s, 0, sizeof(s));//初始化数组
	for (Length = 2; Length <= dim; Length++)//矩阵连乘的规模为r 
	{
		for (begin = 1; begin <= dim - Length + 1; begin++)
		{
			end = begin + Length - 1;
			m[begin][end] = m[begin + 1][end] + p[begin - 1] * p[begin] * p[end];//对m[][]开始赋值
			s[begin][end] = begin;//s[][]存储各子问题的决策点
			for (mid = begin + 1; mid < end; mid++)//寻找最优值
			{
				tmp = m[begin][mid] + m[mid + 1][end] + p[begin - 1] * p[mid] * p[end];
				if (tmp < m[begin][end])
				{
					m[begin][end] = tmp;
					s[begin][end] = mid;
				}
			}
		}
	}
}

void print(int begin, int end)
{
	if (begin == end)
	{
		cout << "(" << begin-1 << ")";
		return;
	}
	cout << "(";
	print(begin, s[begin][end]);
	print(s[begin][end] + 1, end);//递归1到s[1][j]
	cout << ")";
}

int main()
{
	int dim;
	cout << "请输入矩阵的个数n : " << endl;
	cin >> dim;
	int i, j;
	cout << "请依次输入每个矩阵的行数和最后一个矩阵的列数：" << endl;
	for (i = 0; i <= dim; i++)
		cin >> p[i];
	matrixchain(dim);
	print(1, dim);
	cout << endl;
	cout << "最小计算量的值为：" << m[1][dim] << endl;

	system("pause");
	return 0;
}