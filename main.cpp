#include "ConMake.h"
#include "SefaKALKAN.h"

void init();

int check = 1;
int mainController = 1;
int sellerController = 1;
int preferencesController = 1;
int customerController = 1;
int productController = 1;

//If unbounded number entered it brokes game bcs of counter (sayac) can be solved in switch case 
//Can be upgraded by adding do you want to play again and creating new tables on sql by it
int main() {
    MYSQL_ROW row;
    MYSQL_RES* res;
    ConMake conMake;
    MainBody mainBody;
    MYSQL* connect;
    connect = mysql_init(0);
    ConMake::mainCon(connect);
    char tempC1;
    int temp1, temp2, temp3, temp4;
    string tempS1, tempS2, tempS3, tempS4;


    init();
    while (check) {
        std::cout << "1)CRUD about seller\n2)CRUD about Seller preferences\n3)CRUD about ";
        std::cout << "customer\n4)CRUD about Product which created by customer\n5)Check multiple tables at same time\n6)After agreement delete item\n9)Exit\nWhat do you want ? : ";
        std::cin >> mainController;

        switch (mainController) {
        case 1:
            std::cout << "1)Create\n2)Read\n3)Delete\n4)Exit\nWhat do you want ? : ";
            std::cin >> sellerController;
            switch (sellerController)
            {
            case 1:
                std::cout << "Please enter your position : ";
                std::cin >> temp1;
                std::cout << "Please enter your Name : ";
                std::cin >> tempS1;
                std::cout << "Please enter your Surname : ";
                std::cin >> tempS2;
                mainBody.seller(connect, temp1, tempS1, tempS2);
                break;
            case 2:
                MYSQL_ROW row;
                MYSQL_RES* res;
                mysql_query(connect, "Select * from Seller");
                res = mysql_store_result(connect);
                while (row = mysql_fetch_row(res)) {
                    printf("ID : %s, Name : %s,Surname : %s,Current Position : %s,Profile star : %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
                }
                break;
            case 3:
                mysql_query(connect, "DELETE FROM Seller");
                break;
            case 4:
                sellerController = 0;
                break;
            };
            break;
        case 2:
            std::cout << "1)Create\n2)Read\n3)Delete\n4)Exit\nWhat do you want ? :";
            std::cin >> preferencesController;
            switch (preferencesController)
            {
            case 1:
                std::cout << "Please enter your Liked Categories ? : ";
                std::cin >> tempS1;
                std::cout << "Please enter your FavoritedItemID : ";
                std::cin >> temp3;
                std::cout << "Please enter your Max Price Range : ";
                std::cin >> temp1;
                std::cout << "Please enter your Minimum Profile Star : ";
                std::cin >> temp2;
                std::cout << "Please enter your CustomerID ";
                std::cin >> temp4;
                mainBody.preferences(connect, temp1, tempS1, temp3, temp2, temp4);
                break;
            case 2:
                mysql_query(connect, "Select * from preferences");
                MYSQL_ROW row;
                MYSQL_RES* res;
                res = mysql_store_result(connect);
                while (row = mysql_fetch_row(res)) {
                    printf("CustomerID : %s, LikedCategories : %s, PriceRange : %s, MinimumProfileStar : %s, FavoritedItemID : %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
                }
                break;
            case 3:
                mysql_query(connect, "DELETE FROM preferences");
                break;
            case 4:
                preferencesController = 0;
                break;
            };
        case 3:
            std::cout << "1)Create\n2)Read\n3)Delete\n4)Exit\nWhat do you want ? : ";
            std::cin >> customerController;
            switch (customerController)
            {
            case 1:
                std::cout << "Please enter your Name : ";
                std::cin >> tempS1;
                std::cout << "Please enter your Surname : ";
                std::cin >> tempS2;
                std::cout << "Please enter your Max Looking range : ";
                std::cin >> temp1;
                std::cout << "Please enter your current position : ";
                std::cin >> temp2;
                mainBody.customer(connect, temp1, temp2, tempS1, tempS2);
                break;
            case 2:
                mysql_query(connect, "Select * from Customer");
                MYSQL_ROW row;
                MYSQL_RES* res;
                res = mysql_store_result(connect);
                while (row = mysql_fetch_row(res)) {
                    printf("ID : %s, Name : %s, Surname : %s, LookingRange : %s, CurrentPosition : %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
                }
                break;
            case 3:
                mysql_query(connect, "DELETE FROM Customer");
                break;
            case 4:
                customerController = 0;
                break;
            };
            break;
        case 4:
            std::cout << "1)Create\n2)Read\n3)Delete\n4)Exit\nWhat do you want ? : ";
            std::cin >> productController;
            switch (productController)
            {
            case 1:
                std::cout << "Please enter your ownerID : ";
                std::cin >> temp1;
                std::cout << "Please enter your product's category : ";
                std::cin >> tempS1;
                std::cout << "Please enter ID of your photo : ";
                std::cin >> temp2;
                std::cout << "Please enter price of your product : ";
                std::cin >> temp3;
                mainBody.createProduct(connect, temp3, temp2, tempS1, temp1);
                break;
            case 2:
                mysql_query(connect, "Select * from createProduct");
                MYSQL_ROW row;
                MYSQL_RES* res;
                res = mysql_store_result(connect);
                while (row = mysql_fetch_row(res)) {
                    printf("OwnerID : %s, Price : %s, Photo : %s, Category : %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
                }
                break;
            case 3:
                mysql_query(connect, "DELETE FROM createProduct");
                break;
            case 4:
                customerController = 0;
                break;
            };
            break;
        case 5:
            MYSQL_ROW row;
            MYSQL_RES* res;
            mysql_query(connect, "call Item()");//I dont have time so i did not put veriables in funcion but i can put and start it for other tables.
            res = mysql_store_result(connect);
            while (row = mysql_fetch_row(res)) {
                printf("ProfileStar : %s, Price : %s,Photo : %s\n", row[0], row[1], row[2]);
            }
            break;
        case 6:
            mysql_query(connect, "call sefakalk_HomeWork.new_procedure();");
            break;
        case 9:
            check = 0;
            break;
        };
    };




}

void init() {
    check = 1;
    mainController = 1;
    sellerController = 1;
    preferencesController = 1;
    customerController = 1;
    productController = 1;
}
