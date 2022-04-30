#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Çì´õ.h"
#include <cstring>
using namespace std;

void Printer::SetString(const char *in)
{
	strcpy(str, in);
}

void Printer::ShowString()
{
	cout << str << endl;
}