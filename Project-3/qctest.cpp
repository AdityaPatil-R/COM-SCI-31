//Header files
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//Helper functions
int findInstance(string s, string str, int index);
int totalInstances(string s, string str);
bool isValidBatch(string batch);
int passOrDefect(char c, string results);

//Main 5 functions
bool isValidQC(string results);
int passQC(string results);
int defectQC(string results);
int totalQC(string results);
int batches(string results);

int main() {
    return 0;
}

//****************
//Helper Functions
//****************

//Finds the first instance of s in str after the given index in str
int findInstance(string s, string str, int index) {
    for (int i = index; i < str.size() - s.size(); i++) {
        if (s == str.substr(i, s.size())) {
            return i;
        }
    }
    
    return -1;
}

//Finds the total number of times s occurs in str
int totalInstances(string s, string str) {
    int freq = 0;
    
    for (int i = 0; i < str.size() - s.size(); i++) {
        if (s == str.substr(i, s.size())) {
            freq++;
        }
    }
    
    return freq;
}

//Checks that a batch satisfies specified necessary conditions
bool isValidBatch(string batch) {
    int pLoc = findInstance("p", batch, 0);
    int dLoc = findInstance("d", batch, 0);
    
    //Checks that a batch has p and q
    //Checks that only one of each letter is in the batch
    //Checks that the first letter is capital Q
    if (pLoc == -1 || dLoc == -1 ||
        totalInstances("Q", batch) != 1 ||
        totalInstances("p", batch) != 1 ||
        totalInstances("d", batch) != 1 ||
        batch[0] != 'Q') {
        return false;
    }
    
    string Q = batch.substr(0, 1);
    string p = batch.substr(pLoc, 1);
    string d = batch.substr(dLoc, 1);
    string QNum, pNum, dNum;
    
    if (pLoc < dLoc) {
        QNum = batch.substr(1, pLoc - 1);
        pNum = batch.substr(pLoc + 1, dLoc - pLoc - 1);
        dNum = batch.substr(dLoc + 1);
    } else if (dLoc < pLoc) {
        QNum = batch.substr(1, dLoc - 1);
        dNum = batch.substr(dLoc + 1, pLoc - dLoc - 1);
        pNum = batch.substr(pLoc + 1);
    }
    
    //Checks that there are numbers after the letters
    //Checks that each letter is the correct one
    //Checks that the sum of passes and defects is the total number of cases
    //Checks that the total number of tests is greater than 0
    //Checks that the numbers don't have any leading zeroes
    if (QNum == "" || pNum == "" || dNum == "" ||
        Q != "Q" || p != "p" || d != "d" ||
        (stoi(QNum) != stoi(pNum) + stoi(dNum)) ||
        stoi(QNum) <= 0 ||
        QNum != to_string(stoi(QNum)) ||
        pNum != to_string(stoi(pNum)) ||
        dNum != to_string(stoi(dNum))) {
        return false;
    }
    
    return true;
}

//Counts the numbers after the occurences of the character c in results
int passOrDefect(char c, string results) {
    int sum = 0;
    //Loops until it finds c
    for (int i = 0; i < results.size(); i++) {
        if (results[i] == c) {
            string num = "";
            int index;
            
            //Figures out what the next letter is
            int first = findInstance(c == 'p' ? "d" : "p", results, i + 1);
            int Q = findInstance("Q", results, i + 1);
            
            if (first == -1) {
                if (Q == -1) {
                    index = results.size();
                } else {
                    index = Q;
                }
            } else {
                index = first;
            }
            
            //Adds the number of passed tests in a batch to a running sum
            for (int j = i + 1; j < index; j++) {
                num += results[j];
            }
            
            sum += stoi(num);
        }
    }
    
    return sum;
}

//**************
//Main Functions
//**************

//Iterates through the QC test, and splits it into its batches
//Each batch is then individually tested, and if even one fails, the QC test is invalid
bool isValidQC(string results) {
    //Checks that it meets basic conditions
    if (results.size() < 6 || results[0] != 'Q') {
        return false;
    }
    
    int index = 0;
    
    //Loops through results to split it up into batches to test individually
    while (index < results.size()) {
        if (results[index] == 'Q') {
            int end = findInstance("Q", results, index + 1);
            
            if (end == -1) {
                end = results.size();
            }
            
            //Creates and sends a batch for testing
            string batch = results.substr(index, end - index);
            
            if (isValidBatch(batch) == false) {
                return false;
            }
            
            index = end;
        } else {
            index++;
        }
    }
        
    return true;
}

//If the QC is valid, this function calls a helper function to find how many passes there are
int passQC(string results) {
    if (isValidQC(results)) {
        //Uses a helper function to find the number of passes
        return passOrDefect('p', results);
    }
    
    return -1;
}

//If the QC is valid, this function calls a helper function to find how many defects there are
int defectQC(string results) {
    if (isValidQC(results)) {
        //Uses a helper function to find the number of defects
        return passOrDefect('d', results);
    }
    
    return -1;
}

//If the QC is valid, this functionn calls the previous two functions to return the total quality tests
int totalQC(string results) {
    if (isValidQC(results)) {
        //The total test is the sum of passed and defective ones, so the other functions can be used
        return passQC(results) + defectQC(results);
    }
    
    return -1;
}

//If the QC is valid, this function calls a helper function to return how many batches it contains
int batches(string results) {
    if (isValidQC(results)) {
        //Used a helper function made earlier to test validity of batches
        return totalInstances("Q", results);
    }
    
    return -1;
}
