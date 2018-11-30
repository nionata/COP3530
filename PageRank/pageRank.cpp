//
//  pageRank.cpp
//  
//
//  Created by Nicholas Ionata on 11/27/18.
//

#include <string>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int entries, powerIter;
	cin >> entries;
	cin >> powerIter;
	
	//Adjacency List
	unordered_map<string, vector<string>> urlMappings;
	
	for(int i = 0; i < entries; i++) {
		string urlOne, urlTwo;
		cin >> urlOne;
		cin >> urlTwo;
		
		if(urlMappings.find(urlTwo) == urlMappings.end()) {
			vector<string> blank;
			urlMappings[urlTwo] = blank;
		}

		urlMappings[urlOne].push_back(urlTwo);
	}
	
	//KeySet
	vector<string> keys;
	vector<string> keysAlpha;
	keys.reserve(urlMappings.size());
	keysAlpha.reserve(urlMappings.size());
	for(auto kv : urlMappings) {
		keys.push_back(kv.first);
		keysAlpha.push_back(kv.first);
	}
	int urls = keys.size();
	
	//Adjacency Matrix
	double adjacencyMatrix [urls][urls];
	
	for(int i = 0; i < urls; i++) {
		vector<string> pointingNodes = urlMappings[keys[i]];
		int outDeg = pointingNodes.size();
		for(int j = 0; j < urls; j++) {
			adjacencyMatrix[j][i] = 0;
		}
		
		for(int j = 0; j < outDeg; j++) {
			int pointingIndex = distance(keys.begin(), find(keys.begin(), keys.end(), pointingNodes[j]));
			adjacencyMatrix[pointingIndex][i] = 1.0/(double)outDeg;
		}
	}
	
	//Power Iterations
	int powerIterCounter = 1;
	double ranks [urls][1];
	double result [urls][1];
	
	for(int i = 0; i < urls; i++) {
		ranks[i][0] = 1.0/(double) urls;
		result[i][0] = 0.0;
	}
	
	if(powerIter != 1) {
		do {
			for(int i = 0; i < urls; ++i) {
				for(int k = 0; k < urls; ++k){
					result[i][0] += (adjacencyMatrix[i][k] * ranks[k][0]);
				}
			}
			
			for(int i = 0; i < urls; i++) {
				ranks[i][0] = result[i][0];
				result[i][0] = 0;
			}
			powerIterCounter++;
		} while(powerIterCounter < powerIter);
	}
	
	sort(keysAlpha.begin(), keysAlpha.end());
	
	for(int i = 0; i < urls; i++) {
		int index = distance(keys.begin(), find(keys.begin(), keys.end(), keysAlpha[i]));
		cout << keysAlpha[i] << " " << setprecision(2) << fixed << ranks[index][0] << endl;
		
	}
}
