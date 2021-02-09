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
#include "definitions.hpp"
#include "enums.hpp"
#include "tile.hpp"

namespace ms
{
    class Board
        : public std::enable_shared_from_this<Board>
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
            void ChangeRandomSeed();
            std::shared_ptr<Tile> CoordsToTile(uint32_t a_x, uint32_t a_y);

            GameState game_state = GameState::Start;
            std::shared_ptr<sf::RenderWindow> window;
            std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
            sf::Vector2f board_size;
            sf::Vector2f board_position;
            uint32_t mine_count;
            uint32_t flag_count = 0;
            sf::Vector2i tile_count;
            sf::Vector2f tile_size;
            sf::Font tile_font;
            uint8_t tile_font_size;
            uint8_t tile_border_thickness = 1;

            const sf::Color color_base{0xC0, 0xC0, 0xC0};         // light gray
            const sf::Color color_border{0x80, 0x80, 0x80};       // dark gray
            const sf::Color color_cover{0x30, 0x40, 0xDD};        // light blue
            const sf::Color color_mine{0x00, 0x00, 0x00};         // black
            const sf::Color color_mine_clicked{0xFF, 0x00, 0x00}; // red
            const sf::Color color_flag{0xFF, 0x00, 0x00};         // red
            const sf::Color color_question{0xFF, 0xFF, 0xFF};     // white
            const sf::Color color_cross{0xFF, 0x00, 0x00};        // red

            const std::array<sf::Color, 9> color_numbers = 
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

            uint32_t random_seed;
    };
}

#endif // __BOARD_H__