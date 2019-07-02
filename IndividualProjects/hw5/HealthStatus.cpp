//
// Created by njgrove on 4/18/18.
//

#include "HealthStatus.h"
#include <sstream>
#include <iostream>

/** Function Name: AddToHealthScore
 * Function Description: Adds the new values onto the Character's HealthStatus
 * Function Use: Used in the PurchaseComponentBase's AddToHealthScore */
void HealthStatus::AddToHealthScore(FoodValue f, ClothesValue c, EntertainmentValue e){
    m_food += f;
    m_clothes += c;
    m_entertainment += e;
}

/** Function Name: ToString
 * Function Description: Converts HealthStatus into a string
 * Function Use: Used in the printing helper function */
std::string HealthStatus::toString() {
    // Stringstream Initialization
    ToStringVariable ss;

    // Set StringStream
    ss << "Food Value: " << m_food << std::endl << "Clothing Value: " << m_clothes << std::endl << "Entertainment Value: " << m_entertainment;

    // Return as a string
    return ss.str();
}
