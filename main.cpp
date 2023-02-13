#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
//create a universal list<Shipping> to store all the data

struct ShippingData
{
    int id{};
    char warehouse_block{};
    std::string mode_of_shipment;
    int customer_care_calls{};
    int customer_rating{};
    int cost_of_the_product{};
    int prior_purchases{};
    string product_importance;
    char gender{};
    int discount_offered{};
    int weight_in_grams{};
    int reached_on_time{};

};

static list<ShippingData> shippingDataList;
static vector<ShippingData> shippingDataVector;

void displayAll();

ShippingData displayFront();

ShippingData displayLast();

ShippingData findByID();

void deleteFirst();

void deleteLast();

void deleteByPosition();

void insertByPosition();

void RatingsLessThan2();

void sortListByRating();

void populateVector();

void displayAllVector();

void displayByIndex();

void insertByPositionVector();

void sortVectorByProductCost();

void sortVectorByID();

void displayByRating();
void checkForInvalidProductImportanceValues(list<ShippingData> &shippingList, unordered_set<string> validProductImportanceValues);

void display(const ShippingData &sh_data){

    cout << left
         << setw(10) << "ID"
         << setw(10) << "Warehouse Block"
         << setw(10) << "Mode of Shipment"
         << setw(10) << "Customer Care Calls"
         << setw(10) << "Customer Rating"
         << setw(10) << "Cost of the Product"
         << setw(10) << "Prior Purchases"
         << setw(10) << "Product Importance"
         << setw(10) << "Gender"
         << setw(10) << "Discount Offered"
         << setw(10) << "Weight in Grams"
         << setw(10) << "Reached on Time Y/N" << endl;

    cout <<left
        << setw (10) << sh_data.id
            << setw(10) << sh_data.warehouse_block
            << setw(10) << sh_data.mode_of_shipment
            << setw(10) << sh_data.customer_care_calls
            << setw(10) << sh_data.customer_rating
            << setw(10) << sh_data.cost_of_the_product
            << setw(10) << sh_data.prior_purchases
            << setw(10) << sh_data.product_importance
            << setw(10) << sh_data.gender
            << setw(10) << sh_data.discount_offered
            << setw(10) << sh_data.weight_in_grams
            << setw(10) << sh_data.reached_on_time << endl;
}
void parseLine(string line, ShippingData &sh_data) {

    try{

        stringstream sstream(line);
        getline(sstream,line, ',');
        sh_data.id = stoi(line);
        getline(sstream,line, ',');
        sh_data.warehouse_block = line[0];
        getline(sstream,line, ',');
        sh_data.mode_of_shipment = line;
        getline(sstream,line, ',');
        sh_data.customer_care_calls = stoi(line);
        getline(sstream,line, ',');
        sh_data.customer_rating = stoi(line);
        getline(sstream,line, ',');
        sh_data.cost_of_the_product = stoi(line);
        getline(sstream,line, ',');
        sh_data.prior_purchases = stoi(line);
        getline(sstream,line, ',');
        sh_data.product_importance = line;
        getline(sstream,line, ',');
        sh_data.gender = line[0];
        getline(sstream,line, ',');
        sh_data.discount_offered = stoi(line);
        getline(sstream,line, ',');
        sh_data.weight_in_grams = stoi(line);
        getline(sstream,line, ',');
        sh_data.reached_on_time = stoi(line);

    }
    catch (std::invalid_argument const& e)
    {
        cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const& e)
    {
        cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }

};


