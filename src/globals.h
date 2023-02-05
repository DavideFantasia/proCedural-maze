#ifndef GLOBAL_H
#define GLOBAL_H

// ====== Screen size definition here
#define SCREEN_WIDTH            700
#define SCREEN_HEIGTH           600
#define SCREEN_X_POS            100
#define SCREEN_Y_POS            100

// ====== Color definition here ======
#define BACKGROUND_COLOR        0x000000FF
#define TEXT_COLOR              0xFFFFFFFF

// ====== General constants here ======
/**
 * \brief rappresent the minimun frame rate ==> 1 / (16 / 1000) = circa 60fps
 */
#define FRAME_RATE_INF_LIM      16


// ====== Macro definition here ======
/**
 * \brief Macro to convert a hex value in 4 input in 0-256 range 
 */
#define HEX_COLOR(hex)             \
    ((hex) >> (3 * 8)) & 0xFF,     \
    ((hex) >> (2 * 8)) & 0xFF,     \
    ((hex) >> (1 * 8)) & 0xFF,     \
    ((hex) >> (0 * 8)) & 0xFF

#endif
