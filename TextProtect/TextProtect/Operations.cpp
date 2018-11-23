#include"Operations.h"

const int CODE_FIRST_SMALL_LETTER = 97;
const int CODE_LAST_SMALL_LETTER = 122;
const int CODE_FIRST_BIG_LETTER = 65;
const int CODE_LAST_BIG_LETTER = 90;

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
				read >> text;
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

//Шифр Цезаря
void EncryptCesar(struct Classified * classify)
{
	int randomKey = 1 + rand() % +26;

	for (int i = 0; i < classify->text.size(); i++)
	{
		classify->text[i] += randomKey;

		if (classify->text[i] > CODE_LAST_SMALL_LETTER)
			classify->text[i] -= CODE_LAST_SMALL_LETTER - CODE_FIRST_SMALL_LETTER;

		else if (classify->text[i] > CODE_LAST_BIG_LETTER && classify->text[i] < CODE_FIRST_SMALL_LETTER)
			classify->text[i] -= CODE_LAST_BIG_LETTER - CODE_FIRST_BIG_LETTER;

		else if (classify->text[i] < 0)
			classify->text[i] -= CODE_LAST_SMALL_LETTER - CODE_FIRST_SMALL_LETTER;

	}

	classify->method = 1;
	classify->key = randomKey;
}

//Дешифровка Цезаря
//Известный баг: некоторые буквы в итоге не попадают на свое место
void DecryptCesar(struct Declassified * declassify)
{
	int resultPos;
	for (int i = 0; i < declassify->text.size(); i++)
	{
		declassify->text[i] -= declassify->key;

		if (declassify->text[i] > CODE_LAST_BIG_LETTER && declassify->text[i] < CODE_FIRST_SMALL_LETTER)
			declassify->text[i] += CODE_LAST_SMALL_LETTER - CODE_FIRST_SMALL_LETTER;
		else if(declassify->text[i] < CODE_FIRST_BIG_LETTER)
			declassify->text[i] += CODE_LAST_SMALL_LETTER - CODE_FIRST_SMALL_LETTER;
	}
}

void EncryptGronsfeld(struct Classified * classify)
{

}