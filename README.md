A remake of the game Arkanoid in Raylib

## Wishlist (crossed items are done)
1) ~~Web build~~
2) Better collision

## Instructions to compile for web using Emscripten
>mkdir build
>cd build
>emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3" -DCMAKE_EXECUTABLE_SUFFIX=".html" -G "MinGW Makefiles"
>emmake make
>emrun block_game.html