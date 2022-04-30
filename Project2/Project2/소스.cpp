#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++) {
		cout << rand() % 100 << endl;
	}
}