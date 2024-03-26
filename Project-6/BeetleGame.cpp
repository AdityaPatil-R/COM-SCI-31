#include "BeetleGame.h"
#include "BeetleDrawing.h"

#include <iostream>

namespace cs31 {
    BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie() {
    
    }

    // Draw the board by using a BeetleDrawing to draw the two Beetles
    std::string BeetleGame::display(std::string msg) const {
        BeetleDrawing drawing(mHuman, mComputer);
        std::string result = drawing.draw() + "\n" + msg;
        
        return result;
    }


    // TODO when amount is zero, it is a random roll...
    // Otherwise, an amount value is a cheating value...
    void BeetleGame::humanRoll(int amount) {
        // If the amount is zero, roll the Human's die
        // Otherwise, cheat by forcing the amount into the Human's die
        if (amount == 0) {
            mHumanDie.roll();
        } else {
            mHumanDie.setValue(amount);
        }
    }

    // TODO return the value of the Human's die
    int BeetleGame::getHumanDie() const {
        return mHumanDie.getValue();
    }

    // TODO convert the Human's die value to a Beetle's body part
    // Then depending on the body part involved, enforce the game ordering of body parts:
    // - Namely, body before everything else and head before eyes or antenna
    // If allowed, build the desired body part on the Human's beetle
    // If a body part was successfully built, return true
    // Otherwise, return false
    bool BeetleGame::humanPlay() {
        // Convert die value to body part
        Beetle::BodyPart bodyPart = mHuman.convertRollToBodyPart(getHumanDie());
    
        // Based on the body part, checks if conditions to build the part have been met
        if (bodyPart == Beetle::BodyPart::EYE && mHuman.hasBody() && mHuman.hasHead() && !mHuman.hasEye2()) {
            mHuman.buildEye();
            return true;
        } else if (bodyPart == Beetle::BodyPart::ANTENNA && mHuman.hasBody() && mHuman.hasHead() && !mHuman.hasAntenna2()) {
            mHuman.buildAntenna();
            return true;
        } else if (bodyPart == Beetle::BodyPart::LEG && mHuman.hasBody() && !mHuman.hasLeg4()) {
            mHuman.buildLeg();
            return true;
        } else if (bodyPart == Beetle::BodyPart::TAIL && mHuman.hasBody() && !mHuman.hasTail()) {
            mHuman.buildTail();
            return true;
        } else if (bodyPart == Beetle::BodyPart::HEAD && mHuman.hasBody() && !mHuman.hasHead()) {
            mHuman.buildHead();
            return true;
        } else if (bodyPart == Beetle::BodyPart::BODY && !mHuman.hasBody()) {
            mHuman.buildBody();
            return true;
        }
    
        // Returns false if the die value doesn't represent a body part, or other conditions to build it weren't met
        return false;
    }

    // TODO when amount is zero, it is a random roll...
    // Otherwise, an amount value is a cheating value...
    void BeetleGame::computerRoll(int amount) {
        // If the amount is zero, roll the Computer's die
        // Otherwise, cheat by forcing the amount into the Computer's die
        if (amount == 0) {
            mComputerDie.roll();
        } else {
            mComputerDie.setValue(amount);
        }
    }

    // TODO return the value of the Computer's die
    int BeetleGame::getComputerDie() const {
        return mComputerDie.getValue();
    }

    // TODO convert the Computer's die value to a Beetle's body part
    // Then depending on the body part involved, enforce the game ordering of body parts:
    // - Namely, body before everything else and head before eyes or antenna
    // If allowed, build the desired body part on the Computer's beetle
    // If a body part was successfully built, return true
    // Otherwise, return false
    bool BeetleGame::computerPlay() {
        // Convert die value to body part
        Beetle::BodyPart bodyPart = mComputer.convertRollToBodyPart(getComputerDie());
    
        // Based on the body part, checks if conditions to build the part have been met
        if (bodyPart == Beetle::BodyPart::EYE && mComputer.hasBody() && mComputer.hasHead() && !mComputer.hasEye2()) {
            mComputer.buildEye();
            return true;
        } else if (bodyPart == Beetle::BodyPart::ANTENNA && mComputer.hasBody() && mComputer.hasHead() && !mComputer.hasAntenna2()) {
            mComputer.buildAntenna();
            return true;
        } else if (bodyPart == Beetle::BodyPart::LEG && mComputer.hasBody() && !mComputer.hasLeg4()) {
            mComputer.buildLeg();
            return true;
        } else if (bodyPart == Beetle::BodyPart::TAIL && mComputer.hasBody() && !mComputer.hasTail()) {
            mComputer.buildTail();
            return true;
        } else if (bodyPart == Beetle::BodyPart::HEAD && mComputer.hasBody() && !mComputer.hasHead()) {
            mComputer.buildHead();
            return true;
        } else if (bodyPart == Beetle::BodyPart::BODY && !mComputer.hasBody()) {
            mComputer.buildBody();
            return true;
        }
    
        // Returns false if the die value doesn't represent a body part, or other conditions to build it weren't met
        return false;
    }

    // TODO what is the current state of the game
    BeetleGame::GameOutcome BeetleGame::determineGameOutcome() const {
        if (mHuman.isComplete()) {
            // Human always moves first, so it will win in a tie
            return GameOutcome::HUMANWONGAME;
        } else if (mComputer.isComplete()) {
            // Computer only wins if its beetle is complete and the human's isn't
            return GameOutcome::COMPUTERWONGAME;
        }
    
        // If neither beetle is complete, the game isn't yet over
        return GameOutcome::GAMENOTOVER;
    }

    std::string BeetleGame::stringifyGameOutcome() const {
        std::string result = "";
        
        switch(determineGameOutcome()) {
            case GameOutcome::COMPUTERWONGAME:
                result = "Computer Won!";
                break;
            case GameOutcome::HUMANWONGAME:
                result = "Human Won!";
                break;
            case GameOutcome::GAMENOTOVER:
                result = "Game Not Over!";
                break;
        }
        
        return result;
    }

    // TODO has the game ended with a winner?
    bool BeetleGame::gameIsOver() const {
        // If the game isn't not over, then it's over
        return determineGameOutcome() != GameOutcome::GAMENOTOVER;
    }

    Beetle BeetleGame::getHumanBeetle() const {
        return mHuman;
    }

    Beetle BeetleGame::getComputerBeetle() const {
        return mComputer;
    }
}
