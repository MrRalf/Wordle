#include "Wordle.h"

Wordle::Wordle()
{
	MakeWord();
	cout << "Привет, давай поиграем в Wordle" << endl;
	cout << "Я загадал слово из пяти букв, попробуй отгадать его. Помни, у тебя всего пять попыток" << endl << endl;

}

void Wordle::BeginPlay()
{
	count++;
	NumberAttempts();
	if (count == 0)
	{

		cout << "Введи слово: ";
		cin >> strUser;
		WordVerification(strUser);
		ComparisonDirectoryAll(strUser);
	}

	else
	{
		cout << "Введи новое слово: ";
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
	// Установить генератор случайных чисел
	srand(time(NULL));

	// Получить случайное число - формула
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
				cout << endl << "Вы угадали слово, поздравляю!" << endl;
			tryAgain:
				cout << "Хоите сыграть еще раз? Напишите Да или Нет" << endl;
				string ch;
				cin >> ch;
				if (ch == "Да" || ch == "да")
				{
					string strTemp = "*****";
					count = -1;
					cout << endl << "Я загадал новое слово" << endl;
					MakeWord();
					BeginPlay();
				}

				else if (ch == "Нет" || ch == "нет")
				{
					cout << "Спасибо за игру" << endl;
					return;
				}

				else
				{
					cout << "Я Вас не понимаю" << endl;
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
							cout << "Буква " << strUser[i] << " есть в загадонном слове и стоит на нужном месте" << endl;
							temp++;
							strTemp[i] = strProg[i];
							break;
						}
						else if (strProg[i] == strUser[r])
						{
							cout << "Буква " << strUser[r] << " есть в загадонном слове, но стоит в другом месте" << endl;
							temp++;
							break;
						}
						else if (strProg[i] == strUser[i] && strProg[i] == strUser[r])
						{
							cout << "Буква " << strUser[i] << " есть в загадонном слове и стоит на нужном месте, но где то есть еще такая буква" << endl;
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
					cout << "Это неправильное слово и в нем нету нужных букв" << endl;
					BeginPlay();

				}

			}

		}

	}

	cout << "Такого слова нету или я его не знаю(" << endl;
	BeginPlay();



}

void Wordle::WordVerification(string strUser)
{
	if (strUser.size() != 5)
	{
		cout << "Слово состоит не из пяти букв. Попробуй еще раз" << endl;
		cout << "Введи другое слово" << endl << endl;
		BeginPlay();
	}


}

void Wordle::NumberAttempts()
{

	if (count == 5)
	{
		cout << endl << "Ты проиграл" << endl << "Правильное слово " << strProg << endl;
		cout << "Хоите сыграть еще раз? Напишите Да или Нет" << endl;
		string ch;
		cin >> ch;
		if (ch == "Да" || ch == "да")
		{
			string strTemp = "*****";
			count = -1;
			cout << endl << "Я загадал новое слово" << endl;
			MakeWord();
			BeginPlay();
		}

		else if (ch == "Нет" || ch == "нет")
		{
			cout << "Спасибо за игру" << endl;
			return;
		}
	}

	else
	{
		cout << "У тебя осталось " << 5 - count << " попыток" << endl << endl;


	}

}




int main()
{
    system("chcp 1251 > nul");

    Wordle word;
    word.BeginPlay();



    return 0;
}


