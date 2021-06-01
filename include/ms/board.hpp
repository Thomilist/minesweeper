#ifndef __BOARD_H__
#define __BOARD_H__

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
#include "tile.hpp"
#include "../ui/elements/dynamic.hpp"

namespace ms
{
    class Board
        : public std::enable_shared_from_this<Board>
        , public ui::Dynamic
    {
        public:
            Board(  std::shared_ptr<sf::RenderWindow> a_window,
                    sf::Vector2f a_tile_size,
                    sf::Vector2i a_tile_count,
                    uint32_t a_mine_count,
                    uint32_t a_random_seed  );
            ~Board();

            void Draw();
            void Initialise();
            void GenerateBoard();
            void PlaceMines();
            void RemoveMines();
            void MapNearbyTiles();
            void UpdateNearbyMines();
            void SetRandomSeed(uint32_t a_random_seed);
            void NewRandomSeed();
            std::shared_ptr<Tile> CoordsToTile(uint32_t a_x, uint32_t a_y);

            GameState game_state = GameState::Start;                // The state of the current Minesweeper game.
            std::shared_ptr<sf::RenderWindow> window;               // The window all graphics are drawn to.
            std::vector<std::vector<std::shared_ptr<Tile>>> tiles;  // The array of tiles.
            sf::Vector2f board_size;                                // The size of the board in pixels.
            sf::Vector2f board_position;                            // The position in the window of the top left corner of the board.
            uint32_t mine_count;                                    // The number of mines.
            uint32_t flag_count = 0;                                // The number of flags placed.
            sf::Vector2i tile_count;                                // The size of the board in tiles.
            sf::Vector2f tile_size;                                 // The size of each tile in pixels.
            sf::Font tile_font;                                     // The font to use for text elements.
            uint8_t tile_font_size;                                 // The size of the font.
            uint8_t tile_border_thickness = 1;                      // The thickness of the border along the edge of each tile.

            const sf::Color color_base{0xC0, 0xC0, 0xC0};           // Light gray
            const sf::Color color_border{0x80, 0x80, 0x80};         // Dark gray
            const sf::Color color_cover{0x30, 0x40, 0xDD};          // Light blue
            const sf::Color color_mine{0x00, 0x00, 0x00};           // Black
            const sf::Color color_mine_clicked{0xFF, 0x00, 0x00};   // Red
            const sf::Color color_flag{0xFF, 0x00, 0x00};           // Red
            const sf::Color color_question{0xFF, 0xFF, 0xFF};       // White
            const sf::Color color_cross{0xFF, 0x00, 0x00};          // Red

            const std::array<sf::Color, 9> color_numbers =          // The colors of the numbers written on cleared tiles.
            {
                sf::Color::Transparent,         // 0
                sf::Color{0x00, 0x00, 0xFF},    // 1, blue
                sf::Color{0x00, 0x80, 0x00},    // 2, dark green
                sf::Color{0xFF, 0x00, 0x00},    // 3, red
                sf::Color{0x00, 0x00, 0x80},    // 4, dark blue
                sf::Color{0x80, 0x00, 0x00},    // 5, dark red
                sf::Color{0x00, 0x80, 0x80},    // 6, turquoise
                sf::Color{0x00, 0x00, 0x00},    // 7, black
                sf::Color{0x80, 0x80, 0x80}     // 8, dark gray
            };
        
        private:

            uint32_t random_seed;   // The seed used for the mine distribution.
    };
}

#endif // __BOARD_H__