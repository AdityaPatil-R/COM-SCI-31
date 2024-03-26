#include "Beetle.h"

namespace cs31 {
    Beetle::Beetle() {
        mBody = false;
        mTail = false;
        mLeg1 = false;
        mLeg2 = false;
        mLeg3 = false;
        mLeg4 = false;
        mHead = false;
        mEye1 = false;
        mEye2 = false;
        mAntenna1 = false;
        mAntenna2 = false;
    }

    // Convert a tossed die value into a BodyPart
    Beetle::BodyPart Beetle::convertRollToBodyPart(int die) const {
        // If not matching, then return NOTVALID
        BodyPart part = BodyPart::NOTVALID;
        
        if (die == 6)
            part = BodyPart::BODY;
        if (die == 5)
            part = BodyPart::HEAD;
        if (die == 4)
            part = BodyPart::TAIL;
        if (die == 3)
            part = BodyPart::LEG;
        if (die == 2)
            part = BodyPart::ANTENNA;
        if (die == 1)
            part = BodyPart::EYE;
        
        return part;
    }

    // Build the Beetle's body
    void Beetle::buildBody() {
        mBody = true;
    }

    // Has the Beetle's body been built?
    bool Beetle::hasBody() const {
        return mBody;
    }

    // Build the Beetle's tail but only if the body has already been built
    void Beetle::buildTail() {
        mTail = true;
    }

    // Has the Beetle's tail been built?
    bool Beetle::hasTail() const {
        return mTail;
    }

    // Build the Beetle's leg but only if the body has already been built
    void Beetle::buildLeg() {
        // Multiple if statements to check which legs are already built to know which one to build next
        if (hasLeg1()) {
            if (hasLeg2()) {
                if (hasLeg3()) {
                    mLeg4 = true;
                } else {
                    mLeg3 = true;
                }
            } else {
                mLeg2 = true;
            }
        } else {
            mLeg1 = true;
        }
    }

    // Has the Beetle's leg been built?
    bool Beetle::hasLeg1() const {
        return mLeg1;
    }

    bool Beetle::hasLeg2() const {
        return mLeg2;
    }

    bool Beetle::hasLeg3() const {
        return mLeg3;
    }

    bool Beetle::hasLeg4() const {
        return mLeg4;
    }

    // Build the Beetle's head but only if the body has already been built
    void Beetle::buildHead() {
        mHead = true;
    }

    // Has the Beetle's head been built?
    bool Beetle::hasHead() const {
        return mHead;
    }

    // Build the Beetle's eye but only if the head has already been built
    void Beetle::buildEye() {
        // Multiple if statements to check which eyes are already built to know which one to build next
        if (hasEye1()) {
            mEye2 = true;
        } else {
            mEye1 = true;
        }
    }

    // Has the Beetle's eye been built?
    bool Beetle::hasEye1() const {
        return mEye1;
    }

    bool Beetle::hasEye2() const    {
        return mEye2;
    }

    // Build the Beetle's antenna but only if the head has already been built
    void Beetle::buildAntenna() {
        // Multiple if statements to check which antennae are already built to know which one to build next
        if (hasAntenna1()) {
            mAntenna2 = true;
        } else {
            mAntenna1 = true;
        }
    }

    // Has the Beetle's antenna been built?
    bool Beetle::hasAntenna1() const {
        return mAntenna1;
    }

    bool Beetle::hasAntenna2() const {
        return mAntenna2;
    }

    // Is this Beetle completely built out?
    bool Beetle::isComplete() const {
        // Beetle is only complete if every part of it was already built
        return hasBody() && hasHead() && hasEye1() && hasEye2() &&
        hasAntenna1() && hasAntenna2() && hasLeg1() && hasLeg2() && hasLeg3() && hasLeg4() &&
        hasTail();
    }
}
