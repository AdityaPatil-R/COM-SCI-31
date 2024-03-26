#include "Die.h"

#include <random>

namespace cs31 {
    Die::Die(int sides) : mSides(sides), mValue(1) {

    }
    
    void Die::roll() {
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_int_distribution<> dist(1, mSides);
        
        mValue = dist(e2);
    }
    
    int Die::getValue() const {
        return(mValue);
    }

    void Die::setValue(int amount) {
        mValue = amount;
    }
}
