/**
 * @file Wall.h
 * @author Vijay
 *
 * Base class for the item Wall.
 */

#ifndef PROJECT1_WALL_H
#define PROJECT1_WALL_H
#include "Item.h"

/**
* Base class for the item Wall.
*/
class Wall : public Item {
private:
    /// the width of the item
    double mWidth = 0;

    /// the height of the item
    double mHeight = 0;

    /// underlying item image
    std::unique_ptr<wxImage> mItemImage;
    /// underlying item bitmap
    std::unique_ptr<wxBitmap> mItemBitmap;
public:
    /// Default constructor (disabled)
    Wall() = delete;

    /// Copy constructor (disabled)
    Wall(const Wall&) = delete;

    /// Assignment operator
    void operator=(const Wall&) = delete;

    Wall(Level* level, const std::wstring &filename);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitWall(this); }

    void XmlLoad(wxXmlNode *node) override;

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

#endif //PROJECT1_WALL_H
