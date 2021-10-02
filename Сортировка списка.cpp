
	PatternList PatternListSorted;
	ExtremumList* nTemp = g_PatternList.root();
	int recentdatetime = 0;

	while (nTemp != nullptr)
	{
		ExtremumList* minTemp = g_PatternList.root();
		ExtremumList* pTemp = g_PatternList.root();

		while (pTemp != nullptr)
		{
			int mindatetime = 999999999;
			int date = pTemp->pRootE->nEData.pCandle->nCData.nDate;
			int time = pTemp->pRootE->nEData.pCandle->nCData.nTime;
			int datetime = date * 1000000 + time;

			if (datetime < mindatetime && datetime > recentdatetime)
			{
				mindatetime = datetime; 
				minTemp = pTemp;
			}
			pTemp = pTemp->next();
		}
		int date = minTemp->pRootE->nEData.pCandle->nCData.nDate;
		int time = minTemp->pRootE->nEData.pCandle->nCData.nTime;
		recentdatetime = date * 100000 + time;
		PatternListSorted.push_back(minTemp);
		nTemp = nTemp->next();
	}

	PatternListSorted.print();
