#pragma once

#include <iostream>
#include <sstream>
#include "mysql.h"

using namespace std;

class ConMake
{
public:
	static int mainCon(MYSQL* conn);
	static void deleteInside(MYSQL* conn);
	static void showInside(MYSQL* conn, string table);

};

class MainBody {
public:
	static void preferences(MYSQL* conn, int price, string likedCategories, int favoritedItemID, int minimumProfileStar, int customerID);
	static void seller(MYSQL* conn, int currentPosition, string name, string surname);
	//There should be profileStar but seller cannot change or reach it 
	static void customer(MYSQL* conn, int lookingRange, int currentPosition, string name, string surname);
	static void createProduct(MYSQL* conn, int price, int photo, string category, int ownerID);
};
