/*
          8x8 LED Matrix MAX7219 Scrolling Text Example
       Based on the following library:
       GitHub | riyas-org/max7219  https://github.com/riyas-org/max7219
*/
#include <MaxMatrix.h>
#include <avr/pgmspace.h>

PROGMEM const unsigned char EN_chars[] = {
    3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
    1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
    3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
    5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
    4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
    5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
    5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
    1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
    3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
    3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
    5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
    5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
    2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
    4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
    2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
    4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
    4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
    3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
    4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
    4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
    4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
    4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
    4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
    4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
    4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
    4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
    2, 8, B00100100, B00000000, B00000000, B00000000, B00000000, // :
    2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
    3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
    3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
    3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
    4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
    5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
    4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
    4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
    4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
    4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
    4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
    4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
    4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
    4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
    3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
    4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
    4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
    4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
    5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
    5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
    4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
    4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
    4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
    4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
    4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
    5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
    4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
    5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
    5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
    5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
    5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
    4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
    2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
    4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
    2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
    3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
    4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
    2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
    4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
    4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
    4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
    4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
    4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
    3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
    4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
    4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
    3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
    4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
    4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
    3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
    5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
    4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
    4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
    4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
    4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
    4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
    4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
    3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
    4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
    5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
    5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
    5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
    4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
    3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
    3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
    1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
    3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
    4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};

// الفبای فارسی
PROGMEM const unsigned char FA_chars_single[] = {
    3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, // " "
    3, 8, B00000000, B00111111, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, // ا
    5, 8, B00000000, B00111000, B10100000, B00100000, B00111000, B00000000, B00000000, B00000000, // ب
    5, 8, B00000000, B00111000, B10100000, B11100000, B00111000, B00000000, B00000000, B00000000, // پ
    5, 8, B00000000, B00111000, B00100010, B00100010, B00111000, B00000000, B00000000, B00000000, // ت
    5, 8, B00000000, B00111000, B00100010, B00100011, B00111000, B00000000, B00000000, B00000000, // ث
    5, 8, B11110000, B10010100, B11010010, B10011100, B00000000, B00000000, B00000000, B00000000, // ج
    5, 8, B11110000, B11010100, B11110010, B10011100, B00000000, B00000000, B00000000, B00000000, // چ
    5, 8, B11110000, B10010100, B10010010, B10011100, B00000000, B00000000, B00000000, B00000000, // ح
    5, 8, B11110000, B10010100, B10010011, B10011100, B00000000, B00000000, B00000000, B00000000, // خ
    4, 8, B10001000, B01010000, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, // د
    4, 8, B10001010, B01010000, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, // ذ
    4, 8, B10000000, B01000000, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, // ر
    4, 8, B10000000, B01000000, B00101000, B00000000, B00000000, B00000000, B00000000, B00000000, // ز
    4, 8, B10000000, B01001100, B00101000, B00000000, B00000000, B00000000, B00000000, B00000000, // ژ
    8, 8, B11100000, B10000000, B11110000, B00100000, B00110000, B00100000, B00110000, B00000000, // س
    8, 8, B11100000, B10000000, B11110000, B00100100, B00110110, B00100000, B00110000, B00000000, // ش
    8, 8, B11100000, B10000000, B11111000, B00110000, B00101000, B00101000, B00111000, B00000000, // ص
    8, 8, B11100000, B10000000, B11111000, B00110000, B00101010, B00101000, B00111000, B00000000, // ض
    8, 8, B00100000, B00100000, B00111111, B00110000, B00101000, B00101000, B00111000, B00000000, // ط
    8, 8, B00100000, B00100000, B00111111, B00110000, B00101010, B00101000, B00111000, B00000000, // ظ
    4, 8, B11100000, B10111000, B10101000, B00000000, B00000000, B00000000, B00000000, B00000000, // ع
    4, 8, B11100000, B10111000, B10101010, B00000000, B00000000, B00000000, B00000000, B00000000, // غ
    7, 8, B00111000, B00100000, B00100000, B00111000, B00101010, B00111000, B00000000, B00000000, // ف
    7, 8, B01111000, B10000000, B10000000, B10111000, B10101010, B01111010, B00000000, B00000000, // ق
    7, 8, B00110000, B00100000, B00100000, B00111000, B00000100, B00000010, B00000000, B00000000, // ک
    7, 8, B00110000, B00100000, B00100100, B00111010, B00000101, B00000010, B00000000, B00000000, // گ
    5, 8, B01100000, B10000000, B10000000, B01111100, B00000000, B00000000, B00000000, B00000000, // ل
    5, 8, B11111000, B00001000, B00011000, B00011000, B00000000, B00000000, B00000000, B00000000, // م
    6, 8, B01100000, B10000000, B10010000, B10000000, B01100000, B00000000, B00000000, B00000000,
    4, 8, B10000000, B01011000, B00111000, B00000000, B00000000, B00000000, B00000000, B00000000,
    4, 8, B00110000, B00101000, B00110000, B00000000, B00000000, B00000000, B00000000, B00000000,
    5, 8, B11110000, B10000000, B10110000, B11010000, B00000000, B00000000, B00000000, B00000000,// "ی"
};

