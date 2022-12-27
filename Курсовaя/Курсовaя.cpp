#include "StdAfx.h"

#include <iostream>

#include <locale.h>

#include <cstdlib>

#include <conio.h>

#include <iostream>

#include <algorithm>

#include <fstream>

#include <stdlib.h>

#include <time.h>

#include <ctime>

#include <fstream> // ������ � �������

#include <iomanip> // ������������ �����/������

//������������ �������� ���� = 100

#define INF 101

using namespace std;


typedef struct Node {

int vertex;

struct Node* next;

} Node;


int main() {

setlocale(LC_ALL, "RUS");

srand(time(NULL));

fstream _file;

int** mas, N;// N-���������� ������

int menu,quest;

cout << "1-�������������� ���������� ������� ���������" << endl;

cout << "2-������ ���� ������� ���������" << endl;

cin >> menu;

if (menu == 1) //�������������� ����������

{

cout << "������� ������ ������� N x N" << endl;

cin >> N;

mas = (int**)malloc(N * sizeof(int*));

for (int i = 0; i < N; i++)

{

mas[i] = (int*)malloc(N * sizeof(int));

}

for (int i = 0; i < N; i++)

{

mas[i][i] = 0;

for (int j = i + 1; j < N; j++)

{

mas[i][j] = 1 + rand() % 201;

mas[j][i] = mas[i][j];

if (mas[i][j] > 100)

{

mas[i][j] = 10000;

mas[j][i] = mas[i][j];

}

}

}

printf("\n����� ������� ���������\n ");

printf("\n ");

printf("\t");

for (int i = 0; i < N; i++) {

printf("%d\t", i + 1);

}

cout << endl;

for (int i = 0; i < N; i++) { // ����� ������ ���������

printf("\n");

printf("%d\t", i + 1);

for (int j = 0; j < N; j++) {

printf("%d\t", mas[i][j]);

}

}

cout << endl;

cout << endl;

for (int k = 0; k < N; k++)

{

for (int i = 0; i < N; i++)

{

for (int j = 0; j < N; j++)

{

if (mas[i][j] > mas[i][k] + mas[k][j])

mas[i][j] = mas[i][k] + mas[k][j];

}

}

}

cout << "\t";

for (int i = 0; i < N; i++)

{

cout << i+1 << "\t";

};

cout << endl;

cout << endl;

for (int i = 0; i < N; i++)

{

cout << i+1 << "\t";

for (int j = 0; j < N; j++)

{

cout << mas[i][j] << "\t";

}

cout << endl;

}

cout << endl;

cout << "�������� ��������� � ���� ������ ?" << endl;

cout << "1-��" << endl;

cout << "2-���" << endl;

cin >> quest;

if (quest == 1)

{

_file.open("������.txt",ios_base::app);

if (_file.is_open())

{

for (int i = 0; i < N; i++)

{

_file << i + 1 << "\t";

};

_file << endl;

_file << endl;

for (int i = 0; i < N; i++)

{

_file << i + 1 << "\t";

for (int j = 0; j < N; j++)

{

_file << mas[i][j] << "\t";

}

_file << endl;

_file << endl;

}

_file << "---------------------------------------------------------";

}

else

{

cout << "�� ������� �������� ������ � ����!!";

}

_file.close();

}

}

if (menu == 2) // ������ ���������� �������

{

cout << "������� ������ ������� N x N" << endl;

cin >> N;

cout << endl;

cout << endl;

mas = (int**)malloc(N * sizeof(int*));

for (int i = 0; i < N; i++)

{

mas[i] = (int*)malloc(N * sizeof(int));

}

cout << "��������� ������:" << endl;

cout << "���� ������� �� ������� ������� ������� �������� ������ 100!!";

cout << endl;

for (int i = 0; i < N; i++)

{

for (int j = 0; j < N; j++)

{

cout << "������� [" << i << "][" << j << "]=";

cin >> mas[i][j];

}

}

cout << endl;

cout << "\t";

for (int i = 0; i < N; i++)

{

cout << i + 1 << "\t";

}

cout << endl;

cout << endl;

for (int i = 0; i < N; i++)

{

cout << i + 1 << "\t";

for (int j = 0; j < N; j++)

{

cout << mas[i][j]<<"\t";

}

cout << endl;

}

for (int k = 0; k < N; k++)

{

for (int i = 0; i < N; i++)

{

for (int j = 0; j < N; j++)

{

if (mas[i][j] > mas[i][k] + mas[k][j])

mas[i][j] = mas[i][k] + mas[k][j];

}

}

}

cout << endl;

cout << endl;

cout << "\t";

for (int i = 0; i < N; i++)

{

cout << i + 1 << "\t";

};

cout << endl;

cout << endl;

for (int i = 0; i < N; i++)

{

cout << i + 1 << "\t";

for (int j = 0; j < N; j++)

{

cout << mas[i][j] << "\t";

}

cout << endl;

}

cout << endl;

cout << "�������� ��������� � ���� ������?" << endl;

cout << "1-��" << endl;

cout << "2-���" << endl;

cin >> quest;

if (quest == 1)

{

_file.open("������", ios_base::app);

if (_file.is_open())

{

for (int i = 0; i < N; i++)

{

_file << i + 1 << "\t";

};

_file << endl;

_file << endl;

for (int i = 0; i < N; i++)

{

_file << i + 1 << "\t";

for (int j = 0; j < N; j++)
	_file << mas[i][j] << "\t";

}

_file << endl;

_file << endl;

}

_file << "------------------------------------------------";

}

else

{

cout << "�� ������� �������� ������ � ����!!";

}

_file.close();

}

}


