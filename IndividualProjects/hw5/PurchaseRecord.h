//
// Created by njgrove on 4/18/18.
//

#ifndef HOMEWORK5_PURCHASERECORD_H
#define HOMEWORK5_PURCHASERECORD_H

#include "typedef.h"

/** Class Name: PurchaseRecord
 * Class Description: This class basically acts as ledger for all purchases made by the Character
 * Class Use: Biggest role is being used as a for loop in the printing helper function*/
class PurchaseRecord {

public:
    // Purchase Vector Typedef
    typedef std::vector<PurchaseRecord*>      PurchaseRecordVectorType;

    // Default Constructor
    PurchaseRecord():m_barcode{m_barcode}{}

    // PurchaseRecord Constructor
    PurchaseRecord(const StoreType s, const PurchaseBarcode bc):m_store{s},m_barcode{bc}
    {
    }

    // Class Getters
    StoreType getStore() {return m_store;}
    PurchaseBarcode getBarcode() {return m_barcode;}

private:
    // Private String Variables
    const StoreType m_store;

    // Private Int Variables
    const PurchaseBarcode m_barcode;

};


#endif //HOMEWORK5_PURCHASERECORD_H
