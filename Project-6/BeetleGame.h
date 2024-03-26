#ifndef BeetleGameH
#define BeetleGameH

#include <string>

#include "Beetle.h"
#include "Die.h"

namespace cs31 {
    class BeetleGame {
        public:
            BeetleGame();
        
            enum class GameOutcome {HUMANWONGAME, COMPUTERWONGAME, GAMENOTOVER};
        
            std::string display(std::string msg = "") const;
        
            // When amount is zero, it is a random roll...
            // Otherwise, an amount value is a cheating value...
            void humanRoll(int amount = 0);
            int getHumanDie() const;
            bool humanPlay();
        
            // When amount is zero, it is a random roll...
            // Otherwise, an amount value is a cheating value...
            void computerRoll(int amount = 0);
            int getComputerDie() const;
            bool computerPlay();
        
            GameOutcome determineGameOutcome() const;
            std::string stringifyGameOutcome() const;
            bool gameIsOver() const;
        
            // For testing purposes
            Beetle getHumanBeetle() const;
            Beetle getComputerBeetle() const;
        private:
            Beetle mHuman, mComputer;
            Die mHumanDie, mComputerDie;
    };
}

#endif
