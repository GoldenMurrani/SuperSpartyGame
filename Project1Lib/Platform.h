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


    /// The underlying item image
    std::unique_ptr<wxImage> mLeftImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mLeftBitmap;

    /// The underlying item image
    std::unique_ptr<wxImage> mMiddleImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mMiddleBitmap;
    /// The underlying item image
    std::unique_ptr<wxImage> mRightImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mRightBitmap;

    /// Width of platform
    double mWidth = 0;

    /// Height of platform
    double mHeight = 0;
public:
    /// Default constructor (disabled)
    Platform() = delete;

    /// Copy constructor (disabled)
    Platform(const Platform&) = delete;

    /// Assignment operator
    void operator=(const Platform&) = delete;

    Platform(Level* level, std::wstring filename, std::wstring filename2, std::wstring filename3);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitPlatform(this); }

    void XmlLoad(wxXmlNode* node) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Get the width of the item
    * @return Item width in pixels
    */
    int GetWidth() override {return mWidth; }

    /**
     * Get the height of the item
     * @return Item height in pixels
     */
    int GetHeight() override {return mHeight; }
};

#endif //PROJECT1_PLATFORM_H
