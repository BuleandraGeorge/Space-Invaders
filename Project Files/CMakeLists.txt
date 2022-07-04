cmake_minimum_required(VERSION "3.14.0")

project("SpaceInvaders")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
add_executable("${PROJECT_NAME}" "Main.cpp" "Block.cpp" "Block.h" "Blockade.cpp" "Blockade.h" "Board.cpp" "Board.h" "Entity.h" "Entity.cpp" "Invader.h" "Invader.cpp" "InvaderArmy.h" "InvaderArmy.cpp" "Message.h" "Message.cpp" "player.h" "player.cpp" "projectile.h" "projectile.cpp")

set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

#look for SFML and add it
find_package (SFML 2.5.1 REQUIRED system window graphics network audio)

target_link_libraries(SpaceInvaders PRIVATE sfml-audio sfml-graphics sfml-network sfml-system)


#include_directories(${SFML_INCLUDE_DIR})

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin
#install(FILES "Main.cpp" "Block.cpp" "Blockade.cpp"  "Board.cpp" "Entity.cpp" "Invader.cpp" "InvaderArmy.cpp" "Message.cpp" "player.cpp" "projectile.cpp" DESTINATION src)
install(FILES "Main.cpp " DESTINATION src)
# Group into "Source Files" and "Header Files"
    if ("${FILE}" MATCHES ".*\\.cpp")
      set(GROUP "src${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
      set(GROUP "include${GROUP}")
    endif()

	
set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
