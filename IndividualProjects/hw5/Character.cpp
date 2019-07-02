//
// Created by Nick J Grove on 4/4/18.
//

#include "Character.h"

/** Function Name: HealthScoreUpdate
 * Function Description: This function is used as kind of a middle man between the printing helper function and adding values to the Character's
 * HealthStatus
 * Function Use: Used in the printing helper function */
void Character::HealthScoreUpdateC(FoodValue f, ClothesValue c, EntertainmentValue e){
    // Get the Characters HealthStatus
    PurchaseComponentBase &PCB = getPCB();
    // Call the function to physically add the values
    PCB.HealthScoreUpdatePCB(f,c,e);
};
