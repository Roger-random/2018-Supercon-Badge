///////////////////////////////////////////////////////////////////////////////
// Badge Nyancat demo: an adaptation of the (in)famous internet meme
//
// This is an animation that plays at full screen while playing a simplified
// rendition of the video soundtrack.
//
// Pressing '0' on the keyboard mutes the music while animation continues.
// Pressing '9' on the keyboard restarts music if muted, otherwise no effect.
//
// The animation data encoded below is only at 80x60 resolution to conserve
// space. For playback, each pixel is scaled up to fit the full 320x240
// screen resolution.
//
// The music was translated from sheet music by a contributor on musescore.com
//   https://musescore.com/user/179139/scores/170886

#ifndef		__NYANCAT_H
#define		__NYANCAT_H

#include "badge.h"

#ifdef NYANCAT_DEMO

///////////////////////////////////////////////////////////////////////////////
// Entry point to start playing
void nyancat(void);

///////////////////////////////////////////////////////////////////////////////
// Music information to play nyancat song

#define NYANCAT_SEQUENCES 16 // Sequence of measures in music loop
#define NYANCAT_MEASURES 9   // Number of unique measures in the song

// Time duration (in milliseconds) referenced from nyancat_measure below
const uint8_t nyancat_durations[2] = {
    105, // sixteenth
    210, // eighth
};

// Array size for each of the arrays holding music measures
const uint8_t nyancat_measure_limits[NYANCAT_MEASURES] = {
  33,45,42,36,39,42,39,39,39
};

// Measures in the song. Each beat in the measure is separated by a blank line
// Each line has three entires. The first two are notes to be played
// simultaneously denoted in Scientific Pitch Notation
// (https://en.wikipedia.org/wiki/Scientific_pitch_notation)
// The third number is an index into nyancat_durations[] array which is the
// time (in milliseconds) to hold those two notes. This allows music tempo to
// be adjusted with few code changes.

const uint8_t nyancat_measure0[33] = {
    41,79,1,
    53,81,1,

    43,75,0,
    43,76,0,
    55,76,0,
    55,72,0,

    40,75,0,
    40,74,0,
    52,72,1,

    45,72,1,
    57,74,1,
};

const uint8_t nyancat_measure1[45] = {
    38,75,1,
    50,76,0,
    50,74,0,

    43,72,0,
    43,74,0,
    55,76,0,
    55,79,0,

    36,81,0,
    36,76,0,
    48,79,0,
    48,74,0,

    36,76,0,
    36,72,0,
    48,74,0,
    48,72,0,
};

const uint8_t nyancat_measure2[42] = {
    41,76,1,
    53,79,1,

    43,81,0,
    43,76,0,
    55,79,0,
    55,74,0,

    40,76,0,
    40,72,0,
    52,75,0,
    52,76,0,

    45,75,0,
    45,74,0,
    57,72,0,
    57,74,0,
};

const uint8_t nyancat_measure3[36] = {
    38,75,1,
    50,72,0,
    50,74,0,

    43,76,0,
    43,79,0,
    55,74,0,
    55,76,0,

    36,74,0,
    36,72,0,
    48,74,1,

    36,72,1,
    48,74,1,
};

const uint8_t nyancat_measure4[39] = {
    53,72,1,
    57,67,1,

    60,72,1,
    65,67,0,
    65,69,0,

    52,72,0,
    52,74,0,
    55,76,0,
    55,72,0,

    60,77,0,
    60,76,0,
    64,77,0,
    64,79,0,
};

const uint8_t nyancat_measure5[42] = {
    50,72,1,
    53,72,1,

    57,67,0,
    57,69,0,
    62,72,0,
    62,67,0,

    48,77,0,
    48,76,0,
    52,74,0,
    52,72,0,

    55,67,0,
    55,64,0,
    60,65,0,
    60,67,0,
};

const uint8_t nyancat_measure6[39] = {
    53,72,1,
    57,67,0,
    57,69,0,

    60,72,1,
    65,67,0,
    65,69,0,

    52,72,1,
    55,74,0,
    55,76,0,

    60,72,0,
    60,67,0,
    64,69,0,
    64,67,0,
};

const uint8_t nyancat_measure7[39] = {
    50,72,1,
    53,72,0,
    53,71,0,

    57,72,0,
    57,67,0,
    62,69,0,
    62,72,0,

    48,77,0,
    48,76,0,
    52,77,0,
    52,79,0,

    55,72,1,
    60,71,1,
};

const uint8_t nyancat_measure8[39] = {
    50,72,1,
    53,72,0,
    53,71,0,

    57,72,0,
    57,67,0,
    62,69,0,
    62,72,0,

    48,77,0,
    48,76,0,
    52,77,0,
    52,79,0,

    55,72,1,
    60,74,1,
};

// Assemble the measures above into a single array of all measures in the song.
const uint8_t* nyancat_measures[NYANCAT_MEASURES] = {
    nyancat_measure0,
    nyancat_measure1,
    nyancat_measure2,
    nyancat_measure3,
    nyancat_measure4,
    nyancat_measure5,
    nyancat_measure6,
    nyancat_measure7,
    nyancat_measure8,
};

// The song plays its measures in this sequence, looping infinitely
const uint8_t nyancat_sequence[NYANCAT_SEQUENCES] = {
    0,1,2,3,0,1,2,3,4,5,6,7,4,5,6,8
};

///////////////////////////////////////////////////////////////////////////////
// Run-length encoded version of poptartcat.gif animation in 80x60 resolution

// Color palette used in the animation, each entry in 0x00RRGGBB format.
const uint32_t cat4_palette[14] = {
  0x00FFFFFF,
  0x00FFFF00,
  0x00FFCC99,
  0x0033FF00,
  0x00FF99FF,
  0x00FF9999,
  0x00FF9900,
  0x00999999,
  0x000099FF,
  0x00FF3399,
  0x006633FF,
  0x00FF0000,
  0x00003366,
  0x00000000,
};

///////////////////////////////////////////////////////////////////////////////
// Run-length encoded data for each frame in the animation. Each encoding entry
// consists of a 4-bit index into the palette followed by 8-bit length of
// pixels of that color.
//
// Example: 0xC4E means there is a run of 0x4E pixels all of the color at
//          palette index 0xC.
//
// Since each encoding entry takes 12 bits (4 bit palette index, 8 bit length)
// They do not pack nicely in a byte array. Extracting this data requires a lot
// of bitwise manipulators and isn't terribly easy to read.
//
// Example: The first three bytes of frame0 are 0xC4, 0xE0, 0x01. This
//          represents two runs.
//
//          0xC4E = 0x4E pixels of color in palette index 0xC (0x00003366)
//          0x001 = 1 pixel of color in palette index 0 (0x00FFFFFF)
//
// Thanks to the blocky nature of nyancat animation, a super simple run length
// encoding compresses nearly as much as GIF and far simpler to decode.

