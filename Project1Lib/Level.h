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

    /// Game object item is in
    Game *mGame;

    /// Vector that holds the levels Items
    std::vector<std::shared_ptr<Item>> mItems;

    /// Vector that hold the levels declarations
    std::vector<wxXmlNode*> mVecDec;

    /// Level width
    double mWidth = 0;

    /// Level height
    double mHeight = 0;

    /// Sparty start x loaction
    double mStartx = 0;

    /// Sparty start y loaction
    double mStartY = 0;



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

    void LevelInfoSetter(wxXmlNode* node);
};

#endif //PROJECT1_LEVEL_H
