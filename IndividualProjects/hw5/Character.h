//
// Created by Nick J Grove on 4/4/18.
//

#ifndef HOMEWORK5_CHARACTER_H
#define HOMEWORK5_CHARACTER_H

#include "typedef.h"
#include "PurchaseComponentBase.h"
#include "PurchaseRecord.h"
#include "HealthStatus.h"

/** Class Name: Character
 * Class Description: This class stores all the info of the Character which includes their name, home, list of purchases, and their health status.
 * All classes are not very much related to the Character, but the character basically runs the system of this program, because characters buy items,
 * go to stores, and have a quality of health.
 * Class Use: Class is used as the driving variable for the printing helper function */
class Character : public PurchaseRecord, public PurchaseComponentBase{

public:
    // Character Map Typedef
    typedef std::map<CharacterNameType,Character*>      CharacterMapType;

    // Character Constructor
    Character(CharacterNameType c, HomeType h, HealthStatus b, PurchaseRecordVectorType pr):m_character{c},m_home{h},m_purchase_list{pr},m_PCB(PurchaseComponentBase(c,b))
    {
    }

    // Character Destructor
    ~Character(){}

    // Class Getters
    CharacterNameType getName() {return m_character;}
    PurchaseRecordVectorType getPurchase_list() {return m_purchase_list;}
    PurchaseComponentBase & getPCB() {return m_PCB;}

    // Declaration of HealthScoreUpdate
    void HealthScoreUpdateC(FoodValue f, ClothesValue c, EntertainmentValue e);

private:
    // Private Map Variables
    CharacterNameType m_character;

    // Private String Variables
    HomeType m_home;

    // Private Vector Variables
    PurchaseRecordVectorType m_purchase_list;

    // Private PurchaseComponentBase Variables
    PurchaseComponentBase m_PCB;


};

#endif //HOMEWORK5_CHARACTER_H
