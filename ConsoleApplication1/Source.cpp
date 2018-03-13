#include <stdio.h>
#include <iostream>
#include <locale.h>
#include "Header.h"
#include <time.h>

using namespace std;

int i, j;

void main(int args, char *argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	if (args != 0)
	{
		cout << endl;
		for (int i = 0; i < args; i++)
		{
			cout << argv[i];
		}
		cout << endl;
	}
	short int z;

	while (true)
	{
    	cout << "Kakoe zadanie?" << endl;
		cin >> z;
		switch (z)
		{
		case 1:
		{
			//1.	������ ������������ �����.������� �� ��� ������.���������� ������ ������� �������������� �������� �������.
			int r, two = 0;
			cout << "Vvedite razmer massiva?";cin >> r;
			double *m = (double*)calloc(r, sizeof(double));
			for (int i = 0;i < r;i++)
			{
				cin >> *m;
				m++;
			}
			m = m - r;
			for (int i = 0;i < r;i++)
			{
				cout << *m <<endl;
				if (*m > 0)
				{
					two++;
					if (two == 2)
					{
						cout << *m << endl;
						break;
					}
				}
				m++;
			}
			m = m - r;
		}
		break;
		case 2:
		{
			//2.	������ ������������ �����.������� �� ��� ������.����������� �������� ������� � �������� �������.
			int r;
			float *m = NULL;
			cout << "Vvedite razmer massiva?";cin >> r;
			m = (float*)calloc(r, sizeof(float));
			if (hFill(m, &r) == 0)
			{
				float prom;
				int a = 0, b = r - 1;
				for (int i = 0;i < r/2;i++)
				{
					prom = *(m + a);
					*(m + a) = *(m + b);
					*(m + b) = prom;
					a++;b--;
				}
			}
			print_arr(m, r);
			
		}
		break;
		case 3:
		{
			//3.	������ ����� ����� N � ������ �� N ����� �����.���������� ������� �������������� ��������� �������, �� ������� 3.
			int r;
			int *m = NULL;
			cout << "Vvedite razmer massiva?";cin >> r;
			m = (int*)calloc(r, sizeof(int));
			int sum = 0, sa, count = 0;
			if (hFill(m, &r) == 0)
			{
				for (int i = 0;i < r;i++)
				{
					if (*m % 3 != 0)
					{
						sum += *m;
						count++;
					}
					m++;
				}
				sa = sum / count;
				cout << sa << endl;
			}
		}
		break;
		case 4:
		{
			//4.	������ ����� ����� N.������� ������ �� N ����� �����.�������� ������� ������ � ������������ �������� �������
			int r;
			int *m = NULL;
			cout << "Vvedite razmer massiva?";cin >> r;
			m = (int*)calloc(r, sizeof(int));
			int max = 0, im = NULL;
			if (hFill(m, &r) == 0)
			{
				for (int i = 0;i < r;i++)
				{
					if (*m > max)
					{
						max = *m;
						im = i;
					}
					m++;
				}
				m = m - r;
				int prom;
				prom = m[im];
				m[im] = m[0];
				m[0] = prom;
				print_arr(m, r);
			}
		}
		break;
		case 5:
		{
			//15.	������ ����� �����.������� ������ �� �������� �����.��������� ������������ ������������� ��������� �������.
			int r;
			int *m = NULL;
			int *n = NULL;
			int count = 0;
			cout << "Vvedite razmer massiva?";cin >> r;
			m = (int*)calloc(r, sizeof(int));
			create(m, r, 0, 50, positive);
			for (int i = 0;i < r;i++)
			{
				if (*m % 2 != 0)
					count++;
				m++;
			}
			m = m - r;
			int a = 1;
			n = (int*)calloc(count, sizeof(int));
			for (int i = 0;i < r;i++)
			{
				if (*m % 2 != 0)
				{
					*n = *m;
					n++;
					if (*m > 0)
					{
						a *= *m;
					}
				}
				m++;
			}
			n = n - count;
			print_arr(n, count);
			cout << "Proizvedenie = " << a << endl;
		}
		break;
		case 6:
		{
			/*1.	������� strncpy(s1, s2, n) �������� ����� n �������� �� ������ s2 � ������ s1, ������ ��� ������������� ������ s2 ���
				�������� ���������� ������� ��������������� �������� ���������.������� ������ ����� �� � �������� ������������ �������� �������, 
				���� ����� ������ s2 ����� ��� ������ n.������� ���������� ������ s1.�������� ����������� ������ ���� �������.������������� ��� ������� 
				� ������ ����������� ���������, ������� ���������� ���� ��� �������� ������� �������� ��������������� �������.*/
			int r;
			char s2[] = "������� strncpy(s1, s2, n) �������� ����� n �������� �� ������ s2 � ������ s1, ������ ��� ������������� ������ s2 ���";
			cout << "Vvedite razmer massiva?";cin >> r;
			char *s1 = (char*)calloc(r+1, sizeof(char));
			printf("%s", s2);
			copyS(s2, s1, r);
			printf("%s", s1);
		}
		break;
		}



	}







	system("pause");

}