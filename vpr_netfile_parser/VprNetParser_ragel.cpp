
#line 1 "VprNetParser.rl"
#include "VprNetParser.hpp"


#line 157 "VprNetParser.rl"



/* Regal data ****************************************/

#line 13 "VprNetParser.cpp"
static const int VprNetParser_start = 1;
static const int VprNetParser_error = 0;

static const int VprNetParser_en_main = 1;


#line 162 "VprNetParser.rl"
/* Regal data: end ***********************************/

template <typename T>
void VprNetParser<T>::init() {
    buf = &buf_vector[0];
    _BUFSIZE = buf_vector.size();

    
#line 29 "VprNetParser.cpp"
	{
	cs = VprNetParser_start;
	}

#line 170 "VprNetParser.rl"
}


template <typename T>
void VprNetParser<T>::ragel_parse(std::istream &in_stream) {
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
            
#line 64 "VprNetParser.cpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 9: goto st2;
		case 10: goto st113;
		case 32: goto st2;
		case 35: goto st3;
		case 46: goto tr4;
	}
	goto st0;
st0:
cs = 0;
	goto _out;
tr163:
#line 62 "VprNetParser.rl"
	{
        be = p;
        te = p;
    }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 93 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st2;
		case 10: goto st113;
		case 32: goto st2;
		case 35: goto st3;
	}
	goto st0;
tr164:
#line 62 "VprNetParser.rl"
	{
        be = p;
        te = p;
    }
	goto st113;
tr168:
#line 54 "VprNetParser.rl"
	{
        if(ts != be) {
            ls = buf;
        }
        ts = 0;
        process_funcblock();
    }
	goto st113;
tr172:
#line 11 "VprNetParser.rl"
	{
        process_global();
    }
	goto st113;
tr176:
#line 28 "VprNetParser.rl"
	{
        process_input();
    }
	goto st113;
tr180:
#line 32 "VprNetParser.rl"
	{
        process_output();
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 140 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr163;
		case 10: goto tr164;
		case 32: goto tr163;
		case 35: goto tr165;
		case 46: goto tr166;
	}
	goto st0;
tr165:
#line 62 "VprNetParser.rl"
	{
        be = p;
        te = p;
    }
	goto st3;
tr169:
#line 54 "VprNetParser.rl"
	{
        if(ts != be) {
            ls = buf;
        }
        ts = 0;
        process_funcblock();
    }
	goto st3;
tr173:
#line 11 "VprNetParser.rl"
	{
        process_global();
    }
	goto st3;
tr177:
#line 28 "VprNetParser.rl"
	{
        process_input();
    }
	goto st3;
tr181:
#line 32 "VprNetParser.rl"
	{
        process_output();
    }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 188 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st113;
	goto st3;
tr4:
#line 6 "VprNetParser.rl"
	{
        ls = p;
        ts = p;
    }
#line 48 "VprNetParser.rl"
	{
        subblocks.clear();
        ls = p;
        ts = p;
    }
#line 36 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st4;
tr166:
#line 62 "VprNetParser.rl"
	{
        be = p;
        te = p;
    }
#line 6 "VprNetParser.rl"
	{
        ls = p;
        ts = p;
    }
#line 48 "VprNetParser.rl"
	{
        subblocks.clear();
        ls = p;
        ts = p;
    }
#line 36 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st4;
tr170:
#line 54 "VprNetParser.rl"
	{
        if(ts != be) {
            ls = buf;
        }
        ts = 0;
        process_funcblock();
    }
#line 6 "VprNetParser.rl"
	{
        ls = p;
        ts = p;
    }
#line 48 "VprNetParser.rl"
	{
        subblocks.clear();
        ls = p;
        ts = p;
    }
#line 36 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st4;
tr174:
#line 11 "VprNetParser.rl"
	{
        process_global();
    }
#line 6 "VprNetParser.rl"
	{
        ls = p;
        ts = p;
    }
#line 48 "VprNetParser.rl"
	{
        subblocks.clear();
        ls = p;
        ts = p;
    }
#line 36 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st4;
tr178:
#line 28 "VprNetParser.rl"
	{
        process_input();
    }
