/**
 * @file SpeedUp.h
 * @author Matthew Hofmann
 *
 * Base class for speed up class
 */

#ifndef PROJECT1_SPEEDUP_H
#define PROJECT1_SPEEDUP_H

#include "Item.h"
/**
* Base class for speed up class
*/
class SpeedUp : public Item {
private:

    /// Bool if the SpeedUp was collected or not.
    bool mCollected = false;

    /// Game this item is in
    Game* mGame;

    /// X and Y value of the text
    int mTextX = -1000;
    int mTextY = -1000;

    /// Height and Width of the Font
    int mFontHeight = 25;
    int mFontWidth = 50;
public:

    /// Default constructor (disabled)
    SpeedUp() = delete;

    /// Copy constructor (disabled)
    SpeedUp(const ReversePower&) = delete;

    /// Assignment operator
    void operator=(const SpeedUp&) = delete;

    SpeedUp(Level* level, const std::wstring& filename, Game* game);

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitSpeedUp(this); }

    bool CollisionTest(Item* item) override;

    void Update(double elapsed) override;

    void Speed();

    void XmlLoad(wxXmlNode* node) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //PROJECT1_SPEEDUP_H