const uint8_t cat4_frame0[507] = {
  0xC4,0xE0,0x01,0xC0,0x1C,0x50,0xC4,0xB0,0x02,0xC0,0x10,0x01,0xC0,0x1C,0x50,
  0xC4,0xE0,0x01,0xC0,0x1C,0x4E,0x00,0x1C,0x01,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC0,0x20,0x01,0xC4,0xDC,0x02,0x00,0x1C,0x4D,
  0x00,0x2C,0x01,0x00,0x1C,0x4C,0xC0,0x20,0x01,0xC4,0xDC,0x50,0xC1,0xFD,0x14,
  0xC1,0xDC,0x04,0xB0,0x9C,0x09,0xB0,0x8D,0x01,0x21,0x4D,0x01,0xC1,0xCB,0x1D,
  0xD0,0x12,0x04,0x40,0xE2,0x04,0xD0,0x1C,0x1B,0xB1,0xDD,0x01,0x20,0x24,0x07,
  0x90,0x14,0x03,0x90,0x14,0x06,0x20,0x2D,0x01,0xC1,0xBB,0x1D,0xD0,0x12,0x02,
  0x40,0x79,0x01,0x40,0x39,0x01,0x40,0x62,0x02,0xD0,0x1C,0x1B,0xB0,0x46,0x09,
  0xB0,0x96,0x07,0xD0,0x12,0x01,0x40,0x39,0x01,0x41,0x02,0x01,0xD0,0x1C,0x1B,
  0x61,0xDD,0x01,0x20,0x14,0x0C,0xD0,0x24,0x02,0x90,0x14,0x03,0x20,0x1D,0x01,
  0xC0,0x1D,0x02,0xC1,0x86,0x1D,0xD0,0x12,0x01,0x40,0xBD,0x01,0x70,0x2D,0x01,
  0x40,0x52,0x01,0xD0,0x27,0x02,0xD0,0x2C,0x16,0x60,0x41,0x09,0x60,0x9D,0x05,
  0x10,0x2D,0x01,0x20,0x14,0x07,0x90,0x14,0x03,0xD0,0x17,0x03,0xD0,0x14,0x04,
  0x20,0x1D,0x01,0x70,0x3D,0x02,0xC1,0x61,0x16,0xD0,0x17,0x03,0xD0,0x21,0x01,
  0xD0,0x12,0x01,0x40,0xBD,0x01,0x70,0x4D,0x05,0x70,0x4D,0x02,0xC1,0x61,0x16,
  0xD0,0x27,0x03,0xD0,0x32,0x01,0x40,0x49,0x01,0x40,0x6D,0x01,0x70,0xDD,0x02,
  0xC1,0x61,0x04,0x30,0x91,0x09,0x30,0x1D,0x03,0x70,0x2D,0x02,0x20,0x14,0x08,
  0x90,0x1D,0x02,0x71,0x0D,0x01,0xC1,0x53,0x17,0xD0,0x37,0x02,0xD0,0x22,0x01,
  0x40,0x89,0x01,0xD0,0x27,0x10,0xD0,0x1C,0x15,0x31,0x8D,0x03,0x70,0x2D,0x01,
  0x20,0x14,0x01,0x90,0x24,0x06,0xD0,0x27,0x03,0x00,0x1D,0x01,0x70,0x60,0x01,
  0xD0,0x17,0x03,0xD0,0x1C,0x15,0x31,0xAD,0x04,0x20,0x14,0x09,0xD0,0x27,0x03,
  0xD0,0x27,0x04,0xD0,0x17,0x01,0xD0,0x27,0x03,0xD0,0x1C,0x15,0x30,0x48,0x09,
  0x30,0x98,0x06,0xD0,0x22,0x01,0x40,0x69,0x01,0x40,0x2D,0x02,0x70,0x15,0x02,
  0x70,0xA5,0x03,0xD0,0x1C,0x15,0x81,0xDD,0x01,0x20,0x24,0x02,0x90,0x14,0x05,
  0xD0,0x27,0x01,0x50,0x27,0x01,0xD0,0x17,0x03,0xD0,0x17,0x02,0xD0,0x17,0x01,
  0x50,0x3D,0x01,0xC1,0x58,0x1D,0xD0,0x12,0x04,0x40,0x8D,0x01,0x70,0x3D,0x08,
  0x70,0x2D,0x02,0xC1,0x68,0x04,0xA0,0x90,0x01,0x80,0x8A,0x06,0xD0,0x32,0x0C,
  0xD0,0x17,0x0B,0xD0,0x1C,0x18,0xA1,0xBD,0x01,0x70,0x3D,0x18,0xC1,0x9A,0x1B,
  0xD0,0x17,0x03,0xD1,0x8C,0x19,0xA1,0xBD,0x01,0x70,0x2D,0x02,0xC0,0x2D,0x01,
  0x70,0x2D,0x01,0xC0,0x6D,0x01,0x70,0x2D,0x01,0xC0,0x2D,0x01,0x70,0x2D,0x01,
  0xC1,0xAA,0x04,0xC0,0x60,0x01,0xC0,0x2A,0x03,0x00,0x2A,0x04,0xC0,0x5D,0x04,
  0xC0,0x3D,0x03,0xC0,0x8D,0x03,0xC0,0x3D,0x02,0xC1,0xBC,0x50,0xC5,0x0C,0x0D,
  0x00,0x1C,0x42,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x4F,0x00,0x1C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
};

const uint8_t cat4_frame1[512] = {
  0xC4,0x30,0x01,0xC0,0x30,0x01,0xC0,0x8C,0x50,0xC4,0x20,0x01,0xC0,0x50,0x02,
  0xC0,0x6C,0x50,0xC4,0x30,0x01,0xC0,0x30,0x01,0xC0,0x8C,0x45,0x00,0x1C,0x0A,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x1F,0xD1,0x4C,0x1D,0xC0,0x4B,0x09,0xC0,0x9B,0x08,
  0xD0,0x12,0x14,0xD0,0x1C,0x1C,0xB1,0xDD,0x01,0x20,0x44,0x0E,0x20,0x4D,0x01,
  0xC1,0xBB,0x1D,0xD0,0x12,0x02,0x40,0x79,0x01,0x40,0x39,0x01,0x40,0x62,0x02,
  0xD0,0x1C,0x1B,0xB1,0xDD,0x01,0x20,0x24,0x07,0x90,0x14,0x03,0x90,0x14,0x06,
  0x20,0x2D,0x01,0xC1,0xBB,0x04,0x60,0x9B,0x09,0x60,0x7D,0x01,0x20,0x14,0x03,
  0x90,0x14,0x10,0x20,0x1D,0x01,0xC1,0xB6,0x1D,0xD0,0x12,0x01,0x40,0xDD,0x02,
  0x40,0x19,0x01,0x40,0x32,0x01,0xD0,0x1C,0x02,0xD0,0x3C,0x16,0x61,0xDD,0x01,
  0x20,0x14,0x0C,0xD0,0x17,0x02,0xD0,0x14,0x04,0x20,0x1D,0x01,0xC0,0x1D,0x01,
  0x70,0x3D,0x01,0xC1,0x56,0x04,0x10,0x96,0x09,0x10,0x7D,0x01,0x20,0x14,0x07,
  0x90,0x14,0x04,0xD0,0x17,0x03,0xD0,0x14,0x03,0x20,0x1D,0x02,0x70,0x4D,0x01,
  0xC1,0x51,0x17,0xD0,0x31,0x03,0xD0,0x12,0x01,0x40,0xCD,0x01,0x70,0x4D,0x05,
  0x70,0x5D,0x01,0xC1,0x51,0x16,0xD0,0x17,0x03,0xD0,0x11,0x02,0xD0,0x12,0x01,
  0x40,0x49,0x01,0x40,0x7D,0x01,0x70,0xED,0x01,0xC1,0x51,0x04,0x30,0x91,0x09,
  0xD0,0x17,0x03,0xD0,0x42,0x01,0x40,0x89,0x01,0x40,0x2D,0x01,0x71,0x0D,0x01,
  0xC1,0x43,0x16,0xD0,0x17,0x03,0xD0,0x42,0x01,0x40,0x89,0x01,0x40,0x2D,0x01,
  0x70,0x30,0x01,0xD0,0x17,0x06,0x00,0x1D,0x01,0x70,0x3D,0x01,0xC1,0x43,0x17,
  0xD0,0x17,0x05,0xD0,0x12,0x01,0x40,0x19,0x02,0x40,0x8D,0x01,0x70,0x30,0x01,
  0xD0,0x17,0x06,0x00,0x1D,0x01,0x70,0x3D,0x01,0xC1,0x43,0x18,0xD0,0x37,0x02,
  0xD0,0x12,0x01,0x40,0xBD,0x01,0x70,0x3D,0x02,0x70,0x4D,0x01,0x70,0x1D,0x02,
  0x70,0x3D,0x01,0xC1,0x43,0x04,0x80,0x93,0x09,0x80,0x5D,0x03,0x20,0x14,0x06,
  0x90,0x14,0x04,0xD0,0x17,0x01,0x50,0x27,0x0A,0x50,0x3D,0x01,0xC1,0x48,0x1D,
  0xD0,0x12,0x02,0x40,0x29,0x01,0x40,0x7D,0x01,0x70,0x15,0x02,0x70,0x1D,0x01,
  0x70,0x3D,0x01,0x70,0x2D,0x01,0x70,0x15,0x03,0xD0,0x1C,0x14,0x81,0xDD,0x01,
  0x20,0x44,0x09,0xD0,0x17,0x03,0xD0,0x87,0x03,0xD0,0x1C,0x15,0x80,0x4A,0x09,
  0x80,0x9A,0x07,0xD0,0x22,0x0D,0xD0,0x17,0x0B,0xD0,0x2C,0x16,0xA1,0xCD,0x01,
  0x70,0x2D,0x19,0xC1,0x8A,0x1C,0xD0,0x17,0x02,0xD1,0x4C,0x1D,0xA1,0xCD,0x01,
  0x70,0x2D,0x01,0xC0,0x2D,0x01,0x70,0x2D,0x01,0xC0,0x7D,0x01,0x70,0x2D,0x02,
  0xC0,0x1D,0x01,0x70,0x2D,0x01,0xC1,0x9A,0x04,0xC0,0x20,0x01,0xC0,0x6A,0x09,
  0xC0,0x6D,0x03,0xC0,0x4D,0x03,0xC0,0x8D,0x04,0xC0,0x2D,0x03,0xC1,0x9C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x4C,0x00,0x1C,0x03,0xC4,0xC0,0x01,0xC0,0x3C,0x50,0xC5,0x0C,0x50,
  0xC5,0x00,
};

