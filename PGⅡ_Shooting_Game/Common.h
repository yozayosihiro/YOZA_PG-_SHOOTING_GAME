#pragma once

enum class GAME_STATE {
    GAME_TITLE = 0,  // 0
    GAME_INIT,       // 1
    GAME_MAIN,       // 2
    DRAW_GAME_CLEAR, // 3
    DRAW_GAME_OVER,  // 4
    INPUT_RANKING,   // 5
    DRAW_RANKING,    // 6
    DRAW_END,        // 7

    EXIT = 99
};