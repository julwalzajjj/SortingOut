// osnovdz1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdio.h> 
#include <time.h> 
#include <fstream>
#include <windows.h>

using namespace std;
int bubble_sort(int  *A, int colvo) {
	int k;
	for (int i = 0; i < colvo; i++)
		for (int j = 0; j < colvo - 1; j++) {
			if (A[j] > A[j + 1]) {
				k = A[j];
				A[j] = A[j + 1];
				A[j + 1] = A[j];
			}
		}
	return 0;
}
int insertion_sort(int *A, int colvo) {
	for (int i = 0; i < colvo - 1; i++) {
		int ind = i;
		int max = A[ind];
		for (int j = i + 1; j < colvo; j++) {
			if (max < A[j]) {
				max = A[j];
				ind = j;
			}
		}
		swap(A[i], A[ind]);
	}
	return 0;
}
int selection_sort(int *A, int colvo) {
	for (int i = 0; i < colvo; i++) {
		int min = A[i];
		int ind = i;
		for (int j = i + 1; j < colvo; j++) {
			if (A[j] < min) {
				min = A[j];
				ind = j;
			}
		}
		swap(A[i], A[ind]);
	}
	return 0;
}
void merge(int* A, int left, int right, int sr)
{
	int j = left;
	int k = sr + 1;
	int count = right - left + 1;

	if (count <= 1) return;

	int* M;
	M = new int[count];

	for (int i = 0; i < count; ++i) {
		if (j <= sr && k <= right) {
			if (A[j] < A[k])
				M[i] = A[j++];
			else
				M[i] = A[k++];
		}
		else {
			if (j <= sr)
				M[i] = A[j++];
			else
				M[i] = A[k++];
		}
	}

	j = 0;
	for (int i = left; i <= right; ++i) {
		A[i] = M[j++];
	}
	delete[] M;
}
void merge_sort(int* A, int left, int right) {
	int sr;                   
	if (left < right) {            

		sr = (left + right) / 2;

		merge_sort(A, left, sr);    
		merge_sort(A, sr+1, right);
		merge(A, left, right, sr);    
	}
}
void quick_sort(int* A, int L, int R) {
	if ((R - L) <= 1) return;
	int mid = A[L + rand() % (R - L)];
	int x = L, y = L;
	for (int i = L; i < R; ++i)
		if (A[i] < mid) {
			swap(A[x], A[i]);
			if (x != y) swap(A[y], A[i]);
			++x; ++y;
		}
		else if (A[i] == mid) {
			swap(A[y], A[i]);
			++y;
		}
	quick_sort(A, L, x);
	quick_sort(A, y, R);
}
int main()
{
	double N;
	ofstream txtout1;
	txtout1.open("C:\\Users\\user\\Documents\\uchebniki\\new\\margeesort.txt");
	ofstream txtout2;
	txtout2.open("C:\\Users\\user\\Documents\\uchebniki\\new\\bubblesortttt.txt");
	ofstream txtout3;
	txtout3.open("C:\\Users\\user\\Documents\\uchebniki\\new\\insertionss.txt");
	ofstream txtout4;
	txtout4.open("C:\\Users\\user\\Documents\\uchebniki\\new\\selectionsssort.txt");
	ofstream txtout5;
	txtout5.open("C:\\Users\\user\\Documents\\uchebniki\\new\\quiksortt.txt");

	if ((!txtout1) || (!txtout2) || (!txtout3) || (!txtout4) || (!txtout5))
		cout << "Ne udalos' otkritt fail";
	else
	{

		for (N = 10; N <= 50010; N += 1000) {
			int* B;
			B = new int[N];
			srand(time(0));
			for (int i = 0; i < N; i++)
				B[i] = rand() % 25 + 1;
			clock_t start = clock();
			bubble_sort(B, N);
			clock_t end = clock();
			double s = (double)end - (double)start;
			cout << s << " ";
			txtout2 << s << " " << N << endl;

			clock_t start1 = clock();
			insertion_sort(B, N);
			clock_t end1 = clock();
			double s1 = (double)end1 - (double)start1;
			cout << s1 << " ";
			txtout3 << s1 << " " << N << endl;

			clock_t start2 = clock();
			selection_sort(B, N);
			clock_t end2 = clock();
			double s2 = (double)end2 - (double)start2;
			cout << s2 << " ";
			txtout4 << s2 << " " << N << endl;

			clock_t start4 = clock();
			merge_sort(B, 0, N - 1);
			clock_t end4 = clock();
			double s4 = (double)end4 - (double)start4;
			cout << s4 << " ";
			txtout1 << s4 << " " << N << endl;
			
			clock_t start3 = clock();
			quick_sort(B, 0, N);
			clock_t end3 = clock();
			double s3 = (double)end3 - (double)start3;
			cout << s3 << " ";
			txtout5 << s3 << " " << N << endl;

			cout << endl;

		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
