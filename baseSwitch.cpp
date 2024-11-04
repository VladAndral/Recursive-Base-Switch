#include <iostream>

using namespace std;

string switchBase(int numBase10, int baseToSwitchTo);
void recursive_switchBase(int numBase10, int baseToSwitchTo, string& currentString);
string digitArray = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_-=+"; // Easier way to convert up to base 50. We only need to create it once

int main() {

    cout << "Enter base 10 number" << endl;
    int base10Number;
    cin >> base10Number;
    cout << "Enter base to switch to [2-" << digitArray.size() << "]" << endl;
    int baseToSwitchTo;
    cin >> baseToSwitchTo;

    string newNum = switchBase(base10Number, baseToSwitchTo);

    cout << "Here is the number in base " << baseToSwitchTo << ": \n" << newNum << endl;

    // string newNum = switchBase(19, 16);
    // cout << newNum << endl;

}

string switchBase(int numBase10, int baseToSwitchTo) {
    string newNumber;
    recursive_switchBase(numBase10, baseToSwitchTo, newNumber);
    return newNumber;
}

void recursive_switchBase(int numBase10, int baseToSwitchTo, string& currentString) {

    if (numBase10 < baseToSwitchTo) {
        currentString += digitArray[numBase10];
    } else {
        int toAddToSting = numBase10 % baseToSwitchTo;
        recursive_switchBase(numBase10/baseToSwitchTo, baseToSwitchTo, currentString); // Order matters! The first digit comes from base case! Also, integer division
        currentString += digitArray[toAddToSting];
    }
}