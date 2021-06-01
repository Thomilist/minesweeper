#ifndef __TILE_H__
#define __TILE_H__

// Standard libraries
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <cmath>

// SFML modules
#include <SFML/Graphics.hpp>

// Custom headers
#include "../definitions.hpp"
#include "enums.hpp"
#include "board.hpp"

namespace ms
{
    class Tile
    {
        public:
            Tile(   std::shared_ptr<Board> a_board,
                    sf::Vector2i a_tile_index   );
            ~Tile();

            void Draw();
            void Mark();
            void Reveal();
            void RevealSurrounding();
            void UpdateNearbyMines();

            sf::Vector2i tile_index;                            // Index of the tile in the board.
            sf::Vector2f tile_position;                         // The window coordinates of the top left corner of the tile.
            sf::Vector2f tile_position_center;                  // The window coordinates of the center of the tile.
            std::vector<std::shared_ptr<Tile>> tiles_nearby;    // Array pointing to the eight surrounding tiles.
            uint8_t mines_nearby;                               // The number of mines in the eight surrounding tiles.
            uint8_t flags_nearby = 0;                           // The number of flags placed on the eight surrounding tiles.
            bool mine = false;                                  // Indicates if this tile contains a mine.
            bool flagged = false;                               // Indicates if the player has marked this tile with a flag.
            bool questioned = false;                            // Indicates if the player has marked this tile with a question mark.
            bool use_question_marks = true;                     // Indicates if marking with question marks is enabled.
            bool revealed = false;                              // Indicates if this tile is revealed.
        
        private:
            void DrawBase();
            void DrawCover();
            void DrawNumber();
            void DrawMine();
            void DrawFlag();
            void DrawQuestion();
            void DrawCross();

            void PlaceFlag();
            void RemoveFlag();

            void CenterText(    sf::Text& a_text, 
                                sf::RectangleShape& a_box );

            std::shared_ptr<Board> board;                       // Pointer to the board containing this tile.
    };
}

#endif // __TILE_H__