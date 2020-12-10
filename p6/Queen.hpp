#ifndef Queen_hpp
#define Queen_hpp

#include <stdio.h>
#include "Room.hpp"

class Queen: public Room {
    
    public:
    
    Queen (string numberIn, string nameIn, string emailIn, string addon1In, string addon2In);
    
    void setAddOnPrices();
    void setTotalPrice ();
    float getTotalPrice();
};

#endif /* Queen_hpp */
