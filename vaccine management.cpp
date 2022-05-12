// COVID19 MANAGEMENT SYSTEM USING FILE HANDLING IN CPP

// HEADER FILES
#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <unistd.h>
#define TOTAL_VACCINE 400
using namespace std;

class covid_management
{
protected:
    string username;
    string password;
    string usn;
    int tm;
    // FOR VACCINE CENTER
    string center1 = "1center";
    string center2 = "2center";
    string center3 = "3center";
    int sum_vaccine_c1 = 0; // Center1 vaccine Dose
    int sum_vaccine_c2 = 0; // Center2 vaccine Dose
    int sum_vaccine_c3 = 0; // Center3 vaccine Dose
    int add, center_no;
    // For Doctor Details
    string identification_id;
    char specialization[100];
    string center;
    // For User and some Doctor Details
    char name[100];
    char gender[100];
    int age;
    string adhaar;
    int c;
    string phone_no, profession, address, vaccine_name;
    int dose;

public:
    void menu();
    void admin();
    void admin_password();
    void user();
    void user_password();
    void valid(string str); // For Valid Username Or not

    // For ADMIN
    void add_vaccine_stock();     // 1
    void display_vaccine_stock(); // 2
    void show_patient_data();     // 4
    void show_data();             // 4-a
    void applied_vaccine();       // 5
    void search_by_aadhar();      // 4-a(1)
    void search_by_age();         // 4-a(2)
    void search_by_profession();  // 4-a(3)
    void search_by_gender();      // 4-a(4)

    // FOR USER
    void search_center();       // 1
    void add_patient_data();    // 2
    void patient_show_data();   // 3
    void update_patient_data(); // 4
};

void covid_management::menu()
{
    system("cls");
    int choice;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    // MAIN MENU
    cout << "\n\n\t\t -->> MAIN MENU <<--";
    cout << "\n\n\t\t -->>1. ADMIN";
    cout << "\n\t\t -->>2. USER";
    cout << "\n\t\t -->>3. EXIT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice;
    // CALLING RELEVANT FUNCTION AS PER CHOICE
    switch (choice)
    {
    case 1:
        admin();
        break;
    case 2:
        user();
        break;
    case 3:
        system("cls");
        cout << "\n\n\t\t\t COVID19 MANAGEMENT SYSTEM - BY Yukrant and Vidhi";
        Sleep(10);
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        menu();
    }
}

void covid_management::admin()
{
    admin_password();
A:
    system("cls");
    int admin_choice;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    // ADMIN MENU OPTIONS
    cout << "\n\n\t\t -->> ADMIN MENU <<--";
    cout << "\n\n\t\t 1. Add Vaccine Stock";
    cout << "\n\t\t 2. Show Vaccine Center";
    cout << "\n\t\t 3. Show Vaccine Stock";
    cout << "\n\t\t 4. Show Patient Data";
    cout << "\n\t\t 5. Show Total Number Of Vaccines Applied";
    cout << "\n\t\t 6. LOG OUT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> admin_choice;
    switch (admin_choice)
    {
    case 1:
        add_vaccine_stock();
        goto A;
        break;
    case 2:
        search_center();
        goto A;
        break;
    case 3:
        display_vaccine_stock();
        goto A;
        break;
    case 4:
        show_patient_data();
        goto A;
        break;
    case 5:
        applied_vaccine();
        goto A;
        break;
    case 6:
        menu();
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        goto A;
        break;
    }
}

// ADMIN LOGIN
void covid_management::admin_password()
{
    system("cls");
    char a_name[20];
    char a_password[20];
    int ch, i = 0, capt = 0, capta = 0;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t -->> LOGIN ADMIN <<--";
    cout << "\n\n\t\tEnter Your Name: ";
    cin >> a_name;
    cout << "\n\t\tEnter Your Password: ";
    while ((ch = getch()) != 13)
    {
        cout << "*";
        a_password[i] = ch;
        i++;
    }
    a_password[i] = '\0';
    srand(time(0));
    capt = rand();
    cout << "\n\n\t\tCaptcha: " << capt;
    cout << "\n\n\t\tEnter Valid Captcha: ";
    cin >> capta;
    if ((strcmp(a_name, "yukrant") == 0) && (strcmp(a_password, "ylp123") == 0) && (capt == capta))
    {
        cout << "\n\n\n\t\t\t\t\t| Verfiying ADMIN |\n\t\t\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(500);
            cout << "...";
        }
        cout << "\n\nAccess Granted..\n\n";
        system("PAUSE");
        system("cls");
    }
    else
    {
        cout << "\n\n\n\t\t\t\t\t| Verfiying ADMIN |\n\t\t\t\t\t";
        for (int a = 1; a < 8; a++)
        {
            Sleep(500);
            cout << "...";
        }
        cout << "\n\nAccess Aborted...\n\n";
        system("PAUSE");
        system("cls");
        menu();
    }
}

