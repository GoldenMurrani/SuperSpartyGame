#cmake_minimum_required(VERSION 3.20)
project(Project1Lib)

set(SOURCE_FILES Game.cpp Game.h Item.cpp Item.h pch.h MainFrame.cpp MainFrame.h GameView.cpp GameView.h ids.h Enemy.cpp Enemy.h Sparty.cpp Sparty.h Door.cpp Door.h Wall.cpp Wall.h Platform.cpp Platform.h Money.cpp Money.h PowerUp.cpp PowerUp.h Background.cpp Background.h ItemVisitor.cpp ItemVisitor.h MoneyVisitor.cpp MoneyVisitor.h Level.h Level.cpp Declarations.h Declarations.cpp Scoreboard.cpp Scoreboard.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)