const uint8_t cat4_frame2[506] = {
  0xC5,0x0C,0x50,0xC3,0x80,0x02,0xC0,0x50,0x01,0xC1,0x0C,0x50,0xC5,0x0C,0x3C,
  0x00,0x1C,0x13,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC4,0xF0,0x01,
  0xC4,0xF0,0x01,0xC5,0x0C,0x50,0xC4,0xC0,0x02,0xC0,0x10,0x01,0xC5,0x0C,0x4F,
  0x00,0x1C,0x4F,0x00,0x1B,0x03,0xC0,0x9B,0x09,0xC0,0xAD,0x14,0xC1,0xDB,0x1E,
  0xD0,0x12,0x14,0xD0,0x1C,0x1C,0xB1,0xDD,0x01,0x20,0x44,0x0E,0x20,0x4D,0x01,
  0xC1,0xBB,0x1D,0xD0,0x12,0x04,0x40,0xE2,0x04,0xD0,0x1C,0x1B,0x60,0x3B,0x09,
  0x60,0x9B,0x08,0xD0,0x12,0x02,0x40,0x79,0x01,0x40,0x39,0x01,0x40,0x62,0x02,
  0xD0,0x1C,0x1B,0x61,0xDD,0x01,0x20,0x14,0x03,0x90,0x14,0x10,0x20,0x1D,0x01,
  0xC1,0xB6,0x1D,0xD0,0x12,0x01,0x40,0xDD,0x02,0x40,0x19,0x01,0x40,0x32,0x01,
  0xD0,0x1C,0x02,0xD0,0x3C,0x16,0x10,0x36,0x09,0x10,0x96,0x08,0xD0,0x12,0x01,
  0x40,0xCD,0x01,0x70,0x2D,0x01,0x40,0x42,0x01,0xD0,0x1C,0x01,0xD0,0x17,0x03,
  0xD0,0x1C,0x15,0x11,0xDD,0x01,0x20,0x14,0x07,0x90,0x14,0x04,0xD0,0x17,0x03,
  0xD0,0x14,0x03,0x20,0x1D,0x02,0x70,0x4D,0x01,0xC1,0x51,0x1D,0xD0,0x12,0x01,
  0x40,0xCD,0x01,0x70,0x4D,0x05,0x70,0x5D,0x01,0xC1,0x53,0x03,0x10,0x93,0x09,
  0x10,0x8D,0x01,0x20,0x14,0x04,0x90,0x14,0x07,0xD0,0x17,0x0E,0xD0,0x1C,0x15,
  0x31,0xDD,0x01,0x20,0x14,0x04,0x90,0x14,0x07,0xD0,0x17,0x0E,0xD0,0x1C,0x15,
  0x31,0xCD,0x02,0x20,0x14,0x08,0x90,0x14,0x02,0xD0,0x17,0x10,0xD0,0x1C,0x14,
  0x31,0x8D,0x06,0x20,0x14,0x01,0x90,0x24,0x08,0xD0,0x17,0x03,0x00,0x1D,0x01,
  0x70,0x60,0x01,0xD0,0x17,0x03,0xD0,0x1C,0x14,0x80,0x33,0x09,0x80,0x93,0x01,
  0xD0,0x27,0x05,0xD0,0x12,0x01,0x40,0xBD,0x01,0x70,0x3D,0x02,0x70,0x4D,0x01,
  0x70,0x1D,0x02,0x70,0x3D,0x01,0xC1,0x48,0x16,0xD0,0x17,0x04,0xD0,0x32,0x01,
  0x40,0x69,0x01,0x40,0x4D,0x01,0x70,0x15,0x02,0x70,0xA5,0x03,0xD0,0x1C,0x14,
  0x81,0x7D,0x05,0x80,0x1D,0x01,0x20,0x24,0x02,0x90,0x14,0x07,0xD0,0x17,0x01,
  0x50,0x27,0x01,0xD0,0x17,0x03,0xD0,0x17,0x02,0xD0,0x17,0x01,0x50,0x3D,0x01,
  0xC1,0x4A,0x03,0x80,0x9A,0x09,0x80,0x8D,0x01,0x20,0x44,0x09,0xD0,0x17,0x03,
  0xD0,0x87,0x03,0xD0,0x1C,0x15,0xA1,0xDD,0x02,0x20,0xDD,0x01,0x70,0xBD,0x02,
  0xC1,0x6A,0x1D,0xD0,0x22,0x0D,0xD0,0x17,0x0B,0xD0,0x2C,0x16,0xA0,0x20,0x01,
  0xA1,0xAD,0x01,0x70,0x1D,0x19,0xC1,0x80,0x02,0xC0,0x10,0x01,0xA0,0x8C,0x09,
  0xA0,0x8D,0x01,0x70,0x2D,0x02,0xC0,0x1D,0x01,0x70,0x2D,0x01,0xC0,0x7D,0x01,
  0x70,0x3D,0x01,0xC0,0x1D,0x01,0x70,0x2D,0x01,0xC1,0x8C,0x02,0x00,0x1C,0x1A,
  0xD0,0x3C,0x04,0xD0,0x3C,0x08,0xD0,0x4C,0x02,0xD0,0x3C,0x18,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC4,0x50,0x01,0xC0,0xAC,0x50,
  0xC5,0x0C,0x42,0x00,0x1C,0x05,0x00,0x2C,0x06,0xC4,0x20,0x01,0xC0,0x50,0x02,
  0xC0,0x6C,0x50,0xC5,0x0C,0x45,0x00,0x1C,0x0A,0xC5,0x00,
};

const uint8_t cat4_frame3[525] = {
  0xC5,0x0C,0x50,0xC3,0x50,0x01,0xC1,0xAC,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC4,0x60,0x01,0xC0,0x9C,0x44,0x00,0x1C,0x03,
  0x00,0x1C,0x07,0xC5,0x0C,0x50,0xC4,0x30,0x01,0xC0,0x50,0x02,0xC0,0x5C,0x50,
  0xC4,0x40,0x01,0xC0,0x30,0x01,0xC0,0x7C,0x46,0x00,0x1C,0x09,0xB0,0x3C,0x09,
  0xB0,0x9C,0x0A,0xD1,0x4C,0x1D,0xB1,0xED,0x01,0x21,0x4D,0x01,0xC1,0xCB,0x1D,
  0xD0,0x12,0x04,0x40,0xE2,0x04,0xD0,0x1C,0x1B,0xB1,0xDD,0x01,0x20,0x44,0x0E,
  0x20,0x4D,0x01,0xC1,0xB6,0x03,0xB0,0x96,0x09,0xB0,0x8D,0x01,0x20,0x24,0x07,
  0x90,0x14,0x03,0x90,0x14,0x06,0x20,0x2D,0x01,0xC1,0xB6,0x1D,0xD0,0x12,0x01,
  0x40,0x39,0x01,0x41,0x02,0x01,0xD0,0x1C,0x1B,0x61,0xDD,0x01,0x20,0x14,0x0D,
  0xD0,0x24,0x01,0x90,0x14,0x03,0x20,0x1D,0x01,0xC0,0x2D,0x03,0xC1,0x61,0x03,
  0x60,0x91,0x09,0x60,0x8D,0x01,0x20,0x14,0x0C,0xD0,0x17,0x02,0xD0,0x14,0x04,
  0x20,0x1D,0x01,0xC0,0x1D,0x01,0x70,0x3D,0x01,0xC1,0x51,0x1D,0xD0,0x12,0x01,
  0x40,0x79,0x01,0x40,0x4D,0x01,0x70,0x3D,0x01,0x40,0x32,0x01,0xD0,0x27,0x04,
  0xD0,0x1C,0x15,0x11,0xDD,0x01,0x20,0x14,0x0C,0xD0,0x17,0x04,0xD0,0x57,0x05,
  0xD0,0x1C,0x15,0x30,0x31,0x09,0x30,0x91,0x08,0xD0,0x12,0x01,0x40,0x49,0x01,
  0x40,0x7D,0x01,0x70,0xED,0x01,0xC1,0x53,0x1D,0xD0,0x12,0x01,0x40,0x49,0x01,
  0x40,0x7D,0x01,0x70,0xED,0x01,0xC1,0x53,0x1B,0xD0,0x32,0x01,0x40,0x89,0x01,
  0x40,0x2D,0x01,0x71,0x0D,0x01,0xC1,0x43,0x18,0xD0,0x37,0x02,0xD0,0x12,0x01,
  0x40,0x19,0x02,0x40,0x8D,0x01,0x70,0x30,0x01,0xD0,0x17,0x06,0x00,0x1D,0x01,
  0x70,0x3D,0x01,0xC1,0x48,0x03,0x30,0x98,0x09,0x30,0x2D,0x01,0x70,0x5D,0x01,
  0x20,0x14,0x0B,0xD0,0x17,0x03,0xD0,0x27,0x04,0xD0,0x17,0x01,0xD0,0x27,0x03,
  0xD0,0x1C,0x14,0x81,0x6D,0x01,0x70,0x3D,0x04,0x20,0x14,0x06,0x90,0x14,0x04,
  0xD0,0x17,0x01,0x50,0x27,0x0A,0x50,0x3D,0x01,0xC1,0x48,0x16,0xD0,0x17,0x03,
  0xD0,0x18,0x02,0xD0,0x12,0x02,0x40,0x29,0x01,0x40,0x7D,0x01,0x70,0x15,0x02,
  0x70,0x1D,0x01,0x70,0x3D,0x01,0x70,0x2D,0x01,0x70,0x15,0x03,0xD0,0x1C,0x14,
  0xA0,0x38,0x09,0xA0,0x98,0x02,0xD0,0x38,0x03,0xD0,0x12,0x04,0x40,0x9D,0x01,
  0x70,0x3D,0x08,0x70,0x3D,0x01,0xC1,0x5A,0x1D,0xD0,0x22,0x0D,0xD0,0x17,0x0B,
  0xD0,0x2C,0x16,0xA1,0xDD,0x02,0x20,0xDD,0x01,0x70,0xBD,0x02,0xC1,0x6A,0x1C,
  0xD0,0x17,0x02,0xD1,0x9C,0x18,0xC0,0x3A,0x09,0xC0,0x9A,0x07,0xD0,0x17,0x02,
  0xD0,0x1C,0x02,0xD0,0x17,0x02,0xD0,0x1C,0x07,0xD0,0x17,0x02,0xD0,0x2C,0x01,
  0xD0,0x17,0x02,0xD0,0x1C,0x19,0xC1,0xCD,0x03,0xC0,0x4D,0x03,0xC0,0x8D,0x04,
  0xC0,0x2D,0x03,0xC1,0x9C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x3B,0x00,0x1C,0x14,0xC3,0x80,0x01,0xC0,0x40,0x01,0xC1,0x2C,0x50,
  0xC3,0x70,0x01,0xC0,0x60,0x01,0xC1,0x1C,0x37,0x00,0x1C,0x06,0x00,0x1C,0x11,
  0xC5,0x0C,0x38,0x00,0x1C,0x04,0x00,0x1C,0x12,0xC3,0xB0,0x01,0xC1,0x4C,0x50,
  
};

