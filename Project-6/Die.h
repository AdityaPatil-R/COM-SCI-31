#ifndef Die_h
#define Die_h

namespace cs31 {
    class Die {
        public:
            Die(int sides = 6); // By default, a six sided die
        
            void roll();
            int getValue() const;
            void setValue(int amount);
        private:
            int mSides;
            int mValue;
    };
}

#endif
