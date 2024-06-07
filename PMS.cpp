// C++ program to illustrate product shop
// management system using File Handling
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Productshop Class
class productshop {
public:
    void control_panel();
    void add_product();
    void show_product();
    void check_product();
    void update_product();
    void del_product();
};

// Function to display the menus
void productshop::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t\tCONTROL PANEL";
    cout << "\n\n1. ADD PRODUCT";
    cout << "\n2. DISPLAY PRODUCTS";
    cout << "\n3. CHECK PARTICULAR PRODUCT";
    cout << "\n4. UPDATE PRODUCT";
    cout << "\n5. DELETE PRODUCT";
    cout << "\n6. EXIT";
}

// Function to add product
void productshop::add_product()
{
    system("cls");
    fstream file;
    int no_copy;
    string p_name, a_name, p_id;
    cout << "\n\n\t\t\t\tADD PRODUCTS";
    cout << "\n\nProduct ID : ";
    cin >> p_id;
    cout << "\nProduct Name : ";
    cin >> p_name;
    cout << "\nBrand Name : ";
    cin >> a_name;
    cout << "\nNo. of Products : ";
    cin >> no_copy;

    // Open file in append or
    // output mode
    file.open("product.txt",
        ios::out | ios::app);
    file << " " << p_id << " "
        << p_name << " " << a_name
        << " " << no_copy << "\n";
    file.close();
}

// Function to display product
void productshop::show_product()
{
    system("cls");
    fstream file;
    int no_copy;
    string p_name, p_id, a_name;
    cout << "\n\n\t\t\t\t\tAll PRODUCTS";

    // Open the file in input mode
    file.open("product.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\nProduct ID\t\tProduct"
            << "\t\tBrand\t\tNo. of "
            "Products\n\n";
        file >> p_id >> p_name;
        file >> a_name >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {

            cout << " " << p_id
                << "\t\t" << p_name
                << "\t\t" << a_name
                << "\t\t" << no_copy
                << "\n\n";
            file >> p_id >> p_name;
            file >> a_name >> no_copy;
        }

        system("pause");

        // Close the file
        file.close();
    }
}

// Function to check the product
void productshop::check_product()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string p_id, p_name, a_name, p_idd;

    cout << "\n\n\t\t\t\tCheck "
        << "Particular Product";

    // Open the file in input mode
    file.open("product.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nProduct ID : ";
        cin >> p_idd;
        file >> p_id >> p_name;
        file >> a_name >> no_copy;

        while (!file.eof()) {

            if (p_idd == p_id) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                    << "Check Particular Product";
                cout << "\n\nProduct ID : "
                    << p_id;
                cout << "\nName : "
                    << p_name;
                cout << "\nBrand : "
                    << a_name;
                cout << "\nNo. of Products : "
                    << no_copy;
                cout << endl
                    << endl;
                count++;
                break;
            }
            file >> p_id >> p_name;
            file >> a_name >> no_copy;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nProduct ID Not"
            << " Found...";
    }
}

// Function to update the product
void productshop::update_product()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string p_name, p_na, a_name;
    string a_na, p_idd, p_id;

    cout << "\n\n\t\t\t\tUpdate Product Record";
    file1.open("product1.txt",
        ios::app | ios::out);
    file.open("product.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\nProduct ID : ";
        cin >> p_id;
        file >> p_idd >> p_name;
        file >> a_name >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {
            if (p_id == p_idd) {
                system("cls");
                cout << "\t\t\t\t"
                    << "Update Product Record";
                cout << "\n\nNew Product Name : ";
                cin >> p_na;
                cout << "\nBrand Name : ";
                cin >> a_na;
                cout << "\nNo. of Products : ";
                cin >> no_co;
                file1 << " " << p_id << " "
                    << p_na << " "
                    << a_na << " " << no_co
                    << "\n\n";
                count++;
            }
            else
                file1 << " " << p_idd
                << " " << p_name
                << " " << a_name
                << " " << no_copy
                << "\n\n";
            file >> p_idd >> p_name;
            file >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nProduct ID"
            << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("product.txt");
    rename("product1.txt",
        "product.txt");
}

// Function to delete product
void productshop::del_product()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string p_id, p_idd, p_name, a_name;
    cout << "\n\n\t\t\t\tDelete a Product";

    // Append file in output mode
    file1.open("product1.txt",
        ios::app | ios::out);
    file.open("product.txt",
        ios::in);

    if (!file)
        cout << "\n\nFile Opening Error...";
    else {

        cout << "\n\nProduct ID : ";
        cin >> p_id;
        file >> p_idd >> p_name;
        file >> a_name >> no_copy;
        while (!file.eof()) {

            if (p_id == p_idd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                    << "Delete a Product";
                cout << "\n\nProduct is Deleted "
                    << "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << p_idd
                    << " " << p_name
                    << " " << a_name
                    << " " << no_copy
                    << "\n\n";
            file >> p_idd >> p_name;
            file >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nProduct ID "
            << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("product.txt");
    rename("product1.txt",
        "product.txt");
}

// Function for product shop record
void productShopRecord()
{
    int choice;
    char x;
    productshop p;

    while (1) {

        p.control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                p.add_product();
                cout << "\n\nWant to add"
                    << " another product? "
                        "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            p.show_product();
            break;

        case 3:
            p.check_product();
            break;
        case 4:
            p.update_product();
            break;

        case 5:
            p.del_product();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}

// Driver Code
int main()
{
    // Function Call
    productShopRecord();

    return 0;
}

