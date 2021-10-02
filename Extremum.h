#ifndef __EXTREMUM_H__
#define __EXTREMUM_H__

#include "CCandle.h"

class DataExtremum
{
public:
    CCandle* pCandle;
    bool isExtremum;
    void print() const;
};


struct CExtremum
{
public:
    DataExtremum nEData;


private:
    CExtremum* pNextE;
 //   CExtremum* pBackE;

    friend class ExtremumList;
    friend class TradingList;

public:
    CExtremum(DataExtremum _nEData);
    CExtremum(DataExtremum _nEData, CExtremum* _pNextE);

    //CNode* next() { return pNext; }
};


#endif //__EXTREMUM_H__
