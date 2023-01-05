#include "data.hpp"
#include <cstddef>
#include <cassert>

namespace sl {

namespace sw
{

template<Ratio T = double>
constexpr static inline T SHAPIRO_WILK_COEFFICIENTS[] = {
	0.7071,
	0.7071,
	0.6872,
	0.1677,
	0.6646,
	0.2413,
	0.6431,
	0.2806,
	0.0875,
	0.6233,
	0.3031,
	0.1401,
	0.6052,
	0.3164,
	0.1743,
	0.0561,
	0.5888,
	0.3244,
	0.1976,
	0.0947,
	0.5739,
	0.3291,
	0.2141,
	0.1224,
	0.0399,
	0.5601,
	0.3315,
	0.2260,
	0.1429,
	0.0695,
	0.5475,
	0.3325,
	0.2347,
	0.1586,
	0.0922,
	0.0303,
	0.5359,
	0.3325,
	0.2412,
	0.1707,
	0.1099,
	0.0539,
	0.5251,
	0.3318,
	0.2460,
	0.1802,
	0.1240,
	0.0727,
	0.0240,
	0.5150,
	0.3306,
	0.2495,
	0.1878,
	0.1353,
	0.0880,
	0.0433,
	0.5056,
	0.3290,
	0.2521,
	0.1939,
	0.1447,
	0.1005,
	0.0593,
	0.0196,
	0.4968,
	0.3273,
	0.2540,
	0.1988,
	0.1524,
	0.1109,
	0.0725,
	0.0359,
	0.4886,
	0.3253,
	0.2553,
	0.2027,
	0.1587,
	0.1197,
	0.0837,
	0.0496,
	0.0163,
	0.4808,
	0.3232,
	0.2561,
	0.2059,
	0.1641,
	0.1271,
	0.0932,
	0.0612,
	0.0303,
	0.4734,
	0.3211,
	0.2565,
	0.2085,
	0.1686,
	0.1334,
	0.1013,
	0.0711,
	0.0422,
	0.0140,
	0.4643,
	0.3185,
	0.2578,
	0.2119,
	0.1736,
	0.1399,
	0.1092,
	0.0804,
	0.0530,
	0.0263,
	0.4590,
	0.3156,
	0.2571,
	0.2131,
	0.1764,
	0.1443,
	0.1150,
	0.0878,
	0.0618,
	0.0368,
	0.0122,
	0.4542,
	0.3126,
	0.2563,
	0.2139,
	0.1787,
	0.1480,
	0.1201,
	0.0941,
	0.0696,
	0.0459,
	0.0228,
	0.4493,
	0.3098,
	0.2554,
	0.2145,
	0.1807,
	0.1512,
	0.1245,
	0.0997,
	0.0764,
	0.0539,
	0.0321,
	0.0107,
	0.4450,
	0.3069,
	0.2543,
	0.2148,
	0.1822,
	0.1539,
	0.1283,
	0.1046,
	0.0823,
	0.0610,
	0.0403,
	0.0200,
	0.4407,
	0.3043,
	0.2533,
	0.2151,
	0.1836,
	0.1563,
	0.1316,
	0.1089,
	0.0876,
	0.0672,
	0.0476,
	0.0284,
	0.0094,
	0.4366,
	0.3018,
	0.2522,
	0.2152,
	0.1848,
	0.1584,
	0.1346,
	0.1128,
	0.0923,
	0.0728,
	0.0540,
	0.0358,
	0.0178,
	0.4328,
	0.2992,
	0.2510,
	0.2151,
	0.1857,
	0.1601,
	0.1372,
	0.1162,
	0.0965,
	0.0778,
	0.0598,
	0.0424,
	0.0253,
	0.0084,
	0.4291,
	0.2968,
	0.2499,
	0.2150,
	0.1864,
	0.1616,
	0.1395,
	0.1192,
	0.1002,
	0.0822,
	0.0650,
	0.0483,
	0.0320,
	0.0159,
	0.4254,
	0.2944,
	0.2487,
	0.2148,
	0.1870,
	0.1630,
	0.1415,
	0.1219,
	0.1036,
	0.0862,
	0.0697,
	0.0537,
	0.0381,
	0.0227,
	0.0076,
	0.4220,
	0.2921,
	0.2475,
	0.2145,
	0.1874,
	0.1641,
	0.1433,
	0.1243,
	0.1066,
	0.0899,
	0.0739,
	0.0585,
	0.0435,
	0.0289,
	0.0144,
	0.4188,
	0.2898,
	0.2463,
	0.2141,
	0.1878,
	0.1651,
	0.1449,
	0.1265,
	0.1093,
	0.0931,
	0.0777,
	0.0629,
	0.0485,
	0.0344,
	0.0206,
	0.0068,
	0.4156,
	0.2876,
	0.2451,
	0.2137,
	0.1880,
	0.1660,
	0.1463,
	0.1284,
	0.1118,
	0.0961,
	0.0812,
	0.0669,
	0.0530,
	0.0395,
	0.0262,
	0.0131,
	0.4127,
	0.2854,
	0.2439,
	0.2132,
	0.1882,
	0.1667,
	0.1475,
	0.1301,
	0.1140,
	0.0988,
	0.0844,
	0.0706,
	0.0572,
	0.0441,
	0.0314,
	0.0187,
	0.0062,
	0.4096,
	0.2834,
	0.2427,
	0.2127,
	0.1883,
	0.1673,
	0.1487,
	0.1317,
	0.1160,
	0.1013,
	0.0873,
	0.0739,
	0.0610,
	0.0484,
	0.0361,
	0.0239,
	0.0119,
	0.4068,
	0.2813,
	0.2415,
	0.2121,
	0.1883,
	0.1678,
	0.1496,
	0.1331,
	0.1179,
	0.1036,
	0.0900,
	0.0770,
	0.0645,
	0.0523,
	0.0404,
	0.0287,
	0.0172,
	0.0057,
	0.4040,
	0.2794,
	0.2403,
	0.2116,
	0.1883,
	0.1683,
	0.1505,
	0.1344,
	0.1196,
	0.1056,
	0.0924,
	0.0798,
	0.0677,
	0.0559,
	0.0444,
	0.0331,
	0.0220,
	0.0110,
	0.4015,
	0.2774,
	0.2391,
	0.2110,
	0.1881,
	0.1686,
	0.1513,
	0.1356,
	0.1211,
	0.1075,
	0.0947,
	0.0824,
	0.0706,
	0.0592,
	0.0481,
	0.0372,
	0.0264,
	0.0158,
	0.0053,
	0.3989,
	0.2755,
	0.2380,
	0.2104,
	0.1880,
	0.1689,
	0.1520,
	0.1366,
	0.1225,
	0.1092,
	0.0967,
	0.0848,
	0.0733,
	0.0622,
	0.0515,
	0.0409,
	0.0305,
	0.0203,
	0.0101,
	0.3964,
	0.2737,
	0.2368,
	0.2098,
	0.1878,
	0.1691,
	0.1526,
	0.1376,
	0.1237,
	0.1108,
	0.0986,
	0.0870,
	0.0759,
	0.0651,
	0.0546,
	0.0444,
	0.0343,
	0.0244,
	0.0146,
	0.0049,
	0.3940,
	0.2719,
	0.2357,
	0.2091,
	0.1876,
	0.1693,
	0.1531,
	0.1384,
	0.1249,
	0.1123,
	0.1004,
	0.0891,
	0.0782,
	0.0677,
	0.0575,
	0.0476,
	0.0379,
	0.0283,
	0.0188,
	0.0094,
	0.3917,
	0.2701,
	0.2345,
	0.2085,
	0.1874,
	0.1694,
	0.1535,
	0.1392,
	0.1259,
	0.1136,
	0.1020,
	0.0909,
	0.0804,
	0.0701,
	0.0602,
	0.0506,
	0.0411,
	0.0318,
	0.0227,
	0.0136,
	0.0045,
	0.3894,
	0.2684,
	0.2334,
	0.2078,
	0.1871,
	0.1695,
	0.1539,
	0.1398,
	0.1269,
	0.1149,
	0.1035,
	0.0927,
	0.0824,
	0.0724,
	0.0628,
	0.0534,
	0.0442,
	0.0352,
	0.0263,
	0.0175,
	0.0087,
	0.3872,
	0.2667,
	0.2323,
	0.2072,
	0.1868,
	0.1695,
	0.1542,
	0.1405,
	0.1278,
	0.1160,
	0.1049,
	0.0943,
	0.0842,
	0.0745,
	0.0651,
	0.0560,
	0.0471,
	0.0383,
	0.0296,
	0.0211,
	0.0126,
	0.3850,
	0.2651,
	0.2313,
	0.2065,
	0.1865,
	0.1695,
	0.1545,
	0.1410,
	0.1286,
	0.1170,
	0.1062,
	0.0959,
	0.0860,
	0.0765,
	0.0673,
	0.0584,
	0.0497,
	0.0412,
	0.0328,
	0.0245,
	0.0163,
	0.0081,
	0.3830,
	0.2635,
	0.2302,
	0.2058,
	0.1862,
	0.1695,
	0.1548,
	0.1415,
	0.1293,
	0.1180,
	0.1073,
	0.0972,
	0.0876,
	0.0783,
	0.0694,
	0.0607,
	0.0522,
	0.0439,
	0.0357,
	0.0277,
	0.0197,
	0.0118,
	0.0039,
	0.3808,
	0.2620,
	0.2291,
	0.2052,
	0.1859,
	0.1695,
	0.1550,
	0.1420,
	0.1300,
	0.1189,
	0.1085,
	0.0986,
	0.0892,
	0.0801,
	0.0713,
	0.0628,
	0.0546,
	0.0465,
	0.0385,
	0.0307,
	0.0229,
	0.0153,
	0.0076,
	0.3789,
	0.2604,
	0.2281,
	0.2045,
	0.1855,
	0.1693,
	0.1551,
	0.1423,
	0.1306,
	0.1197,
	0.1095,
	0.0998,
	0.0906,
	0.0817,
	0.0731,
	0.0648,
	0.0568,
	0.0489,
	0.0411,
	0.0335,
	0.0259,
	0.0185,
	0.0111,
	0.0037,
	0.3770,
	0.2589,
	0.2271,
	0.2038,
	0.1851,
	0.1692,
	0.1553,
	0.1427,
	0.1312,
	0.1205,
	0.1105,
	0.1010,
	0.0919,
	0.0832,
	0.0748,
	0.0667,
	0.0588,
	0.0511,
	0.0436,
	0.0361,
	0.0288,
	0.0215,
	0.0143,
	0.0071,
	0.3751,
	0.2574,
	0.2260,
	0.2032,
	0.1847,
	0.1691,
	0.1554,
	0.1430,
	0.1317,
	0.1212,
	0.1113,
	0.1020,
	0.0932,
	0.0846,
	0.0764,
	0.0685,
	0.0608,
	0.0532,
	0.0459,
	0.0386,
	0.0314,
	0.0244,
	0.0174,
	0.0104,
	0.0035
};

template<Ratio T = double>
constexpr static inline T SHAPIRO_WILK_P_VALUES[] = {
	0.753,
	0.687,
	0.686,
	0.713,
	0.730,
	0.749,
	0.764,
	0.781,
	0.792,
	0.805,
	0.814,
	0.825,
	0.835,
	0.844,
	0.851,
	0.858,
	0.863,
	0.868,
	0.873,
	0.878,
	0.881,
	0.884,
	0.888,
	0.891,
	0.894,
	0.896,
	0.898,
	0.900,
	0.902,
	0.904,
	0.906,
	0.908,
	0.910,
	0.912,
	0.914,
	0.916,
	0.917,
	0.919,
	0.920,
	0.922,
	0.923,
	0.924,
	0.926,
	0.927,
	0.928,
	0.929,
	0.929,
	0.930,
	0.756,
	0.707,
	0.715,
	0.743,
	0.760,
	0.778,
	0.791,
	0.806,
	0.817,
	0.828,
	0.837,
	0.846,
	0.855,
	0.863,
	0.869,
	0.874,
	0.879,
	0.884,
	0.888,
	0.892,
	0.895,
	0.898,
	0.901,
	0.904,
	0.906,
	0.908,
	0.910,
	0.912,
	0.914,
	0.915,
	0.917,
	0.919,
	0.920,
	0.922,
	0.924,
	0.925,
	0.927,
	0.928,
	0.929,
	0.930,
	0.932,
	0.933,
	0.934,
	0.935,
	0.936,
	0.937,
	0.939,
	0.938,
	0.767,
	0.748,
	0.762,
	0.788,
	0.803,
	0.818,
	0.829,
	0.842,
	0.850,
	0.859,
	0.866,
	0.874,
	0.881,
	0.887,
	0.892,
	0.897,
	0.901,
	0.905,
	0.908,
	0.911,
	0.914,
	0.916,
	0.918,
	0.920,
	0.923,
	0.924,
	0.926,
	0.927,
	0.929,
	0.930,
	0.931,
	0.933,
	0.934,
	0.935,
	0.936,
	0.938,
	0.939,
	0.940,
	0.941,
	0.942,
	0.943,
	0.944,
	0.945,
	0.945,
	0.946,
	0.947,
	0.947,
	0.947,
	0.789,
	0.792,
	0.806,
	0.826,
	0.838,
	0.851,
	0.859,
	0.869,
	0.876,
	0.883,
	0.889,
	0.895,
	0.901,
	0.906,
	0.910,
	0.914,
	0.917,
	0.920,
	0.923,
	0.926,
	0.928,
	0.930,
	0.931,
	0.933,
	0.935,
	0.936,
	0.937,
	0.939,
	0.940,
	0.941,
	0.942,
	0.943,
	0.944,
	0.945,
	0.946,
	0.947,
	0.948,
	0.949,
	0.950,
	0.951,
	0.951,
	0.952,
	0.953,
	0.953,
	0.954,
	0.954,
	0.955,
	0.955
};

}

}