PROGMEM const unsigned char FA_chars_bind_to_forward[] = {
    3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, // " "
    3, 8, B00000000, B00111111, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, // ا
    3, 8, B10100000, B00100000, B00111000, B00000000, B00000000, B00000000, B00000000, B00000000, // ب
    3, 8, B10100000, B11100000, B00111000, B00000000, B00000000, B00000000, B00000000, B00000000, // پ
    3, 8, B00100010, B00100010, B00111000, B00000000, B00000000, B00000000, B00000000, B00000000, // ت
    3, 8, B00100010, B00100011, B00111000, B00000000, B00000000, B00000000, B00000000, B00000000, // ث
    5, 8, B00100000, B10101000, B00100100, B00111000, B00000000, B00000000, B00000000, B00000000, // ج
    5, 8, B00100000, B10101000, B11100100, B00111000, B00000000, B00000000, B00000000, B00000000, // چ
    5, 8, B00100000, B00101000, B00100100, B00111000, B00000000, B00000000, B00000000, B00000000, // ح
    5, 8, B00100000, B00101000, B00100101, B00111000, B00000000, B00000000, B00000000, B00000000, // خ
    4, 8, B10001000, B01010000, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, // د
    4, 8, B10001010, B01010000, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, // ذ
    4, 8, B10000000, B01000000, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, // ر
    4, 8, B10000000, B01000000, B00101000, B00000000, B00000000, B00000000, B00000000, B00000000, // ز
    4, 8, B10000000, B01001100, B00101000, B00000000, B00000000, B00000000, B00000000, B00000000, // ژ
    8, 8, B00100000, B00100000, B00110000, B00100000, B00110000, B00100000, B00110000, B00000000, // س
    8, 8, B00100000, B00100000, B00110000, B00100100, B00110110, B00100000, B00110000, B00000000, // ش
    8, 8, B00100000, B00100000, B00111000, B00110000, B00101000, B00101000, B00111000, B00000000, // ص
    8, 8, B00100000, B00100000, B00111000, B00110000, B00101010, B00101000, B00111000, B00000000, // ض
    8, 8, B00100000, B00100000, B00111111, B00110000, B00101000, B00101000, B00111000, B00000000, // ط
    8, 8, B00100000, B00100000, B00111111, B00110000, B00101010, B00101000, B00111000, B00000000, // ظ
    5, 8, B00100000, B00100000, B00111000, B00101000, B00000000, B00000000, B00000000, B00000000, // ع
    5, 8, B00100000, B00100000, B00111000, B00101010, B00000000, B00000000, B00000000, B00000000, // ع
    7, 8, B00100000, B00100000, B00100000, B00111000, B00101010, B00111000, B00000000, B00000000, // ف
    7, 8, B00100000, B00100000, B00100000, B00111000, B10101010, B01111010, B00000000, B00000000, // ق
    7, 8, B00100000, B00100000, B00100000, B00111000, B00000100, B00000010, B00000000, B00000000, // ک
    7, 8, B00100000, B00100000, B00100100, B00111010, B00000101, B00000010, B00000000, B00000000, // گ
    4, 8, B00100000, B00100000, B00111111, B00000000, B00000000, B00000000, B00000000, B00000000, // ل
    5, 8, B00100000, B00100000, B01100000, B01100000, B00000000, B00000000, B00000000, B00000000,
    5, 8, B00100000, B00100000, B00100100, B00110000, B00000000, B00000000, B00000000, B00000000,
    4, 8, B10000000, B01011000, B00111000, B00000000, B00000000, B00000000, B00000000, B00000000,
    6, 8, B00100000, B00100000, B11111000, B10101000, B11111000, B00000000, B00000000, B00000000,
    3, 8, B10100000, B10100000, B00111000, B00000000, B00000000, B00000000, B00000000, B00000000, // ی
};

