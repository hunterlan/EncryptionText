#include"Operations.h"

using namespace std;

/*
TO DO: 1. Fixing all bags - DONE
2. Writing the second method.
*/

void controlMenu();
void userWriteFile(struct Classified * classify, struct Declassified * declassify, int chooseStruct);
void Decision(struct Classified * classify, struct Declassified * declassify, int chooseStruct);

int main()
{
	controlMenu();
	return 0;
}

void controlMenu()
{
	struct Classified classify;
	struct Declassified declassify;
	char userChoose;
	string path;
	do
	{
		cout << "Choose task: \n";
		cout << "1. Encrypt text by method Cesar\n";
		cout << "2. Decrypt text by method Cesar\n";
		cout << "3. Encrypt text by modified method Cesar\n";
		cout << "4. Decrypt text by modified method Cesar\n";
		cout << "5. Help\n";
		cout << "6.Exit\n";
		cin >> userChoose;
		switch (userChoose)
		{
			char tempChoose;
		case '1':
		case '3':
		{
			cout << "Choose filling text:\n";
			cout << "1.Manual input\n";
			cout << "2.Read from file\n";
			cout << "3.Back\n";
			cin >> tempChoose;
			if (tempChoose == '1')
			{
				cout << "Input the text: ";
				cin >> classify.text;
				if (userChoose == '1')
					EncryptCesar(&classify);
				else
					EncryptCesarModified(&classify);
				Decision(&classify, &declassify, 0);
			}
			else if (tempChoose == '2')
			{
				do
				{
					cout << "Put path to file: ";
					cin >> path;
					classify.ReadFile(path);
					if (classify.text == "false")
						cout << "Cannot open this file.\n";
				} while (classify.text == "false");
				if (userChoose == '1')
					EncryptCesar(&classify);
				else
					EncryptCesarModified(&classify);
				Decision(&classify, &declassify, 0);
			}

		}break;
		case '2':
		case '4':
		{
			cout << "Choose filling text:\n";
			cout << "1.Manual input\n";
			cout << "2.Partly read from file\n";
			cout << "3.Full read from file\n";
			cout << "4.Back\n";
			cin >> tempChoose;

			if (tempChoose == '1')
			{
				cout << "Input the text: ";
				cin >> classify.text;

				if (userChoose == '2')
					EncryptCesar(&classify);
				else
					EncryptCesarModified(&classify);

				Decision(&classify, &declassify, 0);
			}
			else if (tempChoose == '2' || tempChoose == '3')
			{
				do
				{
					cout << "Put path to file: ";
					cin >> path;

					if (tempChoose == '2')
						declassify.TextReadFile(path);
					else
						declassify.FullReadFile(path);

					if (declassify.text == "false")
						cout << "Cannot open this file.\n";

				} while (declassify.text == "false");

				if (userChoose == '2')
					DecryptCesar(&declassify);
				else
					DecryptCesarModified(&declassify);

				Decision(&classify, &declassify, 1);
				
			}
			
		}break;
		
		case '5':
		{
			string temp, help;
			ifstream read("help.txt");
			while (!read.eof())
			{
				read >> temp;
				help += temp;
				if (!read.eof())
					help += ' ';
			}
			cout << help;
		}break;
		case '6':
		{
			cout << "Thank you for using programm!\n";
			cout << "Press any key to exit from programm...";
			getchar();
			getchar();
		}
		default:
			cout << "Wrong choose!\n";
			break;
		}
	} while (userChoose != '6');

}

void Decision(struct Classified * classify, struct Declassified * declassify, int chooseStruct)
{
	char choose;
	do
	{
		cout << "1. See the result\n2. Write to file the result\n3. Back\n";
		cin >> choose;
		switch (choose)
		{
			case 49:
			{
				if (chooseStruct == 0)
					cout << "Your result: " << classify->text << '\n';
				else
					cout << "Your result: " << declassify->text << '\n';
			}break;
			case 50:
			{
				userWriteFile(classify, declassify, chooseStruct);
			}break;
		}
	} while (choose != '3');
}

void userWriteFile(struct Classified * classify, struct Declassified * declassify, int chooseStruct)
{
	bool exit = true;
	string path;
	do
	{
		cout << "Put path to write file: ";
		cin >> path;
		if (chooseStruct == 0)
		{
			if (!classify->WriteFile(path))
			{
				cout << "Cannot write to this file\n";
				exit = true;
			}
		}
		else
		{
			if (!declassify->WriteFile(path))
			{
				cout << "Cannot write to this file\n";
				exit = true;
			}
		}
	} while (exit == false);
}