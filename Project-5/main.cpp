#include <iostream>
#include <string>
#include <cassert>
#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"

using namespace std;

int main() {
    /*
    //Project 5 Spec Provided Test Code
    PlaneFlight shortleg("Howard", "LAX", "LAS", 49.00, 285);
    PlaneFlight longleg("Howard", "LAS", "NYC", 399.00, 2800);
    PlaneFlight sample("Sample", "Sample", "Sample", 0, 1);
    FrequentFlyerAccount account("Howard");
    
    assert(shortleg.getFromCity() == "LAX");
    assert(shortleg.getToCity() == "LAS");
    assert(shortleg.getName() == "Howard");
    assert(to_string(shortleg.getCost()) == "49.000000");
    assert(to_string(shortleg.getMileage()) == "285.000000");

    // account balance starts at zero...
    assert(to_string(account.getBalance()) == "0.000000");
    assert(account.getName() == "Howard");
    assert(account.canEarnFreeFlight(3300.00) == false);

    // flights add to an account balance
    assert(account.addFlightToAccount(shortleg) == true); // returns true because the names match
    assert(account.addFlightToAccount(longleg) == true); // returns true because the names match
    assert(to_string(account.getBalance()) == "3085.000000");

    // free flights reduce an account balance
    if (account.canEarnFreeFlight(285)) {
        assert(account.freeFlight("LAS", "LAX", 285, sample) == true);

        // Howard earned a free flight...
        assert(sample.getName() == "Howard");
        assert(to_string(sample.getCost()) == "0.000000");
        assert(sample.getFromCity() == "LAS" );
        assert(sample.getToCity() == "LAX" );
        assert(to_string(sample.getMileage()) == "285.000000");

        // account has been reduced for this free flight...
        assert(to_string(account.getBalance()) == "2800.000000");
    } else {
        assert(false); // there are enough miles in the account...
    }

    // non-matching names are ignored
    PlaneFlight muffin("Muffin", "LAX", "Doggie Heaven", 500, 500);
    assert(account.addFlightToAccount(muffin) == false);
    assert(to_string(account.getBalance()) == "2800.000000");
    
    //Poject 5 Additional FAQ Test Cases
    PlaneFlight f("Howard", "LAX", "LAS", 65.00, 285);
    
    f.setToCity("LAX");
    f.setFromCity("LAS");
    
    assert(f.getToCity() =="LAS");
    assert(f.getFromCity() == "LAX");
    
    f.setName( "" ); // ignore empty string.... don't do what driver code says...
    assert(f.getName() == "Howard");
    
    //Personal Test Cases
    PlaneFlight test1("Passenger", "Los Angeles", "New York", 1000.00, 500.00);
    assert(to_string(test1.getCost()) == "1000.000000");
    assert(to_string(test1.getMileage()) == "500.000000");
    assert(test1.getName() == "Passenger");
    assert(test1.getFromCity() == "Los Angeles");
    assert(test1.getToCity() == "New York");
    
    test1.setCost(-1000);
    test1.setMileage(0);
    test1.setName("");
    test1.setFromCity("New York");
    test1.setToCity("Los Angeles");
    
    assert(to_string(test1.getCost()) == "-1.000000");
    assert(to_string(test1.getMileage()) == "-1.000000");
    assert(test1.getName() == "Passenger");
    assert(test1.getFromCity() == "Los Angeles");
    assert(test1.getToCity() == "New York");
    
    test1.setFromCity("");
    test1.setToCity("");
    
    assert(test1.getFromCity() == "Los Angeles");
    assert(test1.getToCity() == "New York");
    
    PlaneFlight test2("Passenger", "Los Angeles", "New York", 1000.00, 500.00);
    FrequentFlyerAccount account1("Passenger");
    FrequentFlyerAccount account2("");
    
    assert(to_string(account1.getBalance()) == "0.000000");
    assert(to_string(account2.getBalance()) == "0.000000");
    
    assert(account1.getName() == "Passenger");
    assert(account2.getName() == "");
    
    assert(account1.addFlightToAccount(test2) == true);
    assert(account2.addFlightToAccount(test2) == false);
    
    assert(to_string(account1.getBalance()) == "500.000000");
    
    assert(account1.canEarnFreeFlight(1000.00) == false);
    assert(account1.canEarnFreeFlight(500.00) == true);
    assert(account1.canEarnFreeFlight(250.00) == true);
    assert(account1.canEarnFreeFlight(0.00) == false);
    assert(account1.canEarnFreeFlight(-500.00) == false);
    
    assert(account2.canEarnFreeFlight(500.00) == false);
    assert(account2.canEarnFreeFlight(0.00) == false);
    assert(account2.canEarnFreeFlight(-500.00) == false);
    
    assert(account1.freeFlight("Tokyo", "Tokyo", 1000.00, test2) == false);
    assert(account1.freeFlight("", "", 500.00, test2) == false);
    assert(account1.freeFlight("Paris", "Tokyo", 500.00, test2) == true);
    assert(account2.freeFlight("Paris", "Tokyo", 1000.00, test2) == false);
    
    assert(test2.getFromCity() == "Paris");
    assert(test2.getToCity() == "Tokyo");
    assert(to_string(test2.getMileage()) == "500.000000");
    assert(test2.getName() == "Passenger");
    
    cout << "All tests passed!" << endl;
    */
    
    return 0;
}
