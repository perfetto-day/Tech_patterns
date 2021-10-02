#ifndef __TRADINGLIST_H__
#define __TRADINGLIST_H__

#include "CCandle.h"
#include <iostream>
#include <string>

using namespace std;

class TradingList
{
private:
	CCandle* pStart;
	CCandle* pEnd;
	string ticker;

	friend class ExtremumList;
public:
	TradingList();
	~TradingList();

	void clear();
	void print() const;

	void printticker() const;

	void pop_front();
	void push_back(CandleData _ncData);

	CCandle* getRoot() { return pStart;}

	void readFile(void);

	//void compare(ExtremumList _ExtremumList, unsigned int step);
};

#endif // __TRADINGLIST_H__
