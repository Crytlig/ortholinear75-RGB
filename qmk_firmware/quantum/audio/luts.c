#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "luts.h"

const float vibrato_lut[VIBRATO_LUT_LENGTH] =
{
	1.0022336811487,
	1.0042529943610,
	1.0058584256028,
	1.0068905285205,
	1.0072464122237,
	1.0068905285205,
	1.0058584256028,
	1.0042529943610,
	1.0022336811487,
	1.0000000000000,
	0.9977712970630,
	0.9957650169978,
	0.9941756956510,
	0.9931566259436,
	0.9928057204913,
	0.9931566259436,
	0.9941756956510,
	0.9957650169978,
	0.9977712970630,
	1.0000000000000,
};

const uint16_t frequency_lut[FREQUENCY_LUT_LENGTH] =
{
	0x8E0B,
	0x8C02,
	0x8A00,
	0x8805,
	0x8612,
	0x8426,
	0x8241,
	0x8063,
	0x7E8C,
	0x7CBB,
	0x7AF2,
	0x792E,
	0x7772,
	0x75BB,
	0x740B,
	0x7261,
	0x70BD,
	0x6F20,
	0x6D88,
	0x6BF6,
	0x6A69,
	0x68E3,
	0x6762,
	0x65E6,
	0x6470,
	0x6300,
	0x6194,
	0x602E,
	0x5ECD,
	0x5D71,
	0x5C1A,
	0x5AC8,
	0x597B,
	0x5833,
	0x56EF,
	0x55B0,
	0x5475,
	0x533F,
	0x520E,
	0x50E1,
	0x4FB8,
	0x4E93,
	0x4D73,
	0x4C57,
	0x4B3E,
	0x4A2A,
	0x491A,
	0x480E,
	0x4705,
	0x4601,
	0x4500,
	0x4402,
	0x4309,
	0x4213,
	0x4120,
	0x4031,
	0x3F46,
	0x3E5D,
	0x3D79,
	0x3C97,
	0x3BB9,
	0x3ADD,
	0x3A05,
	0x3930,
	0x385E,
	0x3790,
	0x36C4,
	0x35FB,
	0x3534,
	0x3471,
	0x33B1,
	0x32F3,
	0x3238,
	0x3180,
	0x30CA,
	0x3017,
	0x2F66,
	0x2EB8,
	0x2E0D,
	0x2D64,
	0x2CBD,
	0x2C19,
	0x2B77,
	0x2AD8,
	0x2A3A,
	0x299F,
	0x2907,
	0x2870,
	0x27DC,
	0x2749,
	0x26B9,
	0x262B,
	0x259F,
	0x2515,
	0x248D,
	0x2407,
	0x2382,
	0x2300,
	0x2280,
	0x2201,
	0x2184,
	0x2109,
	0x2090,
	0x2018,
	0x1FA3,
	0x1F2E,
	0x1EBC,
	0x1E4B,
	0x1DDC,
	0x1D6E,
	0x1D02,
	0x1C98,
	0x1C2F,
	0x1BC8,
	0x1B62,
	0x1AFD,
	0x1A9A,
	0x1A38,
	0x19D8,
	0x1979,
	0x191C,
	0x18C0,
	0x1865,
	0x180B,
	0x17B3,
	0x175C,
	0x1706,
	0x16B2,
	0x165E,
	0x160C,
	0x15BB,
	0x156C,
	0x151D,
	0x14CF,
	0x1483,
	0x1438,
	0x13EE,
	0x13A4,
	0x135C,
	0x1315,
	0x12CF,
	0x128A,
	0x1246,
	0x1203,
	0x11C1,
	0x1180,
	0x1140,
	0x1100,
	0x10C2,
	0x1084,
	0x1048,
	0x100C,
	0xFD1,
	0xF97,
	0xF5E,
	0xF25,
	0xEEE,
	0xEB7,
	0xE81,
	0xE4C,
	0xE17,
	0xDE4,
	0xDB1,
	0xD7E,
	0xD4D,
	0xD1C,
	0xCEC,
	0xCBC,
	0xC8E,
	0xC60,
	0xC32,
	0xC05,
	0xBD9,
	0xBAE,
	0xB83,
	0xB59,
	0xB2F,
	0xB06,
	0xADD,
	0xAB6,
	0xA8E,
	0xA67,
	0xA41,
	0xA1C,
	0x9F7,
	0x9D2,
	0x9AE,
	0x98A,
	0x967,
	0x945,
	0x923,
	0x901,
	0x8E0,
	0x8C0,
	0x8A0,
	0x880,
	0x861,
	0x842,
	0x824,
	0x806,
	0x7E8,
	0x7CB,
	0x7AF,
	0x792,
	0x777,
	0x75B,
	0x740,
	0x726,
	0x70B,
	0x6F2,
	0x6D8,
	0x6BF,
	0x6A6,
	0x68E,
	0x676,
	0x65E,
	0x647,
	0x630,
	0x619,
	0x602,
	0x5EC,
	0x5D7,
	0x5C1,
	0x5AC,
	0x597,
	0x583,
	0x56E,
	0x55B,
	0x547,
	0x533,
	0x520,
	0x50E,
	0x4FB,
	0x4E9,
	0x4D7,
	0x4C5,
	0x4B3,
	0x4A2,
	0x491,
	0x480,
	0x470,
	0x460,
	0x450,
	0x440,
	0x430,
	0x421,
	0x412,
	0x403,
	0x3F4,
	0x3E5,
	0x3D7,
	0x3C9,
	0x3BB,
	0x3AD,
	0x3A0,
	0x393,
	0x385,
	0x379,
	0x36C,
	0x35F,
	0x353,
	0x347,
	0x33B,
	0x32F,
	0x323,
	0x318,
	0x30C,
	0x301,
	0x2F6,
	0x2EB,
	0x2E0,
	0x2D6,
	0x2CB,
	0x2C1,
	0x2B7,
	0x2AD,
	0x2A3,
	0x299,
	0x290,
	0x287,
	0x27D,
	0x274,
	0x26B,
	0x262,
	0x259,
	0x251,
	0x248,
	0x240,
	0x238,
	0x230,
	0x228,
	0x220,
	0x218,
	0x210,
	0x209,
	0x201,
	0x1FA,
	0x1F2,
	0x1EB,
	0x1E4,
	0x1DD,
	0x1D6,
	0x1D0,
	0x1C9,
	0x1C2,
	0x1BC,
	0x1B6,
	0x1AF,
	0x1A9,
	0x1A3,
	0x19D,
	0x197,
	0x191,
	0x18C,
	0x186,
	0x180,
	0x17B,
	0x175,
	0x170,
	0x16B,
	0x165,
	0x160,
	0x15B,
	0x156,
	0x151,
	0x14C,
	0x148,
	0x143,
	0x13E,
	0x13A,
	0x135,
	0x131,
	0x12C,
	0x128,
	0x124,
	0x120,
	0x11C,
	0x118,
	0x114,
	0x110,
	0x10C,
	0x108,
	0x104,
	0x100,
	0xFD,
	0xF9,
	0xF5,
	0xF2,
	0xEE,
};

