/*
 * Copyright (c) 2014 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */
#ifdef _FORTIFY_SOURCE
#undef _FORTIFY_SOURCE
#endif

typedef unsigned char bool;

static const unsigned char ATSC_C5[] =
{
    0x01, 0x00, 0x01, 0x3A, 0x01, 0x3C, 0x01, 0x3E,
    0x01, 0x40, 0x01, 0x42, 0x01, 0x44, 0x01, 0x46,
    0x01, 0x48, 0x01, 0x4A, 0x01, 0x4C, 0x01, 0x4E,
    0x01, 0x50, 0x01, 0x52, 0x01, 0x54, 0x01, 0x56,
    0x01, 0x58, 0x01, 0x5A, 0x01, 0x5C, 0x01, 0x5E,
    0x01, 0x60, 0x01, 0x62, 0x01, 0x64, 0x01, 0x66,
    0x01, 0x68, 0x01, 0x6A, 0x01, 0x6C, 0x01, 0x6E,
    0x01, 0x70, 0x01, 0x72, 0x01, 0x74, 0x01, 0x76,
    0x01, 0x78, 0x01, 0xCE, 0x01, 0xD2, 0x01, 0xD4,
    0x01, 0xD6, 0x01, 0xD8, 0x01, 0xDA, 0x01, 0xDC,
    0x01, 0xE6, 0x01, 0xE8, 0x01, 0xEA, 0x01, 0xF0,
    0x01, 0xF2, 0x01, 0xF4, 0x02, 0x06, 0x02, 0x12,
    0x02, 0x14, 0x02, 0x1C, 0x02, 0x28, 0x02, 0x30,
    0x02, 0x34, 0x02, 0x36, 0x02, 0x38, 0x02, 0x3A,
    0x02, 0x3C, 0x02, 0x3E, 0x02, 0x46, 0x02, 0x48,
    0x02, 0x4A, 0x02, 0x4C, 0x02, 0x4E, 0x02, 0x50,
    0x02, 0x52, 0x02, 0x54, 0x02, 0x7E, 0x02, 0x92,
    0x02, 0xAC, 0x02, 0xBA, 0x02, 0xD2, 0x02, 0xE4,
    0x02, 0xFA, 0x03, 0x06, 0x03, 0x1E, 0x03, 0x26,
    0x03, 0x32, 0x03, 0x3E, 0x03, 0x52, 0x03, 0x64,
    0x03, 0x7A, 0x03, 0x94, 0x03, 0x98, 0x03, 0xA4,
    0x03, 0xC8, 0x03, 0xDE, 0x03, 0xE6, 0x03, 0xF4,
    0x04, 0x04, 0x04, 0x06, 0x04, 0x0C, 0x04, 0x10,
    0x04, 0x12, 0x04, 0x14, 0x04, 0x16, 0x04, 0x18,
    0x04, 0x1A, 0x04, 0x1C, 0x04, 0x52, 0x04, 0x6A,
    0x04, 0x8E, 0x04, 0xAE, 0x04, 0xEE, 0x05, 0x06,
    0x05, 0x28, 0x05, 0x44, 0x05, 0x72, 0x05, 0x76,
    0x05, 0x90, 0x05, 0xBE, 0x05, 0xD6, 0x06, 0x0A,
    0x06, 0x44, 0x06, 0x64, 0x06, 0x66, 0x06, 0x9A,
    0x06, 0xD0, 0x06, 0xFC, 0x07, 0x22, 0x07, 0x2C,
    0x07, 0x46, 0x07, 0x54, 0x07, 0x7C, 0x07, 0x8A,
    0x07, 0x8C, 0x07, 0x8E, 0x07, 0x90, 0x07, 0x92,
    0x1B, 0x1C, 0xB4, 0xA4, 0xB2, 0xB7, 0xDA, 0x01,
    0xD1, 0x02, 0x03, 0x9B, 0x04, 0xD5, 0xD9, 0x05,
    0xCB, 0xD6, 0x06, 0xCF, 0x07, 0x08, 0xCA, 0x09,
    0xC9, 0xC5, 0xC6, 0x0A, 0xD2, 0xC4, 0xC7, 0xCC,
    0xD0, 0xC8, 0xD7, 0xCE, 0x0B, 0xC1, 0x0C, 0xC2,
    0xCD, 0xC3, 0x0D, 0x0E, 0x0F, 0x10, 0xD3, 0x11,
    0xD4, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1A, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x29, 0x2A, 0xD8, 0xE5, 0xB9, 0x01, 0xA7, 0xB1,
    0xEC, 0xD1, 0x02, 0xAD, 0xB2, 0xDA, 0xE3, 0xB3,
    0x03, 0xE4, 0xE6, 0x04, 0x9B, 0xE2, 0x05, 0x06,
    0x07, 0x08, 0x09, 0xD5, 0x0A, 0xD6, 0x0B, 0xD9,
    0x0C, 0xA6, 0xE9, 0xCB, 0xC5, 0xCF, 0x0D, 0x0E,
    0xCA, 0xC9, 0x0F, 0xC7, 0x10, 0x11, 0xE1, 0x12,
    0x13, 0xC6, 0xD2, 0xC8, 0xCE, 0xC1, 0xC4, 0xD0,
    0xCC, 0x14, 0x15, 0xEF, 0xC2, 0xD7, 0x16, 0xCD,
    0x17, 0xF4, 0xD4, 0x18, 0x19, 0x1A, 0xC3, 0xD3,
    0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22,
    0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x01, 0x80,
    0xA0, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0xB1, 0x9B,
    0x9B, 0x9B, 0x9B, 0xA0, 0x04, 0xF3, 0xE4, 0xB9,
    0x01, 0xF4, 0xA0, 0x9B, 0x02, 0x03, 0x9B, 0x9B,
    0x9B, 0x9B, 0x01, 0x02, 0x9B, 0xC1, 0xC8, 0xD3,
    0x9B, 0x9B, 0x9B, 0xA0, 0x07, 0x08, 0xB1, 0xD2,
    0xD3, 0xD4, 0xD5, 0xAD, 0xCD, 0xC1, 0x01, 0x02,
    0x03, 0xA0, 0x04, 0x9B, 0x05, 0x06, 0xA0, 0x05,
    0xC9, 0xD7, 0xD3, 0x01, 0x02, 0x9B, 0xAE, 0x80,
    0x03, 0x04, 0x9B, 0x9B, 0x02, 0x03, 0xAD, 0x9B,
    0x01, 0x80, 0xA0, 0xB0, 0x04, 0x05, 0x80, 0x9B,
    0xB1, 0xB2, 0xA0, 0xB0, 0xB9, 0x01, 0x02, 0x03,
    0x02, 0x03, 0xB1, 0xBA, 0x01, 0xB0, 0x9B, 0x80,
    0x80, 0x01, 0xB0, 0x9B, 0x9B, 0xB8, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0xB0, 0x9B, 0xA0, 0x02, 0x03,
    0xB1, 0xB3, 0xB9, 0xB0, 0x01, 0x9B, 0x9B, 0xA0,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x80, 0x9B, 0x9B, 0x13, 0x14, 0xAA, 0xAD,
    0xAE, 0xF6, 0xE7, 0xF4, 0xE2, 0xE9, 0x01, 0x02,
    0xC2, 0xF0, 0x9B, 0xF3, 0xE3, 0xE6, 0xF7, 0x03,
    0xF5, 0x04, 0x05, 0x06, 0xF2, 0x07, 0x08, 0x09,
    0x0A, 0x0B, 0x0C, 0xE4, 0xA0, 0x0D, 0xEC, 0xEE,
    0x0E, 0xED, 0x0F, 0x10, 0x11, 0x12, 0x08, 0x09,
    0xC1, 0xD3, 0x9B, 0x01, 0xC3, 0x02, 0xE9, 0xEC,
    0x03, 0xF2, 0xF5, 0x04, 0xEF, 0xE1, 0x05, 0xE5,
    0x06, 0x07, 0x0B, 0x0C, 0xC1, 0xF9, 0x01, 0xC2,
    0xCF, 0xE5, 0xF5, 0x9B, 0xE9, 0x02, 0xA0, 0x03,
    0x04, 0x05, 0xF2, 0x06, 0xEC, 0x07, 0xE1, 0x08,
    0x09, 0xE8, 0x0A, 0xEF, 0x05, 0x06, 0xF9, 0x9B,
    0x01, 0xF5, 0x02, 0xF2, 0xE9, 0xE5, 0xEF, 0x03,
    0xE1, 0x04, 0x0A, 0x0B, 0xF1, 0xF5, 0xF3, 0x01,
    0xED, 0xF9, 0xC3, 0x02, 0xEC, 0xEE, 0xE4, 0xF8,
    0x03, 0x9B, 0xF6, 0x04, 0x05, 0xE1, 0x06, 0x07,
    0x08, 0x09, 0x07, 0x08, 0xA0, 0x9B, 0xCC, 0x01,
    0xE5, 0x02, 0xEC, 0xF5, 0xEF, 0x03, 0xE9, 0xF2,
    0x04, 0x05, 0xE1, 0x06, 0x09, 0x0A, 0xAE, 0xEC,
    0xF9, 0xC1, 0xE8, 0x01, 0x9B, 0x02, 0x03, 0x04,
    0xE1, 0xF5, 0xE9, 0x05, 0xE5, 0x06, 0xF2, 0xEF,
    0x07, 0x08, 0xEF, 0x05, 0x80, 0x9B, 0xF5, 0x01,
    0x02, 0xE9, 0xE1, 0x03, 0xE5, 0x04, 0xEE, 0x0B,
    0xBA, 0xD4, 0xAE, 0xF2, 0xE3, 0x01, 0xA0, 0x02,
    0x80, 0x9B, 0xED, 0x03, 0xC9, 0xF3, 0xF4, 0x04,
    0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x02, 0x03,
    0x9B, 0xF5, 0x01, 0xE1, 0xEF, 0xE5, 0x05, 0xE9,
    0xE1, 0xEF, 0xF5, 0xEE, 0x9B, 0xE5, 0x01, 0x02,
    0x03, 0x04, 0x04, 0x05, 0xA0, 0x9B, 0x01, 0xF5,
    0x02, 0xE5, 0xEF, 0x03, 0xE1, 0xE9, 0x08, 0x09,
    0xAA, 0xD4, 0x01, 0x9B, 0xE3, 0x02, 0xF2, 0x03,
    0xE5, 0x04, 0xF5, 0xF9, 0xE9, 0x05, 0xEF, 0x06,
    0x07, 0xE1, 0xE5, 0x08, 0xCE, 0xA0, 0xC6, 0xF5,
    0x01, 0x02, 0x9B, 0xC2, 0x03, 0xE1, 0x04, 0xEF,
    0x05, 0xE9, 0x06, 0x07, 0x09, 0x0A, 0xE4, 0xF3,
    0xE6, 0xF6, 0xF7, 0xF0, 0xF2, 0x01, 0xEC, 0x02,
    0x03, 0xA0, 0x9B, 0x04, 0x05, 0xF5, 0x06, 0x07,
    0xEE, 0x08, 0x0B, 0x0C, 0xA0, 0xF3, 0xF9, 0xAE,
    0xD2, 0xC7, 0x01, 0x9B, 0x02, 0xF5, 0x03, 0x04,
    0x05, 0xE9, 0xEC, 0x06, 0xE5, 0x07, 0xEF, 0x08,
    0xE1, 0x09, 0xF2, 0x0A, 0x01, 0xF5, 0x9B, 0xD6,
    0x04, 0x05, 0xE8, 0x9B, 0x01, 0xF5, 0x02, 0xE1,
    0xE9, 0xEF, 0x03, 0xE5, 0x10, 0x11, 0xAA, 0xEC,
    0xF1, 0xAE, 0xA0, 0xF7, 0xED, 0xEE, 0x01, 0x02,
    0x9B, 0xEB, 0x03, 0x04, 0x05, 0x06, 0xE3, 0x07,
    0xEF, 0x08, 0xE9, 0xF5, 0x09, 0xE1, 0xE5, 0xF0,
    0xE8, 0x0A, 0x0B, 0x0C, 0x0D, 0xF4, 0x0E, 0x0F,
    0xE8, 0x0A, 0xAD, 0xCE, 0x9B, 0x01, 0xD6, 0x02,
    0xF5, 0xF7, 0x03, 0x04, 0xE1, 0xE5, 0xE9, 0x05,
    0xF2, 0x06, 0xEF, 0x07, 0x08, 0x09, 0xEE, 0x03,
    0xEC, 0xAE, 0x01, 0x9B, 0x02, 0xF0, 0x06, 0xE9,
    0xA0, 0xC3, 0xEF, 0x9B, 0xE5, 0x01, 0x80, 0x02,
    0x03, 0xE1, 0x04, 0x05, 0x06, 0x07, 0xC6, 0xD7,
    0x01, 0x9B, 0xF2, 0x02, 0x03, 0xE8, 0xE5, 0xE1,
    0x04, 0xE9, 0xEF, 0x05, 0x9B, 0x9B, 0x02, 0xEF,
    0xE1, 0x9B, 0x01, 0xE5, 0x01, 0xEF, 0x9B, 0xE1,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x19, 0x1A, 0x9B, 0xBA,
    0xE5, 0xEA, 0xF8, 0x01, 0x02, 0xE6, 0xA7, 0x03,
    0xFA, 0xE8, 0x04, 0xF7, 0x05, 0xF5, 0xE2, 0x06,
    0xEB, 0x07, 0xF0, 0x08, 0x80, 0xF6, 0xE7, 0x09,
    0xE4, 0x0A, 0xA0, 0xE9, 0x0B, 0xE3, 0xF9, 0x0C,
    0x0D, 0xED, 0x0E, 0x0F, 0xF3, 0x10, 0x11, 0xEC,
    0x12, 0xF4, 0xF2, 0x13, 0xEE, 0x14, 0x15, 0x16,
    0x17, 0x18, 0x0A, 0x0B, 0xF3, 0x9B, 0xF5, 0xE2,
    0x01, 0x80, 0xA0, 0x02, 0xE5, 0xF2, 0xE9, 0x03,
    0xEC, 0x04, 0xF9, 0x05, 0xEF, 0x06, 0xE1, 0x07,
    0x08, 0x09, 0x10, 0x11, 0xC3, 0xCC, 0xC7, 0x9B,
    0xE3, 0x01, 0x80, 0xEC, 0xF9, 0x02, 0xF3, 0x03,
    0xF5, 0x04, 0x05, 0xF2, 0x06, 0xE9, 0xA0, 0x07,
    0x08, 0xEF, 0xF4, 0x09, 0x0A, 0xE1, 0x0B, 0xE8,
    0xEB, 0xE5, 0x0C, 0x0D, 0x0E, 0x0F, 0x0E, 0x0F,
    0xAE, 0xF5, 0xF7, 0x01, 0xEC, 0x02, 0xE4, 0xE7,
    0xF2, 0x03, 0x9B, 0xEF, 0x04, 0xF6, 0x05, 0x06,
    0xF9, 0xF3, 0x07, 0xE9, 0xE1, 0x08, 0x09, 0x80,
    0x0A, 0x0B, 0xE5, 0x0C, 0x0D, 0xA0, 0x1E, 0x1F,
    0x9B, 0xA1, 0xAD, 0xE8, 0xEA, 0xF1, 0xF5, 0xFA,
    0x01, 0x02, 0x03, 0x04, 0xBA, 0xF8, 0xA7, 0xE2,
    0xE9, 0x05, 0x06, 0x07, 0xE6, 0xED, 0xE7, 0xEB,
    0x08, 0x09, 0xF6, 0xF0, 0x0A, 0xEF, 0x0B, 0xE3,
    0x0C, 0x0D, 0x0E, 0xF9, 0x0F, 0xE4, 0xEC, 0x10,
    0xE5, 0x11, 0xF4, 0xF7, 0x12, 0x13, 0xE1, 0x14,
    0x15, 0x16, 0xEE, 0xF3, 0x17, 0x80, 0x18, 0x19,
    0xF2, 0x1A, 0x1B, 0xA0, 0x1C, 0x1D, 0xA0, 0x0B,
    0xF5, 0x9B, 0x01, 0xEC, 0xF3, 0xF2, 0x80, 0xE1,
    0x02, 0x03, 0xF4, 0xE9, 0xEF, 0xE6, 0x04, 0x05,
    0x06, 0x07, 0xE5, 0x08, 0x09, 0x0A, 0x0F, 0x10,
    0xBA, 0xF9, 0xA7, 0xF4, 0x9B, 0x01, 0xE7, 0xEC,
    0x02, 0xEE, 0x03, 0xEF, 0xF5, 0x04, 0xF2, 0x05,
    0x06, 0xE9, 0x07, 0xF3, 0xE1, 0x08, 0x09, 0x0A,
    0x0B, 0xE5, 0x80, 0x0C, 0xE8, 0xA0, 0x0D, 0x0E,
    0xE5, 0x0D, 0xE2, 0xF5, 0xF7, 0x9B, 0xEC, 0x01,
    0xF9, 0xEE, 0x02, 0x03, 0x04, 0xF2, 0x05, 0x80,
    0x06, 0xA0, 0xE1, 0xEF, 0x07, 0xF4, 0xE9, 0x08,
    0x09, 0x0A, 0x0B, 0x0C, 0x15, 0x16, 0xA1, 0xF8,
    0xE9, 0xEB, 0x01, 0x80, 0x9B, 0xFA, 0xE2, 0x02,
    0x03, 0x04, 0xA0, 0xF0, 0x05, 0x06, 0x07, 0xE1,
    0x08, 0xE6, 0xF2, 0xED, 0xF6, 0x09, 0xE4, 0x0A,
    0xEF, 0xF4, 0xEC, 0xF3, 0xE7, 0xE5, 0x0B, 0xE3,
    0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13,
    0xEE, 0x14, 0xEF, 0x01, 0x9B, 0xE1, 0x0B, 0x0C,
    0xD4, 0xEF, 0xE6, 0xEC, 0xF7, 0xE1, 0x01, 0xBA,
    0x02, 0x9B, 0xF9, 0x03, 0x04, 0x05, 0xF3, 0x06,
    0x07, 0x08, 0xE9, 0xA0, 0x09, 0x80, 0xE5, 0x0A,
    0x15, 0x16, 0xA7, 0xBA, 0xE3, 0xF7, 0xF2, 0xAD,
    0xE2, 0x01, 0x02, 0x9B, 0xE6, 0x03, 0xED, 0xF6,
    0x04, 0xEB, 0x05, 0xF4, 0x06, 0x07, 0x08, 0xF3,
    0x09, 0xF5, 0x0A, 0xEF, 0x0B, 0x0C, 0x80, 0xF9,
    0xE1, 0x0D, 0xE4, 0xE9, 0xA0, 0x0E, 0x0F, 0xEC,
    0xE5, 0x10, 0x11, 0x12, 0x13, 0x14, 0x0A, 0x0B,
    0xF9, 0x9B, 0xF5, 0xF3, 0x01, 0x02, 0xE2, 0xED,
    0x80, 0x03, 0xF0, 0xEF, 0x04, 0xA0, 0x05, 0xE9,
    0x06, 0xE1, 0x07, 0x08, 0x09, 0xE5, 0x18, 0x19,
    0xE2, 0xEA, 0xF2, 0xE8, 0xEC, 0xED, 0xFA, 0x9B,
    0x01, 0xF5, 0x02, 0x03, 0xF6, 0x04, 0xBA, 0xE6,
    0x05, 0x06, 0xEB, 0xEF, 0x07, 0xA7, 0xF9, 0x08,
    0x09, 0x0A, 0x0B, 0xE3, 0x0C, 0xEE, 0xE1, 0x0D,
    0xF3, 0x0E, 0xE9, 0x0F, 0x10, 0xF4, 0x80, 0xE4,
    0xE5, 0x11, 0x12, 0xE7, 0xA0, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x1B, 0x1C, 0xAE, 0xFA, 0xBF, 0x01,
    0xA7, 0x9B, 0x02, 0xE9, 0xF8, 0xF9, 0x03, 0xE5,
    0xE8, 0x04, 0xE1, 0xEB, 0x05, 0xE2, 0x06, 0x07,
    0xE3, 0x08, 0xE7, 0xF4, 0x09, 0x80, 0xF6, 0xF0,
    0x0A, 0xE4, 0x0B, 0xF3, 0xF7, 0x0C, 0x0D, 0xEF,
    0xEC, 0xA0, 0x0E, 0x0F, 0xED, 0xE6, 0x10, 0xF5,
    0x11, 0x12, 0x13, 0x14, 0x15, 0xF2, 0x16, 0xEE,
    0x17, 0x18, 0x19, 0x1A, 0x0E, 0x0F, 0xED, 0xA7,
    0x9B, 0xE4, 0x01, 0xF9, 0xF3, 0xF2, 0xF4, 0x02,
    0xE8, 0x03, 0xEC, 0xF0, 0x04, 0xE1, 0xE9, 0x05,
    0x06, 0x80, 0xA0, 0x07, 0x08, 0x09, 0x0A, 0xE5,
    0xEF, 0x0B, 0x0C, 0x0D, 0x9B, 0xF5, 0x18, 0x19,
    0xBA, 0xAC, 0xF6, 0x9B, 0xF0, 0xE2, 0x01, 0xE6,
    0x02, 0xA7, 0xAE, 0xE7, 0x03, 0xE3, 0xF5, 0x04,
    0xED, 0x05, 0x06, 0x07, 0xEB, 0x08, 0x09, 0xEE,
    0xF2, 0x0A, 0xE4, 0x0B, 0xF9, 0xEC, 0x0C, 0x0D,
    0xF4, 0x80, 0x0E, 0xEF, 0xF3, 0xA0, 0xE1, 0x0F,
    0xE9, 0x10, 0x11, 0xE5, 0x12, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x19, 0x1A, 0xA7, 0xAC, 0xBF, 0xC3,
    0xC8, 0xE4, 0xE6, 0xED, 0xF2, 0xAE, 0xEC, 0xEE,
    0xF9, 0x01, 0x02, 0x03, 0x04, 0xBA, 0x05, 0x9B,
    0xF5, 0x06, 0x07, 0x08, 0x09, 0xEB, 0xF0, 0x0A,
    0x0B, 0x0C, 0xE1, 0xE3, 0x0D, 0xE8, 0x0E, 0x0F,
    0xEF, 0x10, 0x11, 0xF3, 0x12, 0xE9, 0x13, 0xE5,
    0x14, 0x15, 0xF4, 0x16, 0x17, 0xA0, 0x18, 0x80,
    0x14, 0x15, 0xBA, 0xBF, 0xE4, 0xF7, 0x9B, 0xA7,
    0x01, 0xEE, 0x02, 0x03, 0x04, 0xE3, 0xE2, 0xED,
    0x05, 0xF9, 0x06, 0xF4, 0x07, 0xEC, 0x08, 0xF5,
    0xF2, 0x09, 0xE1, 0xF3, 0x0A, 0xEF, 0x0B, 0x0C,
    0x0D, 0xE9, 0x80, 0xE5, 0x0E, 0xA0, 0x0F, 0xE8,
    0x10, 0x11, 0x12, 0x13, 0x11, 0x12, 0xEB, 0xFA,
    0x80, 0xE6, 0x9B, 0x01, 0xA0, 0x02, 0x03, 0xE9,
    0xE1, 0x04, 0xE4, 0xF0, 0xED, 0xE2, 0xE3, 0xE7,
    0xEC, 0x05, 0xE5, 0x06, 0x07, 0x08, 0x09, 0xF4,
    0x0A, 0x0B, 0x0C, 0xF3, 0xEE, 0x0D, 0x0E, 0xF2,
    0x0F, 0x10, 0x04, 0xE5, 0xF3, 0xEF, 0x9B, 0x01,
    0xE1, 0x02, 0x03, 0xE9, 0x0B, 0x0C, 0xA7, 0xE2,
    0xEC, 0xE3, 0xF2, 0x01, 0x9B, 0x02, 0x03, 0x04,
    0xE9, 0xEF, 0xEE, 0xE5, 0xE1, 0x80, 0x05, 0xA0,
    0x06, 0x07, 0x08, 0x09, 0xF3, 0x0A, 0x05, 0x06,
    0x9B, 0xA0, 0xE1, 0xE5, 0xE9, 0x01, 0x80, 0xF0,
    0x02, 0xF4, 0x03, 0x04, 0xA0, 0x13, 0xE3, 0xAD,
    0xE4, 0xE9, 0xEE, 0xEF, 0xF0, 0xF4, 0xF6, 0xA1,
    0xE1, 0xED, 0x01, 0xE2, 0x02, 0x03, 0x04, 0xA7,
    0x05, 0x06, 0xF7, 0x07, 0x9B, 0xEC, 0x08, 0xE5,
    0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0xF3, 0x0F,
    0x10, 0x11, 0x80, 0x12, 0x05, 0x06, 0xE5, 0xFA,
    0xA0, 0xF9, 0x9B, 0x01, 0x80, 0xE9, 0x02, 0xE1,
    0x03, 0x04, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B
};

