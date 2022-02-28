/**
 * @file Declerations.h
 * @author malpi
 *
 *
 */

#ifndef PROJECT1_DECLERATIONS_H
#define PROJECT1_DECLERATIONS_H

//#include "Item.h"
//#include "Level.h"

class Level;

class Declerations  {
private:





public:

    /// Default constructor (disabled)
    Declerations() = default;

    /// Copy constructor (disabled)
    Declerations(const Declerations&) = delete;

    /// Assignment operator
    void operator=(const Declerations&) = delete;



//;


    void XmlType(wxXmlNode* node);

    Declerations(Level* p_level);
};

#endif //PROJECT1_DECLERATIONS_H
