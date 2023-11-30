#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "bachelorette.h"

#include "json.hpp"
using json = nlohmann::json;

string returnTitle() {
	fstream titleData;
	titleData.open("title.txt", ios::in);

	string title = "";
	if (titleData.is_open()) {
		//cout << "test1";
		string pass = "";
		while (getline(titleData, pass)) {
			title += pass;
		}
	}
	titleData.close();
	return title;
}

bachelorette readBachelorette(int posInFile) {
	bachelorette bachToPass;
	
	//cout << system("echo %cd%") << endl;

	ifstream fileStream("./bachelorette-data.json");
	
	string line;
	string buf;
	
	//Read file contents into buf
	while (getline(fileStream, line))
		buf += line;

	if (fileStream.is_open())
	{
		//Parses buf, not the ifstream
		json jsonData = json::parse(buf);
		bachToPass.name = jsonData["name"];
		bachToPass.specialInterest = jsonData["specialInterest"];
		//bachToPass.likes = 
	}

	fileStream.close();

	return bachToPass;
}