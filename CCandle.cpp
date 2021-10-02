#include "CCandle.h"
#include <iostream>

using namespace std;


void CandleData::print() const
{
		cout << nPer   << " ";
		cout << nDate  << " ";
		cout << nTime  << " ";
		cout << nOpen  << " ";
		cout << nHigh  << " ";
		cout << nLow  << " ";
		cout << nClose << " ";
		cout << nVol   << " ";
		cout << endl;
}

CandleData::CandleData(int _nPer, int _nDate, int _nTime,
	double _nOpen, double _nHigh, double _nLow, double _nClose, int _nVol) : 
	nPer(_nPer), nDate(_nDate), nTime(_nTime),
	nOpen(_nOpen), nHigh(_nHigh), nLow(_nLow), nClose(_nClose), nVol(_nVol)
{
}

CandleData::CandleData() :
	nPer(0), nDate(0), nTime(0),
	nOpen(0.0), nHigh(0.0), nLow(0.0), nClose(0.0), nVol(0)
{
}

CCandle::CCandle(CandleData _nCData) : nCData(_nCData), pNext(nullptr), pBack(nullptr)
{
}

CCandle::CCandle(CandleData _nCData, CCandle* _pNext, CCandle* _pBack) : nCData(_nCData), pNext(_pNext), pBack(_pBack)
{
}
