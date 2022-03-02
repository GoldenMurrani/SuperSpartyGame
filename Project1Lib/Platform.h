/**
 * @file Platform.h
 * @author Vijay
 *
 * Base class for the item platform.
 */

#ifndef PROJECT1_PLATFORM_H
#define PROJECT1_PLATFORM_H
#include "Item.h"

class Level;
/**
* Base class for the item platform.
*/

class Platform : public Item {
private:
    //Platform is inherits from Item, every private member variable defined here and function should directly use item base class
    // no need to define here again


//    /// The game window this item in going to be in
//    Game *mGame;
//    /// The underlying Platform image
//    std::unique_ptr<wxImage> mItemImage;
//
//    /// The bitmap we can display for this platform
//    std::unique_ptr<wxBitmap> mItemBitmap;
//    /// Item location in the Game
//    double  mX = 0;     ///< X location for the center of the item
//    double  mY = 0;     ///< Y location for the center of the item
      //Level *mLevel;


    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage1;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemBitmap1;

    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage2;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemBitmap2;
    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage3;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemBitmap3;

    double mWidth = 0;

    double mHeight = 0;
public:
    /// Default constructor (disabled)
    Platform() = delete;
    /// Copy constructor (disabled)
    Platform(const Platform&) = delete;

    /// Assignment operator
    void operator=(const Platform&) = delete;

    Platform(Level* level, std::wstring filename, std::wstring filename2, std::wstring filename3);

//    /**
//    * The X location of the item
//    * @return X location in pixels
//    */
//    double GetX() const { return mX; }
//
//    /**
//     * The Y location of the item
//     * @return Y location in pixels
//     */
//    double GetY() const { return mY; }
//    /**
//     * Get the width of the Wall
//     * @return Wall width in pixels
//     */
//    int GetWidth() const { return mItemBitmap->GetWidth(); }
//
//    /**
//     * Get the height of the Wall
//     * @return Wall height in pixels
//     */
//    int GetHeight() const { return mItemBitmap->GetHeight(); }

    //void OnDraw(wxDC *dc);
    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitPlatform(this); }

    void XmlLoad(wxXmlNode* node) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //PROJECT1_PLATFORM_H
