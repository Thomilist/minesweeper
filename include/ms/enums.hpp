#ifndef __ENUMS_H__
#define __ENUMS_H__

namespace ms
{
    // States of the Minesweeper game.
    enum class GameState
    {
        Start,
        Ongoing,
        Lost,
        Won
    };
}

#endif // __ENUMS_H__