#include "ExtremumList.h"
#include <iostream>
#include <cmath>

using namespace std;

ExtremumList::ExtremumList() : pRootE(nullptr)
{
}

ExtremumList::~ExtremumList()
{
	clear();
}

DataExtremum ExtremumList::pop_front()
{
    if (pRootE == nullptr)
    {
        cerr << "CList::pop_front() : List has 0 elements!" << endl;
        exit(1);
    }

    DataExtremum nTemp = pRootE->nEData;
    CExtremum* pTemp = pRootE;
    pRootE = pRootE->pNextE;
    delete pTemp;

    return nTemp;
}

void ExtremumList::push_backE(DataExtremum _nEData)
{
    CExtremum* pTemp = pRootE;
    CExtremum* pTemp1 = pRootE;

    while (pTemp != nullptr)
    {
        pTemp1 = pTemp;
        pTemp = pTemp->pNextE;
    }

    if (pTemp1 == nullptr)
    {
        CExtremum* pNewNode = new CExtremum(_nEData, nullptr);
        pRootE = pNewNode;
    }
    else
    {
        CExtremum* pNewNode = new CExtremum(_nEData, nullptr);
        pTemp1->pNextE = pNewNode;
    }
    
	/*
    CExtremum* pNewExtremum = new CExtremum(_nEData, nullptr);

    if (pRootE == nullptr)
    {
        pRootE = pNewExtremum;
    }
    else
    {
        CExtremum* pTemp = pRootE;

        while (pTemp->pNextE != nullptr)
        {
            pTemp = pTemp->pNextE;
        }

        pTemp->pNextE = pNewExtremum;
    }
    //pRootE->nEData.pCandle->nCData.print();
	*/
}

void ExtremumList::clear()
{
    while (pRootE != nullptr)
    {
        pop_front();
    }
}


void ExtremumList::printE() const
{
    CExtremum* pTemp = pRootE;
    while (pTemp != nullptr)
    {
		cout << pTemp->nEData.isExtremum << " ";
		/*
		cout << pTemp->nEData.pCandle->nCData.nPer << " ";
		cout << pTemp->nEData.pCandle->nCData.nDate << " ";
		cout << pTemp->nEData.pCandle->nCData.nTime << " ";
		cout << pTemp->nEData.pCandle->nCData.nOpen << " ";
		cout << pTemp->nEData.pCandle->nCData.nHigh << " ";
		cout << pTemp->nEData.pCandle->nCData.nLow << " ";
		cout << pTemp->nEData.pCandle->nCData.nClose << " ";
		cout << pTemp->nEData.pCandle->nCData.nVol << endl;
		*/
		pTemp->nEData.pCandle->nCData.print();
        pTemp = pTemp->pNextE;
    }
}

