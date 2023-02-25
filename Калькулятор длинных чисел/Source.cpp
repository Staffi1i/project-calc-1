#include"Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n1 = 1,n2 = 1,n3 = 1, cnt_v_1 = 0, cnt_v_2 = 0, len1 = 0, len2 = 0, len1_2 = 0, len2_2 = 0, i0 = 0, i1 = 1;
	char a1[100], a2[100];
	char y;
	bool znak_num1 = true, znak_num2 = true, znak_num = true;
	int input;
	cout << "########################################################################################################" << endl;
	cout << "#                                      Калькулятор длинных чисел                                       #" << endl;
	cout << "########################################################################################################" << endl;
	cout << "                    Правила: 1. Числа должны содержать до 100 разрядов." << endl;
	cout << "                             2. При вводе отрицательного числа,ставить перед ним знак -." << endl;
	cout << "                             3. При вводе чисел с точкой, записывать точку в виде . или , " << endl;
	cout << "Введите первое число: "; cin >> a1;
	cout << "Введите второе число: "; cin >> a2;
	lenstr(len1, len1_2, a1);
	lenstr(len2, len2_2, a2);
	if (a1[0] == '-')
	{
		znak_num1 = false;
		for (int i = 0; i < len1; i++)
			a1[i] = a1[i + 1];
		len1--;
	}
	if (a2[0] == '-')
	{
		znak_num2 = false;
		for (int i = 0; i < len2; i++)
			a2[i] = a2[i + 1];
		len2--;
	}
	if ((len1_2 || len2_2) != 0)
	{
		n1 = 2;
		n2 = 2;
		n3 = 2;
	}
	int p_len1 = len1, p_len2 = len2;
	int** a = (int**)malloc(n1 * sizeof(int*));
	for (int i = 0; i < n1; i++)
		a[i] = (int*)malloc((len1) * sizeof(int));

	int** b = (int**)malloc(n2 * sizeof(int*));
	for (int i = 0; i < n2; i++)
		b[i] = (int*)malloc((len2) * sizeof(int));

	vvodchisla(len1, a1, a, n1, len1_2);
	vvodchisla(len2, a2, b, n2, len2_2);

	int** c = (int**)malloc(n3 * sizeof(int*));
	for (int i = 0; i < n3; i++)
		c[i] = (int*)malloc(100 * sizeof(int));
	cout << "1 - Сложение\n2 - Вычитание\n3 - Умножение\n4 - Деление(Not working)\nВведите желаемую операцию: ";
	cin >> input; cout << endl;
	cout << "Вывод производить с разделением чисел по 3 разряда? (y -да, n - нет)"; cin >> y; 
	while (input > 4 && input < 1)
	{
		cout << "Такой операции нет.\n1 - Сложение\n2 - Вычитание\n3 - Умножение\n4 - Деление(Not working)\nВведите желаемую операцию : "; cin >> input;
	}
		switch (input)
		{
		case 1: 
		{ 
			if ((znak_num1 == true && znak_num2 == true) || (znak_num1 == false && znak_num2 == false))
			{
				summa(a, b, c, cnt_v_1, cnt_v_2, p_len1, p_len2, n3, len1_2, len2_2);
				cout << "Результат: ";
				output(c, cnt_v_1, n3, cnt_v_2, y);
			}
			else if (znak_num1 == true && znak_num2 == false)
			{
				difference(a, b, c, len1, len2, p_len1, p_len2, cnt_v_1, cnt_v_2, znak_num, n3);
				if (znak_num == false)
				{
					cout << "Результат: ";
					cout << "-";
					output(c, cnt_v_1, n3, cnt_v_2, y);
				}
				else  if(znak_num == true)
				 {
					cout << "Результат: ";
					output(c, cnt_v_1, n3, cnt_v_2,y);
				 }
			 }
			 else if (znak_num1 == false && znak_num2 == true)
			 {
			  difference(b, a, c, len2, len1, p_len2, p_len1, cnt_v_1, cnt_v_2, znak_num, n3);
			  if (znak_num == false)
			  {
				  cout << "Результат: ";
				  cout << "-";
				  output(c, cnt_v_1, n3, cnt_v_2, y);
			  }
			  else
			 {
				cout << "Результат: ";
			 	output(c, cnt_v_1, n3, cnt_v_2, y);
			 }
			  
			}
			break;
		}
		case 2:
		{
			if (znak_num1 == true && znak_num2 == true)
			{
				difference(a, b, c, len1, len2, p_len1, p_len2, cnt_v_1, cnt_v_2, znak_num, n3);
				if (znak_num == false)
				{
					cout << "Результат: ";
					cout << "-";
					output(c, cnt_v_1, n3, cnt_v_2, y);
				}
				else if (znak_num == true)
				{
					cout << "Результат: ";
					output(c, cnt_v_1, n3, cnt_v_2, y);
				}
			}
			else if (znak_num1 == false && znak_num2 == true)
			{
				summa(a, b, c, cnt_v_1, cnt_v_2, p_len1, p_len2, n3, len1_2, len2_2);
					cout << "Результат: ";
					cout << "-";
					output(c, cnt_v_1, n3, cnt_v_2, y);
				
				
			}
			else if (znak_num1 == false && znak_num2 == false)
			{
				difference(b, a, c, len2, len1, p_len2, p_len1, cnt_v_1, cnt_v_2, znak_num, n3);
				if (znak_num == false)
				{
					cout << "Результат: ";
					cout << "-";
					output(c, cnt_v_1, n3, cnt_v_2, y);
				}
				else
				{
					cout << "Результат: ";
					output(c, cnt_v_1, n3, cnt_v_2, y);
				}
			}
			else if (znak_num1 == true && znak_num2 == false)

			{
				summa(a, b, c, cnt_v_1, cnt_v_2, p_len1, p_len2, n3, len1_2, len2_2);
				cout << "Результат: ";
				output(c, cnt_v_1, n3, cnt_v_2, y);
			}
			break;
		}
		case 3:
		{
			if ((znak_num1 == true && znak_num2 == true) || (znak_num1 == false && znak_num2 == false))
			{
				multiplication(a, b, c, len1, len2, cnt_v_1, cnt_v_2, n3);
				cout << "Результат: ";
				output(c, cnt_v_1, n3, cnt_v_2, y);
			}
			else
			{
				multiplication(a, b, c, len1, len2, cnt_v_1, cnt_v_2, n3);
				cout << "Результат: -";
				output(c, cnt_v_1, n3, cnt_v_2, y);
			}
			break;
		}
		case 4:
		{
			cout << "########################################################################################################" << endl;
			cout << "#                                              Coming soon...                                          #" << endl;
			cout << "########################################################################################################" << endl;
			break;
		}
		}
	
	for (int i = 0; i < n3; i++)
	{
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	free(a); free(b); free(c);
}