const uint8_t cat4_frame4[513] = {
  0xC5,0x0C,0x30,0x00,0x1C,0x1F,0xC2,0xF0,0x01,0xC0,0x10,0x02,0xC1,0xDC,0x30,
  0x00,0x1C,0x1F,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC3,0xD0,0x01,0xC1,0x2C,0x50,0xC5,0x0C,0x50,0xC3,0xA0,0x01,0xC0,0x50,0x02,
  0xC0,0xEC,0x50,0xC5,0x0C,0x3D,0x00,0x1C,0x12,0xC0,0x4B,0x09,0xC0,0x9B,0x09,
  0xD1,0x4C,0x1D,0xB1,0xED,0x01,0x21,0x4D,0x01,0xC1,0xCB,0x1D,0xD0,0x12,0x04,
  0x40,0xE2,0x04,0xD0,0x1C,0x1B,0xB1,0xDD,0x01,0x20,0x44,0x0E,0x20,0x4D,0x01,
  0xC1,0xBB,0x04,0x60,0x9B,0x09,0x60,0x7D,0x01,0x20,0x24,0x07,0x90,0x14,0x03,
  0x90,0x14,0x06,0x20,0x2D,0x01,0xC1,0xB6,0x1D,0xD0,0x12,0x01,0x40,0x39,0x01,
  0x41,0x02,0x01,0xD0,0x1C,0x1B,0x61,0xDD,0x01,0x20,0x14,0x0C,0xD0,0x24,0x02,
  0x90,0x14,0x03,0x20,0x1D,0x01,0xC0,0x1D,0x02,0xC1,0x86,0x04,0x10,0x96,0x09,
  0x10,0x7D,0x01,0x20,0x14,0x0B,0xD0,0x17,0x02,0xD0,0x14,0x05,0x20,0x1D,0x02,
  0x70,0x2D,0x02,0xC1,0x61,0x1D,0xD0,0x12,0x01,0x40,0x79,0x01,0x40,0x3D,0x01,
  0x70,0x3D,0x01,0x40,0x42,0x01,0xD0,0x17,0x03,0xD0,0x2C,0x16,0x11,0x6D,0x05,
  0x10,0x2D,0x01,0x20,0x14,0x0B,0xD0,0x17,0x04,0xD0,0x57,0x04,0xD0,0x2C,0x16,
  0x10,0x43,0x09,0x10,0x8D,0x01,0x70,0x4D,0x04,0x20,0x14,0x04,0x90,0x14,0x06,
  0xD0,0x17,0x0D,0xD0,0x2C,0x16,0x31,0x5D,0x02,0x70,0x5D,0x02,0x20,0x14,0x04,
  0x90,0x14,0x06,0xD0,0x17,0x0D,0xD0,0x2C,0x16,0x31,0x5D,0x02,0x70,0x5D,0x02,
  0x20,0x14,0x08,0x90,0x1D,0x02,0x71,0x0D,0x01,0xC1,0x53,0x17,0xD0,0x57,0x01,
  0xD0,0x12,0x01,0x40,0x19,0x02,0x40,0x6D,0x02,0x70,0x30,0x01,0xD0,0x17,0x06,
  0x00,0x1D,0x01,0x70,0x3D,0x01,0xC1,0x53,0x04,0x80,0x93,0x09,0x80,0x5D,0x03,
  0x20,0x14,0x09,0xD0,0x27,0x03,0xD0,0x27,0x04,0xD0,0x17,0x01,0xD0,0x27,0x03,
  0xD0,0x1C,0x15,0x81,0xDD,0x01,0x20,0x14,0x06,0x90,0x14,0x02,0xD0,0x27,0x01,
  0x50,0x27,0x0A,0x50,0x3D,0x01,0xC1,0x58,0x1D,0xD0,0x12,0x02,0x40,0x29,0x01,
  0x40,0x5D,0x02,0x70,0x15,0x02,0x70,0x1D,0x01,0x70,0x3D,0x01,0x70,0x2D,0x01,
  0x70,0x15,0x03,0xD0,0x1C,0x15,0x80,0x4A,0x09,0x80,0x9A,0x06,0xD0,0x22,0x04,
  0x40,0x8D,0x01,0x70,0x3D,0x08,0x70,0x2D,0x02,0xC1,0x6A,0x1B,0xD0,0x42,0x0C,
  0xD0,0x17,0x0B,0xD0,0x1C,0x18,0xA1,0xBD,0x04,0x20,0xCD,0x01,0x70,0xBD,0x01,
  0xC1,0x8A,0x1A,0xD0,0x17,0x03,0xD1,0x9C,0x19,0xA0,0x4C,0x09,0xA0,0x9C,0x04,
  0xD0,0x17,0x02,0xD0,0x1C,0x01,0xD0,0x17,0x03,0xD0,0x1C,0x07,0xD0,0x17,0x02,
  0xD0,0x1C,0x01,0xD0,0x27,0x02,0xD0,0x1C,0x1B,0xC1,0xAD,0x03,0xC0,0x3D,0x04,
  0xC0,0x8D,0x03,0xC0,0x3D,0x03,0xC1,0xBC,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x30,0x00,0x2C,0x1E,0xC3,0x00,0x02,0xC1,0xEC,0x50,
  0xC2,0xD0,0x02,0xC0,0x10,0x02,0xC0,0x10,0x02,0xC1,0xBC,0x2D,0x00,0x2C,0x01,
  0x00,0x2C,0x01,0x00,0x2C,0x1B,0xC5,0x0C,0x30,0x00,0x2C,0x1E,0xC3,0x00,0x02,
  0xC1,0xEC,0x50,
};

const uint8_t cat4_frame5[534] = {
  0xC2,0x90,0x02,0xC2,0x5C,0x29,0x00,0x2C,0x25,0xC2,0x70,0x02,0xC0,0x20,0x02,
  0xC2,0x3C,0x29,0x00,0x2C,0x25,0xC2,0x90,0x02,0xC2,0x5C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC3,0x60,0x01,
  0xC1,0x9C,0x50,0xC5,0x0C,0x50,0xC0,0x4B,0x09,0xC0,0x9B,0x09,0xD1,0x4C,0x1D,
  0xB1,0xED,0x01,0x21,0x4D,0x01,0xC1,0xCB,0x1D,0xD0,0x12,0x04,0x40,0xE2,0x04,
  0xD0,0x1C,0x1B,0xB1,0xDD,0x01,0x20,0x44,0x0E,0x20,0x4D,0x01,0xC1,0xBB,0x04,
  0x60,0x9B,0x09,0x60,0x7D,0x01,0x20,0x24,0x07,0x90,0x14,0x03,0x90,0x14,0x06,
  0x20,0x2D,0x01,0xC1,0xB6,0x1D,0xD0,0x12,0x01,0x40,0x39,0x01,0x40,0x8D,0x02,
  0x40,0x62,0x01,0xD0,0x1C,0x01,0xD0,0x2C,0x18,0x61,0xDD,0x01,0x20,0x14,0x0B,
  0xD0,0x17,0x02,0xD0,0x14,0x01,0x90,0x14,0x03,0x20,0x1D,0x02,0x70,0x2D,0x02,
  0xC1,0x66,0x04,0x10,0x96,0x09,0x10,0x7D,0x01,0x20,0x14,0x0B,0xD0,0x17,0x03,
  0xD0,0x14,0x04,0x20,0x1D,0x01,0x70,0x3D,0x02,0xC1,0x61,0x17,0xD0,0x31,0x03,
  0xD0,0x12,0x01,0x40,0x79,0x01,0x40,0x3D,0x01,0x70,0x4D,0x05,0x70,0x4D,0x02,
  0xC1,0x61,0x16,0xD0,0x17,0x03,0xD0,0x11,0x02,0xD0,0x12,0x01,0x40,0xBD,0x01,
  0x70,0xDD,0x02,0xC1,0x61,0x04,0x30,0x91,0x09,0xD0,0x17,0x03,0xD0,0x42,0x01,
  0x40,0x49,0x01,0x40,0x4D,0x02,0x71,0x0D,0x01,0xC1,0x53,0x16,0xD0,0x17,0x03,
  0xD0,0x42,0x01,0x40,0x49,0x01,0x40,0x4D,0x02,0x70,0x30,0x01,0xD0,0x17,0x06,
  0x00,0x1D,0x01,0x70,0x3D,0x01,0xC1,0x53,0x17,0xD0,0x17,0x05,0xD0,0x12,0x01,
  0x40,0x89,0x01,0xD0,0x27,0x03,0x00,0x1D,0x01,0x70,0x60,0x01,0xD0,0x17,0x03,
  0xD0,0x1C,0x15,0x31,0x8D,0x03,0x70,0x2D,0x01,0x20,0x14,0x01,0x90,0x24,0x06,
  0xD0,0x27,0x03,0xD0,0x27,0x04,0xD0,0x17,0x01,0xD0,0x27,0x03,0xD0,0x1C,0x15,
  0x30,0x48,0x09,0x30,0x98,0x05,0xD0,0x32,0x01,0x40,0x9D,0x02,0x70,0x15,0x02,
  0x70,0xA5,0x03,0xD0,0x1C,0x15,0x81,0xDD,0x01,0x20,0x14,0x06,0x90,0x14,0x02,
  0xD0,0x27,0x01,0x50,0x27,0x01,0xD0,0x17,0x03,0xD0,0x17,0x02,0xD0,0x17,0x01,
  0x50,0x3D,0x01,0xC1,0x58,0x1D,0xD0,0x12,0x02,0x40,0x29,0x01,0x40,0x7D,0x01,
  0x70,0x3D,0x08,0x70,0x2D,0x02,0xC1,0x68,0x04,0xA0,0x98,0x09,0xA0,0x6D,0x02,
  0x20,0x44,0x09,0xD0,0x17,0x0B,0xD0,0x1C,0x17,0x00,0x1A,0x1B,0xD0,0x17,0x01,
  0xD0,0x22,0x0D,0xD0,0xBC,0x18,0x00,0x1A,0x1B,0xD0,0x17,0x01,0xD0,0x22,0x14,
  0xD0,0x1C,0x1C,0xA1,0xAD,0x01,0x70,0x3D,0x15,0x70,0x1D,0x01,0xC1,0xBA,0x04,
  0xC0,0x9A,0x09,0xC0,0x4D,0x01,0x70,0x2D,0x01,0xC0,0x1D,0x01,0x70,0x3D,0x01,
  0xC0,0x7D,0x01,0x70,0x2D,0x01,0xC0,0x1D,0x02,0x70,0x2D,0x01,0xC1,0x70,0x02,
  0xC0,0x10,0x01,0xC1,0xAD,0x03,0xC0,0x2D,0x04,0xC0,0x8D,0x03,0xC0,0x4D,0x03,
  0xC1,0xBC,0x4F,0x00,0x1C,0x4F,0x00,0x1C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC2,0x70,0x01,0xC2,0x8C,0x27,0x00,0x1C,0x28,0xC2,0x50,0x02,
  0xC0,0x10,0x03,0xC2,0x5C,0x25,0x00,0x2C,0x01,0x00,0x3C,0x25,0xC2,0x70,0x01,
  0xC2,0x8C,0x27,0x00,0x1C,0x28,0xC5,0x0C,0x50,
};