void ExtremumList::compare(const TradingList* _TradingList, unsigned int _nStep)
{
	DataExtremum nEData{};
	CandleData nCData;

	CCandle* pBeggin = _TradingList->pStart;
	CCandle* pFinish = _TradingList->pEnd;
	for (unsigned int i = 1; i <= _nStep; i++)
	{
		pBeggin = pBeggin->pNext;
		pFinish = pFinish->pBack;
	}

	unsigned int check2 = 0, check3 = 0;
	CCandle* pTemp = pBeggin;

	while (pTemp != nullptr)
	{
		unsigned int i = 1;
		bool check = true;
		bool check1 = 1;

		double nTempH = pTemp->nCData.nHigh;
		double nTempL = pTemp->nCData.nLow;

		CCandle* pPlus = pTemp->pNext;
		CCandle* pMinus = pTemp->pBack;


		// Checking for Min point
		while (i <= _nStep && check)
		{
			if (pPlus == nullptr)
			{
				if (nTempL < pMinus->nCData.nLow) {}
				else { check = 0; check1 = 0; }
				pMinus = pMinus->pBack;
				i++;
			}
			else
			{
				if (nTempL <= pPlus->nCData.nLow && nTempL < pMinus->nCData.nLow) {}
				else { check = 0; check1 = 0; }
				pPlus = pPlus->pNext;
				pMinus = pMinus->pBack;
				i++;
			}
		}
		if (check1)
		{
			check2++;
			nEData.isExtremum = 0;
			nEData.pCandle = pTemp;
			//cout << "Low (for date:" << pTemp->nCData.nDate << ", time:" << pTemp->nCData.nTime << ") =" << pTemp->nCData.nLow << endl;
			push_backE(nEData);
		}

		// Checking for Max point
		i = 1;
		check = 1;
		check1 = 1;
		pPlus = pTemp->pNext;
		pMinus = pTemp->pBack;

		while (i <= _nStep && check)
		{
			if (pPlus == nullptr)
			{
				if (nTempH > pMinus->nCData.nHigh) {}
				else { check = 0; check1 = 0; }
				pMinus = pMinus->pBack;
				i++;
			}
			else
			{
				if ((nTempH >= pPlus->nCData.nHigh) && (nTempH > pMinus->nCData.nHigh)) {}
				else { check = 0; check1 = 0; }
				pPlus = pPlus->pNext;
				pMinus = pMinus->pBack;
				i++;
			}
		}
		if (check1)
		{
			check3++;
			nEData.isExtremum = 1;
			nEData.pCandle = pTemp;
			//cout << "High (for date:" << pTemp->nCData.nDate << ", time:" << pTemp->nCData.nTime << ") =" << pTemp->nCData.nHigh << endl;
			push_backE(nEData);
		}

		pTemp = pTemp->pNext;
	}
	//cout << "date:" << pTemp->nCData.nDate << "time:" << pTemp->nCData.nTime << endl;
	//CCandle* pTemp = pFinish->pNext;
/*
	while (pTemp != nullptr)
	{
		unsigned int i = 1;
		bool check = true;
		bool check1 = 1;

		double nTempH = pTemp->nCData.nHigh;
		double nTempL = pTemp->nCData.nLow;

		CCandle* pPlus = pTemp->pNext;
		CCandle* pMinus = pTemp->pBack;


		// Checking for Min point
		while (i <= _nStep && check)
		{
			if (pPlus == nullptr)
			{ 
				if (nTempL < pMinus->nCData.nLow) {}
				else { check = 0; check1 = 0; }
				pMinus = pMinus->pBack;
				i++;
			}
			else
			{
				if (nTempL <= pPlus->nCData.nLow && nTempL < pMinus->nCData.nLow) {}
				else { check = 0; check1 = 0; }
				pPlus = pPlus->pNext;
				pMinus = pMinus->pBack;
				i++;
			}
		}
		if (check1)
		{
			check2++;
			nEData.isExtremum = 0;
			nEData.pCandle = pTemp;
			cout << "Low Tail (for date:" << pTemp->nCData.nDate << ", time:" << pTemp->nCData.nTime << ") =" << pTemp->nCData.nLow << endl;
			push_backE(nEData);
			//			cout << nEData.isExtremum << " " << check2 << " " << pTemp << " " << pTemp->nCData.nLow << endl;
			//			_ExtremumList.printE();
		}

		// Checking for Max point
		i = 1;
		check = 1;
		check1 = 1;
		pPlus = pTemp->pNext;
		pMinus = pTemp->pBack;

		while (i <= _nStep && check)
		{
			if (pPlus == nullptr)
			{
				if (nTempH > pMinus->nCData.nHigh) {}
				else { check = 0; check1 = 0; }
				pMinus = pMinus->pBack;
				i++;
			}
			else
			{
				if ((nTempH >= pPlus->nCData.nHigh) && (nTempH > pMinus->nCData.nHigh)) {}
				else { check = 0; check1 = 0; }
				pPlus = pPlus->pNext;
				pMinus = pMinus->pBack;
				i++;
			}
		}
		if (check1)
		{
			check3++;
			nEData.isExtremum = 1;
			nEData.pCandle = pTemp;
			cout << "High Tail (for date:" << pTemp->nCData.nDate << ", time:" << pTemp->nCData.nTime << ") =" << pTemp->nCData.nHigh << endl;
			push_backE(nEData);
		}

		pTemp = pTemp->pNext;
	}
	*/
	if (check2 == 0) { cout << "Warning! There are no elements with correct value of Low for step = " << _nStep << endl; }
	if (check3 == 0) { cout << "Warning! There are no elements with correct value of High for step = " << _nStep << endl; }
}

void ExtremumList::search()
{
	CExtremum* pTempE = pRootE;
	CExtremum* pLastTemp = pTempE->pNextE->pNextE->pNextE->pNextE->pNextE;
	while (pLastTemp != nullptr)
	{
		triangle(pTempE);
		pTempE = pTempE->pNextE;
		pLastTemp = pLastTemp->pNextE;
	}
}

bool OppositeExtremum(const CExtremum* pPrev, const CExtremum* pExamine) // Проверка чередования экстремумов
{
	if (pPrev->nEData.isExtremum != pExamine->nEData.isExtremum)
		return true;
	else
		return false;
}

bool Narrowing(const CExtremum* pPrevPrev, const CExtremum* pPrev, const CExtremum* pExamine)	// проверка условии сужения
{

	double Height;
	double NextHeight;
	if (pExamine->nEData.isExtremum)
	{
		Height = pPrevPrev->nEData.pCandle->nCData.nHigh - pPrev->nEData.pCandle->nCData.nLow;
		NextHeight = pExamine->nEData.pCandle->nCData.nHigh - pPrev->nEData.pCandle->nCData.nLow;
	}
	else
	{
		Height = pPrev->nEData.pCandle->nCData.nHigh - pPrevPrev->nEData.pCandle->nCData.nLow;
		NextHeight = pPrev->nEData.pCandle->nCData.nHigh - pExamine->nEData.pCandle->nCData.nLow;
	}


	if (NextHeight < Height && NextHeight >= 0.618 * Height)
		return true;
	else
		return false;
}

void ExtremumList::triangle(CExtremum* pZero)
{	
	if (OppositeExtremum(pZero, pZero->pNextE))
	{
		int NofPoints = 1;
		ExtremumList Triangle;

		CExtremum* pPrevPrev = pZero;
		CExtremum* pPrev = pPrevPrev->pNextE;
		CExtremum* pExamine = pPrev->pNextE;

		Triangle.push_backE(pZero->nEData);
		Triangle.push_backE(pPrev->nEData);

		for (int num = 2; num <= 5; num++)
		{
			if (OppositeExtremum(pPrev, pExamine) && Narrowing(pPrevPrev, pPrev, pExamine))
			{
				Triangle.push_backE(pExamine->nEData);
				pPrevPrev = pPrev;
				pPrev = pExamine;
				pExamine = pExamine->pNextE;
				NofPoints++;
			}
		}
		if(NofPoints == 5)
			Triangle.printE();
	}
}

