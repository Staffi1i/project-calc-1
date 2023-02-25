#include"Header.h"
using namespace std;
void vvodchisla(int& len, char a1[100], int** a, int&n, int&len2)
{
	int len1 = len;
	for (int i = 0; i < 1; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * (len));
		for (int j = 0; j < len; j++)
		{
			a[i][j] = a1[len - 1 - j] - '0';
		}
	}
	if (n == 2)
		for (int i = 1; i < 2; i++)
		{
			a[i] = (int*)malloc(sizeof(int) * (len2));
			for (int j = 0; j < len2; j++)
			{
				a[i][j] = a1[len2 + len - j] - '0';
			}
		}
}
void lenstr(int& cnt_1,int&cnt_2, char a1[100])
{
	int i = 0;
	while (a1[i] != NULL)
	{
		if (a1[i] < '0' && a1[i] >'9' && a1[i] != ',' && a1[i] != '.')
		{
			cout << "„исло введено неверно. ¬ведите число: "; cin >> a1;
			i = 0;
		}
		else i++;
	}
	i = 0;
	while ((a1[i] != NULL) && (a1[i] != '.') && (a1[i] != ','))
	{
		cnt_1 += 1;
		i++;
	}
	if (a1[i] == '.' || a1[i] == ',')
	{
		i++;
		while (a1[i] != NULL)
		{
			cnt_2++;
			i++;
		}
	}
}
void output(int** a, int &len, int &n, int&len2, char&y)
{
	int cnt = 0;
	for (int i = 0; i < 1; i++)
	{
		for (int j = len - 1; j >= 0; j--)
		{
			cout << a[i][j];
			cnt++;
			if (cnt % 3 == 0 && (y == 'y' || y== 'Y' || y == 'у'))
				cout << " ";
		}

	}
	if (n == 2)
	{
		cout << ".";
		for (int i = 1; i < 2; i++)
		{
			for (int j = len2 - 1; j >= 0; j--)
				cout << a[i][j];
		}
	}
	cout << endl;
}
void output_test(int** a, int& len)
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < len; j++)
			cout << a[i][j] << " ";
	}
	cout << endl;
}
void summa(int** a, int** b, int** c, int& cnt_v_11, int& cnt_v_2, int& p_len1_1, int& p_len2_1, int& n, int& p_len1_2, int& p_len2_2)
{
	int p_len1 = p_len1_1;
	int p_len2 = p_len2_1;
	int cnt_v_1 = cnt_v_11;
	bool p = true;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; p == true; j++)
		{
			if ((p_len1 != 0) && (p_len2 != 0))
			{
				c[i][j] = a[i][j] + b[i][j];
				p_len1 -= 1;
				p_len2 -= 1;
				cnt_v_1++;
			}
			else if (p_len2 != 0)
			{
				c[i][j] = b[i][j];
				p_len2 -= 1;
				cnt_v_1++;
			}
			else if (p_len1 != 0)
			{
				p_len1 -= 1;
				cnt_v_1++;
				c[i][j] = a[i][j];
			}
			else p = false;
		}

	}
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < (cnt_v_1 - 1); j++)
		{
			if (c[i][j] > 9)
			{
				c[i][j + 1] += c[i][j] / 10;
				c[i][j] %= 10;
			}
			if (c[i][cnt_v_1 - 1] > 9)
			{
				c[i][cnt_v_1] = c[i][cnt_v_1 - 1] / 10;
				c[i][cnt_v_1 - 1] %= 10;
				cnt_v_1++;
			}
		}
		cnt_v_11 = cnt_v_1;
	}

	if (n == 2)
	{
		p = true;
		p_len1 = p_len1_2;
		p_len2 = p_len2_2;
		cnt_v_1 = cnt_v_2;
		int len32;
		if (p_len1 > p_len2)
			len32 = p_len1;
		else
			len32 = p_len2;
		for (int i = 1; i < 2; i++)
		{
			
			for (int j = 0; p == true; j++)
			{
				if ((p_len1 != 0) && (p_len2 != 0))
				{
					c[i][len32 - 1] = a[i][p_len1 - 1] + b[i][p_len2 - 1];
					p_len1 -= 1;
					p_len2 -= 1;
					cnt_v_1++;
				}
				else if (p_len2 != 0)
				{
					c[i][len32 - 1] = b[i][p_len2 - 1];
					p_len2 -= 1;
					cnt_v_1++;
				}
				else if (p_len1 != 0)
				{
					c[i][len32 - 1] = a[i][p_len1 - 1];
					p_len1 -= 1;
					cnt_v_1++;
				}
				else p = false;
			}
			cnt_v_2 = cnt_v_1;
		}

		for (int i = 1; i < 2; i++)
		{
			for (int j = 0; j < (cnt_v_1 - 1); j++)
			{
				if (c[i][j] > 9)
				{
					c[i][j + 1] += c[i][j] / 10;
					c[i][j] %= 10;
				}
				if (c[i][cnt_v_1 - 1] > 9)
				{
					c[i][cnt_v_1] = c[i][cnt_v_1 - 1] / 10;
					c[i][cnt_v_1 - 1] %= 10;
					cnt_v_1++;
				}
			}
			if (c[1][cnt_v_1 - 1] > 0)
				c[0][0] += 1;
		}
	}
}

