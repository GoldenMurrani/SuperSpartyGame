/**
 * @file Declerations.h
 * @author malpi
 *
 *
 */

#ifndef PROJECT1_DECLERATIONS_H
#define PROJECT1_DECLERATIONS_H

#include "Item.h"



class Declerations {
private:







public:


    /// Default constructor (disabled)
    Declerations() = default;

    /// Copy constructor (disabled)
    Declerations(const Declerations&) = delete;

    /// Assignment operator
    void operator=(const Declerations&) = delete;

    void XmlType(wxXmlNode* node);


};

#endif //PROJECT1_DECLERATIONS_H
