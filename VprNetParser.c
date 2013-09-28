
#line 1 "VprNetParser.rl"
#include "VprNetParser.hpp"


#line 157 "VprNetParser.rl"



/* Regal data ****************************************/

#line 13 "VprNetParser.c"
static const char _VprNetParser_actions[] = {
	0, 1, 1, 1, 2, 1, 3, 1, 
	4, 1, 5, 1, 7, 1, 9, 1, 
	10, 1, 11, 1, 12, 1, 13, 1, 
	14, 1, 15, 1, 16, 1, 17, 1, 
	18, 2, 14, 3, 2, 14, 12, 3, 
	0, 8, 6, 4, 1, 0, 8, 6, 
	4, 4, 0, 8, 6, 4, 5, 0, 
	8, 6, 4, 9, 0, 8, 6, 4, 
	10, 0, 8, 6
};

static const short _VprNetParser_key_offsets[] = {
	0, 0, 5, 9, 10, 21, 30, 40, 
	51, 55, 58, 59, 60, 61, 62, 63, 
	64, 65, 68, 78, 89, 101, 104, 105, 
	106, 107, 108, 109, 110, 111, 112, 114, 
	124, 133, 143, 154, 166, 171, 172, 180, 
	188, 195, 196, 204, 212, 213, 214, 221, 
	228, 238, 248, 258, 268, 278, 287, 297, 
	308, 312, 317, 318, 325, 335, 345, 355, 
	365, 374, 384, 395, 399, 402, 403, 404, 
	405, 406, 407, 408, 409, 412, 422, 433, 
	445, 446, 454, 462, 463, 464, 471, 481, 
	491, 501, 511, 521, 530, 540, 551, 555, 
	558, 559, 560, 561, 562, 563, 564, 565, 
	568, 578, 589, 601, 602, 610, 618, 619, 
	620, 627, 632, 638, 644, 650
};

