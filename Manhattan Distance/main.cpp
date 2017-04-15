#include "Manhattan.h"

int main()
{
	ifstream inputFile("ManhattanDistance.in");
	ofstream outputFile("ManhattanDistance.out");
	int MaxD;
	inputFile >> MaxD;

	map<int, vector<WaterPipe>> cityHydrantsMap;

	ReadCityMapFromFile(cityHydrantsMap, inputFile);

	for_each(cityHydrantsMap.begin(), cityHydrantsMap.end(), PrintRedundantWaterPipes(MaxD, outputFile));
		
	return 0;
}