//Jane Cristel Bohol
//Outcomes Evaluation #2
//POS Computer System that computes 3 kinds of product input plus 12% VAT
//Implement Input / Output Stream File
//November 22 2021

#include<iostream>
#include<string>
#include<conio.h>
#include <fstream>
#include <cstdlib>

const float TAX = 0.12;
using namespace std;


int main()
{
ifstream in_stream;
ofstream ou_stream;

ou_stream.open("POS.txt", ios::app); 

    int qty1, qty2, qty3;
    long int p1id, p2id, p3id;
    double price1, price2, price3, fprice, tprice1, tprice2, tprice3, tprice, ttprice;
    string p1name, p2name, p3name, cname;


    if (ou_stream.fail())
    {
    cout << "Output file opening failed.\n";
    exit(1);
    }

    cout << "Good Day Shopper!";
    getch();
    
    //Product 1
    cout << "\nPlease Enter Your Name: ";
    getline(cin,cname);
    in_stream >> cname;
    cout << "\nEnter Product Name 1: ";
    getline(cin,p1name);
    in_stream >> p1name;
    cout << "Enter Product ID 1 : ";
    cin >> p1id;
    in_stream >> p1id;
    cout << "Enter Product 1 Price : ";
    cin >> price1;
    in_stream >> price1;
    cout << "Enter Quantity : ";
    cin.ignore();
    cin >> qty1;
    in_stream >> qty1;
    getch();

    //Product 2
    cout << "\nEnter Product Name 2: ";
    cin.ignore();
    getline(cin,p2name);
    in_stream >> p2name;
    cout << "Enter Product ID 2 : ";
    cin >> p2id;
    in_stream >> p2id;
    cout << "Enter Product 2 Price : ";
    cin >> price2;
    in_stream >> price2;
    cout << "Enter Quantity : ";
    cin >> qty2;
    in_stream >> qty2;
    getch();

    //Product 3
    cout << "\nEnter Product Name 3: ";
    cin.ignore();
    getline(cin,p3name);
    in_stream >> p3name;
    cout << "Enter Product ID 3 : ";
    cin >> p3id;
    in_stream >> p3id;
    cout << "Enter Product 3 Price : ";
    cin >> price3;
    in_stream >> price3;
    cin.ignore();
    cout << "Enter Quantity : ";
    cin >> qty3;
    in_stream >> qty3;
    getch();
    

    //Solutions
    tprice1 = price1 * qty1;
    tprice2 = price2 * qty2;
    tprice3 = price3 * qty3;
    tprice = tprice1 + tprice2 + tprice3;
    ttprice = (tprice * TAX) + tprice;

    cout.setf (ios::fixed);
    cout.setf (ios::showpoint);
    cout.precision (2);

    //Receipt
    cout << "\nThank you for shopping with us " << cname << "!" << endl;
    cout << "Here's Your Receipt!" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Product Id Product Name Price" << endl;
    cout << p1id << " " << p1name << " " << "PHP" << tprice1 << endl;
    cout << p2id << " " << p2name << " " << "PHP" << tprice2 << endl;
    cout << p3id << " " << p3name << " " << "PHP" << tprice3 << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Total price w/o TAX : PHP " << tprice << endl;
    cout << "Total Price w/ TAX : PHP " << ttprice << endl;
    cout << "---------------------------------------------" << endl;
    getch();

    // set precision
    ou_stream.setf (ios::fixed);
    ou_stream.setf (ios::showpoint);
    ou_stream.precision (2);

    //Receipt
    ou_stream << "\nThank you for shopping with us " << cname << "!" << endl;
    ou_stream << "Here's Your Receipt!" << endl;
    ou_stream << "--------------------------------------------" << endl;
    ou_stream << "Product Id Product Name Price" << endl;
    ou_stream << p1id << " " << p1name << " " << "PHP" << tprice1 << endl;
    ou_stream << p2id << " " << p2name << " " << "PHP" << tprice2 << endl;
    ou_stream << p3id << " " << p3name << " " << "PHP" << tprice3 << endl;
    ou_stream << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    ou_stream << "Total price w/o TAX : PHP " << tprice << endl;
    ou_stream << "Total Price w/ TAX : PHP " << ttprice << endl;
    ou_stream << "---------------------------------------------" << endl;
    getch();


    ou_stream.close();
    return 0;
}