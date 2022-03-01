/**
 * @file Declerations.h
 * @author malpi
 *
 * Base class for grabbing declarations
 */

#ifndef PROJECT1_DECLARATIONS_H
#define PROJECT1_DECLARATIONS_H


#include "Item.h"

/**
* Base class for grabbing declarations
*/
class Declarations {
private:

    std::vector<wxXmlNode*> mDeclarationVec;

public:

    Declarations(Level* level);

    /// Default constructor (disabled)
    Declarations() = default;

    /// Copy constructor (disabled)
    Declarations(const Declarations&) = delete;

    /// Assignment operator
    void operator=(const Declarations&) = delete;

    void XmlType(wxXmlNode* node);

    std::vector<std::wstring> GetNodeChildren(wxXmlNode* node);

    void SetVec(wxXmlNode* node) {
        mDeclarationVec.push_back(node);
    };
};

#endif //PROJECT1_DECLARATIONS_H