PROGMEM const unsigned char FA_chars_bind_to_back[] = {
    3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, // " "
    3, 8 ,B00000000, B00111111, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, // ا
    5, 8 ,B00111000, B10100000, B00100000, B00111000, B00100000, B00000000, B00000000, B00000000, // ب
    5, 8 ,B00111000, B10100000, B11100000, B00111000, B00100000, B00000000, B00000000, B00000000, // پ
    5, 8 ,B00111000, B00100010, B00100010, B00111000, B00100000, B00000000, B00000000, B00000000, // ت
    5, 8 ,B00111000, B00100010, B00100011, B00111000, B00100000, B00000000, B00000000, B00000000, // ث
    5, 8, B11110000, B10010100, B11010010, B10011100, B00100000, B00000000, B00000000, B00000000, // ج
    5, 8, B11110000, B11010100, B11110010, B10011100, B00100000, B00000000, B00000000, B00000000, // چ
    5, 8, B11110000, B10010100, B10010010, B10011100, B00100000, B00000000, B00000000, B00000000, // ح
    5, 8, B11110000, B10010100, B10010011, B10011100, B00100000, B00000000, B00000000, B00000000, // خ
    4, 8, B10001000, B01010000, B00100000, B00100000, B00000000, B00000000, B00000000, B00000000, // د
    4, 8, B10001010, B01010000, B00100000, B00100000, B00000000, B00000000, B00000000, B00000000, // ذ
    4, 8, B10000000, B01000000, B00100000, B00100000, B00000000, B00000000, B00000000, B00000000, // ر
    4, 8, B10000000, B01000000, B00101000, B00100000, B00000000, B00000000, B00000000, B00000000, // ز
    4, 8, B10000000, B01001100, B00101000, B00100000, B00000000, B00000000, B00000000, B00000000, // ژ
    8, 8, B11100000, B10000000, B11110000, B00100000, B00110000, B00100000, B00110000, B00100000, // س
    8, 8, B11100000, B10000000, B11110000, B00100100, B00110110, B00100000, B00110000, B00100000, // ش
    8, 8, B11100000, B10000000, B11111000, B00110000, B00101000, B00101000, B00111000, B00100000, // ص
    8, 8, B11100000, B10000000, B11111000, B00110000, B00101010, B00101000, B00111000, B00100000, // ض
    8, 8, B00100000, B00100000, B00111111, B00110000, B00101000, B00101000, B00111000, B00100000, // ط
    8, 8, B00100000, B00100000, B00111111, B00110000, B00101010, B00101000, B00111000, B00100000, // ظ
    5, 8, B11100000, B10101000, B10111000, B00101000, B00100000, B00000000, B00000000, B00000000, // ع
    5, 8, B11100000, B10101000, B10111010, B00101000, B00100000, B00000000, B00000000, B00000000, // غ
    7, 8, B00111000, B00100000, B00100000, B00111000, B00101010, B00111000, B00100000, B00000000, // ف
    7, 8, B01111000, B10000000, B10000000, B10111000, B10101010, B01111010, B00100000, B00000000, // ق
    6, 8, B00110000, B00100000, B00100000, B00111000, B00100100, B00100010, B00000000, B00000000, // ک
    6, 8, B00110000, B00100000, B00100100, B00111010, B00100101, B00100010, B00000000, B00000000, // گ
    5, 8, B01100000, B10000000, B10000000, B01111100, B00100000, B00000000, B00000000, B00000000, // ل
    5, 8, B11100000, B00100000, B01100000, B01100000, B00100000, B00000000, B00000000, B00000000,
    6, 8, B01100000, B10000000, B10010000, B10000000, B01100000, B00100000, B00000000, B00000000,
    4, 8, B10000000, B01011000, B00111000, B00100000, B00000000, B00000000, B00000000, B00000000,
    5, 8, B00011100, B00010100, B00111100, B00100000, B00100000, B00000000, B00000000, B00000000,
    6, 8, B11110000, B10000000, B10110000, B11010000, B00010000, B00100000, B00000000, B00000000, // ی
};

