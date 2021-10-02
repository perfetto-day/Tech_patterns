#include "TradingList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


TradingList::TradingList() : pStart(nullptr), pEnd(nullptr), ticker("")
{
}

TradingList::~TradingList()
{
	//cout << "I'm destrucor" << endl;
	clear();
}

void TradingList::pop_front()
{
	if (pStart == nullptr)
	{
		cerr << "TradingList::pop_front() : List has 0 elements!";
		exit(1);
	}

	CandleData nTemp = pStart->nCData;
	CCandle* pTemp = pStart;
	pStart = pStart->pNext;
	if (pStart == nullptr)
		pEnd = nullptr;
	else
		pStart->pBack = nullptr;   //возможно в какой-то момент указатель не работает. Ошибка: нарушение доступа
	delete pTemp;
}

void TradingList::clear()
{
	while (pStart != nullptr)
	{
		pop_front();
	}
}

void  TradingList::push_back(CandleData _nCData)
{
	CCandle* pNewCandle = new CCandle(_nCData, nullptr, pEnd);

	if (pStart == nullptr)
		pStart = pNewCandle;
	else
		pEnd->pNext = pNewCandle;
	pEnd = pNewCandle;
}

void TradingList::print() const
{
	CCandle* pTemp = pStart;

	while (pTemp != nullptr)
	{
		cout << ticker << " ";
		pTemp->nCData.print();
		pTemp = pTemp->pNext;
	}
	cout << endl;
}

void TradingList::printticker() const
{
	cout << ticker << " ";
}

void TradingList::readFile(void)
{

	ifstream inf("DataFile.txt");

	if (!inf)
	{
		cerr << "Uh oh, DataFile.txt could not be opened for reading!" << endl;
		exit(1);
	}

	int type = 0;
	CandleData nCData;
	while (inf)
	{
		string Input;
		inf >> Input;
		int i = 0;
		if(ticker == "")
			ticker = Input;
		if((type >= 1 && type <= 3) || type == 8)
		{
			int value = 0;
			while (Input[i] >= 0x30 && Input[i] <= 0x39)
			{
				value = value + (Input[i] & 0x0F);
				value = value * 10;
				i++;
			}
			value = value / 10;
			switch (type) {
			case 1:
				nCData.nPer = value;
			case 2: 
				nCData.nDate = value;
			case 3:
				nCData.nTime = value;
			case 8: 
				nCData.nVol = value;
			}
		}
		if (type >= 4 && type <= 7)
		{
			double value = 0.0;
			int point = 0;
			int digit = 0;
			while (Input[i] >= 0x30 && Input[i] <= 0x39 || Input[i] == '.')
			{
				if (Input[i] != '.')
				{

					value = value + (Input[i] & 0x0F);
					value = value * 10;
				}
				else point = 1;

				if (point == 1)
					digit++;
				i++;
			}
			for (int j = 0; j < digit; j++)
			{
				value = value / 10;
			}
			switch (type)
			{
			case 4:
				nCData.nOpen = value;
			case 5:
				nCData.nHigh = value;
			case 6:
				nCData.nLow = value;
			case 7:
				nCData.nClose = value;
			}

		}
		type++;
		if (type > 8)
		{
			type = 0;
			push_back(nCData);
		}

	}

	inf.close();


}
