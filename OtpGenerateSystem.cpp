// OtpGenerateSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define ll long long int
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<Windows.h>
#include<time.h>
using namespace std;

vector<pair<ll, string>>s;
bool detail(ll h) {
    if (s.size() == 0)return false;
    else {
        for (int i = 0; i < s.size(); i++) {
            ll a = s[i].first;
            if (a == h)return true;
        }
    }
    return false;
}

int generateOTP(long long int mn) {
    string s = ""; int t = 0;
    srand((unsigned)time(NULL));
    for (int i = 0; i <= 3; i++) {
        int r = 1 + (rand() % 9);
        s += (char)(r)+48;
    }
    t = stoi(s);
    return t;
}
bool verification() {

    int n;
    cout << "\nplease verify payment \n";
    cin >> n;
    return n == 1 ? true : false;
}
bool payment(string s, ll m) {
    bool flag = false;
    cout << "make payment for new registration \n";
    cout << "chose payment mathod:\n\n ";
    int k;
    cout << "press 1 for online payment \n press 2 for QR scanner\n";
    cin >> k;
    if (k == 1)cout << "Branch Bhim UPI no is XXXXXXXXXX \n";
    else if (k == 2)cout << "QRQRQRQR\nQRQRQRQR\nQRQRQRQR\nQRQRQRQR\n";
    else {
        cout << "invalid input\n"; return false;
    }int n;
    if (k == 1 || k == 2) {
        cout << "\n please verify payment by click 1 \n";
        cin >> n;
    }
    n == 1 ? flag = true : flag = false;
    return flag;
}
int main() {
    bool flag = false;
    int e = 0;
    string name = "";
    long long int mn;
    int u;
    cout << "--------------Welcome to the EW skills----------------- " << endl;
    cout << "|                                                     |" << endl;
    cout << "|     press 1: for already have a course              |" << endl;
    cout << "|     press 2: for new registation                    |" << endl;
    cout << "|                                                     |" << endl;
    cout << "-------------------------------------------------------" << endl;
    cin >> u;
   
    if (u == 1) {
        u = 0;
        goto Label1;
    Label1: {
        cout << "\n please enter your phone number to login \n";
        cin >> mn;
        cout<<"Loading";
        cout.flush();
         for(int i=0;i<2;i++){
             for(int i=0;i<3;i++){
                cout<<".";
                cout.flush();
                 Sleep(1000);
           }
             cout<<"\b\b\b     \b\b\b";
         } cout.flush();
          cout<<endl;
          system("cls");
          
        if (detail(mn))
            cout << generateOTP(mn) << " is your One Time Password (OTP) for login/signup at EW skills.\n This OTP will only be valid for 10 minutes -EW skills ";
        else {
            cout << "\n you have not registered in this EW skills \n if you want login press 'y' \n";
            char n = '1'; cin >> n;
            if (n == 'y')
                goto Label2;
        }
        }
    }
    if (u == 2) {
        u = 0;
        goto Label2;
    Label2: {
        string q;

        cout << " Please enter your name \n";
        cin >> q;
        ll m;
        cout << "enter mobile no to registration \n";
        cin >> m;
        if (detail(m))
            cout << "You are already registered!! \n <<" << generateOTP(m) << " >> is your One Time Password (OTP) for login/signup at EW skills.\n This OTP will only be valid for 10 minutes -EW skills ";

        else if (payment(q, m)) {
            s.push_back({ m,q });
            cout << "Congratulations, you are now an integral part of our organization.\n";
            cout << "\n << " << generateOTP(m) << " >> is your One Time Password (OTP) for login/signup at EW skills.\n This OTP will only be valid for 10 minutes -EW skills ";
        }

        else {
            system("cls");
            cout << "Registration failed!!!! \n try again.";//system("cls");
        }
        }
    cout << "\n\nif you want login enter 1\n else if required new registration enter 2\n otherwise enter 0\n";
    cin >> e;
    if (e == 1)goto Label1;
    else if (e == 2)goto Label2;
    else cout << "Invalid input \n";
    }
}
