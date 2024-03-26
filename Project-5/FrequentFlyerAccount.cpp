#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"

//Constructor
FrequentFlyerAccount::FrequentFlyerAccount(string name) {
    mName = name;
    mBalance = 0;
}

//Accessor functions
double FrequentFlyerAccount::getBalance() {
    return mBalance;
}

string FrequentFlyerAccount::getName() {
    return mName;
}

//Adds flight to account
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
    if (mName == flight.getName() && flight.getCost() > 0 && flight.getToCity() != flight.getFromCity()
        && flight.getToCity().size() != 0 && flight.getFromCity().size() != 0) {
        mBalance += flight.getMileage();
        
        return true;
    }

    return false;
}

//Checks if a flyer can earn them a free flight of a certain mileage
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
    return mBalance >= mileage && mileage > 0;
}

//Redeems a free flight for a flyer if they are eligible
bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight) {
    if (canEarnFreeFlight(mileage) && from != to && from.size() > 0 && to.size() > 0) {
        //Decreases balance by the mileage to account for the new flight
        mBalance -= mileage;
        
        //Updates flight details with the free flight the flyer is eligible for
        flight.setFromCity(from);
        flight.setToCity(to);
        flight.setMileage(mileage);
        flight.setName(mName);
        
        return true;
    }

    return false;
}
