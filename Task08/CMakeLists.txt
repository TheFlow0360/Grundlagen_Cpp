set(SOURCE
    ${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/program.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/spacegame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/target.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/planet.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/spaceship.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/deathstar.cpp
    PARENT_SCOPE
)
set(HEADERS
    ${HEADERS}
    ${CMAKE_CURRENT_SOURCE_DIR}/program.h
    ${CMAKE_CURRENT_SOURCE_DIR}/spacegame.h
    ${CMAKE_CURRENT_SOURCE_DIR}/target.h
    ${CMAKE_CURRENT_SOURCE_DIR}/planet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/spaceship.h
    ${CMAKE_CURRENT_SOURCE_DIR}/deathstar.h
    PARENT_SCOPE
)
