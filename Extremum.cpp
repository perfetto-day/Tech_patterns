#include "Extremum.h"
#include <iostream>

using namespace std;

CExtremum::CExtremum(DataExtremum _nEData) : nEData(_nEData), pNextE(nullptr)
{
}

CExtremum::CExtremum(DataExtremum _nEData, CExtremum* _pNextE) : nEData(_nEData), pNextE(_pNextE)
{
}

void DataExtremum::print() const
{
	cout << isExtremum << " ";
	pCandle->nCData.print();
	cout << endl;
}