const uint8_t cat4_frame6[540] = {
  0xC2,0x00,0x02,0xC2,0xEC,0x50,0xC1,0xD0,0x02,0xC0,0x10,0x02,0xC0,0x10,0x02,
  0xC2,0xBC,0x50,0xC2,0x00,0x02,0xC2,0xEC,0x20,0x00,0x2C,0x2E,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC3,0x20,0x01,0xC1,0xDC,0x32,
  0x00,0x1C,0x1D,0xC3,0x00,0x02,0xC0,0x10,0x01,0xC1,0xCC,0x32,0x00,0x1C,0x1D,
  0xC5,0x0C,0x1F,0xD1,0x4C,0x1D,0xB0,0x3C,0x09,0xB0,0x9C,0x09,0xD0,0x12,0x14,
  0xD0,0x1C,0x1C,0xB1,0xDD,0x01,0x20,0x44,0x0E,0x20,0x4D,0x01,0xC1,0xBB,0x1D,
  0xD0,0x12,0x02,0x40,0x79,0x01,0x40,0x39,0x01,0x40,0x62,0x02,0xD0,0x1C,0x1B,
  0xB1,0xDD,0x01,0x20,0x24,0x07,0x90,0x14,0x03,0x90,0x14,0x06,0x20,0x2D,0x01,
  0xC1,0xB6,0x03,0xB0,0x96,0x09,0xB0,0x8D,0x01,0x20,0x14,0x03,0x90,0x14,0x10,
  0x20,0x1D,0x01,0xC1,0xB6,0x1D,0xD0,0x12,0x01,0x40,0xCD,0x02,0x40,0x29,0x01,
  0x40,0x32,0x01,0xD0,0x1C,0x01,0xD0,0x2C,0x18,0x61,0xDD,0x01,0x20,0x14,0x0B,
  0xD0,0x17,0x02,0xD0,0x14,0x05,0x20,0x1D,0x02,0x70,0x2D,0x02,0xC1,0x61,0x03,
  0x60,0x91,0x09,0x60,0x1D,0x05,0x60,0x2D,0x01,0x20,0x14,0x07,0x90,0x14,0x03,
  0xD0,0x17,0x03,0xD0,0x14,0x04,0x20,0x1D,0x01,0x70,0x3D,0x02,0xC1,0x61,0x16,
  0xD0,0x17,0x03,0xD0,0x21,0x01,0xD0,0x12,0x01,0x40,0xBD,0x01,0x70,0x4D,0x05,
  0x70,0x4D,0x02,0xC1,0x61,0x16,0xD0,0x27,0x03,0xD0,0x32,0x01,0x40,0x49,0x01,
  0x40,0x6D,0x01,0x70,0xDD,0x02,0xC1,0x63,0x03,0x10,0x93,0x09,0x10,0x2D,0x03,
  0x70,0x2D,0x02,0x20,0x14,0x08,0x90,0x1D,0x02,0x71,0x0D,0x01,0xC1,0x53,0x17,
  0xD0,0x37,0x02,0xD0,0x22,0x01,0x40,0x89,0x01,0xD0,0x27,0x10,0xD0,0x1C,0x15,
  0x31,0x8D,0x03,0x70,0x2D,0x01,0x20,0x14,0x01,0x90,0x24,0x06,0xD0,0x27,0x03,
  0x00,0x1D,0x01,0x70,0x60,0x01,0xD0,0x17,0x03,0xD0,0x1C,0x15,0x31,0xAD,0x04,
  0x20,0x14,0x09,0xD0,0x27,0x03,0xD0,0x27,0x04,0xD0,0x17,0x01,0xD0,0x27,0x03,
  0xD0,0x1C,0x15,0x80,0x33,0x09,0x80,0x93,0x07,0xD0,0x22,0x01,0x40,0x69,0x01,
  0x40,0x2D,0x02,0x70,0x15,0x02,0x70,0xA5,0x03,0xD0,0x1C,0x15,0x81,0xDD,0x01,
  0x20,0x24,0x02,0x90,0x14,0x05,0xD0,0x27,0x01,0x50,0x27,0x01,0xD0,0x17,0x03,
  0xD0,0x17,0x02,0xD0,0x17,0x01,0x50,0x3D,0x01,0xC1,0x58,0x1D,0xD0,0x12,0x04,
  0x40,0x8D,0x01,0x70,0x3D,0x08,0x70,0x2D,0x02,0xC1,0x6A,0x03,0x80,0x9A,0x09,
  0x80,0x7D,0x03,0x20,0xCD,0x01,0x70,0xBD,0x01,0xC0,0xE0,0x01,0xC0,0x9A,0x1B,
  0xD0,0x17,0x03,0xD1,0x8C,0x0D,0x00,0x1C,0x03,0x00,0x1C,0x07,0xA1,0xBD,0x01,
  0x70,0x3D,0x18,0xC1,0x9A,0x1B,0xD0,0x17,0x02,0xD0,0x2C,0x02,0xD0,0x17,0x02,
  0xD0,0x1C,0x06,0xD0,0x17,0x02,0xD0,0x1C,0x02,0xD0,0x17,0x02,0xD0,0x1C,0x1A,
  0xC0,0x3A,0x09,0xC0,0x9A,0x06,0xD0,0x4C,0x03,0xD0,0x3C,0x08,0xD0,0x3C,0x03,
  0xD0,0x2C,0x0E,0x00,0x1C,0x05,0x00,0x2C,0x05,0xC5,0x0C,0x44,0x00,0x1C,0x03,
  0x00,0x1C,0x07,0xC4,0x60,0x01,0xC0,0x9C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x20,0x00,0x1C,0x2F,0xC1,0xF0,0x01,0xC0,0x10,0x02,
  0xC2,0xDC,0x20,0x00,0x1C,0x2F,0xC2,0x00,0x01,0xC2,0xFC,0x50,0xC5,0x0C,0x50,
  
};