void LoadData(){

// ifStream read file from the directory
    ifstream file("shipping-data-large.csv");
    if (file.good())
    {
        string line;
        while (getline(file, line))
        {
            ShippingData sh_data;
            parseLine(line, sh_data);
            shippingDataList.push_back(sh_data);
        }
        file.close();

    }
    else
    {
        cout << "File not found" << endl;
    }



}

   void linkedListFeatures()
   {
        cout<<"Please select one of the following Linked List options"<<endl;
        cout<<"1 - Display Linked-List Elements"<<endl;
        cout<<"2 - Display Front Element in linked-list"<<endl;
        cout<<"3 - Display Last Element from linked-list"<<endl;
        cout<<"4 - Find the Element by ID"<<endl;
        cout<<"5 - Delete First Element"<<endl;
        cout<<"6 - Delete Last Element"<<endl;
        cout<<"7 - Delete Nth Element"<<endl;
        cout<<"8 - Insert an element at Nth position"<<endl;
        cout<<"9 - Count Customer Ratings that are less than 2"<<endl;
        cout<<"10 - Sort the Linked-List in order of Customer Rating"<<endl;
        cout<<"11 - Exit"<<endl;
        cout<<"Please enter your choice: "<<endl;
        int choice;
        cin >>  choice;

        if(choice < 1 || choice > 11){
            throw "Invalid Choice";
        }
        else{
            switch(choice)
            {
                case 1:
                cout<<"You have selected Display Linked-List Elements"<<endl;
                displayAll();
                break;
                case 2:
                cout<<"You have selected Display Front Element in linked-list"<<endl;
                displayFront();
                break;
                case 3:
                cout<<"You have selected Display Last Element from linked-list"<<endl;
                displayLast();
                break;
                case 4:
                cout<<"You have selected Find the Element by ID"<<endl;
                findByID();
                break;
                case 5:
                cout<<"You have selected Delete First Element"<<endl;
                deleteFirst();
                break;
                case 6:
                cout<<"You have selected Delete Last Element"<<endl;
                deleteLast();
                break;
                case 7:
                cout<<"You have selected Delete Nth Element"<<endl;
                deleteByPosition();
                break;
                case 8:
                cout<<"You have selected Insert an element at Nth position"<<endl;
                insertByPosition();
                break;
                case 9:
                cout<<"You have selected Count Customer Ratings that are less than 2"<<endl;
                        RatingsLessThan2();
                break;
                case 10:
                cout<<"You have selected Sort the Linked-List in order of Customer Rating"<<endl;
                sortListByRating();
                break;
                case 11:
                cout<<"You have selected Exit"<<endl;
                break;
                default:
                cout << ("Invalid Choice");
            }
        }
   }

void sortListByRating() {

    //Sort the Linked-List in order of Customer Rating
    shippingDataList.sort([](ShippingData& a, ShippingData& b)
    {
        return a.customer_rating < b.customer_rating;
    });
    for (auto iter = shippingDataList.begin(); iter != shippingDataList.end(); iter++) {
        //print out the total data of the list
        cout << "ID: " << iter->id << " Customer Rating: " << iter->customer_rating << endl;

    }

}

void RatingsLessThan2() {

    //Count Customer Ratings that are less than 2.
    int count = 0;
    for (auto iter = shippingDataList.begin(); iter != shippingDataList.end(); iter++) {
        if (iter->customer_rating < 2) {
            count++;
        }
    }
    cout << "Number of ratings less than 2: " << count << endl;

}

void insertByPosition() {

    //insert element by position
    int position;
    cout << "Please enter the position you want to insert: " << endl;
    cin >> position;
    if (position < shippingDataList.size())
    {
        auto iter = shippingDataList.begin();
        for (int i = 0; i < position; i++) {
            iter++;
        }
        ShippingData newData;
        cout << "Please enter the ID: " << endl;
        cin >> newData.id;
        cout << "Please enter the warehouse Block: " << endl;
        cin >> newData.warehouse_block;
        cout << "Please enter the Mode of Shipment: " << endl;
        cin >> newData.mode_of_shipment;
        cout << "Please enter the customer care calls: " << endl;
        cin >> newData.customer_care_calls;
        cout << "Please enter the customer rating: " << endl;
        cin >> newData.customer_rating;
        cout << "Please enter the cost of the product: " << endl;
        cin >> newData.cost_of_the_product;
        cout << "Please enter the prior purchases: " << endl;
        cin >> newData.prior_purchases;
        cout << "Please enter the product importance: " << endl;
        cin >> newData.product_importance;
        cout << "Please enter the gender: " << endl;
        cin >> newData.gender;
        cout << "Please enter the discount offered: " << endl;
        cin >> newData.discount_offered;
        cout << "Please enter the weight in gms: " << endl;
        cin >> newData.weight_in_grams;
        cout << "Please enter the Reached on time: " << endl;
        cin >> newData.reached_on_time;
        shippingDataList.insert(iter, newData);
    }
    else
    {
        cout<<"Position not found"<<endl;
    }
}

void deleteByPosition() {

    //delete element by position
    int position;
    cout << "Please enter the position you want to delete: " << endl;
    cin >> position;
    if (position < shippingDataList.size())
    {
        auto iter = shippingDataList.begin();
        for (int i = 0; i < position; i++) {
            iter++;
        }
        shippingDataList.erase(iter);
    }
    else
    {
        cout<<"Position not found"<<endl;
    }
}

void deleteLast() {

    //delete last element in the list
    auto iter = shippingDataList.end();
    iter--;
    shippingDataList.erase(iter);
    cout    << "Last element deleted" << endl;

}

