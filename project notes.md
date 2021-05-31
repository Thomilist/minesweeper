# Project Notes

## Implemented Features

* Basic gameplay
    * Left click, right click, dual/double click
    * Flags, question marks
* Random board generation
    * Seed-based
    * Always hit open area on first click

## Known Issues

* Clicking outside the board throws a std::out_of_range error
* An area above and to the left of the board, equivalent to row -1 and collumn -1, is considered part of row 0 and collumn 0

## To-Do List

* Live counters
    * Flags placed / total mines
    * Time
        * Live placement on leaderboard
    * Clearance progress
* Menus
    * https://stackoverflow.com/questions/2298242/callback-functions-in-c
    * Main
    * End-game
    * Settings
    * Replays
    * Statistics
    * Leaderboard
        * speedrun.com integration?
* Settings
    * Difficulties (preset / custom)
    * Seed
    * Enable question marks
    * Replay save behavior
* Replays
    * Save, load and play replays