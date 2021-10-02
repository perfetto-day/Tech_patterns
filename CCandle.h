#ifndef __CCANDLE_H__
#define __CCANDLE_H__

struct CandleData
{
public:
	int nPer;
	int nDate;
	int nTime;
	double nOpen;
	double nHigh;
	double nLow;
	double nClose;
	int nVol;

	void print() const;

	CandleData(int _nPer, int _nDate, int _nTime, 
		double _nOpen, double _nHigh, double _nLow, double _nClose, int _nVol);
	
	CandleData();
};

struct CCandle
{
public:
	CandleData nCData;

private:
	CCandle* pNext;
	CCandle* pBack;

	friend class TradingList;
	friend class ExtremumList;
public:
	CCandle(CandleData _nCData);
	CCandle(CandleData _nCData, CCandle* _pNext, CCandle* _pBack);
	
	//CCandle* next() { return pNext; }
};

#endif //__CCANDLE_