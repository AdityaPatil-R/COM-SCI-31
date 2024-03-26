//Libraries
#include <iostream>
#include <string>

using namespace std;

//Declare variables
string stateName = "";
double purchaseAmount = 0.00;
string month = "";
double day, year = 0.00;
double stateTaxRate, avgLocalTaxRate, levy = 0.00;

int main() {
    //Collect inputs and store them in appropriately named variables
    //Used getline, cin, cin.ignore, and cin.clear() appropriately to correctly gather inputs
    cout << "State Name: ";
    getline(cin, stateName);
    
    cout << "Purchase amount: ";
    cin >> purchaseAmount;
    cin.clear();
    cin.ignore(10000, '\n');
    
    cout << "Provide the month: ";
    getline(cin, month);
    
    cout << "Provide the day: ";
    cin >> day;
    cin.clear();
    
    cout << "Provide the year: ";
    cin >> year;
    cin.clear();
    
    //Check if state is valid (Spelled and capitalized correctly)
    if (!(stateName == "Alabama" ||
          stateName == "Alaska" ||
          stateName == "Arizona" ||
          stateName == "Arkansas" ||
          stateName == "California" ||
          stateName == "Colorado" ||
          stateName == "Connecticut" ||
          stateName == "Delaware" ||
          stateName == "Florida" ||
          stateName == "Georgia" ||
          stateName == "Hawaii" ||
          stateName == "Idaho" ||
          stateName == "Illinois" ||
          stateName == "Indiana" ||
          stateName == "Iowa" ||
          stateName == "Kansas" ||
          stateName == "Kentucky" ||
          stateName == "Louisiana" ||
          stateName == "Maine" ||
          stateName == "Maryland" ||
          stateName == "Massachusetts" ||
          stateName == "Michigan" ||
          stateName == "Minnesota" ||
          stateName == "Mississippi" ||
          stateName == "Missouri" ||
          stateName == "Montana" ||
          stateName == "Nebraska" ||
          stateName == "Nevada" ||
          stateName == "New Hampshire" ||
          stateName == "New Jersey" ||
          stateName == "New Mexico" ||
          stateName == "New York" ||
          stateName == "North Carolina" ||
          stateName == "North Dakota" ||
          stateName == "Ohio" ||
          stateName == "Oklahoma" ||
          stateName == "Oregon" ||
          stateName == "Pennsylvania" ||
          stateName == "Rhode Island" ||
          stateName == "South Carolina" ||
          stateName == "South Dakota" ||
          stateName == "Tennessee" ||
          stateName == "Texas" ||
          stateName == "Utah" ||
          stateName == "Vermont" ||
          stateName == "Virginia" ||
          stateName == "Washington" ||
          stateName == "West Virginia" ||
          stateName == "Wisconsin" ||
          stateName == "Wyoming")) {
        cout << "Invalid state!";
    //Check if purchaseAmount is valid (A positive number greater than 0)
    } else if (purchaseAmount <= 0.0) {
        cout << "Invalid amount!";
    //Check if month is valid (Spelled and capitalized correctly)
    } else if (!(month == "January" ||
                 month == "February" ||
                 month == "March" ||
                 month == "April" ||
                 month == "May" ||
                 month == "June" ||
                 month == "July" ||
                 month == "August" ||
                 month == "September" ||
                 month == "October" ||
                 month == "November" ||
                 month == "December")) {
        cout << "Invalid month!";
    //Check if day is valid (In between 1 and 31)
    } else if (day < 1 || day > 31) {
        cout << "Invalid day!";
    //Check if year is valid (In between 1 and 2025)
    } else if (year < 1 || year > 2025) {
        cout << "Invalid year!";
    } else {
        //This point only reached if there's no issues with any of the inputs
        //Set taxes based on the states while also taking tax free days into account
        //No need to include states with no taxes in if statements, as tax rates are initialized to 0
        if (stateName == "Alabama") {
            if (!(month == "July" && (day >= 15.00 && day <= 17.00))) {
                stateTaxRate = 4.00;
                avgLocalTaxRate = 5.14;
            }
        } else if (stateName == "Alaska") {
            avgLocalTaxRate = 1.43;
        } else if (stateName == "Arizona") {
            stateTaxRate = 5.60;
            avgLocalTaxRate = 2.77;
        } else if (stateName == "Arkansas") {
            if (!(month == "August" && (day == 6.00 || day == 7.00))) {
                stateTaxRate = 6.50;
                avgLocalTaxRate = 2.93;
            }
        } else if (stateName == "California") {
            stateTaxRate = 7.25;
            avgLocalTaxRate = 1.31;
            levy = 1.00;
        } else if (stateName == "Colorado") {
            stateTaxRate = 2.90;
            avgLocalTaxRate = 4.73;
        } else if (stateName == "Connecticut") {
            if (!(month == "August" && (day >= 21.00 && day <= 27.00))) {
                stateTaxRate = 6.35;
            }
        } else if (stateName == "Florida") {
            stateTaxRate = 6.00;
            avgLocalTaxRate = 1.05;
        } else if (stateName == "Georgia") {
            stateTaxRate = 4.00;
            avgLocalTaxRate = 3.29;
        } else if (stateName == "Hawaii") {
            stateTaxRate = 4.00;
            avgLocalTaxRate = 0.41;
        } else if (stateName == "Idaho") {
            stateTaxRate = 6.00;
            avgLocalTaxRate = 0.03;
        } else if (stateName == "Illinois") {
            stateTaxRate = 6.25;
            avgLocalTaxRate = 2.49;
        } else if (stateName == "Indiana") {
            stateTaxRate = 7.00;
        } else if (stateName == "Iowa") {
            if (!(month == "August" && (day == 5.00 || day == 6.00))) {
                stateTaxRate = 6.00;
                avgLocalTaxRate = 0.82;
            }
        } else if (stateName == "Kansas") {
            stateTaxRate = 6.50;
            avgLocalTaxRate = 2.17;
        } else if (stateName == "Kentucky") {
            stateTaxRate = 6.00;
        } else if (stateName == "Louisiana") {
            stateTaxRate = 4.45;
            avgLocalTaxRate = 5.00;
        } else if (stateName == "Maine") {
            stateTaxRate = 5.50;
        } else if (stateName == "Maryland") {
            if (!(month == "August" && (day >= 14.00 && day <= 20.00))) {
                stateTaxRate = 6.00;
            }
        } else if (stateName == "Massachusetts") {
            if (!(month == "August" && (day == 14.00 || day == 15.00))) {
                stateTaxRate = 6.25;
            }
        } else if (stateName == "Michigan") {
            stateTaxRate = 6.00;
        } else if (stateName == "Minnesota") {
            stateTaxRate = 6.88;
            avgLocalTaxRate = 0.55;
        } else if (stateName == "Mississippi") {
            if (!(month == "July" && (day == 29.00 || day == 30.00))) {
                stateTaxRate = 7.00;
                avgLocalTaxRate = 0.07;
            }
        } else if (stateName == "Missouri") {
            if (!(month == "April" && (day >= 19.00 && day <= 25.00))) {
                stateTaxRate = 4.23;
                avgLocalTaxRate = 3.90;
            }
        } else if (stateName == "Nebraska") {
            stateTaxRate = 5.50;
            avgLocalTaxRate = 1.35;
        } else if (stateName == "Nevada") {
            if (!(month == "August" && (day >= 5.00 && day <= 7.00))) {
                stateTaxRate = 6.85;
                avgLocalTaxRate = 1.29;
            }
        } else if (stateName == "New Jersey") {
            stateTaxRate = 6.63;
            avgLocalTaxRate = -0.03;
        } else if (stateName == "New Mexico") {
            stateTaxRate = 5.13;
            avgLocalTaxRate = 2.69;
        } else if (stateName == "New York") {
            stateTaxRate = 4.00;
            avgLocalTaxRate = 4.49;
        } else if (stateName == "North Carolina") {
            stateTaxRate = 4.75;
            avgLocalTaxRate = 2.22;
        } else if (stateName == "North Dakota") {
            stateTaxRate = 5.00;
            avgLocalTaxRate = 1.85;
        } else if (stateName == "Ohio") {
            if (!(month == "August" && (day >= 5.00 && day <= 7.00))) {
                stateTaxRate = 5.75;
                avgLocalTaxRate = 1.42;
            }
        } else if (stateName == "Oklahoma") {
            if (!(month == "August" && (day >= 6.00 && day <= 8.00))) {
                stateTaxRate = 4.50;
                avgLocalTaxRate = 4.42;
            }
        } else if (stateName == "Pennsylvania") {
            stateTaxRate = 6.00;
            avgLocalTaxRate = 0.34;
        } else if (stateName == "Rhode Island") {
            stateTaxRate = 7.00;
        } else if (stateName == "South Carolina") {
            if (!(month == "August" && (day >= 5.00 && day <= 7.00))) {
                stateTaxRate = 6.00;
                avgLocalTaxRate = 1.43;
            }
        } else if (stateName == "South Dakota") {
            stateTaxRate = 4.50;
            avgLocalTaxRate = 1.90;
        } else if (stateName == "Tennessee") {
            if (!(month == "July" && (day >= 29.00 && day <= 31.00))) {
                stateTaxRate = 7.00;
                avgLocalTaxRate = 2.47;
            }
        } else if (stateName == "Texas") {
            if (!(month == "August" && (day >= 5.00 && day <= 7.00))) {
                stateTaxRate = 6.25;
                avgLocalTaxRate = 1.94;
            }
        } else if (stateName == "Utah") {
            stateTaxRate = 5.95;
            avgLocalTaxRate = 0.99;
            levy = 1.25;
        } else if (stateName == "Vermont") {
            stateTaxRate = 6.00;
            avgLocalTaxRate = 0.18;
        } else if (stateName == "Virginia") {
            stateTaxRate = 5.30;
            avgLocalTaxRate = 0.35;
            levy = 1.00;
        } else if (stateName == "Washington") {
            stateTaxRate = 6.50;
            avgLocalTaxRate = 2.67;
        } else if (stateName == "West Virginia") {
            if (!(month == "August" && (day >= 5.00 && day <= 7.00))) {
                stateTaxRate = 6.00;
                avgLocalTaxRate = 0.39;
            }
        } else if (stateName == "Wisconsin") {
            stateTaxRate = 5.00;
            avgLocalTaxRate = 0.44;
        } else if (stateName == "Wyoming") {
            stateTaxRate = 4.00;
            avgLocalTaxRate = 1.36;
        }
        
        //Ensures that every payment outputted has 2 decimal places
        cout.setf(ios::fixed);
        cout.precision(2);
                
        //Calculates and outputs the final payment
        cout << "Please pay a total of $" << purchaseAmount * (1.00 + 0.01 * (stateTaxRate + avgLocalTaxRate + levy));
    }
}