const uint8_t cat4_frame7[546] = {
  0xC1,0x40,0x01,0xC0,0x30,0x01,0xC3,0x7C,0x50,0xC1,0x30,0x01,0xC0,0x50,0x02,
  0xC3,0x5C,0x50,0xC1,0x40,0x01,0xC0,0x30,0x01,0xC3,0x7C,0x16,0x00,0x1C,0x39,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x2B,0x00,0x1C,0x24,
  0xC2,0xB0,0x01,0xC2,0x4C,0x28,0x00,0x3C,0x01,0x00,0x2C,0x22,0xC2,0x80,0x03,
  0xC0,0x10,0x02,0xC2,0x2C,0x2B,0x00,0x1C,0x24,0xC2,0xB0,0x01,0xC2,0x4C,0x1F,
  0xD1,0x4C,0x1D,0xB0,0x3C,0x09,0xB0,0x9C,0x09,0xD0,0x12,0x14,0xD0,0x1C,0x1C,
  0xB1,0xDD,0x01,0x20,0x44,0x0E,0x20,0x4D,0x01,0xC1,0xBB,0x1D,0xD0,0x12,0x02,
  0x40,0x79,0x01,0x40,0x39,0x01,0x40,0x62,0x02,0xD0,0x1C,0x1B,0xB1,0xDD,0x01,
  0x20,0x24,0x07,0x90,0x14,0x03,0x90,0x14,0x06,0x20,0x2D,0x01,0xC1,0xB6,0x03,
  0xB0,0x96,0x09,0xB0,0x8D,0x01,0x20,0x14,0x03,0x90,0x14,0x10,0x20,0x1D,0x01,
  0xC1,0xB6,0x1D,0xD0,0x12,0x01,0x40,0xDD,0x02,0x40,0x19,0x01,0x40,0x32,0x01,
  0xD0,0x1C,0x02,0xD0,0x3C,0x16,0x61,0xDD,0x01,0x20,0x14,0x0C,0xD0,0x17,0x02,
  0xD0,0x14,0x04,0x20,0x1D,0x01,0xC0,0x1D,0x01,0x70,0x3D,0x01,0xC1,0x51,0x03,
  0x60,0x91,0x09,0x60,0x8D,0x01,0x20,0x14,0x07,0x90,0x14,0x04,0xD0,0x17,0x03,
  0xD0,0x14,0x03,0x20,0x1D,0x02,0x70,0x4D,0x01,0xC1,0x51,0x17,0xD0,0x31,0x03,
  0xD0,0x12,0x01,0x40,0xCD,0x01,0x70,0x4D,0x05,0x70,0x5D,0x01,0xC1,0x51,0x16,
  0xD0,0x17,0x03,0xD0,0x11,0x02,0xD0,0x12,0x01,0x40,0x49,0x01,0x40,0x7D,0x01,
  0x70,0xED,0x01,0xC1,0x53,0x03,0x10,0x93,0x09,0x10,0x1D,0x01,0x70,0x3D,0x04,
  0x20,0x14,0x08,0x90,0x14,0x02,0xD0,0x17,0x10,0xD0,0x1C,0x14,0x31,0x6D,0x01,
  0x70,0x3D,0x04,0x20,0x14,0x08,0x90,0x14,0x02,0xD0,0x17,0x03,0x00,0x1D,0x01,
  0x70,0x60,0x01,0xD0,0x17,0x03,0xD0,0x1C,0x14,0x31,0x7D,0x01,0x70,0x5D,0x01,
  0x20,0x14,0x01,0x90,0x24,0x08,0xD0,0x17,0x03,0x00,0x1D,0x01,0x70,0x60,0x01,
  0xD0,0x17,0x03,0xD0,0x1C,0x14,0x31,0x8D,0x03,0x70,0x2D,0x01,0x20,0x14,0x0B,
  0xD0,0x17,0x03,0xD0,0x27,0x04,0xD0,0x17,0x01,0xD0,0x27,0x03,0xD0,0x1C,0x14,
  0x80,0x33,0x09,0x80,0x93,0x06,0xD0,0x32,0x01,0x40,0x69,0x01,0x40,0x4D,0x01,
  0x70,0x15,0x02,0x70,0xA5,0x03,0xD0,0x1C,0x14,0x81,0xDD,0x01,0x20,0x24,0x02,
  0x90,0x14,0x07,0xD0,0x17,0x01,0x50,0x27,0x01,0xD0,0x17,0x03,0xD0,0x17,0x02,
  0xD0,0x17,0x01,0x50,0x3D,0x01,0xC1,0x48,0x1D,0xD0,0x12,0x04,0x40,0x9D,0x01,
  0x70,0x3D,0x08,0x70,0x3D,0x01,0xC1,0x5A,0x03,0x80,0x9A,0x09,0x80,0x8D,0x02,
  0x20,0xDD,0x01,0x70,0xBD,0x02,0xC0,0x30,0x01,0xC1,0x2A,0x1C,0xD0,0x17,0x02,
  0xD1,0x9C,0x18,0xA1,0xCD,0x01,0x70,0x2D,0x14,0xC1,0xDA,0x1C,0xD0,0x17,0x02,
  0xD0,0x1C,0x02,0xD0,0x17,0x02,0xD0,0x1C,0x07,0xD0,0x17,0x02,0xD0,0x2C,0x01,
  0xD0,0x17,0x02,0xD0,0x1C,0x19,0xC0,0x3A,0x09,0xC0,0x9A,0x07,0xD0,0x3C,0x04,
  0xD0,0x3C,0x08,0xD0,0x4C,0x02,0xD0,0x3C,0x03,0x00,0x1C,0x05,0x00,0x2C,0x0E,
  0xC5,0x0C,0x50,0xC3,0xD0,0x01,0xC1,0x2C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC1,0xC0,0x01,0xC3,0x3C,0x1C,0x00,0x1C,0x33,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,
};

const uint8_t cat4_frame8[506] = {
  0xC5,0x0C,0x50,0xC0,0x80,0x02,0xC0,0x50,0x01,0xC4,0x0C,0x50,0xC5,0x0C,0x0C,
  0x00,0x1C,0x43,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC2,0x20,0x01,
  0xC2,0xDC,0x22,0x00,0x1C,0x2D,0xC5,0x0C,0x50,0xC1,0xE0,0x02,0xC0,0x20,0x01,
  0xC0,0x10,0x02,0xC2,0xAC,0x50,0xC2,0x20,0x01,0xC2,0xDC,0x22,0x00,0x1C,0x2D,
  0xC0,0x4B,0x09,0xC0,0x9B,0x09,0xD1,0x4C,0x1D,0xB1,0xED,0x01,0x21,0x4D,0x01,
  0xC1,0xCB,0x1D,0xD0,0x12,0x04,0x40,0xE2,0x04,0xD0,0x1C,0x1B,0xB1,0xDD,0x01,
  0x20,0x44,0x0E,0x20,0x4D,0x01,0xC1,0xBB,0x04,0x60,0x9B,0x09,0x60,0x7D,0x01,
  0x20,0x24,0x07,0x90,0x14,0x03,0x90,0x14,0x06,0x20,0x2D,0x01,0xC1,0xB6,0x1D,
  0xD0,0x12,0x01,0x40,0x39,0x01,0x41,0x02,0x01,0xD0,0x1C,0x1B,0x61,0xDD,0x01,
  0x20,0x14,0x0D,0xD0,0x24,0x01,0x90,0x14,0x03,0x20,0x1D,0x01,0xC0,0x2D,0x03,
  0xC1,0x66,0x04,0x10,0x96,0x09,0x10,0x7D,0x01,0x20,0x14,0x0C,0xD0,0x17,0x02,
  0xD0,0x14,0x04,0x20,0x1D,0x01,0xC0,0x1D,0x01,0x70,0x3D,0x01,0xC1,0x51,0x1D,
  0xD0,0x12,0x01,0x40,0x79,0x01,0x40,0x4D,0x01,0x70,0x3D,0x01,0x40,0x32,0x01,
  0xD0,0x27,0x04,0xD0,0x1C,0x15,0x11,0xDD,0x01,0x20,0x14,0x0C,0xD0,0x17,0x04,
  0xD0,0x57,0x05,0xD0,0x1C,0x15,0x10,0x43,0x09,0x10,0x93,0x07,0xD0,0x12,0x01,
  0x40,0x49,0x01,0x40,0x7D,0x01,0x70,0xED,0x01,0xC1,0x53,0x1D,0xD0,0x12,0x01,
  0x40,0x49,0x01,0x40,0x7D,0x01,0x70,0xED,0x01,0xC1,0x53,0x1C,0xD0,0x22,0x01,
  0x40,0x89,0x01,0x40,0x2D,0x01,0x71,0x0D,0x01,0xC1,0x43,0x18,0xD0,0x62,0x01,
  0x40,0x19,0x02,0x40,0x8D,0x01,0x70,0x30,0x01,0xD0,0x17,0x06,0x00,0x1D,0x01,
  0x70,0x3D,0x01,0xC1,0x43,0x04,0x80,0x93,0x09,0xD0,0x27,0x05,0xD0,0x12,0x01,
  0x40,0xBD,0x01,0x70,0x3D,0x02,0x70,0x4D,0x01,0x70,0x1D,0x02,0x70,0x3D,0x01,
  0xC1,0x48,0x16,0xD0,0x17,0x04,0xD0,0x32,0x01,0x40,0x69,0x01,0x40,0x4D,0x01,
  0x70,0x15,0x02,0x70,0xA5,0x03,0xD0,0x1C,0x14,0x81,0x7D,0x05,0x80,0x1D,0x01,
  0x20,0x24,0x02,0x90,0x14,0x07,0xD0,0x17,0x01,0x50,0x27,0x01,0xD0,0x17,0x03,
  0xD0,0x17,0x02,0xD0,0x17,0x01,0x50,0x3D,0x01,0xC1,0x48,0x04,0xA0,0x98,0x09,
  0xA0,0x7D,0x01,0x20,0x44,0x09,0xD0,0x17,0x03,0xD0,0x87,0x03,0xD0,0x1C,0x15,
  0xA1,0xDD,0x02,0x20,0xDD,0x01,0x70,0xBD,0x02,0xC1,0x6A,0x1D,0xD0,0x22,0x0D,
  0xD0,0x17,0x0B,0xD0,0x2C,0x16,0xA1,0xDD,0x01,0x70,0x1D,0x19,0xC1,0x8A,0x04,
  0xC0,0x9A,0x09,0xC0,0x7D,0x01,0x70,0x2D,0x02,0xC0,0x1D,0x01,0x70,0x2D,0x01,
  0xC0,0x7D,0x01,0x70,0x3D,0x01,0x00,0x1D,0x01,0x70,0x2D,0x01,0xC1,0x8C,0x1D,
  0xD0,0x3C,0x04,0xD0,0x3C,0x08,0xD0,0x4C,0x02,0xD0,0x3C,0x18,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC1,0x50,0x01,0xC3,0xAC,0x50,
  0xC5,0x0C,0x12,0x00,0x1C,0x05,0x00,0x2C,0x36,0xC1,0x20,0x01,0xC0,0x50,0x02,
  0xC3,0x6C,0x50,0xC5,0x0C,0x15,0x00,0x1C,0x3A,0xC5,0x00,
};

