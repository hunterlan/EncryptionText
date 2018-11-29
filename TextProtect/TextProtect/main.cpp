#include"Operations.h"

using namespace std;

/*
TO DO: 1. Fixing all bags - DONE
2. Writing the second method.
*/

void controlMenu();

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
			string path;
			case '1':
			{
				cout << "Choose filling text:\n";
				cout << "1.Manual input\n";
				cout << "2.Read from file\n";
				cout << "3.Back";
				cin >> tempChoose;
				if (tempChoose == '1')
				{
					cout << "Input the text: ";
					cin >> classify.text;
					EncryptCesar(&classify);
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
					EncryptCesar(&classify);
				}
				/*
				bool exit = false;
					do
					{
						cout << "Put path to write file: ";
						cin >> path;
						if (!classify.WriteFile(path))
							cout << "Cannot write to this file\n";
					} while (exit == false);*/
			}break;
			case 2:
			{
				cout << "Choose filling text:\n";
				cout << "1.Manual input\n";
				cout << "2.Partly read from file\n";
				cout << "3.Full read from file\n";
				cout << "4.Back\n";
			}break;
			case 3:
			{
				cout << "Choose filling text:\n";
				cout << "1.Manual input\n";
				cout << "2.Read from file\n";
				cout << "3.Back";
			}break;
			case 4:
			{
				cout << "Choose filling text:\n";
				cout << "1.Manual input\n";
				cout << "2.Partly read from file\n";
				cout << "3.Full read from file\n";
				cout << "4.Back\n";
			}break;
			case 5:
			{
				//Read help.txt
			}
			case 6: 
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