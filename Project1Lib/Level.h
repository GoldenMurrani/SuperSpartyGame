/**
 * @file Level.h
 * @author malpi
 *
 *
 */

#ifndef PROJECT1_LEVEL_H
#define PROJECT1_LEVEL_H

#include "Item.h"
#include "Declarations.h"

class Game;



class Level {
private:
    Game *mGame;
    Declarations *mDeclarations;
    std::vector<std::shared_ptr<Item>> mItems;
    std::vector<wxXmlNode*> mVecDec;
public:

   void Load(const wxString &filename);

   void XmlDeclare(wxXmlNode* node);

   std::vector<std::wstring> Level::GetNodeChildren(wxXmlNode *node);

   Level(Game * game);

    void XmlLevel(wxXmlNode* node);

    void VectorNode(wxXmlNode* node);

    void XmlType(wxXmlNode* node);

    std::vector<std::wstring> XmlType(wxString nodeName, wxString typeId);

    void XmlItem(wxXmlNode* node);

    void Add(std::shared_ptr<Item> item);
};

#endif //PROJECT1_LEVEL_H