// USER LOGIN
void covid_management::user()
{
    user_password();
B:
    system("cls");
    int user_choice;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    // USER MENU OPTIONS
    cout << "\n\n\t\t -->> USER MENU <<--";
    cout << "\n\n\t\t 1. Search Vaccination Center";
    cout << "\n\t\t 2. Apply For Vaccine First Dose";
    cout << "\n\t\t 3. Show Details";
    cout << "\n\t\t 4. Apply For Vaccine Second Dose";
    cout << "\n\t\t 5. LOG OUT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> user_choice;
    switch (user_choice)
    {
    case 1:
        search_center();
        goto B;
    case 2:
        add_patient_data();
        goto B;
    case 3:
        patient_show_data();
        goto B;
    case 4:
        update_patient_data();
        goto B;
    case 5:
        menu();
    default:
        cout << "\n\n\t\tInvalid Choice.. Please Try Again..\n";
        cout << "\n\nPress Any Key To Continue..";
        getch();
        goto B;
    }
}

// USER REGISTRATION AND LOGIN
void covid_management::valid(string str) // Check Username is available or not
{
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
        return;
    }
    else
    {
        tm++;
        if (tm == 3)
        {
            cout << "\nThis Username already exists\nPlease Try Again..";
            file.close();
            return;
        }
        cout << "\nThis Username already exists!";
        cout << "\n\n\t\tCreate a Username: ";
        cin >> usn;
        valid(usn);
    }
}

void covid_management::user_password()
{
    system("cls");
    char c;
    int user_choice;
    string fname, usern;
    ofstream fileo;
    ifstream filei;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t -->> USER SUB-MENU <<--";
    cout << "\n\n\t\t 1. Create Account";
    cout << "\n\t\t 2. Login";
    cout << "\n\t\t 3. Back";
    cout << "\n\t\tEnter Choice: ";
    cin >> user_choice;
    if (user_choice == 1)
    {
        system("cls");
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\n\t\t -->> REGISTRATION USER <<--";
        cout << "\n\n\t\tEnter Your Name: ";
        cin.ignore();
        getline(cin, username);
        cout << "\n\t\tEnter Your Username: ";
        cin >> usn;
        tm = 0;
        valid(usn);
        if (tm >= 3)
        {
            // continue;
        }
        cout << "\n\t\tEnter Your password: ";
        cin >> password;
        fname = usn + ".txt";
        fileo.open(fname.c_str());
        fileo << usn << endl
              << username << endl
              << password << endl;
        cout << "\nYou are successfully registered:)";
        cout << "\n\nPress Any Key To Continue..";
        Sleep(500);
        getch();
        fileo.close();
        user();
    }
    else if (user_choice == 2)
    {
        system("cls");
        string u_name, u_pass;
        cout << "\n\t\t\t\t*****************************************";
        cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
        cout << "\n\t\t\t\t*****************************************";
        // LOGIN USER
        cout << "\n\n\t\t -->> LOGIN USER <<--";
        cout << "\n\n\t\tEnter Your Username: ";
        cin >> u_name;
        cout << "\n\t\tEnter Your Password: ";
        cin >> u_pass;
        fname = u_name + ".txt";
        filei.open(fname.c_str());
        if (!filei.is_open() && filei.fail())
        {
            cout << "\nYou are not registered, please register before logging in.\n";
            filei.close();
            getch();
            user_password();
        }
        getline(filei, usern);
        getline(filei, u_pass);
        if (u_name == usn && u_pass == password)
        {
            cout << "\nYou are successfully logged in:)";
            cout << "\n\nPress Any Key To Continue..";
            Sleep(500);
            getch();
            user();
        }
    }
    else if (user_choice == 3)
    {
        menu();
    }
    else
    {
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        user_password();
    }
}

//************ADMIN************

void covid_management::add_vaccine_stock()
{
A:
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> ADD VACCINE IN CENTER <<--";
    cout << "\n\n\t\t1. " << center1 << "\t\t2. " << center2;
    cout << "\n\n\t\t3. " << center3 << "\t\t4. BACK";
    cout << "\n\t\tEnter Choice: ";
    cin >> center_no;
    switch (center_no)
    {
    case 1:
    {
        file.open("center1.txt", ios::app);
        cout << "\n\t\t -->> For Center 1 <<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> add;
        sum_vaccine_c1 = sum_vaccine_c1 + add;
        file << sum_vaccine_c1;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c1;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\nPress Any Key To Continue..";
        getch();
        goto A;
        break;
    }
    case 2:
    {
        file.open("center2.txt", ios::app);
        cout << "\n\t\t -->> For Center 2 <<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> add;
        sum_vaccine_c2 = sum_vaccine_c2 + add;
        file << sum_vaccine_c2;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c2;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\nPress Any Key To Continue..";
        getch();
        goto A;
        break;
    }
    case 3:
    {
        file.open("center3.txt", ios::app);
        cout << "\n\t\t -->> For Center 3 <<--";
        cout << "\n\tEnter Number Of Vaccines You Want To Add: ";
        cin >> add;
        sum_vaccine_c3 = sum_vaccine_c3 + add;
        file << sum_vaccine_c3;
        file.close();
        cout << "\n\n\tVaccine In Center: " << sum_vaccine_c3;
        cout << "\n\n\t\tSUCCESSFULLY ADDED VACCINES TO THE CENTER";
        cout << "\n\n\nPress Any Key To Continue..";
        getch();
        goto A;
        break;
    }
    case 4:
        break;
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
        cout << "\n\n Press Any Key To Continue: ";
        getch();
        add_vaccine_stock();
        break;
    }
}

