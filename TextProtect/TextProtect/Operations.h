#ifndef _OPERATIONS_H
#define _OPERATIONS_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>
#include<cctype>

using namespace std;

struct Classified
{
	string text;
	int method;
	int key;
	void ReadFile(string path);
	bool WriteFile(string path);
};

struct Declassified
{
	string text;
	int method;
	int key;
	void FullReadFile(string path);
	void TextReadFile(string path);
	bool WriteFile(string path);
};

void EncryptCesar(struct Classified * classify);
void DecryptCesar(struct Declassified * declassify);
void EncryptCesarModified(struct Classified * classify);
void DecryptCesarModified(struct Declassified * declassify);
//void EncryptGronsfeld(struct Classified * classify);
//void DecryptGronsfeld(struct Declassified * declassify);

#endif _OPERATIONS_H