void difference(int** a, int** b, int** c, int& len1, int& len2, int& p_len1, int& p_len2, int& cnt_v_1, int& cnt_v_2, bool& znak_num, int&n)
{
	bool p = true;
	for (int i = 0; i < 1; i++)
		for (int j = 0; p == true; j++)
		{
			if (len1 > len2)
			{
				if (p_len1 != 0 && p_len2 != 0)
				{
					c[i][j] = a[i][j] - b[i][j];
					p_len1 -= 1;
					p_len2 -= 1;
					cnt_v_1++;
				}
				else if (p_len1 != 0)
				{
					c[i][j] = a[i][j];
					p_len1 -= 1;
					cnt_v_1++;
				}
				else { p = false; znak_num = true; }
			}
			else if (len1 < len2)
			{
				if (p_len1 != 0 && p_len2 != 0)
				{
					c[i][j] = b[i][j] - a[i][j];
					p_len1 -= 1;
					p_len2 -= 1;
					cnt_v_1++;
				}
				else if (p_len2 != 0)
				{
					c[i][j] = b[i][j];
					p_len2 -= 1;
					cnt_v_1++;
				}
				else { p = false; znak_num = false; }
			}
			else if (len1 == len2)
			{
				if (p_len1 != 0 && p_len2 != 0)
				{
					c[i][j] = a[i][j] - b[i][j];
					p_len1 -= 1;
					p_len2 -= 1;
					cnt_v_1++;
				}
				else p = false;
			}
		}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (cnt_v_1); j++)
		{
			if (c[i][j] > 0)
				if (j >= cnt1)
					cnt1 = j;
			if (c[i][j] < 0)
				if (j >= cnt2)
					cnt2 = j;
		}
	if (cnt1 > cnt2)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (cnt_v_1); j++)
			{
				if (c[i][j] < 0)
				{
					c[i][j] += 10;
					c[i][j + 1] -= 1;
				}
			}
	else
	{
		znak_num = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (cnt_v_1); j++)
				if (c[i][j] < 0)
					c[i][j] *= -1;
	}
}
void multiplication(int** a, int** b, int** c, int& len1, int& len2, int& cnt_v_1, int& cnt_v_2, int&n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 100; j++)
			c[i][j] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < len1; j++)
		{
			int ost = 0;
			for (int l = 0; l < len2; l++)
			{
				c[i][j + l] += a[i][j] * b[i][l] + ost;
				ost = c[i][j + l] / 10;
				c[i][j + l] %= 10;
			}
			if (ost) c[i][j + len2] += ost;
		}
		cnt_v_1 = len1 + len2;
		while (cnt_v_1 > 1 && c[i][cnt_v_1 - 1] == 0) cnt_v_1--;
	}
}