#include "PlaneFlight.h"

//Constructor
PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
    mName = passengerName;
    mFromCity = fromCity;
    mToCity = toCity;
    mCost = cost;
    mMileage = mileage;
}

double PlaneFlight::getCost() {
    return mCost;
}

void PlaneFlight::setCost(double cost) {
    //Cost cannot be negative
    if (cost >= 0) {
        mCost = cost;
    } else {
        mCost = -1;
    }
}

double PlaneFlight::getMileage() {
    return mMileage;
}

void PlaneFlight::setMileage(double mileage) {
    //Mileage must be greater than zero
    if (mileage > 0) {
        mMileage = mileage;
    } else {
        mMileage = -1;
    }
}

string PlaneFlight::getName() {
    return mName;
}

void PlaneFlight::setName(string name) {
    //Empty name value not allowed
    if (name.size() > 0) {
        mName = name;
    }
}

string PlaneFlight::getFromCity() {
    return mFromCity;
}

void PlaneFlight::setFromCity(string from) {
    //Starting city can't be empty or the same as ending city
    if (from.size() > 0 && from != mToCity) {
        mFromCity = from;
    }
}

string PlaneFlight::getToCity() {
    return mToCity;
}

void PlaneFlight::setToCity(string to) {
    //Ending city can't be empty or the same as starting city
    if (to.size() > 0 && to != mFromCity) {
        mToCity = to;
    }
}