static const unsigned char ATSC_C7[] =
{
    0x01, 0x00, 0x01, 0x2C, 0x01, 0x2E, 0x01, 0x30,
    0x01, 0x32, 0x01, 0x34, 0x01, 0x36, 0x01, 0x38,
    0x01, 0x3A, 0x01, 0x3C, 0x01, 0x3E, 0x01, 0x40,
    0x01, 0x42, 0x01, 0x44, 0x01, 0x46, 0x01, 0x48,
    0x01, 0x4A, 0x01, 0x4C, 0x01, 0x4E, 0x01, 0x50,
    0x01, 0x52, 0x01, 0x54, 0x01, 0x56, 0x01, 0x58,
    0x01, 0x5A, 0x01, 0x5C, 0x01, 0x5E, 0x01, 0x60,
    0x01, 0x62, 0x01, 0x64, 0x01, 0x66, 0x01, 0x68,
    0x01, 0x6A, 0x01, 0xDE, 0x01, 0xE0, 0x01, 0xEA,
    0x01, 0xEC, 0x01, 0xEE, 0x01, 0xF0, 0x01, 0xF2,
    0x01, 0xF8, 0x01, 0xFA, 0x01, 0xFC, 0x01, 0xFE,
    0x02, 0x00, 0x02, 0x04, 0x02, 0x16, 0x02, 0x20,
    0x02, 0x22, 0x02, 0x2C, 0x02, 0x32, 0x02, 0x38,
    0x02, 0x3C, 0x02, 0x40, 0x02, 0x44, 0x02, 0x46,
    0x02, 0x4A, 0x02, 0x4C, 0x02, 0x54, 0x02, 0x56,
    0x02, 0x58, 0x02, 0x5A, 0x02, 0x5C, 0x02, 0x5E,
    0x02, 0x60, 0x02, 0x62, 0x02, 0x76, 0x02, 0x84,
    0x02, 0x94, 0x02, 0xA2, 0x02, 0xB2, 0x02, 0xBA,
    0x02, 0xC8, 0x02, 0xD2, 0x02, 0xDE, 0x02, 0xEA,
    0x02, 0xF2, 0x02, 0xFC, 0x03, 0x08, 0x03, 0x10,
    0x03, 0x1A, 0x03, 0x28, 0x03, 0x2A, 0x03, 0x34,
    0x03, 0x4A, 0x03, 0x5A, 0x03, 0x5E, 0x03, 0x64,
    0x03, 0x6E, 0x03, 0x70, 0x03, 0x72, 0x03, 0x74,
    0x03, 0x76, 0x03, 0x78, 0x03, 0x7A, 0x03, 0x7C,
    0x03, 0x7E, 0x03, 0x80, 0x03, 0xB4, 0x03, 0xCE,
    0x03, 0xF0, 0x04, 0x1A, 0x04, 0x58, 0x04, 0x6E,
    0x04, 0x8E, 0x04, 0xAC, 0x04, 0xD8, 0x04, 0xE0,
    0x04, 0xF4, 0x05, 0x24, 0x05, 0x40, 0x05, 0x76,
    0x05, 0xAE, 0x05, 0xCE, 0x05, 0xD0, 0x06, 0x06,
    0x06, 0x34, 0x06, 0x60, 0x06, 0x86, 0x06, 0x92,
    0x06, 0xAA, 0x06, 0xB8, 0x06, 0xDC, 0x06, 0xEC,
    0x06, 0xEE, 0x06, 0xF0, 0x06, 0xF2, 0x06, 0xF4,
    0x14, 0x15, 0x9B, 0xD6, 0xC9, 0xCF, 0xD7, 0xC7,
    0x01, 0xA2, 0xCE, 0xCB, 0x02, 0x03, 0xC5, 0xCC,
    0xC6, 0xC8, 0x04, 0xC4, 0x05, 0xC2, 0x06, 0xC3,
    0xD2, 0x07, 0xD3, 0x08, 0xCA, 0xD4, 0x09, 0xCD,
    0xD0, 0x0A, 0xC1, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x38, 0x39, 0xAD, 0xAF, 0xB7, 0xDA,
    0xA8, 0xB3, 0xB5, 0x01, 0x02, 0x9B, 0xB4, 0xF1,
    0xA2, 0xD5, 0xD6, 0xD9, 0x03, 0x04, 0x05, 0xCF,
    0x06, 0xC9, 0xF9, 0xEA, 0xEB, 0xF5, 0xF6, 0x07,
    0x08, 0x09, 0xB2, 0xC5, 0xC6, 0xB1, 0x0A, 0xEE,
    0xCB, 0x0B, 0xD4, 0x0C, 0xC4, 0xC8, 0xD2, 0x0D,
    0x0E, 0x0F, 0xC7, 0xCA, 0xCE, 0xD0, 0xD7, 0x10,
    0xC2, 0x11, 0xCC, 0xEC, 0xE5, 0xE7, 0x12, 0xCD,
    0x13, 0x14, 0xC3, 0x15, 0x16, 0x17, 0xED, 0x18,
    0x19, 0xF2, 0x1A, 0xD3, 0x1B, 0x1C, 0xE4, 0x1D,
    0xC1, 0xE3, 0x1E, 0xE9, 0xF0, 0xE2, 0xF7, 0x1F,
    0xF3, 0xE6, 0x20, 0x21, 0x22, 0xE8, 0xEF, 0x23,
    0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0xF4,
    0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0xE1, 0x30, 0x31,
    0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x9B, 0x9B,
    0x03, 0x04, 0x80, 0xAE, 0xC8, 0xD4, 0x01, 0x02,
    0x9B, 0xA0, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x02, 0xF3, 0xA0, 0xF4, 0x9B, 0x01,
    0x9B, 0x9B, 0xAC, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x01, 0xA0, 0x9B, 0xA2, 0x07, 0x08, 0xE2, 0xE4,
    0xE5, 0xE6, 0xA0, 0xF2, 0xE1, 0x01, 0x02, 0xF3,
    0xE3, 0x03, 0x04, 0x05, 0x9B, 0x06, 0x04, 0x80,
    0xCA, 0xD3, 0xA2, 0x01, 0x9B, 0x02, 0x03, 0xA0,
    0x9B, 0xA0, 0x03, 0x04, 0x9B, 0xB7, 0xF4, 0xA0,
    0xB0, 0xF3, 0x01, 0x02, 0xB9, 0x02, 0xB8, 0x9B,
    0xA0, 0x01, 0xAE, 0x02, 0xB6, 0x9B, 0x01, 0xA0,
    0xA0, 0x01, 0x9B, 0xB0, 0xAE, 0x01, 0x9B, 0xA0,
    0xAE, 0x01, 0xA0, 0x9B, 0x9B, 0x9B, 0x9B, 0x01,
    0xAC, 0xAE, 0x9B, 0x9B, 0x02, 0x03, 0x9B, 0xA0,
    0xB5, 0xB6, 0xB8, 0x01, 0x9B, 0xA0, 0x9B, 0xA0,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0xA0,
    0x9B, 0x9B, 0x08, 0x09, 0xE6, 0xF5, 0xF3, 0xF4,
    0x9B, 0xE4, 0x01, 0xED, 0x02, 0x03, 0x04, 0xF2,
    0x05, 0x06, 0xEC, 0xEE, 0x07, 0xA0, 0x05, 0x06,
    0x9B, 0xEC, 0xF5, 0x01, 0x02, 0xE1, 0xEF, 0xE5,
    0xE9, 0xF2, 0x03, 0x04, 0x06, 0x07, 0x9B, 0xE9,
    0xF9, 0xF2, 0xF5, 0x01, 0x02, 0x03, 0xEC, 0xEF,
    0xE1, 0x04, 0xE8, 0x05, 0x05, 0x06, 0xF9, 0xF2,
    0xF5, 0x9B, 0xE5, 0xEF, 0x01, 0x02, 0xE9, 0xE1,
    0x03, 0x04, 0x06, 0x07, 0xE1, 0xE9, 0xEE, 0xF6,
    0xE4, 0xEC, 0xF3, 0x01, 0x02, 0xF2, 0x03, 0x04,
    0x9B, 0x05, 0x02, 0x03, 0xE5, 0xEC, 0x9B, 0xEF,
    0x01, 0xF2, 0x05, 0x06, 0xF5, 0xEF, 0x9B, 0xEC,
    0xE9, 0x01, 0xE1, 0xF2, 0x02, 0xE5, 0x03, 0x04,
    0x03, 0x04, 0x9B, 0xE5, 0xE9, 0xF5, 0xE1, 0x01,
    0xEF, 0x02, 0x04, 0x05, 0xA0, 0xC9, 0xF3, 0x9B,
    0xAE, 0xF2, 0x01, 0x02, 0x03, 0xEE, 0xEF, 0x05,
    0x9B, 0xAE, 0xE9, 0xE5, 0x01, 0xF5, 0x02, 0xE1,
    0x03, 0x04, 0xE5, 0x03, 0xE1, 0xE9, 0xF2, 0x9B,
    0x01, 0x02, 0x03, 0x04, 0x9B, 0xE9, 0xF5, 0x01,
    0xE5, 0x02, 0xEF, 0xE1, 0xE1, 0x05, 0x9B, 0xE3,
    0xEF, 0x01, 0xF5, 0xE5, 0x02, 0x03, 0xE9, 0x04,
    0xE5, 0x03, 0x9B, 0xE9, 0x01, 0xE1, 0xEF, 0x02,
    0x03, 0x04, 0xA7, 0xEE, 0xEC, 0xF2, 0xF3, 0x01,
    0x9B, 0x02, 0xE1, 0x06, 0x9B, 0xE8, 0xE9, 0x01,
    0xF2, 0xEC, 0x02, 0xEF, 0x03, 0xE5, 0x04, 0x05,
    0x9B, 0x9B, 0x03, 0x04, 0x9B, 0xAE, 0x01, 0xE9,
    0x02, 0xE1, 0xE5, 0xEF, 0x09, 0x0A, 0xF6, 0xF9,
    0x01, 0xAE, 0xE3, 0xE9, 0xF5, 0x9B, 0xE5, 0xEF,
    0x02, 0x03, 0xE1, 0x04, 0xE8, 0x05, 0x06, 0xF4,
    0x07, 0x08, 0xE8, 0x07, 0xE5, 0xF7, 0xD6, 0xE1,
    0x9B, 0xE9, 0xF2, 0x01, 0x02, 0x03, 0x04, 0xEF,
    0x05, 0x06, 0xAE, 0x01, 0x9B, 0xEE, 0xE9, 0x02,
    0xE5, 0x9B, 0xA0, 0x01, 0x03, 0x04, 0x9B, 0xE8,
    0xE5, 0xE1, 0xEF, 0x01, 0xE9, 0x02, 0x9B, 0x9B,
    0x9B, 0xEF, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B,
    0x18, 0x19, 0xE8, 0xEF, 0xF8, 0x9B, 0xA7, 0xF7,
    0xFA, 0x01, 0x02, 0x03, 0x04, 0xE5, 0xAE, 0x05,
    0xE6, 0xE2, 0x06, 0xF6, 0xEB, 0xF5, 0xE9, 0x07,
    0xF0, 0xF9, 0xE7, 0x08, 0x09, 0xE4, 0x0A, 0xE3,
    0x0B, 0xED, 0x0C, 0xF3, 0x0D, 0x0E, 0x0F, 0xEC,
    0x10, 0xF4, 0x11, 0x12, 0xF2, 0xA0, 0x13, 0x14,
    0x15, 0xEE, 0x16, 0x17, 0x0B, 0x0C, 0xE4, 0xF3,
    0x9B, 0xAE, 0xE2, 0x01, 0x02, 0x03, 0xEC, 0xA0,
    0x04, 0xE9, 0xF2, 0xF5, 0x05, 0xF9, 0xE1, 0x06,
    0xEF, 0x07, 0xE5, 0x08, 0x09, 0x0A, 0x0F, 0x10,
    0xF1, 0xAE, 0xC4, 0xF9, 0xAC, 0x01, 0xE3, 0x02,
    0x9B, 0xF2, 0x03, 0x04, 0xA0, 0xEC, 0xF5, 0x05,
    0x06, 0xE9, 0x07, 0xEB, 0x08, 0xF4, 0x09, 0xE5,
    0x0A, 0xEF, 0xE1, 0xE8, 0x0B, 0x0C, 0x0D, 0x0E,
    0x13, 0x14, 0xA7, 0xBB, 0xE6, 0xED, 0xF7, 0xE7,
    0xF6, 0x01, 0x02, 0x9B, 0xEE, 0x03, 0x04, 0xEC,
    0x05, 0xF5, 0x06, 0xAC, 0xE4, 0xF9, 0xF2, 0x07,
    0x08, 0x09, 0xAE, 0x0A, 0xEF, 0x0B, 0xE1, 0xF3,
    0x0C, 0xE9, 0x0D, 0x0E, 0x0F, 0x10, 0xE5, 0x11,
    0x12, 0xA0, 0x1D, 0x1E, 0xA9, 0xE8, 0xF5, 0x9B,
    0x01, 0xAD, 0xBB, 0xEB, 0xFA, 0x02, 0xA7, 0xE6,
    0xE2, 0xE7, 0x03, 0x04, 0x05, 0x06, 0xE9, 0xF8,
    0x07, 0xAC, 0xEF, 0xF0, 0x08, 0xED, 0xF6, 0xF9,
    0x09, 0xF7, 0x0A, 0x0B, 0xAE, 0x0C, 0xE3, 0x0D,
    0xE5, 0xF4, 0x0E, 0x0F, 0xE4, 0x10, 0xEC, 0x11,
    0xE1, 0x12, 0x13, 0x14, 0x15, 0x16, 0xEE, 0xF3,
    0x17, 0x18, 0xF2, 0xA0, 0x19, 0x1A, 0x1B, 0x1C,
    0x09, 0x0A, 0xAE, 0x9B, 0xEC, 0x01, 0xF5, 0x02,
    0xF4, 0xE6, 0x03, 0xE1, 0xE5, 0xE9, 0x04, 0xF2,
    0xEF, 0x05, 0x06, 0x07, 0xA0, 0x08, 0x0E, 0x0F,
    0xAD, 0xE7, 0x9B, 0xA7, 0xF9, 0x01, 0xEC, 0x02,
    0xAC, 0xF2, 0x03, 0xAE, 0xF3, 0xF5, 0x04, 0x05,
    0xEF, 0x06, 0x07, 0xE9, 0xE1, 0x08, 0x09, 0xE8,
    0x0A, 0x0B, 0xE5, 0x0C, 0xA0, 0x0D, 0x0D, 0x0E,
    0xA7, 0xAC, 0xF3, 0xAD, 0x01, 0x02, 0x9B, 0xF9,
    0xF5, 0xAE, 0x03, 0xEE, 0x04, 0xF2, 0x05, 0x06,
    0xF4, 0x07, 0x08, 0x09, 0xEF, 0xE1, 0xA0, 0x0A,
    0xE9, 0x0B, 0x0C, 0xE5, 0x14, 0x15, 0xAC, 0xE2,
    0xF8, 0x9B, 0xAE, 0xFA, 0x01, 0xEB, 0x02, 0xA0,
    0x03, 0x04, 0xF0, 0x05, 0x06, 0xE6, 0xF6, 0x07,
    0xE4, 0xED, 0xE7, 0x08, 0xE1, 0xEF, 0xF2, 0x09,
    0x0A, 0x0B, 0xEC, 0x0C, 0xE5, 0xE3, 0x0D, 0xF4,
    0x0E, 0xF3, 0x0F, 0x10, 0x11, 0xEE, 0x12, 0x13,
    0x03, 0xEF, 0x9B, 0xE1, 0xE5, 0xF5, 0x01, 0x02,
    0x08, 0x09, 0xEC, 0xF9, 0xA7, 0xEE, 0x01, 0xAC,
    0x9B, 0xAE, 0x02, 0x03, 0x04, 0xF3, 0x05, 0xE9,
    0x06, 0xA0, 0x07, 0xE5, 0x16, 0x17, 0xA7, 0xAD,
    0xEE, 0xE3, 0xEB, 0xF2, 0x9B, 0xE2, 0x01, 0x02,
    0xF5, 0x03, 0xF4, 0xAC, 0x04, 0x05, 0xE6, 0xED,
    0xF6, 0x06, 0xAE, 0xF0, 0x07, 0x08, 0xF3, 0x09,
    0x0A, 0xE4, 0x0B, 0x0C, 0xF9, 0x0D, 0xEF, 0x0E,
    0xE1, 0x0F, 0x10, 0xE9, 0xEC, 0x11, 0xA0, 0xE5,
    0x12, 0x13, 0x14, 0x15, 0x0C, 0x0D, 0xA7, 0xBB,
    0x9B, 0x01, 0xF9, 0xAE, 0xE2, 0x02, 0xED, 0xF3,
    0x03, 0xF5, 0xEF, 0xF0, 0x04, 0x05, 0xE9, 0x06,
    0x07, 0x08, 0x09, 0xA0, 0xE1, 0xE5, 0x0A, 0x0B,
    0x19, 0x1A, 0xAD, 0xBB, 0xE2, 0xEA, 0xED, 0xF2,
    0xFA, 0xE6, 0xEC, 0x01, 0x02, 0x03, 0x9B, 0xF5,
    0x04, 0xA7, 0xF6, 0xF9, 0x05, 0x06, 0xEB, 0xEF,
    0x07, 0x08, 0x09, 0x0A, 0xAC, 0x0B, 0x0C, 0xE3,
    0xAE, 0x0D, 0xEE, 0xE9, 0x0E, 0xE1, 0x0F, 0xF3,
    0x10, 0x11, 0xF4, 0x12, 0xE7, 0xE5, 0x13, 0x14,
    0xE4, 0x15, 0x16, 0x17, 0xA0, 0x18, 0x1A, 0x1B,
    0xC2, 0x9B, 0xAD, 0xAC, 0xF8, 0x01, 0xAE, 0x02,
    0x03, 0xE5, 0xE7, 0xE8, 0xF9, 0xE9, 0xEB, 0x04,
    0xE3, 0xE1, 0x05, 0xF6, 0x06, 0xE4, 0x07, 0xE2,
    0xF0, 0x08, 0x09, 0xF3, 0xF4, 0xF7, 0xEF, 0x0A,
    0x0B, 0x0C, 0x0D, 0xEC, 0x0E, 0x0F, 0x10, 0xF5,
    0xED, 0x11, 0xE6, 0xA0, 0x12, 0xF2, 0x13, 0x14,
    0x15, 0xEE, 0x16, 0x17, 0x18, 0x19, 0x0E, 0x0F,
    0xAD, 0xED, 0xF9, 0x9B, 0xAE, 0x01, 0xF3, 0x02,
    0x03, 0xF5, 0xF4, 0xF0, 0x04, 0xEF, 0x05, 0xE9,
    0x06, 0xE8, 0xA0, 0xE1, 0xEC, 0x07, 0xF2, 0x08,
    0xE5, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x9B, 0xF5,
    0x19, 0x1A, 0xA9, 0xBB, 0xF6, 0xE6, 0x01, 0x9B,
    0xAD, 0xE2, 0xF0, 0x02, 0xA7, 0x03, 0x04, 0x05,
    0xF5, 0xE3, 0xAC, 0xE7, 0xF2, 0x06, 0xEB, 0x07,
    0xEC, 0xED, 0xEE, 0xF9, 0x08, 0xAE, 0x09, 0x0A,
    0xE4, 0x0B, 0x0C, 0xF4, 0x0D, 0xF3, 0x0E, 0x0F,
    0x10, 0xE1, 0xEF, 0x11, 0xE9, 0x12, 0x13, 0xE5,
    0x14, 0xA0, 0x15, 0x16, 0x17, 0x18, 0xA0, 0x16,
    0xA2, 0xA7, 0xE2, 0xEB, 0xED, 0xEE, 0x9B, 0xF7,
    0x01, 0x02, 0x03, 0xBB, 0xF9, 0xF0, 0x04, 0x05,
    0xEC, 0x06, 0x07, 0x08, 0xF5, 0xE1, 0x09, 0xAC,
    0xE3, 0x0A, 0xE8, 0x0B, 0xE9, 0x0C, 0xEF, 0xF3,
    0xAE, 0x0D, 0x0E, 0xE5, 0x0F, 0x10, 0x11, 0xF4,
    0x12, 0x13, 0x14, 0x15, 0x14, 0x15, 0xBB, 0xE2,
    0xAD, 0xED, 0x01, 0x9B, 0xA7, 0xE3, 0xAC, 0xEC,
    0xEE, 0x02, 0xF7, 0x03, 0x04, 0xF9, 0x05, 0x06,
    0x07, 0x08, 0xF4, 0xAE, 0xF5, 0x09, 0x0A, 0xF2,
    0xE1, 0xF3, 0x0B, 0x0C, 0x0D, 0xE9, 0x0E, 0x0F,
    0xEF, 0xE5, 0x10, 0xA0, 0xE8, 0x11, 0x12, 0x13,
    0x11, 0x12, 0xEF, 0xF6, 0x9B, 0xEB, 0xF9, 0x01,
    0xA0, 0xE2, 0x02, 0xE1, 0x03, 0xED, 0x04, 0xE3,
    0xE9, 0x05, 0xE4, 0xE5, 0xE7, 0x06, 0xEC, 0xF0,
    0x07, 0x08, 0x09, 0x0A, 0x0B, 0xF3, 0x0C, 0xF4,
    0xEE, 0x0D, 0xF2, 0x0E, 0x0F, 0x10, 0x05, 0xE5,
    0xF3, 0xF9, 0x9B, 0x01, 0xEF, 0x02, 0x03, 0xE1,
    0x04, 0xE9, 0x0A, 0x0B, 0xAE, 0x9B, 0xEC, 0xED,
    0x01, 0x02, 0xF3, 0xEE, 0xF2, 0x03, 0xE5, 0x04,
    0xE8, 0xA0, 0xE1, 0x05, 0xEF, 0x06, 0x07, 0x08,
    0xE9, 0x09, 0x05, 0x06, 0xA0, 0xAC, 0xAD, 0xF4,
    0xE9, 0x01, 0x02, 0xE1, 0xE5, 0x03, 0x9B, 0x04,
    0x11, 0xA0, 0xBF, 0xE1, 0xE2, 0xE6, 0xED, 0xE4,
    0xE9, 0xF7, 0xA7, 0x01, 0x02, 0xBB, 0x03, 0x04,

    0xEC, 0x05, 0x9B, 0xEE, 0x06, 0xEF, 0x07, 0xAC,
    0xE5, 0xF3, 0x08, 0x09, 0x0A, 0xAE, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10, 0x06, 0x07, 0xA0, 0xAE,
    0xE1, 0xE5, 0xEC, 0xFA, 0x9B, 0xEF, 0xE9, 0x01,
    0x02, 0x03, 0x04, 0x05, 0x9B, 0x9B, 0x9B, 0x9B,
    0x9B, 0x9B, 0x9B, 0x9B, 0x9B, 0x9B
};