static const char _VprNetParser_trans_keys[] = {
	9, 10, 32, 35, 46, 9, 10, 32, 
	35, 10, 92, 95, 103, 105, 111, 48, 
	58, 65, 93, 97, 122, 9, 32, 95, 
	48, 58, 65, 93, 97, 122, 9, 32, 
	92, 95, 48, 58, 65, 93, 97, 122, 
	9, 10, 32, 35, 95, 48, 58, 65, 
	93, 97, 122, 9, 10, 32, 35, 9, 
	32, 112, 105, 110, 108, 105, 115, 116, 
	58, 9, 32, 92, 9, 32, 92, 95, 
	48, 58, 65, 93, 97, 122, 9, 10, 
	32, 35, 95, 48, 58, 65, 93, 97, 
	122, 9, 10, 32, 35, 92, 95, 48, 
	58, 65, 93, 97, 122, 9, 32, 115, 
	117, 98, 98, 108, 111, 99, 107, 58, 
	9, 32, 9, 32, 92, 95, 48, 58, 
	65, 93, 97, 122, 9, 32, 95, 48, 
	58, 65, 93, 97, 122, 9, 32, 92, 
	95, 48, 58, 65, 93, 97, 122, 9, 
	10, 32, 35, 95, 48, 58, 65, 93, 
	97, 122, 9, 10, 32, 35, 92, 95, 
	48, 58, 65, 93, 97, 122, 9, 10, 
	32, 35, 115, 10, 10, 95, 48, 58, 
	65, 93, 97, 122, 10, 95, 48, 58, 
	65, 93, 97, 122, 95, 48, 58, 65, 
	93, 97, 122, 10, 10, 95, 48, 58, 
	65, 93, 97, 122, 10, 95, 48, 58, 
	65, 93, 97, 122, 10, 10, 95, 48, 
	58, 65, 93, 97, 122, 95, 48, 58, 
	65, 93, 97, 122, 9, 32, 95, 108, 
	48, 58, 65, 93, 97, 122, 9, 32, 
	95, 111, 48, 58, 65, 93, 97, 122, 
	9, 32, 95, 98, 48, 58, 65, 93, 
	97, 122, 9, 32, 95, 97, 48, 58, 
	65, 93, 98, 122, 9, 32, 95, 108, 
	48, 58, 65, 93, 97, 122, 9, 32, 
	95, 48, 58, 65, 93, 97, 122, 9, 
	32, 92, 95, 48, 58, 65, 93, 97, 
	122, 9, 10, 32, 35, 95, 48, 58, 
	65, 93, 97, 122, 9, 10, 32, 35, 
	9, 10, 32, 35, 112, 10, 95, 48, 
	58, 65, 93, 97, 122, 9, 32, 95, 
	110, 48, 58, 65, 93, 97, 122, 9, 
	32, 95, 112, 48, 58, 65, 93, 97, 
	122, 9, 32, 95, 117, 48, 58, 65, 
	93, 97, 122, 9, 32, 95, 116, 48, 
	58, 65, 93, 97, 122, 9, 32, 95, 
	48, 58, 65, 93, 97, 122, 9, 32, 
	92, 95, 48, 58, 65, 93, 97, 122, 
	9, 10, 32, 35, 95, 48, 58, 65, 
	93, 97, 122, 9, 10, 32, 35, 9, 
	32, 112, 105, 110, 108, 105, 115, 116, 
	58, 9, 32, 92, 9, 32, 92, 95, 
	48, 58, 65, 93, 97, 122, 9, 10, 
	32, 35, 95, 48, 58, 65, 93, 97, 
	122, 9, 10, 32, 35, 92, 95, 48, 
	58, 65, 93, 97, 122, 10, 10, 95, 
	48, 58, 65, 93, 97, 122, 10, 95, 
	48, 58, 65, 93, 97, 122, 10, 10, 
	95, 48, 58, 65, 93, 97, 122, 9, 
	32, 95, 117, 48, 58, 65, 93, 97, 
	122, 9, 32, 95, 116, 48, 58, 65, 
	93, 97, 122, 9, 32, 95, 112, 48, 
	58, 65, 93, 97, 122, 9, 32, 95, 
	117, 48, 58, 65, 93, 97, 122, 9, 
	32, 95, 116, 48, 58, 65, 93, 97, 
	122, 9, 32, 95, 48, 58, 65, 93, 
	97, 122, 9, 32, 92, 95, 48, 58, 
	65, 93, 97, 122, 9, 10, 32, 35, 
	95, 48, 58, 65, 93, 97, 122, 9, 
	10, 32, 35, 9, 32, 112, 105, 110, 
	108, 105, 115, 116, 58, 9, 32, 92, 
	9, 32, 92, 95, 48, 58, 65, 93, 
	97, 122, 9, 10, 32, 35, 95, 48, 
	58, 65, 93, 97, 122, 9, 10, 32, 
	35, 92, 95, 48, 58, 65, 93, 97, 
	122, 10, 10, 95, 48, 58, 65, 93, 
	97, 122, 10, 95, 48, 58, 65, 93, 
	97, 122, 10, 10, 95, 48, 58, 65, 
	93, 97, 122, 9, 10, 32, 35, 46, 
	9, 10, 32, 35, 46, 115, 9, 10, 
	32, 35, 46, 112, 9, 10, 32, 35, 
	46, 115, 9, 10, 32, 35, 46, 115, 
	0
};

static const char _VprNetParser_single_lengths[] = {
	0, 5, 4, 1, 5, 3, 4, 5, 
	4, 3, 1, 1, 1, 1, 1, 1, 
	1, 3, 4, 5, 6, 3, 1, 1, 
	1, 1, 1, 1, 1, 1, 2, 4, 
	3, 4, 5, 6, 5, 1, 2, 2, 
	1, 1, 2, 2, 1, 1, 1, 1, 
	4, 4, 4, 4, 4, 3, 4, 5, 
	4, 5, 1, 1, 4, 4, 4, 4, 
	3, 4, 5, 4, 3, 1, 1, 1, 
	1, 1, 1, 1, 3, 4, 5, 6, 
	1, 2, 2, 1, 1, 1, 4, 4, 
	4, 4, 4, 3, 4, 5, 4, 3, 
	1, 1, 1, 1, 1, 1, 1, 3, 
	4, 5, 6, 1, 2, 2, 1, 1, 
	1, 5, 6, 6, 6, 6
};

static const char _VprNetParser_range_lengths[] = {
	0, 0, 0, 0, 3, 3, 3, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 3, 3, 0, 0, 3, 3, 
	3, 0, 3, 3, 0, 0, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	0, 0, 0, 3, 3, 3, 3, 3, 
	3, 3, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 3, 0, 0, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0
};