#line 6 "VprNetParser.rl"
	{
        ls = p;
        ts = p;
    }
#line 48 "VprNetParser.rl"
	{
        subblocks.clear();
        ls = p;
        ts = p;
    }
#line 36 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st4;
tr182:
#line 32 "VprNetParser.rl"
	{
        process_output();
    }
#line 6 "VprNetParser.rl"
	{
        ls = p;
        ts = p;
    }
#line 48 "VprNetParser.rl"
	{
        subblocks.clear();
        ls = p;
        ts = p;
    }
#line 36 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 323 "VprNetParser.cpp"
	switch( (*p) ) {
		case 43: goto st5;
		case 46: goto st5;
		case 92: goto st47;
		case 103: goto st48;
		case 105: goto st60;
		case 111: goto st86;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
tr10:
#line 40 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        funcblocktype = string(label_start, p - label_start);
    }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 376 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st6;
		case 32: goto st6;
		case 43: goto tr12;
		case 46: goto tr12;
		case 92: goto tr13;
		case 126: goto tr12;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr12;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr12;
	} else
		goto tr12;
	goto st0;
tr12:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 404 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr14;
		case 10: goto tr15;
		case 32: goto tr14;
		case 35: goto tr16;
		case 43: goto st7;
		case 46: goto st7;
		case 126: goto st7;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st7;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st7;
	} else
		goto st7;
	goto st0;
tr14:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 437 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st8;
		case 10: goto st9;
		case 32: goto st8;
		case 35: goto st45;
	}
	goto st0;
tr15:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 459 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st9;
		case 32: goto st9;
		case 112: goto tr21;
	}
	goto st0;
tr21:
#line 67 "VprNetParser.rl"
	{
        pin_list.clear();
        in_pin_list = true;
    }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 477 "VprNetParser.cpp"
	if ( (*p) == 105 )
		goto st11;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 110 )
		goto st12;
	goto st0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) == 108 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	if ( (*p) == 105 )
		goto st14;
	goto st0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 115 )
		goto st15;
	goto st0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 116 )
		goto st16;
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	if ( (*p) == 58 )
		goto st17;
	goto st0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 9: goto st18;
		case 32: goto st18;
		case 92: goto st44;
	}
	goto st0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 9: goto st18;
		case 32: goto st18;
		case 43: goto tr31;
		case 46: goto tr31;
		case 92: goto tr32;
		case 126: goto tr31;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr31;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr31;
	} else
		goto tr31;
	goto st0;
tr31:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 564 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr33;
		case 10: goto tr34;
		case 32: goto tr33;
		case 35: goto tr35;
		case 43: goto st19;
		case 46: goto st19;
		case 126: goto st19;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st19;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st19;
	} else
		goto st19;
	goto st0;
tr33:
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
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 603 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st20;
		case 10: goto tr38;
		case 32: goto st20;
		case 35: goto tr39;
		case 43: goto tr31;
		case 46: goto tr31;
		case 92: goto tr40;
		case 126: goto tr31;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr31;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr31;
	} else
		goto tr31;
	goto st0;
tr34:
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
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st21;
tr38:
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 653 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st21;
		case 32: goto st21;
		case 115: goto tr42;
	}
	goto st0;
tr42:
#line 15 "VprNetParser.rl"
	{
        subblocks.push_back(SubBlock());
        p_subblock = &subblocks[subblocks.size() - 1];
        in_subblock_pin_list = true;
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 672 "VprNetParser.cpp"
	if ( (*p) == 117 )
		goto st23;
	goto st0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 98 )
		goto st24;
	goto st0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 98 )
		goto st25;
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 108 )
		goto st26;
	goto st0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 111 )
		goto st27;
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	if ( (*p) == 99 )
		goto st28;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 107 )
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	if ( (*p) == 58 )
		goto st30;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 9: goto st31;
		case 32: goto st31;
	}
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 9: goto st31;
		case 32: goto st31;
		case 43: goto tr52;
		case 46: goto tr52;
		case 92: goto tr53;
		case 126: goto tr52;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr52;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr52;
	} else
		goto tr52;
	goto st0;
