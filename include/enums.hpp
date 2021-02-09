#ifndef __ENUMS_H__
#define __ENUMS_H__

namespace ms
{
        enum class TileState
    {
        Zero,
        One,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Basic,
        Flag,
        Question,
        Mine,
        MineWrong,
        MineClicked
    };

    enum class GameState
    {
        Start,
        Ongoing,
        Lost,
        Won
    };
}

#endif // __ENUMS_H__