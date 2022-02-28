/**
 * @file Level.h
 * @author malpi
 *
 *
 */

#ifndef PROJECT1_LEVEL_H
#define PROJECT1_LEVEL_H


class Game;


class Level {
private:
    Game *mGame;
public:

   void Load(const wxString &filename);

   void XmlDeclare(wxXmlNode* node);

   void XmlType(wxXmlNode* node);

   std::vector<std::wstring> Level::GetNodeChildren(wxXmlNode *node);

   Level(Game * game);
};

#endif //PROJECT1_LEVEL_H