const uint8_t cat4_frame9[536] = {
  0xC5,0x0C,0x50,0xC0,0x50,0x01,0xC4,0xAC,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC1,0x70,0x01,0xC3,0x8C,0x15,0x00,0x1C,0x04,
  0x00,0x1C,0x35,0xC5,0x0C,0x50,0xC1,0x40,0x01,0xC0,0x60,0x01,0xC3,0x4C,0x50,
  0xC1,0x50,0x01,0xC0,0x40,0x01,0xC3,0x5C,0x17,0x00,0x1C,0x38,0xC0,0x4B,0x09,
  0xC0,0x9B,0x09,0xD1,0x4C,0x1D,0xB1,0xED,0x01,0x21,0x4D,0x01,0xC1,0xCB,0x1D,
  0xD0,0x12,0x04,0x40,0xE2,0x04,0xD0,0x1C,0x1B,0xB1,0xDD,0x01,0x20,0x44,0x0E,
  0x20,0x4D,0x01,0xC1,0xBB,0x04,0x60,0x9B,0x09,0x60,0x7D,0x01,0x20,0x24,0x07,
  0x90,0x14,0x03,0x90,0x14,0x06,0x20,0x2D,0x01,0xC1,0xB6,0x1D,0xD0,0x12,0x01,
  0x40,0x39,0x01,0x41,0x02,0x01,0xD0,0x1C,0x1B,0x61,0xDD,0x01,0x20,0x14,0x0D,
  0xD0,0x24,0x01,0x90,0x14,0x03,0x20,0x1D,0x01,0xC0,0x2D,0x03,0xC1,0x66,0x04,
  0x10,0x96,0x09,0x10,0x7D,0x01,0x20,0x14,0x0C,0xD0,0x17,0x02,0xD0,0x14,0x04,
  0x20,0x1D,0x01,0xC0,0x1D,0x01,0x70,0x3D,0x01,0xC1,0x51,0x1D,0xD0,0x12,0x01,
  0x40,0x79,0x01,0x40,0x4D,0x01,0x70,0x3D,0x01,0x40,0x32,0x01,0xD0,0x27,0x04,
  0xD0,0x1C,0x15,0x11,0xDD,0x01,0x20,0x14,0x0C,0xD0,0x17,0x04,0xD0,0x57,0x05,
  0xD0,0x1C,0x15,0x10,0x43,0x09,0x10,0x93,0x07,0xD0,0x12,0x01,0x40,0x49,0x01,
  0x40,0x7D,0x01,0x70,0xED,0x01,0xC1,0x53,0x1D,0xD0,0x12,0x01,0x40,0x49,0x01,
  0x40,0x7D,0x01,0x70,0xED,0x01,0xC1,0x53,0x1B,0xD0,0x32,0x01,0x40,0x89,0x01,
  0x40,0x2D,0x01,0x71,0x0D,0x01,0xC1,0x43,0x18,0xD0,0x37,0x02,0xD0,0x12,0x01,
  0x40,0x19,0x02,0x40,0x8D,0x01,0x70,0x30,0x01,0xD0,0x17,0x06,0x00,0x1D,0x01,
  0x70,0x3D,0x01,0xC1,0x43,0x04,0x80,0x93,0x09,0x80,0x1D,0x01,0x70,0x5D,0x01,
  0x20,0x14,0x0B,0xD0,0x17,0x03,0xD0,0x27,0x04,0xD0,0x17,0x01,0xD0,0x27,0x03,
  0xD0,0x1C,0x14,0x81,0x6D,0x01,0x70,0x3D,0x04,0x20,0x14,0x06,0x90,0x14,0x04,
  0xD0,0x17,0x01,0x50,0x27,0x0A,0x50,0x3D,0x01,0xC1,0x48,0x16,0xD0,0x17,0x03,
  0xD0,0x18,0x02,0xD0,0x12,0x02,0x40,0x29,0x01,0x40,0x7D,0x01,0x70,0x15,0x02,
  0x70,0x1D,0x01,0x70,0x3D,0x01,0x70,0x2D,0x01,0x70,0x15,0x03,0xD0,0x1C,0x14,
  0x80,0x4A,0x09,0x80,0x9A,0x01,0xD0,0x3A,0x03,0xD0,0x12,0x04,0x40,0x9D,0x01,
  0x70,0x3D,0x08,0x70,0x3D,0x01,0xC1,0x5A,0x1D,0xD0,0x22,0x0D,0xD0,0x17,0x0B,
  0xD0,0x2C,0x16,0xA1,0xDD,0x02,0x20,0xDD,0x01,0x70,0xBD,0x02,0xC1,0x6A,0x1C,
  0xD0,0x17,0x02,0xD1,0x9C,0x18,0xA0,0x4C,0x09,0xA0,0x9C,0x06,0xD0,0x17,0x02,
  0xD0,0x1C,0x02,0xD0,0x17,0x02,0xD0,0x1C,0x02,0x00,0x3C,0x01,0x00,0x1D,0x01,
  0x70,0x2D,0x02,0xC0,0x1D,0x01,0x70,0x2D,0x01,0xC1,0x9C,0x1C,0xD0,0x3C,0x04,
  0xD0,0x3C,0x05,0x00,0x1C,0x02,0xD0,0x4C,0x02,0xD0,0x3C,0x19,0xC2,0xB0,0x01,
  0xC2,0x4C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC0,0xC0,0x01,
  0xC4,0x3C,0x0A,0x00,0x1C,0x03,0x00,0x1C,0x41,0xC5,0x0C,0x08,0x00,0x2C,0x05,
  0x00,0x1C,0x40,0xC0,0x80,0x02,0xC0,0x50,0x01,0xC4,0x0C,0x50,0xC0,0xA0,0x01,
  0xC0,0x30,0x01,0xC4,0x1C,0x0C,0x00,0x1C,0x43,0xC5,0x00,
};