tr52:
#line 94 "VprNetParser.rl"
	{
        subblock_label_start = p;
    }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 765 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr54;
		case 32: goto tr54;
		case 43: goto st32;
		case 46: goto st32;
		case 126: goto st32;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st32;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st32;
	} else
		goto st32;
	goto st0;
tr54:
#line 98 "VprNetParser.rl"
	{
        length = p - subblock_label_start;
        if(length < 0) {
            subblock_label_start = buf + (subblock_label_start - be);
        }
        p_subblock->label = string(subblock_label_start, p - subblock_label_start);
    }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 796 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st33;
		case 32: goto st33;
		case 43: goto tr57;
		case 46: goto tr57;
		case 92: goto tr58;
		case 126: goto tr57;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr57;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr57;
	} else
		goto tr57;
	goto st0;
tr57:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 824 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr59;
		case 10: goto tr60;
		case 32: goto tr59;
		case 35: goto tr61;
		case 43: goto st34;
		case 46: goto st34;
		case 126: goto st34;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st34;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto st0;
tr59:
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
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 863 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st35;
		case 10: goto tr64;
		case 32: goto st35;
		case 35: goto tr65;
		case 43: goto tr57;
		case 46: goto tr57;
		case 92: goto tr66;
		case 126: goto tr57;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr57;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr57;
	} else
		goto tr57;
	goto st0;
tr60:
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
#line 21 "VprNetParser.rl"
	{
        in_subblock_pin_list = false;
        int num_pins = p_subblock->pins.size();
        p_subblock->clock_pin = p_subblock->pins[num_pins - 1];
        p_subblock->pins.resize(num_pins - 1);
    }
	goto st114;
tr64:
#line 21 "VprNetParser.rl"
	{
        in_subblock_pin_list = false;
        int num_pins = p_subblock->pins.size();
        p_subblock->clock_pin = p_subblock->pins[num_pins - 1];
        p_subblock->pins.resize(num_pins - 1);
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 919 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr167;
		case 10: goto tr168;
		case 32: goto tr167;
		case 35: goto tr169;
		case 46: goto tr170;
		case 115: goto tr42;
	}
	goto st0;
tr167:
#line 54 "VprNetParser.rl"
	{
        if(ts != be) {
            ls = buf;
        }
        ts = 0;
        process_funcblock();
    }
	goto st36;
tr175:
#line 28 "VprNetParser.rl"
	{
        process_input();
    }
	goto st36;
tr179:
#line 32 "VprNetParser.rl"
	{
        process_output();
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 955 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st36;
		case 10: goto st113;
		case 32: goto st36;
		case 35: goto st3;
		case 115: goto tr42;
	}
	goto st0;
tr61:
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
#line 21 "VprNetParser.rl"
	{
        in_subblock_pin_list = false;
        int num_pins = p_subblock->pins.size();
        p_subblock->clock_pin = p_subblock->pins[num_pins - 1];
        p_subblock->pins.resize(num_pins - 1);
    }
	goto st37;
tr65:
#line 21 "VprNetParser.rl"
	{
        in_subblock_pin_list = false;
        int num_pins = p_subblock->pins.size();
        p_subblock->clock_pin = p_subblock->pins[num_pins - 1];
        p_subblock->pins.resize(num_pins - 1);
    }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1000 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st114;
	goto st37;
