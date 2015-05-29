#include<iostream>
using namespace std;
int readNumber()
{
    cout << "please input a number:"<< endl;
    int a = 0;
    cin >> a;
    return a;
}
void writeAnswer(int a)
{
    cout << "the answer is " << a << endl;
}
