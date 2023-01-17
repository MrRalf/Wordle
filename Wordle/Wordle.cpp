#include "Wordle.h"

Wordle::Wordle()
{
	MakeWord();
	cout << "������, ����� �������� � Wordle" << endl;
	cout << "� ������� ����� �� ���� ����, �������� �������� ���. �����, � ���� ����� ���� �������" << endl << endl;

}

void Wordle::BeginPlay()
{
	count++;
	NumberAttempts();
	if (count == 0)
	{

		cout << "����� �����: ";
		cin >> strUser;
		WordVerification(strUser);
		ComparisonDirectoryAll(strUser);
	}

	else
	{
		cout << "����� ����� �����: ";
		cin >> strUser;
		WordVerification(strUser);
		ComparisonDirectoryAll(strUser);
	}


}

void Wordle::MakeWord()
{
	strProg = UseDirectory[GetRandomNumber(0, 198)];
}

int Wordle::GetRandomNumber(int min, int max)
{
	// ���������� ��������� ��������� �����
	srand(time(NULL));

	// �������� ��������� ����� - �������
	num = min + rand() % (max - min + 1);

	return num;
}

void Wordle::ComparisonDirectoryAll(string strUser)
{
	for (int k = 0; k < strUser.size(); k++)
	{
		if ((strUser[k] >= -64) && (strUser[k] <= -33))
		{
			strUser[k] += 32;
		}
		else if (strUser[k] == -72)
		{
			strUser[k] += 16;
		}
	}


	for (int j = 0; j < DirectoryAll.size(); j++)
	{



		if (DirectoryAll[j] == strUser)
		{

			if (strProg == strUser)
			{
				cout << endl << "�� ������� �����, ����������!" << endl;
			tryAgain:
				cout << "����� ������� ��� ���? �������� �� ��� ���" << endl;
				string ch;
				cin >> ch;
				if (ch == "��" || ch == "��")
				{
					string strTemp = "*****";
					count = -1;
					cout << endl << "� ������� ����� �����" << endl;
					MakeWord();
					BeginPlay();
				}

				else if (ch == "���" || ch == "���")
				{
					cout << "������� �� ����" << endl;
					return;
				}

				else
				{
					cout << "� ��� �� �������" << endl;
					goto tryAgain;
				}
			}

			else if (strProg != strUser)
			{
				int temp = 0;

				for (int i = 0; i < strUser.size(); i++)
				{
					for (int r = 0; r < strProg.size(); r++)
					{
						if (strProg[i] == strUser[i])
						{
							cout << "����� " << strUser[i] << " ���� � ���������� ����� � ����� �� ������ �����" << endl;
							temp++;
							strTemp[i] = strProg[i];
							break;
						}
						else if (strProg[i] == strUser[r])
						{
							cout << "����� " << strUser[r] << " ���� � ���������� �����, �� ����� � ������ �����" << endl;
							temp++;
							break;
						}
						else if (strProg[i] == strUser[i] && strProg[i] == strUser[r])
						{
							cout << "����� " << strUser[i] << " ���� � ���������� ����� � ����� �� ������ �����, �� ��� �� ���� ��� ����� �����" << endl;
							temp++;
							break;
						}

					}



				}

				if (temp > 0)
				{
					cout << endl << strUser;
					cout << endl << strTemp << endl;
					BeginPlay();
				}
				else if (temp == 0)
				{
					cout << "��� ������������ ����� � � ��� ���� ������ ����" << endl;
					BeginPlay();

				}

			}

		}

	}

	cout << "������ ����� ���� ��� � ��� �� ����(" << endl;
	BeginPlay();



}

void Wordle::WordVerification(string strUser)
{
	if (strUser.size() != 5)
	{
		cout << "����� ������� �� �� ���� ����. �������� ��� ���" << endl;
		cout << "����� ������ �����" << endl << endl;
		BeginPlay();
	}


}

void Wordle::NumberAttempts()
{

	if (count == 5)
	{
		cout << endl << "�� ��������" << endl << "���������� ����� " << strProg << endl;
		cout << "����� ������� ��� ���? �������� �� ��� ���" << endl;
		string ch;
		cin >> ch;
		if (ch == "��" || ch == "��")
		{
			string strTemp = "*****";
			count = -1;
			cout << endl << "� ������� ����� �����" << endl;
			MakeWord();
			BeginPlay();
		}

		else if (ch == "���" || ch == "���")
		{
			cout << "������� �� ����" << endl;
			return;
		}
	}

	else
	{
		cout << "� ���� �������� " << 5 - count << " �������" << endl << endl;


	}

}




int main()
{
    system("chcp 1251 > nul");

    Wordle word;
    word.BeginPlay();



    return 0;
}