static const short _VprNetParser_index_offsets[] = {
	0, 0, 6, 11, 13, 22, 29, 37, 
	46, 51, 55, 57, 59, 61, 63, 65, 
	67, 69, 73, 81, 90, 100, 104, 106, 
	108, 110, 112, 114, 116, 118, 120, 123, 
	131, 138, 146, 155, 165, 171, 173, 179, 
	185, 190, 192, 198, 204, 206, 208, 213, 
	218, 226, 234, 242, 250, 258, 265, 273, 
	282, 287, 293, 295, 300, 308, 316, 324, 
	332, 339, 347, 356, 361, 365, 367, 369, 
	371, 373, 375, 377, 379, 383, 391, 400, 
	410, 412, 418, 424, 426, 428, 433, 441, 
	449, 457, 465, 473, 480, 488, 497, 502, 
	506, 508, 510, 512, 514, 516, 518, 520, 
	524, 532, 541, 551, 553, 559, 565, 567, 
	569, 574, 580, 587, 594, 601
};

static const unsigned char _VprNetParser_indicies[] = {
	0, 2, 0, 3, 4, 1, 0, 2, 
	0, 3, 1, 2, 3, 6, 5, 7, 
	8, 9, 5, 5, 5, 1, 10, 10, 
	5, 5, 5, 5, 1, 11, 11, 13, 
	12, 12, 12, 12, 1, 14, 15, 14, 
	16, 17, 17, 17, 17, 1, 18, 19, 
	18, 20, 1, 19, 19, 21, 1, 22, 
	1, 23, 1, 24, 1, 25, 1, 26, 
	1, 27, 1, 28, 1, 29, 29, 30, 
	1, 29, 29, 32, 31, 31, 31, 31, 
	1, 33, 34, 33, 35, 36, 36, 36, 
	36, 1, 37, 38, 37, 39, 40, 31, 
	31, 31, 31, 1, 41, 41, 42, 1, 
	43, 1, 44, 1, 45, 1, 46, 1, 
	47, 1, 48, 1, 49, 1, 50, 1, 
	51, 51, 1, 51, 51, 53, 52, 52, 
	52, 52, 1, 54, 54, 55, 55, 55, 
	55, 1, 56, 56, 58, 57, 57, 57, 
	57, 1, 59, 60, 59, 61, 62, 62, 
	62, 62, 1, 63, 64, 63, 65, 66, 
	57, 57, 57, 57, 1, 67, 2, 67, 
	3, 42, 1, 69, 68, 63, 62, 62, 
	62, 62, 1, 56, 62, 62, 62, 62, 
	1, 55, 55, 55, 55, 1, 41, 70, 
	37, 36, 36, 36, 36, 1, 29, 36, 
	36, 36, 36, 1, 29, 1, 19, 20, 
	17, 17, 17, 17, 1, 5, 5, 5, 
	5, 1, 10, 10, 5, 71, 5, 5, 
	5, 1, 10, 10, 5, 72, 5, 5, 
	5, 1, 10, 10, 5, 73, 5, 5, 
	5, 1, 10, 10, 5, 74, 5, 5, 
	5, 1, 10, 10, 5, 75, 5, 5, 
	5, 1, 76, 76, 5, 5, 5, 5, 
	1, 77, 77, 79, 78, 78, 78, 78, 
	1, 80, 81, 80, 82, 83, 83, 83, 
	83, 1, 84, 85, 84, 86, 1, 87, 
	2, 87, 3, 21, 1, 85, 86, 83, 
	83, 83, 83, 1, 10, 10, 5, 88, 
	5, 5, 5, 1, 10, 10, 5, 89, 
	5, 5, 5, 1, 10, 10, 5, 90, 
	5, 5, 5, 1, 10, 10, 5, 91, 
	5, 5, 5, 1, 92, 92, 5, 5, 
	5, 5, 1, 93, 93, 95, 94, 94, 
	94, 94, 1, 96, 97, 96, 98, 99, 
	99, 99, 99, 1, 100, 101, 100, 102, 
	1, 101, 101, 103, 1, 104, 1, 105, 
	1, 106, 1, 107, 1, 108, 1, 109, 
	1, 110, 1, 111, 111, 112, 1, 111, 
	111, 114, 113, 113, 113, 113, 1, 115, 
	116, 115, 117, 118, 118, 118, 118, 1, 
	119, 120, 119, 121, 122, 113, 113, 113, 
	113, 1, 124, 123, 119, 118, 118, 118, 
	118, 1, 111, 118, 118, 118, 118, 1, 
	111, 1, 101, 102, 99, 99, 99, 99, 
	1, 10, 10, 5, 125, 5, 5, 5, 
	1, 10, 10, 5, 126, 5, 5, 5, 
	1, 10, 10, 5, 127, 5, 5, 5, 
	1, 10, 10, 5, 128, 5, 5, 5, 
	1, 10, 10, 5, 129, 5, 5, 5, 
	1, 130, 130, 5, 5, 5, 5, 1, 
	131, 131, 133, 132, 132, 132, 132, 1, 
	134, 135, 134, 136, 137, 137, 137, 137, 
	1, 138, 139, 138, 140, 1, 139, 139, 
	141, 1, 142, 1, 143, 1, 144, 1, 
	145, 1, 146, 1, 147, 1, 148, 1, 
	149, 149, 150, 1, 149, 149, 152, 151, 
	151, 151, 151, 1, 153, 154, 153, 155, 
	156, 156, 156, 156, 1, 157, 158, 157, 
	159, 160, 151, 151, 151, 151, 1, 162, 
	161, 157, 156, 156, 156, 156, 1, 149, 
	156, 156, 156, 156, 1, 149, 1, 139, 
	140, 137, 137, 137, 137, 1, 163, 164, 
	163, 165, 166, 1, 167, 168, 167, 169, 
	170, 42, 1, 171, 172, 171, 173, 174, 
	21, 1, 175, 176, 175, 177, 178, 42, 
	1, 179, 180, 179, 181, 182, 42, 1, 
	0
};

