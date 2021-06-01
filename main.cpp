// Standard libraries
#include <iostream>
#include <vector>
#include <stdint.h>
#include <memory>

// SFML modules
#include <SFML/Graphics.hpp>

// Custom headers
#include "include/definitions.hpp"
#include "include/ms/board.hpp"
#include "include/ms/eventhandler.hpp"
#include "include/ms/eventlog.hpp"

int main()
{
    // Create window.
    std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(  sf::VideoMode::getDesktopMode(),
                                                                    WINDOW_TITLE,
                                                                    sf::Style::Fullscreen   ));

    // Create Minesweeper board.
    std::shared_ptr<ms::Board> board(new ms::Board( window,
                                                    sf::Vector2f(50.f, 50.f),
                                                    sf::Vector2i(30, 16),
                                                    uint32_t(99),
                                                    time(0) ));
    board->Initialise();

    // Create event log.
    std::shared_ptr<ms::EventLog> event_log(new ms::EventLog(board));
    event_log->InitialiseLogs();

    // Create event object.
    std::shared_ptr<sf::Event> event(new sf::Event());

    // Render loop.
    while (window->isOpen())
    {
        while (window->pollEvent(*event))
        {
            ms::EventHandler(event, event_log, window, board);
        }

        window->clear();
        board->Draw();
        window->display();
    }

    return 0;
}