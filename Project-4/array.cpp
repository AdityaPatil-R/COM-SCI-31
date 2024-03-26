//Header file libraries
#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

//Required functions
int locateMaximum(const string array[], int n);
int countFloatingPointValues(const string array[], int n);
bool hasNoCapitals(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholder);

int main() {
    /*
    //Provided test cases
    string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon" };
    assert(hasNoCapitals(folks, 5) == true);

    string data[5] = { "mamaBbcca", "mamaBbcca", "12,", "98.76", "tyrion" };
    assert(locateMaximum(data, 5) == 4);
    assert(countFloatingPointValues(data, 5) == 1);
    assert(hasNoCapitals(data, 5) == false);
    assert(hasNoCapitals(folks, 8) == true);
    assert(shiftLeft(data, 5, 2, "foo") == 2);

    string data2[5] = { "mamaBbcca", "mamaBbcca", "12,", "98.76", "tyrion" };
    assert(shiftLeft(data2, 5, 10, "bar") == 5);

    string data3[5] = { "mamaBbcca", "mamaBbcca", "12,", "98.76", "tyrion" };
    assert(shiftLeft(data, -5, 10, "foobar") == -1);

    string a[6] = { "123", "456", "789", "gamma", "beta", "delta" };
    assert( hasNoCapitals(a, 6) == true );
    assert( countFloatingPointValues(a, 3) == 3 );

    string name[5]={"Andrew","Bethany","Christie","Danny","Edward"};
    assert( shiftLeft(name, 3, 2, "foo") == 2 );

    string str[5] = {"7", "12", "5", "32", "1"};
    assert(locateMaximum(str, 4) == 0);

    string numbers[4] = {"0000076", "00.00.76", "7600+00", "76.0000"};
    assert(countFloatingPointValues(numbers, 4) == 2);
    
    //My test cases
    string test1[5] = {"1312", "362", "64", "11111", "9"};
    assert(locateMaximum(test1, 5) == 4);

    string test2[4] = {"hello", "5913", "World", "stupid5"};
    assert(locateMaximum(test2, 3) == 0);

    string test3[5] = {"1312", "362", "64", "11111", "9"};
    assert(countFloatingPointValues(test3, 5) == 5);

    string test4[5] = {"13.5", "2+6", "79-32", "1,2,3", "03.4.1"};
    assert(countFloatingPointValues(test4, 5) == 1);

    string test5[5] = {"this1", "class2", "is3", "so4", "fun5"};
    assert(hasNoCapitals(test5, 5) == true);

    string test6[5] = {"This", "Class", "Is", "So", "Fun"};
    assert(hasNoCapitals(test6, 5) == false);

    string test7[5] = {"fio23j", "FOI&23l", "jfoiWW7", "+fjo&#-", "*@fja_?"};
    assert(shiftLeft(test7, 5, 10, "testing") == 5);
    cout << test7[0] + " " + test7[1] + " " + test7[2] + " " + test7[3] + " " + test7[4] << endl;
    assert("testing testing testing testing testing" == test7[0] + " " + test7[1] + " " + test7[2] + " " + test7[3] + " " + test7[4]);

    string test8[5] = {"I", "really", "hope", "this", "works"};
    assert(shiftLeft(test8, 4, 2, "testing") == 2);
    cout << test8[0] + " " + test8[1] + " " + test8[2] + " " + test8[3] + " " + test8[4] << endl;
    assert("hope this testing testing works" == test8[0] + " " + test8[1] + " " + test8[2] + " " + test8[3] + " " + test8[4]);

    cerr << "All tests succeeded" << endl;
    */
}

//Locates the index of the largest item in the first n strings of array
int locateMaximum(const string array[], int n) {
    if (n <= 0) {
        return -1;
    }

    int maxLengthIndex = 0;

    //Loops backward to return smallest index in the case of repetitions of the largest object
    for (int i = n - 1; i >= 0; i--) {
        if (array[i] > array[maxLengthIndex]) {
            maxLengthIndex = i;
        }
    }

    return maxLengthIndex;
}

//Counts the number of floating point values in the first n strings of array
int countFloatingPointValues(const string array[], int n) {
    if (n <= 0) {
        return -1;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isFloatingPoint = true;
        int numDecimalPoints = 0;

        for (int j = 0; j < array[i].size(); j++) {
            if ((array[i][j] == '.')) {
                numDecimalPoints++;
            //Check that the string doesn't contain a plus sign, minus sign, comma, or is a letter
            } else if (array[i][j] == '+' || array[i][j] == '-' || array[i][j] == ',' || ! isdigit(array[i][j])) {
                isFloatingPoint = false;
            }
        }

        //Verify that there's no more than one decimal point
        if (numDecimalPoints > 1) {
            isFloatingPoint = false;
        }
        
        if (isFloatingPoint) {
            count++;
        }
    }

    return count;
}

//Checks if there's any capital letters in the first n strings of array
bool hasNoCapitals(const string array[], int n) {
    if (n <= 0) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < array[i].size(); j++) {
            //Check every character in every string
            if (isupper(array[i][j])) {
                return false;
            }
        }
    }

    return true;
}

//Shifts the first n strings in array left by amount, replacing an amount number of the right-most values until index n with placeholder
int shiftLeft(string array[], int n, int amount, string placeholder) {
    if (n <= 0 || amount < 0) {
        return -1;
    }

    //If the number of strings being shifted are less than how far they get shifted, the first n strings become placeholder
    if (amount >= n) {
        for (int i = 0; i < n; i++) {
            array[i] = placeholder;
        }
        
        return n;
    }

    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < n - 1; j++) {
            //Shifting the string to the left
            array[j] = array[j + 1];
        }
        
        //Filling in the n-ith string with the placeholder, goes until i reaches amount, so amount number of strings left of n are replaced
        array[n - i - 1] = placeholder;
    }

    return amount;
}
