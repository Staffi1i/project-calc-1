#pragma once
#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <string>
#include <locale.h>
void vvodchisla(int& len, char a1[100], int** a, int& n, int& len2);
void lenstr(int& cnt_1,int & cnt_2, char a1[100]);
void output(int** a, int &len, int &n, int&len2, char &y);
void summa(int** a, int** b, int** c, int& cnt1, int& cnt2, int & p_len1_1, int &p_len2_1,int&n, int&p_len1_2, int&p_len2_2);
void output_test(int** a, int& len);
void difference(int** a, int** b, int** c, int& len1, int& len2, int& p_len1, int& p_len2, int& cnt_v_1, int& cnt_v_2, bool& znak_num, int&n);
void multiplication(int** a, int** b, int** c, int& len1, int& len2, int& cnt_v_1, int& cnt_v_2, int&n);