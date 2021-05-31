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
#include "definitions.hpp"
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

            sf::Vector2i tile_index;
            sf::Vector2f tile_position;
            sf::Vector2f tile_position_center;
            std::vector<std::shared_ptr<Tile>> tiles_nearby;
            uint8_t mines_nearby;
            uint8_t flags_nearby = 0;
            bool mine = false;
            bool flagged = false;
            bool questioned = false;
            bool use_question_marks = true;
            bool revealed = false;
        
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

            std::shared_ptr<Board> board;
    };
}

#endif // __TILE_H__