static const unsigned char *atsc_tables[] =
{
    ATSC_C5,
    ATSC_C7,
};


/* returns the root for character input from table Table[] */
static int huffman_get_root(unsigned int input, const unsigned char *table)
{
    if (input > 127)
        return -1;
    return (table[input * 2] << 8) | table[(input * 2) + 1];
}

/* Returns the bit number bit from string test[] */
static bool huffman_get_bit(const unsigned char *src, unsigned int bit)
{
    return (src[(bit - (bit & 0x7)) >> 3] >> (7 - (bit & 0x7))) & 0x01;
}

int psi_atsc_huffman_to_string(unsigned char *out_str, const unsigned char *compressed,
                                unsigned int size, unsigned int table_index)
{
    unsigned char *pstr = out_str;
    const unsigned char *table = atsc_tables[table_index];
    int totalbits = size * 8;
    int bit = 0;
    int root = huffman_get_root(0, table);
    int node = 0;
    bool thebit;
    unsigned char val;
	int str_bytes = 0;

    while (bit < totalbits)
    {
        thebit = huffman_get_bit(compressed, bit);
        val = (thebit) ? table[root + (node*2) + 1] : table[root + (node*2)];

        if (val & 0x80)
        {
            /* Got a Null Character so return */
            if ((val & 0x7F) == 0)
            {
                return str_bytes;//return out_str;
            }
            /* Escape character so next character is uncompressed */
            if ((val & 0x7F) == 27)
            {
                int i;
                unsigned char val2 = 0;
                for (i = 0 ; i < 7 ; i++)
                {
                    val2 |= huffman_get_bit(compressed, bit + i + 2) << (6 - i);
                }
                *pstr++ = (char)val2;
				str_bytes ++;
                bit += 8;
                root = huffman_get_root(val2, table);
            }
            /* Standard Character */
            else
            {
                root = huffman_get_root(val & 0x7F, table);
                *pstr++ = (char)(val & 0x7F);
				str_bytes ++;
            }
            node = 0;
        }
        else
        {
            node = val;
        }
        bit++;
    }
    /* If you get here something went wrong so just return a blank string */
    //AM_TRACE("something went wrong!\n");
    return (str_bytes);
}
