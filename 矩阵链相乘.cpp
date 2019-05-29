#include<iostream>
#include<cstring> 
using namespace std;

//������������ӣ�û�ж�̬�������ɸĽ�
int p[100];//p �洢ÿ�������ά��
int m[100][100], s[100][100];//m�洢���е���С��������s�洢��Ӧ���еķָ��


void matrixchain(int dim)
{
	int begin, Length, end, mid, tmp;
	memset(m, 0, sizeof(m));
	memset(s, 0, sizeof(s));//��ʼ������
	for (Length = 2; Length <= dim; Length++)//�������˵Ĺ�ģΪr 
	{
		for (begin = 1; begin <= dim - Length + 1; begin++)
		{
			end = begin + Length - 1;
			m[begin][end] = m[begin + 1][end] + p[begin - 1] * p[begin] * p[end];//��m[][]��ʼ��ֵ
			s[begin][end] = begin;//s[][]�洢��������ľ��ߵ�
			for (mid = begin + 1; mid < end; mid++)//Ѱ������ֵ
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
	print(s[begin][end] + 1, end);//�ݹ�1��s[1][j]
	cout << ")";
}

int main()
{
	int dim;
	cout << "���������ĸ���n : " << endl;
	cin >> dim;
	int i, j;
	cout << "����������ÿ����������������һ�������������" << endl;
	for (i = 0; i <= dim; i++)
		cin >> p[i];
	matrixchain(dim);
	print(1, dim);
	cout << endl;
	cout << "��С��������ֵΪ��" << m[1][dim] << endl;

	system("pause");
	return 0;
}