tr66:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 1014 "VprNetParser.cpp"
	switch( (*p) ) {
		case 10: goto st35;
		case 43: goto st34;
		case 46: goto st34;
		case 126: goto st34;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st34;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto st0;
tr58:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 1040 "VprNetParser.cpp"
	switch( (*p) ) {
		case 10: goto st33;
		case 43: goto st34;
		case 46: goto st34;
		case 126: goto st34;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st34;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto st0;
tr53:
#line 94 "VprNetParser.rl"
	{
        subblock_label_start = p;
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 1066 "VprNetParser.cpp"
	switch( (*p) ) {
		case 43: goto st32;
		case 46: goto st32;
		case 126: goto st32;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st32;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st32;
	} else
		goto st32;
	goto st0;
tr35:
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
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st41;
tr39:
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1111 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st21;
	goto st41;
tr40:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1125 "VprNetParser.cpp"
	switch( (*p) ) {
		case 10: goto st20;
		case 43: goto st19;
		case 46: goto st19;
		case 126: goto st19;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st19;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st19;
	} else
		goto st19;
	goto st0;
tr32:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1151 "VprNetParser.cpp"
	switch( (*p) ) {
		case 10: goto st18;
		case 43: goto st19;
		case 46: goto st19;
		case 126: goto st19;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st19;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st19;
	} else
		goto st19;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) == 10 )
		goto st18;
	goto st0;
tr16:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 1188 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st9;
	goto st45;
tr13:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 1202 "VprNetParser.cpp"
	switch( (*p) ) {
		case 43: goto st7;
		case 46: goto st7;
		case 126: goto st7;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st7;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st7;
	} else
		goto st7;
	goto st0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 43: goto st5;
		case 46: goto st5;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 108: goto st49;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 111: goto st50;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 98: goto st51;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 97: goto st52;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 108: goto st53;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 9: goto tr76;
		case 32: goto tr76;
		case 43: goto st5;
		case 46: goto st5;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
tr76:
#line 40 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        funcblocktype = string(label_start, p - label_start);
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 1374 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st54;
		case 32: goto st54;
		case 43: goto tr78;
		case 46: goto tr78;
		case 92: goto tr79;
		case 126: goto tr78;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr78;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr78;
	} else
		goto tr78;
	goto st0;
tr78:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 1402 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr80;
		case 10: goto tr81;
		case 32: goto tr80;
		case 35: goto tr82;
		case 43: goto st55;
		case 46: goto st55;
		case 126: goto st55;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st55;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st55;
	} else
		goto st55;
	goto st0;
tr80:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 1435 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st56;
		case 10: goto st115;
		case 32: goto st56;
		case 35: goto st58;
	}
	goto st0;
tr81:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 1457 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr171;
		case 10: goto tr172;
		case 32: goto tr171;
		case 35: goto tr173;
		case 46: goto tr174;
		case 112: goto tr21;
	}
	goto st0;
tr171:
#line 11 "VprNetParser.rl"
	{
        process_global();
    }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 1477 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st57;
		case 10: goto st113;
		case 32: goto st57;
		case 35: goto st3;
		case 112: goto tr21;
	}
	goto st0;
tr82:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 1500 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st115;
	goto st58;
tr79:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 1514 "VprNetParser.cpp"
	switch( (*p) ) {
		case 43: goto st55;
		case 46: goto st55;
		case 126: goto st55;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st55;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st55;
	} else
		goto st55;
	goto st0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 110: goto st61;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 112: goto st62;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 117: goto st63;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 116: goto st64;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 9: goto tr92;
		case 32: goto tr92;
		case 43: goto st5;
		case 46: goto st5;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
tr92:
#line 40 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        funcblocktype = string(label_start, p - label_start);
    }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 1647 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st65;
		case 32: goto st65;
		case 43: goto tr94;
		case 46: goto tr94;
		case 92: goto tr95;
		case 126: goto tr94;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr94;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr94;
	} else
		goto tr94;
	goto st0;
tr94:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 1675 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr96;
		case 10: goto tr97;
		case 32: goto tr96;
		case 35: goto tr98;
		case 43: goto st66;
		case 46: goto st66;
		case 126: goto st66;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st66;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st66;
	} else
		goto st66;
	goto st0;
tr96:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 1708 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st67;
		case 10: goto st68;
		case 32: goto st67;
		case 35: goto st84;
	}
	goto st0;
tr97:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 1730 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st68;
		case 32: goto st68;
		case 112: goto tr103;
	}
	goto st0;
