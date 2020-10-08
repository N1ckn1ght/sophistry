#include <iostream>
#include <vector>
#include <windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void print_t(vector <int> a)
{
	for (unsigned int i = 0; i < a.size(); i++)
	{
		cout << a[i] << "\t";
	}
}

void ff(vector <bool> fork, vector <bool>& fork_temp)
{
	if (fork != fork_temp)
	{
		SetConsoleTextAttribute(hConsole, 7);
		cout << "��������� �����: ";
		for (unsigned int j = 0; j < fork.size(); j++)
		{
			if (fork[j]) cout << (j + 1) << " ";
		}
		cout << endl;
		fork_temp.assign(fork.begin(), fork.end());
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	SetConsoleTextAttribute(hConsole, 7);
	cout << "�����:" << endl;
	cout << "�����:   5   1   2   3   4   5 ..." << endl;
	cout << "��������:  1   2   3   4   5 ...\n" << endl;

	vector <bool> fork{ 1, 1, 1, 1, 1 };
	vector <int> time_initial{ 20, 5, 30, 15, 2 };
	vector <int> time{ 20, 5, 30, 15, 2 };
	vector <int> status{ 1, 1, 1, 1, 1 };
	
	// stats
	vector <int> starv{ 0, 0, 0, 0, 0 };
	vector <int> think{ 0, 0, 0, 0, 0 };
	vector <int> eatin{ 0, 0, 0, 0, 0 };
	vector <int> fork_idle{ 0, 0, 0, 0, 0 };
	vector <int> fail{ 0, 0, 0, 0, 0 };

	// time
	int lim = 2000;

	SetConsoleTextAttribute(hConsole, 15);
	cout << "������� 1 ���������� � ������� ������: " << time[0] << endl;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "������� 2 ���������� � ������� ������: " << time[1] << endl;
	SetConsoleTextAttribute(hConsole, 13);
	cout << "������� 3 ���������� � ������� ������: " << time[2] << endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout << "������� 4 ���������� � ������� ������: " << time[3] << endl;
	SetConsoleTextAttribute(hConsole, 11);
	cout << "������� 5 ���������� � ������� ������: " << time[4] << endl;
	cout << endl;

	vector <bool> fork_temp;
	fork_temp.assign(fork.begin(), fork.end());

	// ����������� ����������� ��� 4 ��������, ��. ��������.
	int a = 0;
	// ������������� ������ ��� 5 ��������, ��. ��������.
	int timer = 5;

	for (int cycle = 0; cycle < lim; cycle++)
	{
		// ������� 1
		if (time[0] > 0)
		{
			if (status[0] == 1 || status[0] == 3)
			{
				time[0]--;
				think[0]++;
			}
			else if (status[0] == 4)
			{
				time[0]--;
				eatin[0]++;
			}
		}
		if (time[0] == 0)
		{
			if (status[0] == 1)
			{
				if (fork[0])
				{
					fork[0] = false;
					SetConsoleTextAttribute(hConsole, 15);
					cout << "������� 1 �������� ���������� � ���� ����� ������." << endl;

					if (fork[4])
					{
						fork[4] = false;
						SetConsoleTextAttribute(hConsole, 15);
						time[0] = 20;
						status[0] = 4;
						cout << "������� 1 ���� ��� ����� � ����� ���� � ������� ������: " << time[0] << endl;
					}
					else {
						status[0] = 3;
						time[0] = 5;
						cout << "������� 1 �� ���� ����� ����� �����, �� ���������� ������ ����� � ������� ������: " << time[0] << endl;
					}
				}
				else 
				{
					status[0] = 2;
					SetConsoleTextAttribute(hConsole, 15);
					cout << "������� 1 �������� ���������� � ��������� ����������� ����� ������, ����� ��� �����������." << endl;
					starv[0]++;
				}
			}
			else if (status[0] == 2)
			{
				starv[0]++;
			}
			else if (status[0] == 3)
			{
				if (fork[4])
				{
					fork[4] = false;
					SetConsoleTextAttribute(hConsole, 15);
					time[0] = 20;
					status[0] = 4;
					cout << "������� 1 ���� ��� ����� � ����� ���� � ������� ������: " << time[0] << endl;
				}
				else
				{
					fail[0]++;
					fork[0] = true;
					time[0] = 20;
					status[0] = 1;
					SetConsoleTextAttribute(hConsole, 15);
					cout << "������� 1 �� ���� ������ � ������������ � ������������, ������: " << time[0] << endl;
				}
			}
			else if (status[0] == 4)
			{
				fork[0] = true;
				fork[4] = true;
				time[0] = 20;
				status[0] = 1;
				SetConsoleTextAttribute(hConsole, 15);
				cout << "������� 1 �������� ������� � ����� ���������� ������: " << time[0] << endl;
			}
		}
		ff(fork, fork_temp);

		// ���������� ������ ����� ����� �������� �������� 1
		if (status[1] == 2 && fork[0] == true)
		{
			fork[0] = false;
			SetConsoleTextAttribute(hConsole, 14);
			time[1] = 5;
			status[1] = 3;
			cout << "������� 2 ���������� ����� ����� � ����� ���� ��������� ������: " << time[1] << endl;
			starv[1]--;
		}
		if (status[4] == 3 && fork[4] == true)
		{
			fork[4] = false;
			time[4] = 1;
			status[4] = 4;
			SetConsoleTextAttribute(hConsole, 11);
			cout << "������� 5 ���� ��� ����� � ����� ���� � ������� ������: " << time[4] << endl;
		}
		ff(fork, fork_temp);

		// ������� 2
		if (time[1] > 0)
		{
			if (status[1] == 1)
			{
				time[1]--;
				think[1]++;
			}
			else if (status[1] == 3)
			{
				time[1]--;
				eatin[1]++;
			}
		}
		if (time[1] == 0)
		{
			if (status[1] == 1)
			{
				if (fork[1])
				{
					fork[1] = false;
					status[1] = 2;
					SetConsoleTextAttribute(hConsole, 14);
					cout << "������� 2 �������� ���������� � ���� ����� ������, ����� ������� ����� �����." << endl;

					if (fork[0])
					{
						fork[0] = false;
						SetConsoleTextAttribute(hConsole, 14);
						time[1] = 5;
						status[1] = 3;
						cout << "������� 2 ���� ��� ����� � ����� ���� � ������� ������: " << time[1] << endl;
					}
					else
					{
						starv[1]++;
					}
				}
				else
				{
					fail[1]++;
					time[1] = 5;
					SetConsoleTextAttribute(hConsole, 14);
					cout << "������� 2 �� ���� ������ � ������������ � ������������, ������: " << time[1] << endl;
				}
			}
			else if (status[1] == 2)
			{
				if (fork[0])
				{
					fork[0] = false;
					SetConsoleTextAttribute(hConsole, 14);
					time[1] = 5;
					status[1] = 3;
					cout << "������� 2 ���� ��� ����� � ����� ���� � ������� ������: " << time[1] << endl;
				}
				else
				{
					starv[1]++;
				}
			}
			else if (status[1] == 3)
			{
				fork[1] = true;
				fork[0] = true;
				time[1] = 5;
				status[1] = 1;
				SetConsoleTextAttribute(hConsole, 14);
				cout << "������� 2 �������� ������� � ����� ���������� ������: " << time[1] << endl;
			}
		}
		ff(fork, fork_temp);

		// ���������� ������ ����� ����� �������� �������� 2
		if (status[0] == 2 && fork[0] == true)
		{
			fork[0] = false;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "������� 1 ���������� ����� ������." << endl;

			if (fork[4])
			{
				fork[4] = false;
				time[0] = 20;
				status[0] = 4;
				SetConsoleTextAttribute(hConsole, 15);
				cout << "������� 1 ���� ��� ����� � ����� ���� � ������� ������: " << time[0] << endl;
			}
			else {
				status[0] = 3;
				time[0] = 5;
				cout << "������� 1 �� ���� ����� ����� �����, �� ���������� ������ ����� � ������� ������: " << time[0] << endl;
			}
			starv[0]--;
		}
		ff(fork, fork_temp);

		// ������� 3
		if (time[2] > 0)
		{
			if (status[2] == 1)
			{
				think[2]++;
				time[2]--;
			}
			if (status[2] == 3 || status[2] == 4)
			{
				eatin[2]++;
				time[2]--;
			}
		}
		if (time[2] == 0)
		{
			if (status[2] == 1)
			{
				if (fork[2] && fork[1])
				{
					fork[1] = false;
					fork[2] = false;
					time[2] = 15;
					status[2] = 3;
					SetConsoleTextAttribute(hConsole, 13);
					cout << "������� 3 ���� ��� ����� � ����� ���� � ������� ������: " << time[2] << endl;
				}
				else
				{
					starv[2]++;
				}
			}
			else if (status[2] >= 3)
			{
				if (fork[0] && fork[3] && status[2] != 4)
				{
					status[2] = 4;
					time[2] = 15;
					SetConsoleTextAttribute(hConsole, 13);
					cout << "������� 3 ������ ��������� ����� ����� ���� �� ���� � ��� ��� ������: " << time[2] << endl;
				}
				else
				{
					status[2] = 1;
					time[2] = 30;
					SetConsoleTextAttribute(hConsole, 13);
					cout << "������� 3 �������� ������� � ����� ���������� ������: " << time[2] << endl;
					fork[1] = true;
					fork[2] = true;
				}
			}
		}
		ff(fork, fork_temp);

		// ������� 4
		if (time[3] > 0)
		{
			if (status[3] == 1)
			{
				think[3]++;
				time[3]--;
			}
			else if (status[3] == 3)
			{
				eatin[3]++;
				time[3]--;
			}
		}
		if (time[3] == 0)
		{
			if (status[3] == 1)
			{
				if (fork[2] && fork[3])
				{
					status[3] = 3;
					time[3] = 11 * (a + 1);
					a = 0;
					fork[2] = false;
					fork[3] = false;
					SetConsoleTextAttribute(hConsole, 12);
					cout << "������� 4 ���� ��� ����� � ����� ���� � ������� ������: " << time[3] << endl;
				}
				else
				{
					a++;
					fail[3]++;
					time[3] = ((15 - a) > 6 ? (15 - a) : 6);
					SetConsoleTextAttribute(hConsole, 12);
					cout << "������� 4 �� ���� ������ (� " << a << " ���), ���������� ������: " << time[3] << endl;
				}
			}
			else if (status[3] == 3)
			{
				status[3] = 1;
				time[3] = 15;
				SetConsoleTextAttribute(hConsole, 12);
				cout << "������� 4 �������� ������� � ����� ���������� ������: " << time[3] << endl;
				fork[2] = true;
				fork[3] = true;
			}
		}
		ff(fork, fork_temp);

		// ���������� ������ ����� ����� �������� �������� 4
		if (status[4] == 2 && fork[3] == true)
		{
			fork[3] = false;
			SetConsoleTextAttribute(hConsole, 11);
			cout << "������� 5 ���������� ����� �����." << endl;

			if (fork[4])
			{
				fork[4] = false;
				time[4] = 1;
				status[4] = 4;
				SetConsoleTextAttribute(hConsole, 11);
				cout << "������� 5 ���� ��� ����� � ����� ���� � ������� ������: " << time[4] << endl;
			}
			else {
				status[4] = 3;
				timer = 5;
				cout << "������� 5 �� ���� ����� ����� ������, �� ���������� ����� ����� � ������� ������: " << timer << endl;
			}
		}
		ff(fork, fork_temp);

		// ������� 5
		if (time[4] > 0)
		{
			if (status[4] == 1)
			{
				think[4]++;
				time[4]--;
			}
			else if (status[4] == 4)
			{
				eatin[4]++;
				time[4]--;
			}
		}
		if (time[4] == 0)
		{
			if (status[4] == 1)
			{
				if (fork[3])
				{
					fork[3] = false;
					SetConsoleTextAttribute(hConsole, 11);
					cout << "������� 5 �������� ���������� � ���� ����� �����." << endl;

					if (fork[4])
					{
						fork[4] = false;
						time[4] = 1;
						status[4] = 4;
						SetConsoleTextAttribute(hConsole, 11);
						cout << "������� 5 ���� ��� ����� � ����� ���� � ������� ������: " << time[4] << endl;
					}
					else
					{
						status[4] = 3;
						timer = 5;
						cout << "������� 5 �� ���� ����� ����� ������, �� ���������� ����� ����� � ������� ������: " << timer << endl;
					}
				}
				else
				{
					status[4] = 2;
					SetConsoleTextAttribute(hConsole, 11);
					cout << "������� 5 �������� ���������� � ��������� ����������� ����� �����, ����� ��� �����������." << endl;
				}
			}
			else if (status[4] == 2)
			{
				// � ������ �������������� fork[3] ������� ���������� � ����� ��, ���. �������� ������ ������.
				starv[4]++;
			}
			else if (status[4] == 3)
			{
				// ���������� ���. �������� �� fork[4] ������ ������.
				starv[4]++;
				timer--;
				if (timer == 0)
				{
					fail[4]++;
					fork[3] = true;
					time[4] = 2;
					status[4] = 1;
					SetConsoleTextAttribute(hConsole, 11);
					cout << "������� 5 �� ���� ������ � ������������ � ������������, ������: " << time[4] << endl;
					timer = 5;
				}
			}
			else if (status[4] == 4)
			{
				fork[3] = true;
				fork[4] = true;
				time[4] = 2;
				status[4] = 1;
				SetConsoleTextAttribute(hConsole, 11);
				cout << "������� 5 �������� ������� � ����� ���������� ������: " << time[4] << endl;
			}
		}
		ff(fork, fork_temp);

		// �������� ��������� �����
		for (unsigned int i = 0; i < fork.size(); i++)
		{
			if (fork[i]) fork_idle[i]++;
		}
	}
	
	// ������������� "������� �������" (����� ����� ��� ���� ������ ����� ��� ������������� starv[i])
	for (unsigned int i = 0; i < starv.size(); i++)
	{
		if (starv[i] + think[i] + eatin[i] > lim) starv[i]--;
	}

	SetConsoleTextAttribute(hConsole, 7);
	cout << endl;
	cout << "�������� ����������:\t\t";
	print_t(think);
	cout << endl;
	cout << "�������� ���:\t\t\t";
	print_t(eatin);
	cout << endl;
	cout << "�������� ��������:\t\t";
	print_t(starv);
	cout << endl;
	cout << "����� ��������������:\t\t";
	print_t(fork_idle);
	cout << endl;
	cout << "����������� ������� ������:\t";
	print_t(fail);
	cout << endl << "(5 � 1 ����� ��������� ����� 1 ��������, 1 � 2 ����� 2, � �.�., 4 � 5 ����� 5 ��������)" << endl;
}
