#ifndef __MINESWEEPER_H__
#define __MINESWEEPER_H__

// Standard libraries
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <cmath>

// SFML modules
#include <SFML/Graphics.hpp>

namespace ms
{
    class Tile;
    class Board;
    class EventHandler;
    class EventLog;
    class MouseAction;
    
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
    
    class Tile
    {
        public:
            Tile(   std::shared_ptr<Board> a_board,
                    sf::Vector2i a_tile_index   );
            ~Tile();

            void Draw();
            void Mark();
            void Reveal();
            void UpdateNearbyMines();

            sf::Vector2i tile_index;
            sf::Vector2f tile_position;
            sf::Vector2f tile_position_center;
            std::vector<std::shared_ptr<Tile>> tiles_nearby;
            uint8_t mines_nearby;
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

            void CenterText(    sf::Text& a_text, 
                                sf::RectangleShape& a_box );

            std::shared_ptr<Board> board;
    };

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
            void GenerateBoard();
            void PlaceMines();
            void MapNearbyTiles();
            void UpdateNearbyMines();
            std::shared_ptr<Tile> CoordsToTile(uint32_t a_x, uint32_t a_y);

            GameState game_state = GameState::Start;
            std::shared_ptr<sf::RenderWindow> window;
            std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
            sf::Vector2f board_size;
            sf::Vector2f board_position;
            uint32_t mine_count;
            sf::Vector2i tile_count;
            sf::Vector2f tile_size;
            sf::Font tile_font;
            uint8_t tile_font_size;
            uint8_t tile_border_thickness = 2;

            sf::Color color_base{0xC0, 0xC0, 0xC0};         // light gray
            sf::Color color_border{0x80, 0x80, 0x80};       // dark gray
            sf::Color color_cover{0x30, 0x40, 0xDD};        // light blue
            sf::Color color_mine{0x00, 0x00, 0x00};         // black
            sf::Color color_mine_clicked{0xFF, 0x00, 0x00}; // red
            sf::Color color_flag{0xFF, 0x00, 0x00};         // red
            sf::Color color_question{0xFF, 0xFF, 0xFF};     // white
            sf::Color color_cross{0xFF, 0x00, 0x00};        // red

            std::array<sf::Color, 9> color_numbers = 
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

    class EventHandler
    {
        public:
            EventHandler(   std::shared_ptr<sf::Event> a_event,
                            std::shared_ptr<EventLog> a_event_log,
                            std::shared_ptr<sf::RenderWindow> a_window,
                            std::shared_ptr<Board> a_board  );
            ~EventHandler();

        private:

            std::shared_ptr<sf::Event> event;
            std::shared_ptr<EventLog> event_log;
            std::shared_ptr<sf::RenderWindow> window;
            std::shared_ptr<Board> board;
    };

    class EventLog
    {
        public:

            EventLog(std::shared_ptr<Board> a_board);
            ~EventLog();

            MouseAction left_press;
            MouseAction left_release;
            MouseAction right_press;
            MouseAction right_release;

        private:
            std::shared_ptr<Board> board;


    };
    
    class MouseAction
    {
        public:
            MouseAction();
            ~MouseAction();

            void Log();

            sf::Time time_last = sf::milliseconds(-1);
            sf::Vector2i tile_coords = sf::Vector2i(-1, -1);
        
        private:
            sf::Clock clock;
    };
}

#endif // __MINESWEEPER_H__