tr103:
#line 67 "VprNetParser.rl"
	{
        pin_list.clear();
        in_pin_list = true;
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 1748 "VprNetParser.cpp"
	if ( (*p) == 105 )
		goto st70;
	goto st0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	if ( (*p) == 110 )
		goto st71;
	goto st0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	if ( (*p) == 108 )
		goto st72;
	goto st0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( (*p) == 105 )
		goto st73;
	goto st0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 115 )
		goto st74;
	goto st0;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 116 )
		goto st75;
	goto st0;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 58 )
		goto st76;
	goto st0;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 9: goto st77;
		case 32: goto st77;
		case 92: goto st83;
	}
	goto st0;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 9: goto st77;
		case 32: goto st77;
		case 43: goto tr113;
		case 46: goto tr113;
		case 92: goto tr114;
		case 126: goto tr113;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr113;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr113;
	} else
		goto tr113;
	goto st0;
tr113:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 1835 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr115;
		case 10: goto tr116;
		case 32: goto tr115;
		case 35: goto tr117;
		case 43: goto st78;
		case 46: goto st78;
		case 126: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st78;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st78;
	} else
		goto st78;
	goto st0;
tr115:
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
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 1874 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st79;
		case 10: goto tr120;
		case 32: goto st79;
		case 35: goto tr121;
		case 43: goto tr113;
		case 46: goto tr113;
		case 92: goto tr122;
		case 126: goto tr113;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr113;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr113;
	} else
		goto tr113;
	goto st0;
tr116:
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
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st116;
tr120:
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 1924 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr175;
		case 10: goto tr176;
		case 32: goto tr175;
		case 35: goto tr177;
		case 46: goto tr178;
		case 115: goto tr42;
	}
	goto st0;
tr117:
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
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st80;
tr121:
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 1964 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st116;
	goto st80;
tr122:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 1978 "VprNetParser.cpp"
	switch( (*p) ) {
		case 10: goto st79;
		case 43: goto st78;
		case 46: goto st78;
		case 126: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st78;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st78;
	} else
		goto st78;
	goto st0;
tr114:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 2004 "VprNetParser.cpp"
	switch( (*p) ) {
		case 10: goto st77;
		case 43: goto st78;
		case 46: goto st78;
		case 126: goto st78;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st78;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st78;
	} else
		goto st78;
	goto st0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) == 10 )
		goto st77;
	goto st0;
tr98:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 2041 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st68;
	goto st84;
tr95:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 2055 "VprNetParser.cpp"
	switch( (*p) ) {
		case 43: goto st66;
		case 46: goto st66;
		case 126: goto st66;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st66;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st66;
	} else
		goto st66;
	goto st0;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 117: goto st87;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 116: goto st88;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 112: goto st89;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 117: goto st90;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
		case 43: goto st5;
		case 46: goto st5;
		case 116: goto st91;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 9: goto tr130;
		case 32: goto tr130;
		case 43: goto st5;
		case 46: goto st5;
		case 126: goto st5;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st5;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st5;
	} else
		goto st5;
	goto st0;
tr130:
#line 40 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        funcblocktype = string(label_start, p - label_start);
    }
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
#line 2209 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st92;
		case 32: goto st92;
		case 43: goto tr132;
		case 46: goto tr132;
		case 92: goto tr133;
		case 126: goto tr132;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr132;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr132;
	} else
		goto tr132;
	goto st0;
tr132:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 2237 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr134;
		case 10: goto tr135;
		case 32: goto tr134;
		case 35: goto tr136;
		case 43: goto st93;
		case 46: goto st93;
		case 126: goto st93;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st93;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st93;
	} else
		goto st93;
	goto st0;
tr134:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 2270 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st94;
		case 10: goto st95;
		case 32: goto st94;
		case 35: goto st111;
	}
	goto st0;
tr135:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 2292 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st95;
		case 32: goto st95;
		case 112: goto tr141;
	}
	goto st0;
tr141:
#line 67 "VprNetParser.rl"
	{
        pin_list.clear();
        in_pin_list = true;
    }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 2310 "VprNetParser.cpp"
	if ( (*p) == 105 )
		goto st97;
	goto st0;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	if ( (*p) == 110 )
		goto st98;
	goto st0;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	if ( (*p) == 108 )
		goto st99;
	goto st0;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	if ( (*p) == 105 )
		goto st100;
	goto st0;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	if ( (*p) == 115 )
		goto st101;
	goto st0;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	if ( (*p) == 116 )
		goto st102;
	goto st0;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	if ( (*p) == 58 )
		goto st103;
	goto st0;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 9: goto st104;
		case 32: goto st104;
		case 92: goto st110;
	}
	goto st0;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 9: goto st104;
		case 32: goto st104;
		case 43: goto tr151;
		case 46: goto tr151;
		case 92: goto tr152;
		case 126: goto tr151;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr151;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr151;
	} else
		goto tr151;
	goto st0;