PROGMEM const unsigned char FA_chars_bind_to_both[] = {
    3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, // " "
    3, 8 ,B00000000, B00111111, B00100000, B00000000, B00000000, B00000000, B00000000, B00000000, // ا
    4, 8 ,B10100000, B00100000, B00111000, B00100000, B00000000, B00000000, B00000000, B00000000, // ب
    4, 8 ,B10100000, B11100000, B00111000, B00100000, B00000000, B00000000, B00000000, B00000000, // پ
    4, 8 ,B00100010, B00100010, B00111000, B00100000, B00000000, B00000000, B00000000, B00000000, // ت
    4, 8 ,B00100010, B00100011, B00111000, B00100000, B00000000, B00000000, B00000000, B00000000, // ث
    5, 8, B00100000, B10101000, B00100100, B00111000, B00100000, B00000000, B00000000, B00000000, // ج
    5, 8, B00100000, B10101000, B11100100, B00111000, B00100000, B00000000, B00000000, B00000000, // چ
    5, 8, B00100000, B00101000, B00100100, B00111000, B00100000, B00000000, B00000000, B00000000, // ح
    5, 8, B00100000, B00101000, B00100101, B00111000, B00100000, B00000000, B00000000, B00000000, // خ
    4, 8, B10001000, B01010000, B00100000, B00100000, B00000000, B00000000, B00000000, B00000000, // د
    4, 8, B10001010, B01010000, B00100000, B00100000, B00000000, B00000000, B00000000, B00000000, // ذ
    4, 8, B10000000, B01000000, B00100000, B00100000, B00000000, B00000000, B00000000, B00000000, // ر
    4, 8, B10000000, B01000000, B00101000, B00100000, B00000000, B00000000, B00000000, B00000000, // ز
    4, 8, B10000000, B01001100, B00101000, B00100000, B00000000, B00000000, B00000000, B00000000, // ژ
    8, 8, B00100000, B00100000, B00110000, B00100000, B00110000, B00100000, B00110000, B00100000, // س
    8, 8, B00100000, B00100000, B00110000, B00100100, B00110110, B00100000, B00110000, B00100000, // ش
    8, 8, B00100000, B00100000, B00111000, B00110000, B00101000, B00101000, B00111000, B00100000, // ص
    8, 8, B00100000, B00100000, B00111000, B00110000, B00101010, B00101000, B00111000, B00100000, // ض
    8, 8, B00100000, B00100000, B00111111, B00110000, B00101000, B00101000, B00111000, B00100000, // ط
    8, 8, B00100000, B00100000, B00111111, B00110000, B00101010, B00101000, B00111000, B00100000, // ظ
    5, 8, B00100000, B00101000, B00111000, B00101000, B00100000, B00000000, B00000000, B00000000, // ع
    5, 8, B00100000, B00101000, B00111010, B00101000, B00100000, B00000000, B00000000, B00000000, // غ
    7, 8, B00100000, B00100000, B00100000, B00111000, B00101010, B00111000, B00100000, B00000000, // ف
    7, 8, B00100000, B00100000, B00111000, B00101010, B00111010, B00100000, B00000000, B00000000, // ق
    6, 8, B00100000, B00100000, B00100000, B00111000, B00100100, B00100010, B00000000, B00000000, // ک
    6, 8, B00100000, B00100000, B00100100, B00111010, B00100101, B00100010, B00000000, B00000000, // گ
    4, 8, B00100000, B00100000, B00111111, B00100000, B00000000, B00000000, B00000000, B00000000, // ل
    5, 8, B00100000, B00100000, B01100000, B01100000, B00100000, B00000000, B00000000, B00000000,
    5, 8, B00100000, B00100000, B00100010, B00111000, B00100000, B00000000, B00000000, B00000000,
    4, 8, B10000000, B01011000, B00111000, B00100000, B00000000, B00000000, B00000000, B00000000,
    6, 8, B00100000, B00100000, B11111000, B10101000, B11111000, B00100000, B00000000, B00000000,
    4, 8, B10100000, B10100000, B00111000, B00100000, B00000000, B00000000, B00000000, B00000000, // ی
};






const int DIN = 10;     //IN pin of MAX7219 module
const int CLK = 13;     // CLK pin of MAX7219 module
const int CS = 11;      // CS pin of MAX7219 module
const int maxInUse = 4; // number of 8*8 modules
const int refrehDelay = 150; // delay time between shifts

MaxMatrix m(DIN, CS, CLK, maxInUse);




char16_t text[100] = u"سلام دنیا      "; // Scrolling text






void setup(){
    m.init();          // module initialize
    m.setIntensity(1); // dot matix intensity 0-15
    Serial.begin(9600);
}

void loop(){
  
        printStringWithShift(text);
 
        if (Serial.available() > 0){
          clearScreenAndText();
          readSerialInput();
        }
        
}

void clearScreenAndText(){
    for (int i = 0; i < 100; i++)
    {
        text[i] = 0;
    }
    m.clear(); // این چرا تو حلقس؟  دیگه نیست
}