static const char _VprNetParser_trans_targs[] = {
	2, 0, 113, 3, 4, 5, 47, 48, 
	60, 86, 6, 6, 7, 46, 8, 9, 
	45, 7, 8, 9, 45, 10, 11, 12, 
	13, 14, 15, 16, 17, 18, 44, 19, 
	43, 20, 21, 41, 19, 20, 21, 41, 
	42, 21, 22, 23, 24, 25, 26, 27, 
	28, 29, 30, 31, 32, 40, 33, 32, 
	33, 34, 39, 35, 114, 37, 34, 35, 
	114, 37, 38, 36, 37, 114, 41, 49, 
	50, 51, 52, 53, 54, 54, 55, 59, 
	56, 115, 58, 55, 56, 115, 58, 57, 
	61, 62, 63, 64, 65, 65, 66, 85, 
	67, 68, 84, 66, 67, 68, 84, 69, 
	70, 71, 72, 73, 74, 75, 76, 77, 
	83, 78, 82, 79, 116, 80, 78, 79, 
	116, 80, 81, 80, 116, 87, 88, 89, 
	90, 91, 92, 92, 93, 112, 94, 95, 
	111, 93, 94, 95, 111, 96, 97, 98, 
	99, 100, 101, 102, 103, 104, 110, 105, 
	109, 106, 117, 107, 105, 106, 117, 107, 
	108, 107, 117, 2, 113, 3, 4, 36, 
	113, 3, 4, 57, 113, 3, 4, 36, 
	113, 3, 4, 36, 113, 3, 4
};

static const char _VprNetParser_trans_actions[] = {
	0, 0, 0, 0, 39, 0, 0, 0, 
	0, 0, 11, 0, 29, 29, 31, 31, 
	31, 0, 0, 0, 0, 17, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 21, 
	21, 23, 36, 36, 0, 0, 19, 19, 
	21, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 25, 25, 27, 0, 
	0, 21, 21, 23, 33, 33, 0, 0, 
	5, 5, 21, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 11, 0, 29, 29, 
	31, 31, 31, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 11, 0, 29, 29, 
	31, 31, 31, 0, 0, 0, 0, 17, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 21, 21, 23, 36, 36, 0, 0, 
	19, 19, 21, 0, 0, 0, 0, 0, 
	0, 0, 11, 0, 29, 29, 31, 31, 
	31, 0, 0, 0, 0, 17, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 21, 
	21, 23, 36, 36, 0, 0, 19, 19, 
	21, 0, 0, 15, 15, 15, 63, 13, 
	13, 13, 58, 1, 1, 1, 43, 7, 
	7, 7, 48, 9, 9, 9, 53
};

static const char _VprNetParser_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 15, 13, 1, 7, 9
};

static const int VprNetParser_start = 1;
static const int VprNetParser_error = 0;

static const int VprNetParser_en_main = 1;


#line 162 "VprNetParser.rl"
/* Regal data: end ***********************************/


void VprNetParser::init() {
    buf = &buf_vector[0];
    _BUFSIZE = buf_vector.size();

    
#line 349 "VprNetParser.c"
	{
	cs = VprNetParser_start;
	}

#line 170 "VprNetParser.rl"
}


