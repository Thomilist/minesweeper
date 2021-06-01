#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define FONT_PATH "C:\\Windows\\Fonts\\cour.ttf"    // Path to the font.
#define WINDOW_TITLE "Minesweeper"                  // Title of the window.
#define DOUBLE_CLICK_TIMEOUT 500                    // Time between the clicks in a double click.

namespace ms
{
    class Tile;
    class Board;
    class EventHandler;
    class EventLog;
    class MouseAction;
}

namespace ui
{
    class Element;
    class Dynamic;
    class Button;
    class Toggle;
    class Static;
    class Text;
}

#endif // __DEFINITIONS_H__