void readSerialInput(){
    int count = 0;
    while (Serial.available() > 0)
    {
        text[count] = Serial.read();
        
        Serial.print("read: ");
        Serial.println(text[count]);
        
        count++;
    }
}

// Display=the extracted characters with scrolling
void printCharWithShift(char16_t c){
    byte buffer[10];

    if (c < 32)
        return;
    c -= 32;
    memcpy_P(buffer, EN_chars + 7 * c, 7);
    m.writeSprite(32, 0, buffer);
    m.setColumn(32 + buffer[0], 0);
    for (int i = 0; i < buffer[0] + 1; i++){
        delay(refrehDelay);
        m.shiftLeft(false, false); 
    }
    
}

void printPersianCharWithShift(char16_t c , bool  bindToPrevios, bool bindToNext){
    // todo

    // find right char
    byte buffer[10];

    if(!bindToPrevios && !bindToNext){
        memcpy_P(buffer, FA_chars_single + 10 * getPersianIndex(c), 10);
//        Serial.println("!pre  ::  !next");
    }

    if(!bindToPrevios && bindToNext){
        memcpy_P(buffer, FA_chars_bind_to_forward + 10 * getPersianIndex(c), 10);
//        Serial.println("!pre  ::  next");
    }

    if(bindToPrevios && !bindToNext){
        memcpy_P(buffer, FA_chars_bind_to_back + 10 * getPersianIndex(c), 10);
//        Serial.println("pre  ::  !next");
    }

    if(bindToPrevios && bindToNext){
        memcpy_P(buffer, FA_chars_bind_to_both + 10 * getPersianIndex(c), 10);
//        Serial.println("pre  ::  next");
    }

//for(int i=0;i<7;i++){
//  Serial.print(buffer[i]);
//  Serial.println(",");
//}

    // render
    // todo shift to right
    for (int i = 0; i < buffer[0]; i++){
        delay(refrehDelay);
        m.shiftRight(false, true);
    }

    m.writeSprite(0, 0, buffer);
}

int getPersianIndex(char16_t c){

    switch (c){
        case u' ': return 0;
        case u'ا': return 1;
        case u'ب': return 2;
        case u'پ': return 3;
        case u'ت': return 4;
        case u'ث': return 5;
        case u'ج': return 6;
        case u'چ': return 7;
        case u'ح': return 8;
        case u'خ': return 9;
        case u'د': return 10;
        case u'ذ': return 11;
        case u'ر': return 12;
        case u'ز': return 13;
        case u'ژ': return 14;
        case u'س': return 15;
        case u'ش': return 16;
        case u'ص': return 17;
        case u'ض': return 18;
        case u'ط': return 19;
        case u'ظ': return 20;
        case u'ع': return 21;
        case u'غ': return 22;
        case u'ف': return 23;
        case u'ق': return 24;
        case u'ک': return 25;
        case u'گ': return 26;
        case u'ل': return 27;
        case u'م': return 28;
        case u'ن': return 29;
        case u'و': return 30;
        case u'ه': return 31;
        case u'ی': return 32;
        
        default : return 32;
    }
}

// چپطظگکمنتلبیسشجحخهعغفقثصض true
// ودذرزژا false
bool canMergeToForward(char16_t c){
    
    switch (c){

    case u'و': return false;
    case u'د': return false;
    case u'ذ': return false;
    case u'ر': return false;
    case u'ز': return false;
    case u'ژ': return false;
    case u'ا': return false;
    case u' ': return false;
    
    default: return true;

    }
}

// false for " " , true for others
bool canMergeToBack(char16_t c){
    
    if(c == ' ') return false;
    else return true;
}


// Extract the characters from the text string
void printStringWithShift(char16_t *s){

    // detect if text is persian
    // this will not support mixed persian and english text

    
    
    bool isFirstChar = true;

    if (*s >= 1000){// persian text

        Serial.println("persian");
        while (*s != 0){
//          Serial.println(*s);

              if(isFirstChar){// first char
                   printPersianCharWithShift(*s ,false  ,canMergeToBack( *(s+1) ));
                   isFirstChar = false;

                   
              }else if(*(s+1) == 0){// last char
                  printPersianCharWithShift(*s ,canMergeToForward(*(s-1))  ,false );


              }else{// other chars
                  printPersianCharWithShift(*s ,canMergeToForward(*(s-1))  ,canMergeToBack(*(s+1)));
              }
            s++;
        }
    } else{ // english text

        Serial.println("english");
        while (*s != 0){
          
            printCharWithShift(*s);
            s++;
        }
    }
}

