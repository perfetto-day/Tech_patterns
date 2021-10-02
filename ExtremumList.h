#ifndef __EXTREMUMLIST_H__
#define __EXTREMUMLIST_H__

#include "Extremum.h"
#include "TradingList.h"


class ExtremumList
{
private:
	CExtremum* pRootE;

public:
	ExtremumList();
	~ExtremumList();

	DataExtremum pop_front();

	void push_backE(DataExtremum nEData);

	void clear();

	void printE() const;

	void compare(const TradingList* _TradingList, unsigned int _nStep);

	void search();
	void triangle(CExtremum* pZero);


};


#endif // __EXTREMUMLIST_H__