void deleteFirst() {

    //delete first element in the list
    auto iter = shippingDataList.begin();
    shippingDataList.erase(iter);
    cout    << "First element deleted" << endl;
}

ShippingData findByID() {

    //find element by ID
    int id;
    cout<<"Please enter the ID you want to find: "<<endl;
    cin>>id;
    auto iter = shippingDataList.begin();
    while(iter != shippingDataList.end())
    {
        if(iter->id == id)
        {
            display(*iter);
            return *iter;
        }
        iter++;
    }
    cout<<"ID not found"<<endl;
    return *iter;

}

ShippingData displayLast() {

    //display last element in the list
    auto iter = shippingDataList.end();
    iter--;
    display(*iter);
    return *iter;

}

ShippingData displayFront() {

    //display 2nd element in the list
    auto iter = shippingDataList.begin();
    iter++;
    display(*iter);
    return *iter;

}

void displayAll() {


    for(auto & iter : shippingDataList)
    {
        display(iter);
    }

}

void vectorFeatures() {
       //a. Populate Vector from the current Linked-List
       //b. Display All Elements from the vector
       //c. Display Element at Index Position i : (user to enter index)
       //d. Insert New Shipping Record at position 2
       //e. Sort the Vector in order of Product Cost
       //f. Sort the vector in order of ID
       //g. Display shipping records where customer rating is less than 3 (you must
       //create a separate vector using copy_if from the <algorithm> library.)
        cout << "Please select one of the following Vector options" << endl;
        cout << "1 - Populate Vector from the current Linked-List" << endl;
        cout << "2 - Display All Elements from the vector" << endl;
        cout << "3 - Display Element at Index Position " << endl;
        cout << "4 - Insert New Shipping Record at the position " << endl;
        cout << "5 - Sort the Vector in order of Product Cost" << endl;
        cout << "6 - Sort the vector in order of ID" << endl;
        cout << "7 - Display shipping records where customer rating is less than 3" << endl;
        cout << "8 - Exit" << endl;
        int choice;
        cin >> choice;
        try {
            if (choice != 8) {
                switch (choice) {
                    case 1:
                        populateVector();
                        break;
                    case 2:
                        displayAllVector();
                        break;
                    case 3:
                        displayByIndex();
                        break;
                    case 4:
                        insertByPositionVector();
                        break;
                    case 5:
                        sortVectorByProductCost();
                        break;
                    case 6:
                        sortVectorByID();
                        break;
                    case 7:
                        displayByRating();
                        break;
                    case 8:
                        cout << "You have selected Exit" << endl;
                        break;
                    default:
                        throw invalid_argument("Invalid choice");
                }
            } else {
                cout << "You have selected Exit" << endl;
            }
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
   }

void displayByRating() {

    //Display shipping records where customer rating is less than 3
    vector<ShippingData> sh_data2;
    copy_if(shippingDataVector.begin(), shippingDataVector.end(), back_inserter(sh_data2), [](ShippingData& a) {
        return a.customer_rating < 3;
    });
    for (auto & iter : sh_data2) {
        display(iter);
    }

}

void sortVectorByID() {

    //Sort the vector in order of ID
    sort(shippingDataVector.begin(), shippingDataVector.end(), [](ShippingData a, ShippingData b) {
        return a.id < b.id;
    });
    cout << "Vector sorted by ID" << endl;
    for(auto & iter : shippingDataVector) {
        display(iter);
    }

}

void sortVectorByProductCost() {

    //Sort the Vector in order of Product Cost
    sort(shippingDataVector.begin(), shippingDataVector.end(), [](ShippingData& a, ShippingData& b) {
        return a.cost_of_the_product < b.cost_of_the_product;
    });
    cout << "Vector sorted by Product Cost" << endl;
    for(auto & iter : shippingDataVector) {
        display(iter);
    }


}

void insertByPositionVector() {

    //insert element by position
    int position;
    cout << "Please enter the position you want to insert: " << endl;
    cin >> position;
    if (position < shippingDataVector.size())
    {
        auto iter = shippingDataVector.begin();
        for (int i = 0; i < position; i++) {
            iter++;
        }
        ShippingData newData;
        cout << "Please enter the ID: " << endl;
        cin >> newData.id;
        cout << "Please enter the warehouse Block: " << endl;
        cin >> newData.warehouse_block;
        cout << "Please enter the Mode of Shipment: " << endl;
        cin >> newData.mode_of_shipment;
        cout << "Please enter the customer care calls: " << endl;
        cin >> newData.customer_care_calls;
        cout << "Please enter the customer rating: " << endl;
        cin >> newData.customer_rating;
        cout << "Please enter the cost of the product: " << endl;
        cin >> newData.cost_of_the_product;
        cout << "Please enter the prior purchases: " << endl;
        cin >> newData.prior_purchases;
        cout << "Please enter the product importance: " << endl;
        cin >> newData.product_importance;
        cout << "Please enter the gender: " << endl;
        cin >> newData.gender;
        cout << "Please enter the discount offered: " << endl;
        cin >> newData.discount_offered;
        cout << "Please enter the weight in gms: " << endl;
        cin >> newData.weight_in_grams;
        cout << "Please enter the Reached on time: " << endl;
        cin >> newData.reached_on_time;
        shippingDataVector.insert(iter, newData);
    }
    else
    {
        cout<<"Position not found"<<endl;
    }

}

void displayByIndex() {

    //display element of vector by index
    int index;
    cout << "Please enter the index you want to display: " << endl;
    cin >> index;
    if (index < shippingDataVector.size())
    {
        auto iter = shippingDataVector.begin();
        for (int i = 0; i < index; i++) {
            iter++;
        }
        display(*iter);
    }
    else
    {
        cout<<"Index not found"<<endl;
    }

}

void displayAllVector() {

    for(auto & iter : shippingDataVector)
    {
        display(iter);
    }

}

void populateVector() {

    //a. Populate Vector from the current Linked-List
    for(auto & iter : shippingDataList)
    {
        shippingDataVector.push_back(iter);

    }
    cout  << "Vector populated Successfully" << endl;
}

void setFeatures() {
       /*
        * * a. Check that all Shipping Records have valid Product Importance (Populate
        an <unordered_set> with valid Product Importance values
        {“low”,”medium”,”high”} and check each record’s product importance
        value against the values in the set.

        */
        unordered_set<string> validProductImportanceValues = {"low", "medium", "high"};
        checkForInvalidProductImportanceValues(shippingDataList, validProductImportanceValues);
   }

void checkForInvalidProductImportanceValues(list<ShippingData> &shippingList, unordered_set<string> validProductImportanceValues)

{

    /*
    Identify those that do not have a valid
    value and print out their id and the invalid value. Place this in a function
    called checkForInvalidProductImportanceValues(list,set), and pass in the
    list of struct and the unordered set of valid values. Use an iterator in the
    function to iterate over the list
    */
    for(auto & iter : shippingDataList)
    {
        if(validProductImportanceValues.find(iter.product_importance) == validProductImportanceValues.end())
        {
            cout << "Invalid Product Importance Value: " << iter.product_importance << " for ID: " << iter.id << endl;
        }
    }



}
   void mapFeatures()
   {
        //Create a <unordered_map> from the contents of the Linked-List
        //(mapping id to a shipping record)
        //b. Find and Display a record given an ID
        unordered_map<int, ShippingData> shippingDataMap;
        for(auto & iter : shippingDataList)
        {
            shippingDataMap.insert({iter.id, iter});
        }
        int id;
        cout << "Please enter the ID you want to display: " << endl;
        cin >> id;
        auto iter = shippingDataMap.find(id);
        if(iter != shippingDataMap.end())
        {
            display(iter->second);
        }
        else
        {
            cout << "ID not found" << endl;
        }

   }

void Menu(){

    bool exit = false;
    while(!exit) {
        cout << "Welcome to the Shipping Data Analysis Program" << endl;
        cout << "Please select one of the following options" << endl;
        cout << "1 - Linked List Features" << endl;
        cout << "2 - Vector Features" << endl;
        cout << "3 - Set Features" << endl;
        cout << "4 - Map Features" << endl;
        cout << "5 - Exit" << endl;
        cout << "Please enter your choice: " << endl;
        try {
            int choice;
            cin >> choice;
            if (choice < 1 || choice > 5) {
                throw "Invalid choice";
            } else {
                switch (choice) {
                    case 1:
                        cout << "You have selected Linked List Features" << endl;
                        linkedListFeatures();
                        break;
                    case 2:
                        cout << "You have selected Vector Features" << endl;
                        vectorFeatures();
                        break;
                    case 3:
                        cout << "You have selected Set Features" << endl;
                        setFeatures();
                        break;
                    case 4:
                        cout << "You have selected Map Features" << endl;
                        mapFeatures();
                        break;
                    case 5:
                        cout << "You have selected Exit" << endl;
                        break;
                }
            }
        } catch (const char *msg) {
            cerr << msg << endl;
            }
    }
}

int main()
{
    LoadData();
    Menu();
    return 0;
}