//
// Created by njgrove on 4/18/18.
//

#ifndef HOMEWORK5_HEALTHSTATUS_H
#define HOMEWORK5_HEALTHSTATUS_H

#include "typedef.h"

/** Class Name: HealthStatus
 * Class Description: This class stores a food value, a clothing value, and an entertainment value. All of these combine to be a HealthStatus.
 * HealthStatus changes depending on the value, with an Item its the straight value, with Store its a multiplier, and Character its the multiplication
 * of the two.
 * Class Use: Primarily used through the PurchaseComponentBase just to store values */
class HealthStatus {

public:

    // HealthStatus Default Constructor
    HealthStatus(){}

    // HealthStatus Constructor
    HealthStatus(FoodValue fv, ClothesValue cv, EntertainmentValue ev):m_food{fv},m_clothes{cv},m_entertainment{ev}
    {
    }

    // Declaration of toString
    std::string toString();

    // Class Getters
    FoodValue getFoodVal() const {return m_food;}
    ClothesValue getClothesVal() const {return m_clothes;}
    EntertainmentValue getEntVal() const {return m_entertainment;}

    // Declaration of AddToHealthScore
    void AddToHealthScore(FoodValue f, ClothesValue c, EntertainmentValue e);

private:
    // Private Double Variables
    FoodValue m_food;
    ClothesValue m_clothes;
    EntertainmentValue m_entertainment;


};


#endif //HOMEWORK5_HEALTHSTATUS_H
