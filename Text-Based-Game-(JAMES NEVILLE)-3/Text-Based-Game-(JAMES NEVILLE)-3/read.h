#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "bachelorette.h"

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