const uint8_t cat4_frame10[512] = {
  0xC5,0x00,0x01,0xC4,0xFC,0x01,0x00,0x2C,0x4D,0x00,0x1C,0x4F,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC0,0xD0,0x01,0xC4,0x2C,0x50,
  0xC5,0x0C,0x50,0xC0,0xA0,0x01,0xC0,0x50,0x02,0xC3,0xEC,0x50,0xC5,0x0C,0x0D,
  0x00,0x1C,0x42,0xB0,0x3C,0x09,0xB0,0x9C,0x0A,0xD1,0x4C,0x1D,0xB1,0xED,0x01,
  0x21,0x4D,0x01,0xC1,0xCB,0x1D,0xD0,0x12,0x04,0x40,0xE2,0x04,0xD0,0x1C,0x1B,
  0xB1,0xDD,0x01,0x20,0x44,0x0E,0x20,0x4D,0x01,0xC1,0xB6,0x03,0xB0,0x96,0x09,
  0xB0,0x8D,0x01,0x20,0x24,0x07,0x90,0x14,0x03,0x90,0x14,0x06,0x20,0x2D,0x01,
  0xC1,0xB6,0x1D,0xD0,0x12,0x01,0x40,0x39,0x01,0x41,0x02,0x01,0xD0,0x1C,0x1B,
  0x61,0xDD,0x01,0x20,0x14,0x0C,0xD0,0x24,0x02,0x90,0x14,0x03,0x20,0x1D,0x01,
  0xC0,0x1D,0x02,0xC1,0x81,0x03,0x60,0x91,0x09,0x60,0x8D,0x01,0x20,0x14,0x0B,
  0xD0,0x17,0x02,0xD0,0x14,0x05,0x20,0x1D,0x02,0x70,0x2D,0x02,0xC1,0x61,0x1D,
  0xD0,0x12,0x01,0x40,0x79,0x01,0x40,0x3D,0x01,0x70,0x3D,0x01,0x40,0x42,0x01,
  0xD0,0x17,0x03,0xD0,0x2C,0x16,0x11,0x6D,0x05,0x10,0x2D,0x01,0x20,0x14,0x0B,
  0xD0,0x17,0x04,0xD0,0x57,0x04,0xD0,0x2C,0x16,0x30,0x31,0x09,0x30,0x9D,0x01,
  0x70,0x4D,0x04,0x20,0x14,0x04,0x90,0x14,0x06,0xD0,0x17,0x0D,0xD0,0x2C,0x16,
  0x31,0x5D,0x02,0x70,0x5D,0x02,0x20,0x14,0x04,0x90,0x14,0x06,0xD0,0x17,0x0D,
  0xD0,0x2C,0x16,0x31,0x5D,0x02,0x70,0x5D,0x02,0x20,0x14,0x08,0x90,0x1D,0x02,
  0x71,0x0D,0x01,0xC1,0x53,0x17,0xD0,0x57,0x01,0xD0,0x12,0x01,0x40,0x19,0x02,
  0x40,0x6D,0x02,0x70,0x30,0x01,0xD0,0x17,0x06,0x00,0x1D,0x01,0x70,0x3D,0x01,
  0xC1,0x58,0x03,0x30,0x98,0x09,0x30,0x6D,0x03,0x20,0x14,0x09,0xD0,0x27,0x03,
  0xD0,0x27,0x04,0xD0,0x17,0x01,0xD0,0x27,0x03,0xD0,0x1C,0x15,0x81,0xDD,0x01,
  0x20,0x14,0x06,0x90,0x14,0x02,0xD0,0x27,0x01,0x50,0x27,0x0A,0x50,0x3D,0x01,
  0xC1,0x58,0x1D,0xD0,0x12,0x02,0x40,0x29,0x01,0x40,0x5D,0x02,0x70,0x15,0x02,
  0x70,0x1D,0x01,0x70,0x3D,0x01,0x70,0x2D,0x01,0x70,0x15,0x03,0xD0,0x1C,0x15,
  0xA0,0x38,0x09,0xA0,0x98,0x07,0xD0,0x22,0x04,0x40,0x8D,0x01,0x70,0x3D,0x08,
  0x70,0x2D,0x02,0xC1,0x6A,0x1B,0xD0,0x42,0x0C,0xD0,0x17,0x0B,0xD0,0x1C,0x18,
  0xA1,0xBD,0x04,0x20,0xCD,0x01,0x70,0xBD,0x01,0xC1,0x8A,0x1A,0xD0,0x17,0x03,
  0xD1,0x9C,0x19,0xC0,0x3A,0x09,0xC0,0x9A,0x05,0xD0,0x17,0x02,0xD0,0x10,0x01,
  0xD0,0x17,0x03,0xD0,0x10,0x02,0xC0,0x5D,0x01,0x70,0x2D,0x01,0xC0,0x1D,0x02,
  0x70,0x2D,0x01,0xC1,0xBC,0x1A,0xD0,0x3C,0x03,0xD0,0x4C,0x08,0xD0,0x3C,0x03,
  0xD0,0x3C,0x1B,0xC2,0x20,0x01,0xC2,0xDC,0x22,0x00,0x1C,0x2D,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC0,0x30,0x01,0xC4,0xCC,0x03,0x00,0x1C,0x4C,
  0xC5,0x00,0x01,0xC0,0x20,0x01,0xC0,0x10,0x02,0xC4,0x90,0x01,0xC0,0x20,0x01,
  0xC0,0x10,0x02,0xC4,0x9C,0x50,0xC0,0x30,0x01,0xC4,0xCC,0x03,0x00,0x1C,0x4C,
  0xC5,0x00,
};

const uint8_t cat4_frame11[513] = {
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC0,0x60,0x01,0xC4,0x9C,0x50,
  0xC5,0x0C,0x50,0xB0,0x3C,0x09,0xB0,0x9C,0x0A,0xD1,0x4C,0x1D,0xB1,0xED,0x01,
  0x21,0x4D,0x01,0xC1,0xCB,0x1D,0xD0,0x12,0x04,0x40,0xE2,0x04,0xD0,0x1C,0x1B,
  0xB1,0xDD,0x01,0x20,0x44,0x0E,0x20,0x4D,0x01,0xC1,0xB6,0x03,0xB0,0x96,0x09,
  0xB0,0x8D,0x01,0x20,0x24,0x07,0x90,0x14,0x03,0x90,0x14,0x06,0x20,0x2D,0x01,
  0xC1,0xB6,0x1D,0xD0,0x12,0x01,0x40,0x39,0x01,0x40,0x8D,0x02,0x40,0x62,0x01,
  0xD0,0x1C,0x01,0xD0,0x2C,0x18,0x61,0xDD,0x01,0x20,0x14,0x0B,0xD0,0x17,0x02,
  0xD0,0x14,0x01,0x90,0x14,0x03,0x20,0x1D,0x02,0x70,0x2D,0x02,0xC1,0x61,0x03,
  0x60,0x91,0x09,0x60,0x8D,0x01,0x20,0x14,0x0B,0xD0,0x17,0x03,0xD0,0x14,0x04,
  0x20,0x1D,0x01,0x70,0x3D,0x02,0xC1,0x61,0x17,0xD0,0x31,0x03,0xD0,0x12,0x01,
  0x40,0x79,0x01,0x40,0x3D,0x01,0x70,0x4D,0x05,0x70,0x4D,0x02,0xC1,0x61,0x16,
  0xD0,0x17,0x03,0xD0,0x11,0x02,0xD0,0x12,0x01,0x40,0xBD,0x01,0x70,0xDD,0x02,
  0xC1,0x63,0x03,0x10,0x93,0x09,0x10,0x1D,0x01,0x70,0x3D,0x04,0x20,0x14,0x04,
  0x90,0x14,0x04,0xD0,0x27,0x10,0xD0,0x1C,0x15,0x31,0x6D,0x01,0x70,0x3D,0x04,
  0x20,0x14,0x04,0x90,0x14,0x04,0xD0,0x27,0x03,0x00,0x1D,0x01,0x70,0x60,0x01,
  0xD0,0x17,0x03,0xD0,0x1C,0x15,0x31,0x7D,0x01,0x70,0x5D,0x01,0x20,0x14,0x08,
  0x90,0x1D,0x02,0x70,0x30,0x01,0xD0,0x17,0x06,0x00,0x1D,0x01,0x70,0x3D,0x01,
  0xC1,0x53,0x18,0xD0,0x37,0x02,0xD0,0x12,0x01,0x40,0x19,0x02,0x40,0x6D,0x02,
  0x70,0x3D,0x02,0x70,0x4D,0x01,0x70,0x1D,0x02,0x70,0x3D,0x01,0xC1,0x58,0x03,
  0x30,0x98,0x09,0x30,0x6D,0x03,0x20,0x14,0x09,0xD0,0x27,0x01,0x50,0x27,0x0A,
  0x50,0x3D,0x01,0xC1,0x58,0x1D,0xD0,0x12,0x01,0x40,0x69,0x01,0x40,0x2D,0x02,
  0x70,0x15,0x02,0x70,0x1D,0x01,0x70,0x3D,0x01,0x70,0x2D,0x01,0x70,0x15,0x03,
  0xD0,0x1C,0x15,0x81,0xDD,0x01,0x20,0x24,0x02,0x90,0x14,0x07,0xD0,0x17,0x03,
  0xD0,0x87,0x02,0xD0,0x2C,0x16,0xA0,0x38,0x09,0xA0,0x98,0x02,0x00,0x18,0x04,
  0xD0,0x22,0x04,0x40,0x9D,0x01,0x70,0xBD,0x01,0xC1,0x8A,0x15,0x00,0x1A,0x04,
  0x00,0x1D,0x01,0x70,0x1D,0x02,0x20,0xDD,0x0B,0xC1,0x9A,0x1A,0xD0,0x17,0x02,
  0xD0,0x22,0x14,0xD0,0x2C,0x1B,0xA1,0xAD,0x01,0x70,0x3D,0x15,0x70,0x1D,0x01,
  0xC1,0xBC,0x03,0xA0,0x9C,0x08,0x00,0x1A,0x05,0xD0,0x17,0x02,0xD0,0x1C,0x01,
  0xD0,0x17,0x03,0xD0,0x1C,0x07,0xD0,0x17,0x02,0xD0,0x1C,0x01,0xD0,0x27,0x02,
  0xD0,0x1C,0x1B,0xC1,0xAD,0x03,0xC0,0x2D,0x04,0xC0,0x8D,0x03,0xC0,0x4D,0x03,
  0xC1,0xBC,0x15,0x00,0x1C,0x04,0x00,0x1C,0x35,0xC1,0x70,0x01,0xC3,0x8C,0x50,
  0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC5,0x0C,0x50,0xC0,0x20,0x01,0xC4,0xDC,0x50,
  0xC0,0x30,0x01,0xC4,0xCC,0x03,0x00,0x1C,0x4C,0xC5,0x0C,0x02,0x00,0x1C,0x4D,
  0xC5,0x0C,0x50,
};

// Assemble the individual frames together into an array representing the entire
// animation.
const uint8_t* cat4_frames[12] = {
  cat4_frame0,
  cat4_frame1,
  cat4_frame2,
  cat4_frame3,
  cat4_frame4,
  cat4_frame5,
  cat4_frame6,
  cat4_frame7,
  cat4_frame8,
  cat4_frame9,
  cat4_frame10,
  cat4_frame11,
};

#endif // NYANCAT_DEMO
#endif // __NYANCAT_H