void VprNetParser::ragel_parse(std::istream &in_stream) {
    bool done = false;
    int i = 0;
    have = 0;
    while ( !done ) {
        /* How much space is in the buffer? */
        int space = _BUFSIZE - have;
        if ( space == 0 ) {
            /* Buffer is full. */
            cerr << "TOKEN TOO BIG" << endl;
            exit(1);
        }
        /* Read in a block after any data we already have. */
        char *p = buf + have;
        in_stream.read( p, space );
        int len = in_stream.gcount();
        char *pe = p + len;
        char *eof = 0;

        /* If no data was read indicate EOF. */
        if ( len == 0 ) {
            eof = pe;
            done = true;
        } else {
            
#line 383 "VprNetParser.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _VprNetParser_trans_keys + _VprNetParser_key_offsets[cs];
	_trans = _VprNetParser_index_offsets[cs];

	_klen = _VprNetParser_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _VprNetParser_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _VprNetParser_indicies[_trans];
	cs = _VprNetParser_trans_targs[_trans];

	if ( _VprNetParser_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _VprNetParser_actions + _VprNetParser_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 6 "VprNetParser.rl"
	{
        ls = p;
        ts = p;
    }
	break;
	case 1:
#line 11 "VprNetParser.rl"
	{
        process_global();
    }
	break;
	case 2:
#line 15 "VprNetParser.rl"
	{
        subblocks.push_back(SubBlock());
        p_subblock = &subblocks[subblocks.size() - 1];
        in_subblock_pin_list = true;
    }
	break;
	case 3:
#line 21 "VprNetParser.rl"
	{
        in_subblock_pin_list = false;
        int num_pins = p_subblock->pins.size();
        p_subblock->clock_pin = p_subblock->pins[num_pins - 1];
        p_subblock->pins.resize(num_pins - 1);
    }
	break;
	case 4:
#line 28 "VprNetParser.rl"
	{
        process_input();
    }
	break;
	case 5:
#line 32 "VprNetParser.rl"
	{
        process_output();
    }
	break;
	case 6:
#line 36 "VprNetParser.rl"
	{
        label_start = p;
    }
	break;
	case 7:
#line 40 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        funcblocktype = string(label_start, p - label_start);
    }
	break;
	case 8:
#line 48 "VprNetParser.rl"
	{
        subblocks.clear();
        ls = p;
        ts = p;
    }
	break;
	case 9:
#line 54 "VprNetParser.rl"
	{
        if(ts != be) {
            ls = buf;
        }
        ts = 0;
        process_funcblock();
    }
	break;
	case 10:
#line 62 "VprNetParser.rl"
	{
        be = p;
        te = p;
    }
	break;
	case 11:
#line 67 "VprNetParser.rl"
	{
        pin_list.clear();
        in_pin_list = true;
    }
	break;
	case 12:
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	break;
	case 13:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	break;
	case 14:
#line 80 "VprNetParser.rl"
	{
        length = p - pin_start;
        if(length < 0) {
            pin_start = buf + (pin_start - be);
        }
        if(in_pin_list) {
            pin_list.push_back(
                string(pin_start, p - pin_start));
        } else if(in_subblock_pin_list) {
            p_subblock->pins.push_back(
                string(pin_start, p - pin_start));
        }
    }
	break;
	case 15:
#line 94 "VprNetParser.rl"
	{
        subblock_label_start = p;
    }
	break;
	case 16:
#line 98 "VprNetParser.rl"
	{
        length = p - subblock_label_start;
        if(length < 0) {
            subblock_label_start = buf + (subblock_label_start - be);
        }
        p_subblock->label = string(subblock_label_start, p - subblock_label_start);
    }
	break;
	case 17:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	break;
	case 18:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	break;
#line 607 "VprNetParser.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _VprNetParser_actions + _VprNetParser_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 1:
#line 11 "VprNetParser.rl"
	{
        process_global();
    }
	break;
	case 4:
#line 28 "VprNetParser.rl"
	{
        process_input();
    }
	break;
	case 5:
#line 32 "VprNetParser.rl"
	{
        process_output();
    }
	break;
	case 9:
#line 54 "VprNetParser.rl"
	{
        if(ts != be) {
            ls = buf;
        }
        ts = 0;
        process_funcblock();
    }
	break;
	case 10:
#line 62 "VprNetParser.rl"
	{
        be = p;
        te = p;
    }
	break;
#line 658 "VprNetParser.c"
		}
	}
	}

	_out: {}
	}

#line 198 "VprNetParser.rl"

            if ( cs == VprNetParser_error ) {
                /* Machine failed before finding a token. */
                cerr << "PARSE ERROR" << endl;
                exit(1);
            }
            if ( ts == 0 ) {
                have = 0;
            } else {
                /* There is a prefix to preserve, shift it over. */
                have = pe - ts;
                memmove( buf, ts, have );
                te = buf + (te-ts);
                ts = buf;
            }
        }
    }
}