tr151:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 2397 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr153;
		case 10: goto tr154;
		case 32: goto tr153;
		case 35: goto tr155;
		case 43: goto st105;
		case 46: goto st105;
		case 126: goto st105;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st105;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st105;
	} else
		goto st105;
	goto st0;
tr153:
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
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 2436 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto st106;
		case 10: goto tr158;
		case 32: goto st106;
		case 35: goto tr159;
		case 43: goto tr151;
		case 46: goto tr151;
		case 92: goto tr160;
		case 126: goto tr151;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto tr151;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr151;
	} else
		goto tr151;
	goto st0;
tr154:
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
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st117;
tr158:
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 2486 "VprNetParser.cpp"
	switch( (*p) ) {
		case 9: goto tr179;
		case 10: goto tr180;
		case 32: goto tr179;
		case 35: goto tr181;
		case 46: goto tr182;
		case 115: goto tr42;
	}
	goto st0;
tr155:
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
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st107;
tr159:
#line 72 "VprNetParser.rl"
	{
        in_pin_list = false;
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 2526 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st117;
	goto st107;
tr160:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 2540 "VprNetParser.cpp"
	switch( (*p) ) {
		case 10: goto st106;
		case 43: goto st105;
		case 46: goto st105;
		case 126: goto st105;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st105;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st105;
	} else
		goto st105;
	goto st0;
tr152:
#line 76 "VprNetParser.rl"
	{
        pin_start = p;
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 2566 "VprNetParser.cpp"
	switch( (*p) ) {
		case 10: goto st104;
		case 43: goto st105;
		case 46: goto st105;
		case 126: goto st105;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st105;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st105;
	} else
		goto st105;
	goto st0;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 10 )
		goto st104;
	goto st0;
tr136:
#line 110 "VprNetParser.rl"
	{
        length = p - label_start;
        if(length < 0) {
            label_start = buf + (label_start - be);
        }
        label = string(label_start, p - label_start);
    }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 2603 "VprNetParser.cpp"
	if ( (*p) == 10 )
		goto st95;
	goto st111;
tr133:
#line 106 "VprNetParser.rl"
	{
        label_start = p;
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 2617 "VprNetParser.cpp"
	switch( (*p) ) {
		case 43: goto st93;
		case 46: goto st93;
		case 126: goto st93;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 58 )
			goto st93;
	} else if ( (*p) > 95 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st93;
	} else
		goto st93;
	goto st0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 115: 
#line 11 "VprNetParser.rl"
	{
        process_global();
    }
	break;
	case 116: 
#line 28 "VprNetParser.rl"
	{
        process_input();
    }
	break;
	case 117: 
#line 32 "VprNetParser.rl"
	{
        process_output();
    }
	break;
	case 114: 
#line 54 "VprNetParser.rl"
	{
        if(ts != be) {
            ls = buf;
        }
        ts = 0;
        process_funcblock();
    }
	break;
	case 113: 
#line 62 "VprNetParser.rl"
	{
        be = p;
        te = p;
    }
	break;
#line 2789 "VprNetParser.cpp"
	}
	}

	_out: {}
	}

#line 199 "VprNetParser.rl"

            if ( cs == VprNetParser_error ) {
                /* Machine failed before finding a token. */
                cerr << "PARSE ERROR" << endl;
                for (int i = 0; i < buf_vector.size(); i++) {
                    cerr << buf_vector[i];
                }
                cerr << endl;
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

template void VprNetParser<int>::init();
template void VprNetParser<int>::ragel_parse(std::istream &in_stream);
template void VprNetParser<unsigned int>::init();
template void VprNetParser<unsigned int>::ragel_parse(std::istream &in_stream);
