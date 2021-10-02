#include "TradingList.h"
#include "ExtremumList.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	TradingList theList;
	theList.readFile();
	//theList.print();
	
	ExtremumList ListE;
	cout << endl << "Compare(5):" << endl;
	ListE.compare(&theList, 20);
	//theList.compare(ListE, 20);
	ListE.printE();
	cout << endl << "End"<< endl;
	ListE.search();
	
	return 0;
}