void covid_management::search_center()
{
    system("cls");
    ifstream file;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> Various Vaccination Centers In Your City <<--";
    file.open("center1.txt");
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        file >> sum_vaccine_c1;
        cout << "\n\n\t\t-->> " << center1 << " <<--";
        cout << "\n\t\tTotal Vaccine: " << sum_vaccine_c1;
    }
    file.close();
    file.open("center2.txt");
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        file >> sum_vaccine_c2;
        cout << "\n\n\t\t-->> " << center2 << " <<--";
        cout << "\n\t\tTotal Vaccine: " << sum_vaccine_c2;
    }
    file.close();
    file.open("center3.txt");
    if (!file)
    {
        cout << "\nFile Not Found ";
    }
    else
    {
        file >> sum_vaccine_c3;
        cout << "\n\n\t\t-->> " << center3 << " <<--";
        cout << "\n\t\tTotal Vaccine: " << sum_vaccine_c3;
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::display_vaccine_stock()
{
    system("cls");
    ifstream ind;
    fstream file1, file2, file3;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t->> Available Vaccine Stock <<--\n\n";
    int i = 0;
    file1.open("center1.txt"); // Open Center1
    file2.open("center2.txt"); // Open Center2
    file3.open("center3.txt"); // Open Center3
    file1 >> sum_vaccine_c1;
    file2 >> sum_vaccine_c2;
    file3 >> sum_vaccine_c3;
    ind.open("Patient_Data.dat"); // Data take from Patient file
    ind.seekg(0, ios::beg);
    while (ind.read((char *)this, sizeof(covid_management)))
        ;
    {
        i++;
    }
    ind.close();
    int s = TOTAL_VACCINE + sum_vaccine_c1 + sum_vaccine_c2 + sum_vaccine_c3 - i;
    file1.close();
    file2.close();
    file3.close();
    cout << "\n\nAvailable Number Of Vaccines are: " << s;
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::applied_vaccine()
{
    ifstream ind;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> VACCINATED PERSON <<--";
    int i = 0;
    ind.open("Patient_Data.dat");
    ind.seekg(0, ios::beg);
    while (ind.read((char *)this, sizeof(covid_management)))
    {
        i++;
    }
    ind.close();
    cout << "\n\n\t\tVaccinated Person: " << i;
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::show_patient_data()
{
B:
    system("cls");
    int choice;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA <<--";
    cout << "\n\t\t1. Search Data By Aadhar \t\t\t2. Search Data BY  AGE" << endl;
    cout << "\n\t\t3. Search Data By Profession \t\t\t4. Search Data By Gender" << endl;
    cout << "\n\t\t5. EXIT";
    cout << "\n\n\t\tEnter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        search_by_aadhar();
        goto B;
    case 2:
        search_by_age();
        goto B;
    case 3:
        search_by_profession();
        goto B;
    case 4:
        search_by_gender();
        goto B;
    case 5:
        break;
    default:
        cout << "\n\n\t\tInvalid Choice.. Please Try Again..";
        getch();
        goto B;
    }
}

void covid_management::search_by_aadhar()
{
    int count = 0;
    string sadhaar;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY AADHAR <<--";
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> sadhaar;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(covid_management));
    }
    while (!file.eof())
    {
        if (sadhaar.compare(adhaar) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(covid_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::search_by_age()
{
    int count = 0;
    int sage;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY AGE <<--";
    cout << "\n\n\t\tEnter Your Age: ";
    cin >> sage;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(covid_management));
    }
    while (!file.eof())
    {
        if (sage == age)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(covid_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::search_by_profession()
{
    int count = 0;
    string sprofession;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY PROFESSION <<--";
    cout << "\n\n\t\tEnter Your Profession: ";
    cin >> sprofession;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(covid_management));
    }
    while (!file.eof())
    {
        if (sprofession.compare(profession) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(covid_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::search_by_gender()
{
    int count = 0;
    char sgender[10];
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH PATIENT DATA BY GENDER <<--";
    cout << "\n\n\t\tEnter Your Gender: ";
    cin >> sgender;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(covid_management));
    }
    while (!file.eof())
    {
        if (strcmp(sgender, gender) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(covid_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

//***********USER*************

void covid_management::add_patient_data()
{
    fstream file;
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> APPLY FOR VACCINE FIRST DOSE <<--";
    cout << "\n\n\t\tEnter Name: ";
    fflush(stdin);
    cin.getline(name, 100);
C:
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> adhaar;
    if (adhaar.length() != 12)
    {
        cout << "\nInvalid Aadhar Card Number";
        goto C;
    }
    else
    {
        // The first letter should not start with 0 or 1
        if (adhaar[0] == '0' || adhaar[0] == '1')
        {
            cout << "\nInvalid Aadhar Card Number";
            goto C;
        }
        else
        {
            cout << "\nValid Aadhar Card Number";
        }
    }
B:
    cout << "\n\n\t\tEnter Your Mobile Number: ";
    cin >> phone_no;
    if (phone_no.length() != 10)
    {
        cout << "\nInvalid Phone Number";
        goto B;
    }
    else
    {
        // The First letter should not start with 0 or 1
        if (phone_no[0] == '0' || phone_no[0] == '1')
        {
            cout << "\nInvalid Phone Number";
            goto B;
        }
        else
        {
            cout << "\nValid Phone Number";
        }
    }
    cout << "\n\n\t\tEnter Gender (M/F): ";
    cin >> gender;
    cout << "\n\n\t\tEnter Age: ";
    cin >> age;
    cout << "\n\n\t\tEnter Profession: ";
    cin.ignore();
    getline(cin, profession);
    cout << "\n\n\t\tEnter Permanent Address: ";
    cin >> address;
    cout << "\n\n\t\tEnter Vaccine Name [Covishield & Covaxin]: ";
    cin >> vaccine_name;
    cout << "\n\n\t\tEnter Dose: ";
    cin >> dose;
    cout << "\n\n\t\tEnter Center Allotted: ";
    cin >> center;
    file.open("Patient_Data.dat", ios::app | ios::binary);
    file.write((char *)this, sizeof(covid_management));
    cout << "\n\nYOU HAVE SUCCESSFULLY VACCINATED :)";
    cout << "\n\nPress Any Key To Continue..";
    file.close();
    getch();
}

void covid_management::patient_show_data()
{
    int count = 0;
    string vadhaar;
    ifstream file;
    file.open("Patient_Data.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> SEARCH DATA BY AADHAR <<--";
    cout << "\n\n\t\tEnter Aadhar No.: ";
    cin >> vadhaar;
    if (!file)
    {
        cout << "\nFile Not Found!";
    }
    else
    {
        file.read((char *)this, sizeof(covid_management));
    }
    while (!file.eof())
    {
        if (vadhaar.compare(adhaar) == 0)
        {
            count++;
            show_data();
        }
        file.read((char *)this, sizeof(covid_management));
    }
    if (count == 0)
    {
        cout << "\nRecord Not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

void covid_management::show_data()
{
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Aadhar No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << adhaar;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Mobile No.: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << phone_no;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Gender: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << gender;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Age: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << age;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Profession: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << profession;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Vaccine Name: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << vaccine_name;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Dose: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << dose;
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << endl
         << "Center Allotted: ";
    cout.setf(ios::right, ios::adjustfield);
    cout.width(25);
    cout << setfill(' ') << center;
}

void covid_management::update_patient_data()
{
    fstream file;
    system("cls");
    string maadhaar;
    int count = 0;
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\t\t\t\t   *    COVID19 MANAGEMENT SYSTEM    *";
    cout << "\n\t\t\t\t*****************************************";
    cout << "\n\n\t\t-->> APPLY FOR SECOND DOSE <<--";
    cout << "\n\n\t\tEnter Your Aadhar No.: ";
    file.open("Patient_Data.dat", ios::in | ios::out | ios::binary | ios::ate);
    file.seekg(0);
    file.read((char *)this, sizeof(*this));
    cin >> maadhaar;
    while (!file.eof())
    {
        if (maadhaar.compare(adhaar) == 0)
        {
            count++;
            dose++;
            cout << "\nDose: " << dose;
            file.seekp(file.tellp() - sizeof(*this));
            file.write((char *)this, sizeof(*this));
            cout << "\n\nYou are Vaccinated :)";
        }
        file.read((char *)this, sizeof(*this));
    }
    if (count == 0)
    {
        cout << "\nRecord not Found!";
    }
    file.close();
    cout << "\n\nPress Any Key To Continue..";
    getch();
}

int main()
{
    covid_management system;
    system.menu();
}