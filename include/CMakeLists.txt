add_library(Tile tile.cpp)
target_link_libraries(Tile sfml-graphics)
target_link_libraries(Tile Board)

add_library(Board board.cpp)
target_link_libraries(Board sfml-graphics)
target_link_libraries(Board Tile)

add_library(EventHandler eventhandler.cpp)
target_link_libraries(EventHandler sfml-graphics)
target_link_libraries(EventHandler Board)
target_link_libraries(EventHandler EventLog)

add_library(EventLog eventlog.cpp)
target_link_libraries(EventLog sfml-graphics)
target_link_libraries(EventLog Board)
target_link_libraries(EventLog MouseAction)

add_library(MouseAction mouseaction.cpp)
target_link_libraries(MouseAction sfml-graphics)
target_link_libraries(MouseAction Board)