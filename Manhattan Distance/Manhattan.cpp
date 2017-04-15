#include "Manhattan.h"

int Distance(const WaterPipe &a, const WaterPipe &b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void ReadCityMapFromFile(map<int, vector<WaterPipe>> &cityHydrantsMap, istream& fin)
{
	int row, col;
	fin >> row >> col;
	for (int i = 0; i<row; i++)
		for (int j = 0; j<col; j++)
		{
			int hydrant_ID;
			fin >> hydrant_ID;
			cityHydrantsMap[hydrant_ID].push_back(WaterPipe(i, j));
		}
}

void PrintRedundantWaterPipes::operator()(const pair<int, vector<WaterPipe>> currentHydrant)
{
	bool sameid = false;
	for (auto currentWaterPipe = currentHydrant.second.begin(), END = currentHydrant.second.end() - 1; currentWaterPipe != END; currentWaterPipe++)
	{

		for (auto cmpWithCurrentWaterPipe = currentWaterPipe + 1; cmpWithCurrentWaterPipe != (END + 1); cmpWithCurrentWaterPipe++)
		{
			if (Distance(*currentWaterPipe, *cmpWithCurrentWaterPipe) <= _ManhattanDistance)
				if (sameid == false)
				{
					fout << currentHydrant.first << " : (" << currentWaterPipe->x << "," << currentWaterPipe->y << ") (" << cmpWithCurrentWaterPipe->x << "," << cmpWithCurrentWaterPipe->y << ")";
					sameid = true;
				}
				else
					fout << ";(" << currentWaterPipe->x << "," << currentWaterPipe->y << ") (" << cmpWithCurrentWaterPipe->x << "," << cmpWithCurrentWaterPipe->y << ")";
		}

	}
	if (sameid)
		fout << endl;
}