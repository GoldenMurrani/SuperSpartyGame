/**
 * @file Level.h
 * @author malpi
 *
 *
 */

#ifndef PROJECT1_LEVEL_H
#define PROJECT1_LEVEL_H

#include "Declerations.h"

class Game;

class Level {
private:
    Game *mGame;
    std::shared_ptr<Declerations> mDeclerations;
protected:
    Level(Game * game);
public:

   void Load(const wxString &filename);
   void XmlDeclare(wxXmlNode* node);



};

#endif //PROJECT1_LEVEL_H
