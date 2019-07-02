//
// Created by njgrove on 4/18/18.
//

#include "PurchaseComponentBase.h"

/** Function Name: AddToHealthScore
 * Function Description: Adds the new values onto the Character's HealthStatus
 * Function Use: Used in the HealthScoreUpdate */
void PurchaseComponentBase::HealthScoreUpdatePCB(FoodValue f, ClothesValue c, EntertainmentValue e){
    HealthStatus HS = getHealthStatus();
    HS.AddToHealthScore(f,c,e);
}
