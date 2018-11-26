#include"Operations.h"

const int CODE_FIRST_SMALL_LETTER = 97;
const int CODE_LAST_SMALL_LETTER = 122;
const int CODE_FIRST_BIG_LETTER = 65;
const int CODE_LAST_BIG_LETTER = 90;

const string ALPHABET_SMALL = "abcdefghijklmnopqrtstuvwxyz";
const string ALPHABET_BIG = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void Classified::ReadFile(string path)
{
	ifstream read(path);
	if (!read.is_open())
	{
		text = "false";
	}
	else
	{
		read >> text;
		read.close();
	}
}

bool Classified::WriteFile(string path)
{
	bool isSuccesful = true;
	ofstream write(path);
	if (!write.is_open())
	{
		isSuccesful = false;
	}
	else
	{
		write << method << '\n';
		write << key << '\n';
		write << text;
		write.close();
	}
	return isSuccesful;
}

void Declassified::ReadFile(string path)
{
	string temp;
	text = "";
	ifstream read(path);
	if (!read.is_open())
	{
		text = "false";
	}
	else
	{
		for (int i = 0; !read.eof(); i++)
		{
			if (i == 0)
			{
				read >> method;
			}
			else if (i == 1)
			{
				read >> key;
			}
			else
			{
				read >> temp;
				if (read.eof())
				{
					text += temp;
					break;
				}
				else
				{
					text += temp;
					text += ' ';
				}
			}
		}
		
		read.close();
	}
}

bool Declassified::WriteFile(string path)
{
	bool isSuccesful = true;
	ofstream write(path);
	if (!write.is_open())
	{
		isSuccesful = false;
	}
	else
	{
		write << text;
		write.close();
	}
	return isSuccesful;
}


//Шифр Цезаря модифицированный
//Баг который стал фичей: некоторые буквы становятся запятыми и т.п. 
//С одной стороны, это не совсем хорошо, но если мы расшифровываем нашей программой, то
//это повышает криптостойкость
void EncryptCesarModified(struct Classified * classify)
{
	int randomKey = 1 + rand() % +26;

	for (int i = 0; i < classify->text.size(); i++)
	{
		classify->text[i] += randomKey;

		/*if (classify->text[i] > CODE_LAST_SMALL_LETTER)
			classify->text[i] -= CODE_LAST_SMALL_LETTER - CODE_FIRST_SMALL_LETTER;

		else if (classify->text[i] > CODE_LAST_BIG_LETTER && classify->text[i] < CODE_FIRST_SMALL_LETTER)
			classify->text[i] -= CODE_LAST_BIG_LETTER - CODE_FIRST_BIG_LETTER;*/

			/*else if (classify->text[i] < 0)
				classify->text[i] -= CODE_LAST_SMALL_LETTER - CODE_FIRST_SMALL_LETTER;*/

	}

	classify->method = 1;
	classify->key = randomKey;
}

//Дешифровка Цезаря
void DecryptCesarModified(struct Declassified * declassify)
{
	//bool isSmallLetter = true;
	for (int i = 0; i < declassify->text.size(); i++)
	{
		/*if (!declassify->text[i] >= CODE_FIRST_SMALL_LETTER)
			isSmallLetter = false;*/

		declassify->text[i] -= declassify->key;

		/*if (declassify->text[i] > CODE_LAST_BIG_LETTER && declassify->text[i] < CODE_FIRST_SMALL_LETTER)
			declassify->text[i] += CODE_LAST_SMALL_LETTER - CODE_FIRST_SMALL_LETTER;
		else if(declassify->text[i] < CODE_FIRST_BIG_LETTER)
			declassify->text[i] += CODE_LAST_SMALL_LETTER - CODE_FIRST_SMALL_LETTER;*/
	}
}

void EncryptCesar(struct Classified * classify)
{
	int randomKey = 1 + rand() % + 26, startPos = 0, finishPos;
	for (int i = 0; i < classify->text.size(); i++)
	{
		finishPos = 0;
		while(finishPos == 0)
		{
			if (classify->text[i] >= CODE_FIRST_BIG_LETTER && classify->text[i] <= CODE_LAST_BIG_LETTER)
			{
				if (classify->text[i] == ALPHABET_BIG[startPos])
				{
					finishPos = startPos + randomKey;
					if (finishPos >= ALPHABET_BIG.size())
						finishPos -= ALPHABET_BIG.size();
					classify->text[i] = ALPHABET_BIG[finishPos];
					startPos = 0;
				}
				else
					startPos++;
			}
			else if (classify->text[i] >= CODE_FIRST_SMALL_LETTER &&
				classify->text[i] <= CODE_LAST_SMALL_LETTER)
			{
				if (classify->text[i] == ALPHABET_SMALL[startPos])
				{
					finishPos = startPos + randomKey;
					if (finishPos >= ALPHABET_SMALL.size())
						finishPos -= ALPHABET_SMALL.size();
					classify->text[i] = ALPHABET_SMALL[finishPos];
					startPos = 0;
				}
				else
					startPos++;
			}
			else
				break;
		}
		}
		
	classify->method = 2;
	classify->key = randomKey;
}

void DecryptCesar(struct Declassified * declassify)
{
	int startPos = 0, finishPos;
	for (int i = 0; i < declassify->text.size(); i++)
	{
		finishPos = 0;
		while (finishPos == 0)
		{
			if (declassify->text[i] >= CODE_FIRST_BIG_LETTER && declassify->text[i] <= CODE_LAST_BIG_LETTER)
			{
				if (declassify->text[i] == ALPHABET_BIG[startPos])
				{
					finishPos = startPos - declassify->key;
					if (finishPos < 0)
						finishPos = -finishPos;
					declassify->text[i] = ALPHABET_BIG[finishPos];
					startPos = 0;
				}
				else
					startPos++;
			}
			else if (declassify->text[i] >= CODE_FIRST_SMALL_LETTER
				&& declassify->text[i] <= CODE_LAST_SMALL_LETTER)
			{
				if (declassify->text[i] == ALPHABET_SMALL[startPos])
				{
					finishPos = startPos - declassify->key;
					if (finishPos < 0)
						finishPos = -finishPos;
					declassify->text[i] = ALPHABET_SMALL[finishPos];
					startPos = 0;
				}
				else
					startPos++;
			}
			else
				break;
		}
	}
}


//void EncryptGronsfeld(struct Classified * classify)
//{
//	string tempPassword;
//	int password;
//	cout << "Write 4 numeracals for password: ";
//	cin >> password;
//	int i = 0;
//	while (classify->text.size() > tempPassword.size())
//	{
//		tempPassword.push_back(tempPassword[i]);
//		if (i == 3)
//			i = 0;
//		else
//			i++;
//	}
//	password = atoll(tempPassword.c_str());
//	for (int i = 0; i < classify->text.size(); i++)
//	{
//		countDivide = 8;
//		while (temp > 0)
//		{
//			if(countDi)
//		}
//		classify->text[i] += numKey;
//	}
//	classify->method = 3;
//	classify->key = password;
//}