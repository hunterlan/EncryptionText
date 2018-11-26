#include"Operations.h"

using namespace std;

/*
TO DO: 1. Fixing all bags - DONE
2. Writing the second method.
*/



int main()
{
	struct Classified classify;
	struct Declassified declassify;
	classify.text = "abra";
	EncryptCesarModified(&classify);
	classify.WriteFile("1.txt");
	declassify.ReadFile("1.txt");
	DecryptCesarModified(&declassify);
	declassify.WriteFile("2.txt");
	classify.text = "Lopem ipsum";
	EncryptCesar(&classify);
	classify.WriteFile("3.txt");
	return 0;
}