#pragma once
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct WaterPipe
{
	int x, y;
	WaterPipe(int x = 0, int y = 0) : x(x), y(y) {}
};

int Distance(const WaterPipe &a, const WaterPipe &b);

struct PrintRedundantWaterPipes
{
	PrintRedundantWaterPipes(int& md, ofstream& f) : _ManhattanDistance(md), fout(f) {}

	void operator()(const pair<int, vector<WaterPipe>> currentHydrant);
	
	int& _ManhattanDistance;
	ofstream& fout;
};

void ReadCityMapFromFile(map<int, vector<WaterPipe>> &cityHydrantsMap, istream& fin);
