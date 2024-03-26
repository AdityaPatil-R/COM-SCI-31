#ifndef BeetleDrawingH
#define BeetleDrawingH

#include <string>

#include "Beetle.h"

namespace cs31 {
    class BeetleDrawing {
        public:
            BeetleDrawing(Beetle playerBeetle, Beetle computerBeetle);
            // Draw one line at a time
            std::string draw(int lineNumber);
            // Draw all six lines
            std::string draw();
        private:
            Beetle mPlayer, mComputer;
    };
}

#endif
