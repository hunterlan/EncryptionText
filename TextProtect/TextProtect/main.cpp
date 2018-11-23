#include"Operations.h"

using namespace std;

/*
TO DO: 1. Fixing all bags
2. Writing the second method.
*/



int main()
{
	struct Classified classify;
	struct Declassified declassify;
	classify.text = "abra";
	EncryptCesar(&classify);
	classify.WriteFile("1.txt");
	declassify.ReadFile("1.txt");
	DecryptCesar(&declassify);
	declassify.WriteFile("2.txt");
	return 0;
}