add_library(Element element.cpp)
target_link_libraries(Element sfml-graphics)

add_library(Dynamic dynamic.cpp)
target_link_libraries(Dynamic sfml-graphics)
target_link_libraries(Dynamic Element)