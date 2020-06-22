#include "ConMake.h"

int ConMake::mainCon(MYSQL* conn)
{
    conn = mysql_real_connect(conn, "srvc65.turhost.com", "sefakalk_sef", "sefakalkan!", "sefakalk_HomeWork", 3306, NULL, 0);

    if (conn) {
        cout << "Successfully connected to Database" << endl;

        return 1;
    }
    else {
        cout << "Unable to connect Database";
        return 0;
    }
}

void ConMake::deleteInside(MYSQL* conn) {

    // DELETE FROM `Game2`
    mysql_query(conn, "DELETE FROM `Game2`");// could be improved by adding Game + int like did in main so could be deleted on like  (DELETE FROM Game+int)
}

void ConMake::showInside(MYSQL* conn, string table) {

    MYSQL_ROW row;
    MYSQL_RES* res;
    string temp = "SELECT * FROM " + table;

    mysql_query(conn, temp.c_str());// We could also do the same thing to game2 
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) {
        printf("PLAYER1 : %s, PLAYER2: %s,PLAYER3: %s,PLAYER4: %s,PLAYER5: %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
    }
}

void MainBody::customer(MYSQL* conn, int lookingRange, int currentPosition, string name, string surname) {

    string temp;
    temp = "INSERT INTO `Customer`(`Name`, `Surname`, `LookingRange`, `CurrentPosition`) VALUES(\"" + name + "\",\"" + surname + "\"," + to_string(lookingRange) + "," + to_string(currentPosition) + ")";
    mysql_query(conn, temp.c_str());

}

void MainBody::createProduct(MYSQL* conn, int price, int photo, string category, int ownerID) {
    string temp;
    temp = "INSERT INTO `createProduct`(`OwnerID`, `Price`, `Photo`, `Category`) VALUES(" + to_string(ownerID) + "," + to_string(price) + "," + to_string(photo) + ",\"" + category + "\")";
    mysql_query(conn, temp.c_str());
}

void MainBody::seller(MYSQL* conn, int currentPosition, string name, string surname) {
    string temp;
    temp = "INSERT INTO `Seller`(`Name`, `Surname`, `CurrentPosition`) VALUES(\"" + name + "\",\"" + surname + "\"," + to_string(currentPosition) + ")";
    mysql_query(conn, temp.c_str());
}

void MainBody::preferences(MYSQL* conn, int price, string likedCategories, int favoritedItemID, int minimumProfileStar, int customerID) {
    string temp;
    temp = "INSERT INTO `preferences`(`LikedCategories`, `FavoritedItemID`, `PriceRange`, `MinimumProfileStar`,`customerID`)\
        VALUES(\"" + likedCategories + "\"," + to_string(favoritedItemID) + "," + to_string(price) + "," + to_string(minimumProfileStar) + "," + to_string(customerID) + ")";
    std::cout << "\n\n" << temp << " \n\n";
    mysql_query(conn, temp.c_str());
}


