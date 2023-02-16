#include "soup.h"

namespace soup {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2022 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Phasor __m_phasor_56;
	Phasor __m_phasor_36;
	Phasor __m_phasor_74;
	Phasor __m_phasor_38;
	Phasor __m_phasor_72;
	Phasor __m_phasor_40;
	Phasor __m_phasor_34;
	Phasor __m_phasor_76;
	Phasor __m_phasor_26;
	Phasor __m_phasor_32;
	Phasor __m_phasor_78;
	Phasor __m_phasor_30;
	Phasor __m_phasor_24;
	Phasor __m_phasor_42;
	Phasor __m_phasor_44;
	Phasor __m_phasor_64;
	Phasor __m_phasor_54;
	Phasor __m_phasor_62;
	Phasor __m_phasor_58;
	Phasor __m_phasor_70;
	Phasor __m_phasor_52;
	Phasor __m_phasor_50;
	Phasor __m_phasor_46;
	Phasor __m_phasor_66;
	Phasor __m_phasor_68;
	Phasor __m_phasor_48;
	Phasor __m_phasor_80;
	Phasor __m_phasor_28;
	Phasor __m_phasor_60;
	Phasor __m_phasor_8;
	Phasor __m_phasor_88;
	Phasor __m_phasor_22;
	Phasor __m_phasor_86;
	Phasor __m_phasor_12;
	Phasor __m_phasor_6;
	Phasor __m_phasor_90;
	Phasor __m_phasor_4;
	Phasor __m_phasor_94;
	Phasor __m_phasor_92;
	Phasor __m_phasor_14;
	Phasor __m_phasor_10;
	Phasor __m_phasor_20;
	Phasor __m_phasor_18;
	Phasor __m_phasor_16;
	Phasor __m_phasor_84;
	Phasor __m_phasor_82;
	Sah __m_sah_65;
	Sah __m_sah_85;
	Sah __m_sah_93;
	Sah __m_sah_63;
	Sah __m_sah_91;
	Sah __m_sah_95;
	Sah __m_sah_81;
	Sah __m_sah_61;
	Sah __m_sah_67;
	Sah __m_sah_73;
	Sah __m_sah_75;
	Sah __m_sah_71;
	Sah __m_sah_77;
	Sah __m_sah_87;
	Sah __m_sah_69;
	Sah __m_sah_83;
	Sah __m_sah_89;
	Sah __m_sah_79;
	Sah __m_sah_49;
	Sah __m_sah_57;
	Sah __m_sah_59;
	Sah __m_sah_19;
	Sah __m_sah_23;
	Sah __m_sah_27;
	Sah __m_sah_25;
	Sah __m_sah_29;
	Sah __m_sah_17;
	Sah __m_sah_13;
	Sah __m_sah_5;
	Sah __m_sah_15;
	Sah __m_sah_7;
	Sah __m_sah_11;
	Sah __m_sah_9;
	Sah __m_sah_31;
	Sah __m_sah_21;
	Sah __m_sah_35;
	Sah __m_sah_53;
	Sah __m_sah_47;
	Sah __m_sah_55;
	Sah __m_sah_33;
	Sah __m_sah_45;
	Sah __m_sah_51;
	Sah __m_sah_37;
	Sah __m_sah_39;
	Sah __m_sah_43;
	Sah __m_sah_41;
	SineCycle __m_cycle_110;
	SineCycle __m_cycle_109;
	SineCycle __m_cycle_107;
	SineCycle __m_cycle_117;
	SineCycle __m_cycle_108;
	SineCycle __m_cycle_116;
	SineCycle __m_cycle_111;
	SineCycle __m_cycle_114;
	SineCycle __m_cycle_106;
	SineCycle __m_cycle_115;
	SineCycle __m_cycle_112;
	SineCycle __m_cycle_113;
	SineCycle __m_cycle_105;
	SineCycle __m_cycle_119;
	SineCycle __m_cycle_118;
	SineCycle __m_cycle_104;
	SineData __sinedata;
	int vectorsize;
	int __exception;
	t_sample __m_carry_98;
	t_sample samplerate;
	t_sample __m_carry_102;
	t_sample __m_count_96;
	t_sample m_JoyY_1;
	t_sample m_JoyX_3;
	t_sample m_Reset_2;
	t_sample __m_count_100;
	t_sample samples_to_seconds;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_JoyY_1 = ((int)0);
		m_Reset_2 = ((int)0);
		m_JoyX_3 = ((int)0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_4.reset(0);
		__m_sah_5.reset(0);
		__m_phasor_6.reset(0.5);
		__m_sah_7.reset(0);
		__m_phasor_8.reset(0);
		__m_sah_9.reset(0);
		__m_phasor_10.reset(0.5);
		__m_sah_11.reset(0);
		__m_phasor_12.reset(0.05);
		__m_sah_13.reset(0);
		__m_phasor_14.reset(0.15);
		__m_sah_15.reset(0);
		__m_phasor_16.reset(0.25);
		__m_sah_17.reset(0);
		__m_phasor_18.reset(0.35);
		__m_sah_19.reset(0);
		__m_phasor_20.reset(0.45);
		__m_sah_21.reset(0);
		__m_phasor_22.reset(0.55);
		__m_sah_23.reset(0);
		__m_phasor_24.reset(0.65);
		__m_sah_25.reset(0);
		__m_phasor_26.reset(0.75);
		__m_sah_27.reset(0);
		__m_phasor_28.reset(0.85);
		__m_sah_29.reset(0);
		__m_phasor_30.reset(0.95);
		__m_sah_31.reset(0);
		__m_phasor_32.reset(0);
		__m_sah_33.reset(0);
		__m_phasor_34.reset(0.1);
		__m_sah_35.reset(0);
		__m_phasor_36.reset(0.2);
		__m_sah_37.reset(0);
		__m_phasor_38.reset(0.3);
		__m_sah_39.reset(0);
		__m_phasor_40.reset(0.4);
		__m_sah_41.reset(0);
		__m_phasor_42.reset(0.5);
		__m_sah_43.reset(0);
		__m_phasor_44.reset(0.6);
		__m_sah_45.reset(0);
		__m_phasor_46.reset(0.7);
		__m_sah_47.reset(0);
		__m_phasor_48.reset(0.8);
		__m_sah_49.reset(0);
		__m_phasor_50.reset(0.9);
		__m_sah_51.reset(0);
		__m_phasor_52.reset(0.025);
		__m_sah_53.reset(0);
		__m_phasor_54.reset(0.125);
		__m_sah_55.reset(0);
		__m_phasor_56.reset(0.225);
		__m_sah_57.reset(0);
		__m_phasor_58.reset(0.325);
		__m_sah_59.reset(0);
		__m_phasor_60.reset(0.425);
		__m_sah_61.reset(0);
		__m_phasor_62.reset(0.525);
		__m_sah_63.reset(0);
		__m_phasor_64.reset(0.625);
		__m_sah_65.reset(0);
		__m_phasor_66.reset(0.725);
		__m_sah_67.reset(0);
		__m_phasor_68.reset(0.825);
		__m_sah_69.reset(0);
		__m_phasor_70.reset(0.925);
		__m_sah_71.reset(0);
		__m_phasor_72.reset(0);
		__m_sah_73.reset(0);
		__m_phasor_74.reset(0.175);
		__m_sah_75.reset(0);
		__m_phasor_76.reset(0.275);
		__m_sah_77.reset(0);
		__m_phasor_78.reset(0.375);
		__m_sah_79.reset(0);
		__m_phasor_80.reset(0.475);
		__m_sah_81.reset(0);
		__m_phasor_82.reset(0.575);
		__m_sah_83.reset(0);
		__m_phasor_84.reset(0.675);
		__m_sah_85.reset(0);
		__m_phasor_86.reset(0.775);
		__m_sah_87.reset(0);
		__m_phasor_88.reset(0.875);
		__m_sah_89.reset(0);
		__m_phasor_90.reset(0.975);
		__m_sah_91.reset(0);
		__m_phasor_92.reset(0.1);
		__m_sah_93.reset(0);
		__m_phasor_94.reset(0.6);
		__m_sah_95.reset(0);
		__m_count_96 = 0;
		__m_carry_98 = 0;
		__m_count_100 = 0;
		__m_carry_102 = 0;
		__m_cycle_104.reset(samplerate, 0);
		__m_cycle_105.reset(samplerate, 0);
		__m_cycle_106.reset(samplerate, 0);
		__m_cycle_107.reset(samplerate, 0);
		__m_cycle_108.reset(samplerate, 0);
		__m_cycle_109.reset(samplerate, 0);
		__m_cycle_110.reset(samplerate, 0);
		__m_cycle_111.reset(samplerate, 0);
		__m_cycle_112.reset(samplerate, 0);
		__m_cycle_113.reset(samplerate, 0);
		__m_cycle_114.reset(samplerate, 0);
		__m_cycle_115.reset(samplerate, 0);
		__m_cycle_116.reset(samplerate, 0);
		__m_cycle_117.reset(samplerate, 0);
		__m_cycle_118.reset(samplerate, 0);
		__m_cycle_119.reset(samplerate, 0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		samples_to_seconds = (1 / samplerate);
		int expr_13790 = (m_Reset_2 > ((t_sample)0.001));
		t_sample add_1418 = (m_JoyX_3 + ((t_sample)0.2));
		t_sample sub_13934 = (add_1418 - ((t_sample)0.2));
		t_sample scale_13931 = ((safepow((sub_13934 * ((t_sample)1)), ((int)1)) * ((t_sample)0.8)) + ((t_sample)0.2));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample phasor_437 = __m_phasor_4(((int)20), samples_to_seconds);
			t_sample sah_446 = __m_sah_5(m_JoyX_3, phasor_437, ((t_sample)0.5));
			t_sample phasor_436 = __m_phasor_6(((int)20), samples_to_seconds);
			t_sample sah_445 = __m_sah_7(m_JoyX_3, phasor_436, ((t_sample)0.5));
			t_sample sub_444 = (sah_446 - sah_445);
			t_sample pow_443 = safepow(sub_444, ((int)2));
			t_sample phasor_440 = __m_phasor_8(((int)20), samples_to_seconds);
			t_sample sah_450 = __m_sah_9(m_JoyY_1, phasor_440, ((t_sample)0.5));
			t_sample phasor_438 = __m_phasor_10(((int)20), samples_to_seconds);
			t_sample sah_449 = __m_sah_11(m_JoyY_1, phasor_438, ((t_sample)0.5));
			t_sample sub_448 = (sah_450 - sah_449);
			t_sample pow_447 = safepow(sub_448, ((int)2));
			t_sample add_442 = (pow_443 + pow_447);
			t_sample sqrt_441 = sqrt(add_442);
			t_sample div_3460 = (sqrt_441 * ((t_sample)2));
			t_sample phasor_5804 = __m_phasor_12(((int)1), samples_to_seconds);
			t_sample sah_5078 = __m_sah_13(div_3460, phasor_5804, ((t_sample)0.5));
			t_sample phasor_5318 = __m_phasor_14(((int)1), samples_to_seconds);
			t_sample sah_5077 = __m_sah_15(div_3460, phasor_5318, ((t_sample)0.5));
			t_sample phasor_5331 = __m_phasor_16(((int)1), samples_to_seconds);
			t_sample sah_5076 = __m_sah_17(div_3460, phasor_5331, ((t_sample)0.5));
			t_sample phasor_5344 = __m_phasor_18(((int)1), samples_to_seconds);
			t_sample sah_5075 = __m_sah_19(div_3460, phasor_5344, ((t_sample)0.5));
			t_sample phasor_5357 = __m_phasor_20(((int)1), samples_to_seconds);
			t_sample sah_5074 = __m_sah_21(div_3460, phasor_5357, ((t_sample)0.5));
			t_sample phasor_5370 = __m_phasor_22(((int)1), samples_to_seconds);
			t_sample sah_5073 = __m_sah_23(div_3460, phasor_5370, ((t_sample)0.5));
			t_sample phasor_5383 = __m_phasor_24(((int)1), samples_to_seconds);
			t_sample sah_5072 = __m_sah_25(div_3460, phasor_5383, ((t_sample)0.5));
			t_sample phasor_5396 = __m_phasor_26(((int)1), samples_to_seconds);
			t_sample sah_5071 = __m_sah_27(div_3460, phasor_5396, ((t_sample)0.5));
			t_sample phasor_5409 = __m_phasor_28(((int)1), samples_to_seconds);
			t_sample sah_5070 = __m_sah_29(div_3460, phasor_5409, ((t_sample)0.5));
			t_sample phasor_5422 = __m_phasor_30(((int)1), samples_to_seconds);
			t_sample sah_5069 = __m_sah_31(div_3460, phasor_5422, ((t_sample)0.5));
			t_sample expr_6235 = (((((((((sah_5078 + sah_5077) + sah_5076) + sah_5075) + sah_5074) + sah_5073) + sah_5072) + sah_5071) + sah_5070) + sah_5069);
			t_sample phasor_3890 = __m_phasor_32(((int)1), samples_to_seconds);
			t_sample sah_4083 = __m_sah_33(div_3460, phasor_3890, ((t_sample)0.5));
			t_sample phasor_3939 = __m_phasor_34(((int)1), samples_to_seconds);
			t_sample sah_4095 = __m_sah_35(div_3460, phasor_3939, ((t_sample)0.5));
			t_sample phasor_3950 = __m_phasor_36(((int)1), samples_to_seconds);
			t_sample sah_4107 = __m_sah_37(div_3460, phasor_3950, ((t_sample)0.5));
			t_sample phasor_3961 = __m_phasor_38(((int)1), samples_to_seconds);
			t_sample sah_4121 = __m_sah_39(div_3460, phasor_3961, ((t_sample)0.5));
			t_sample phasor_3972 = __m_phasor_40(((int)1), samples_to_seconds);
			t_sample sah_4120 = __m_sah_41(div_3460, phasor_3972, ((t_sample)0.5));
			t_sample phasor_3983 = __m_phasor_42(((int)1), samples_to_seconds);
			t_sample sah_4119 = __m_sah_43(div_3460, phasor_3983, ((t_sample)0.5));
			t_sample phasor_3994 = __m_phasor_44(((int)1), samples_to_seconds);
			t_sample sah_4135 = __m_sah_45(div_3460, phasor_3994, ((t_sample)0.5));
			t_sample phasor_4005 = __m_phasor_46(((int)1), samples_to_seconds);
			t_sample sah_4134 = __m_sah_47(div_3460, phasor_4005, ((t_sample)0.5));
			t_sample phasor_4016 = __m_phasor_48(((int)1), samples_to_seconds);
			t_sample sah_4133 = __m_sah_49(div_3460, phasor_4016, ((t_sample)0.5));
			t_sample phasor_4027 = __m_phasor_50(((int)1), samples_to_seconds);
			t_sample sah_4147 = __m_sah_51(div_3460, phasor_4027, ((t_sample)0.5));
			t_sample expr_6234 = (((((((((sah_4083 + sah_4095) + sah_4107) + sah_4121) + sah_4120) + sah_4119) + sah_4135) + sah_4134) + sah_4133) + sah_4147);
			t_sample add_5244 = (expr_6234 + expr_6235);
			t_sample phasor_5819 = __m_phasor_52(((int)1), samples_to_seconds);
			t_sample sah_5568 = __m_sah_53(div_3460, phasor_5819, ((t_sample)0.5));
			t_sample phasor_5834 = __m_phasor_54(((int)1), samples_to_seconds);
			t_sample sah_5567 = __m_sah_55(div_3460, phasor_5834, ((t_sample)0.5));
			t_sample phasor_5849 = __m_phasor_56(((int)1), samples_to_seconds);
			t_sample sah_5566 = __m_sah_57(div_3460, phasor_5849, ((t_sample)0.5));
			t_sample phasor_5864 = __m_phasor_58(((int)1), samples_to_seconds);
			t_sample sah_5565 = __m_sah_59(div_3460, phasor_5864, ((t_sample)0.5));
			t_sample phasor_5879 = __m_phasor_60(((int)1), samples_to_seconds);
			t_sample sah_5564 = __m_sah_61(div_3460, phasor_5879, ((t_sample)0.5));
			t_sample phasor_5894 = __m_phasor_62(((int)1), samples_to_seconds);
			t_sample sah_5563 = __m_sah_63(div_3460, phasor_5894, ((t_sample)0.5));
			t_sample phasor_5909 = __m_phasor_64(((int)1), samples_to_seconds);
			t_sample sah_5562 = __m_sah_65(div_3460, phasor_5909, ((t_sample)0.5));
			t_sample phasor_5924 = __m_phasor_66(((int)1), samples_to_seconds);
			t_sample sah_5561 = __m_sah_67(div_3460, phasor_5924, ((t_sample)0.5));
			t_sample phasor_5939 = __m_phasor_68(((int)1), samples_to_seconds);
			t_sample sah_5560 = __m_sah_69(div_3460, phasor_5939, ((t_sample)0.5));
			t_sample phasor_5954 = __m_phasor_70(((int)1), samples_to_seconds);
			t_sample sah_5559 = __m_sah_71(div_3460, phasor_5954, ((t_sample)0.5));
			t_sample expr_6237 = (((((((((sah_5568 + sah_5567) + sah_5566) + sah_5565) + sah_5564) + sah_5563) + sah_5562) + sah_5561) + sah_5560) + sah_5559);
			t_sample phasor_5969 = __m_phasor_72(((int)1), samples_to_seconds);
			t_sample sah_5545 = __m_sah_73(div_3460, phasor_5969, ((t_sample)0.5));
			t_sample phasor_5984 = __m_phasor_74(((int)1), samples_to_seconds);
			t_sample sah_5544 = __m_sah_75(div_3460, phasor_5984, ((t_sample)0.5));
			t_sample phasor_5999 = __m_phasor_76(((int)1), samples_to_seconds);
			t_sample sah_5543 = __m_sah_77(div_3460, phasor_5999, ((t_sample)0.5));
			t_sample phasor_6014 = __m_phasor_78(((int)1), samples_to_seconds);
			t_sample sah_5542 = __m_sah_79(div_3460, phasor_6014, ((t_sample)0.5));
			t_sample phasor_6029 = __m_phasor_80(((int)1), samples_to_seconds);
			t_sample sah_5541 = __m_sah_81(div_3460, phasor_6029, ((t_sample)0.5));
			t_sample phasor_6044 = __m_phasor_82(((int)1), samples_to_seconds);
			t_sample sah_5540 = __m_sah_83(div_3460, phasor_6044, ((t_sample)0.5));
			t_sample phasor_6059 = __m_phasor_84(((int)1), samples_to_seconds);
			t_sample sah_5539 = __m_sah_85(div_3460, phasor_6059, ((t_sample)0.5));
			t_sample phasor_6074 = __m_phasor_86(((int)1), samples_to_seconds);
			t_sample sah_5538 = __m_sah_87(div_3460, phasor_6074, ((t_sample)0.5));
			t_sample phasor_6089 = __m_phasor_88(((int)1), samples_to_seconds);
			t_sample sah_5537 = __m_sah_89(div_3460, phasor_6089, ((t_sample)0.5));
			t_sample phasor_6104 = __m_phasor_90(((int)1), samples_to_seconds);
			t_sample sah_5536 = __m_sah_91(div_3460, phasor_6104, ((t_sample)0.5));
			t_sample expr_6236 = (((((((((sah_5545 + sah_5544) + sah_5543) + sah_5542) + sah_5541) + sah_5540) + sah_5539) + sah_5538) + sah_5537) + sah_5536);
			t_sample add_6133 = (expr_6237 + expr_6236);
			t_sample add_6176 = (add_5244 + add_6133);
			t_sample div_6233 = (add_6176 * ((t_sample)0.025));
			t_sample out3 = div_6233;
			t_sample phasor_3756 = __m_phasor_92(((int)10), samples_to_seconds);
			t_sample sah_412 = __m_sah_93(div_6233, phasor_3756, ((t_sample)0.5));
			t_sample phasor_3766 = __m_phasor_94(((int)10), samples_to_seconds);
			t_sample sah_411 = __m_sah_95(div_6233, phasor_3766, ((t_sample)0.5));
			t_sample sub_410 = (sah_412 - sah_411);
			t_sample abs_409 = fabs(sub_410);
			t_sample out4 = abs_409;
			int expr_13791 = ((((t_sample)0.015) >= abs_409) && (div_6233 >= ((t_sample)0.001)));
			int switch_398 = (expr_13791 ? ((int)1) : ((int)0));
			__m_count_96 = (expr_13790 ? 0 : (fixdenorm(__m_count_96 + switch_398)));
			int carry_97 = 0;
			if ((expr_13790 != 0)) {
				__m_count_96 = 0;
				__m_carry_98 = 0;
				
			} else if (((((int)48000) > 0) && (__m_count_96 >= ((int)48000)))) {
				int wraps_99 = (__m_count_96 / ((int)48000));
				__m_carry_98 = (__m_carry_98 + wraps_99);
				__m_count_96 = (__m_count_96 - (wraps_99 * ((int)48000)));
				carry_97 = 1;
				
			};
			int counter_401 = __m_count_96;
			int counter_402 = carry_97;
			int counter_403 = __m_carry_98;
			int switch_391 = (expr_13791 ? ((int)0) : ((int)5));
			__m_count_100 = (expr_13790 ? 0 : (fixdenorm(__m_count_100 + switch_391)));
			int carry_101 = 0;
			if ((expr_13790 != 0)) {
				__m_count_100 = 0;
				__m_carry_102 = 0;
				
			} else if (((((int)48000) > 0) && (__m_count_100 >= ((int)48000)))) {
				int wraps_103 = (__m_count_100 / ((int)48000));
				__m_carry_102 = (__m_carry_102 + wraps_103);
				__m_count_100 = (__m_count_100 - (wraps_103 * ((int)48000)));
				carry_101 = 1;
				
			};
			int counter_393 = __m_count_100;
			int counter_394 = carry_101;
			int counter_395 = __m_carry_102;
			int sub_392 = (counter_403 - counter_395);
			t_sample out5 = sub_392;
			t_sample expr_13559 = (((sub_392 > ((int)2)) * ((int)1)) * ((t_sample)0.33333333333333));
			t_sample expr_13556 = (((sub_392 > ((int)5)) * ((int)1)) * ((t_sample)0.16666666666667));
			t_sample expr_13555 = (((sub_392 > ((int)6)) * ((int)1)) * ((t_sample)0.14285714285714));
			int expr_13561 = (sub_392 > ((int)0));
			t_sample expr_13558 = (((sub_392 > ((int)3)) * ((int)1)) * ((t_sample)0.25));
			t_sample expr_13560 = (((sub_392 > ((int)1)) * ((int)1)) * ((t_sample)0.5));
			t_sample expr_13557 = (((sub_392 > ((int)4)) * ((int)1)) * ((t_sample)0.2));
			__m_cycle_104.freq(((int)40));
			t_sample cycle_13550 = __m_cycle_104(__sinedata);
			t_sample cycleindex_13551 = __m_cycle_104.phase();
			__m_cycle_105.freq(((int)20480));
			t_sample cycle_13516 = __m_cycle_105(__sinedata);
			t_sample cycleindex_13517 = __m_cycle_105.phase();
			t_sample mul_13514 = (((int)0) * cycle_13516);
			__m_cycle_106.freq(((int)80));
			t_sample cycle_13548 = __m_cycle_106(__sinedata);
			t_sample cycleindex_13549 = __m_cycle_106.phase();
			t_sample mul_13534 = (expr_13561 * cycle_13548);
			__m_cycle_107.freq(((int)160));
			t_sample cycle_13546 = __m_cycle_107(__sinedata);
			t_sample cycleindex_13547 = __m_cycle_107.phase();
			t_sample mul_13532 = (expr_13560 * cycle_13546);
			__m_cycle_108.freq(((int)320));
			t_sample cycle_13544 = __m_cycle_108(__sinedata);
			t_sample cycleindex_13545 = __m_cycle_108.phase();
			t_sample mul_13530 = (expr_13559 * cycle_13544);
			__m_cycle_109.freq(((int)640));
			t_sample cycle_13542 = __m_cycle_109(__sinedata);
			t_sample cycleindex_13543 = __m_cycle_109.phase();
			t_sample mul_13528 = (expr_13558 * cycle_13542);
			__m_cycle_110.freq(((int)10240));
			t_sample cycle_13520 = __m_cycle_110(__sinedata);
			t_sample cycleindex_13521 = __m_cycle_110.phase();
			t_sample mul_13518 = (((int)0) * cycle_13520);
			__m_cycle_111.freq(((int)1280));
			t_sample cycle_13540 = __m_cycle_111(__sinedata);
			t_sample cycleindex_13541 = __m_cycle_111.phase();
			t_sample mul_13526 = (expr_13557 * cycle_13540);
			__m_cycle_112.freq(((int)2560));
			t_sample cycle_13538 = __m_cycle_112(__sinedata);
			t_sample cycleindex_13539 = __m_cycle_112.phase();
			t_sample mul_13524 = (expr_13556 * cycle_13538);
			__m_cycle_113.freq(((int)5120));
			t_sample cycle_13536 = __m_cycle_113(__sinedata);
			t_sample cycleindex_13537 = __m_cycle_113.phase();
			t_sample mul_13522 = (expr_13555 * cycle_13536);
			t_sample mul_13552 = ((((((((((cycle_13550 + mul_13522) + mul_13524) + mul_13526) + mul_13518) + mul_13528) + mul_13530) + mul_13532) + mul_13534) + mul_13514) * ((t_sample)0.5));
			t_sample expr_13840 = (mul_13552 * (sub_392 >= ((int)0)));
			t_sample mul_13173 = (expr_13840 * ((t_sample)0.5));
			t_sample noise_1420 = noise();
			t_sample mul_1419 = (scale_13931 * noise_1420);
			t_sample expr_13841 = (mul_1419 * (sub_392 >= ((int)-50)));
			t_sample mul_13110 = (expr_13841 * ((t_sample)0.2));
			t_sample mul_10792 = (div_6233 * ((int)8));
			__m_cycle_114.freq(((int)240));
			t_sample cycle_3133 = __m_cycle_114(__sinedata);
			t_sample cycleindex_3134 = __m_cycle_114.phase();
			t_sample mul_8559 = (((int)240) * mul_10792);
			t_sample mul_3129 = (cycle_3133 * mul_8559);
			t_sample add_3132 = (((int)240) + mul_3129);
			__m_cycle_115.freq(add_3132);
			t_sample cycle_3135 = __m_cycle_115(__sinedata);
			t_sample cycleindex_3136 = __m_cycle_115.phase();
			t_sample expr_13842 = (cycle_3135 * (sub_392 >= ((int)5)));
			t_sample mul_13236 = (expr_13842 * ((t_sample)0.5));
			t_sample mul_11112 = (div_6233 * ((int)10));
			__m_cycle_116.freq(((int)114));
			t_sample cycle_10734 = __m_cycle_116(__sinedata);
			t_sample cycleindex_10735 = __m_cycle_116.phase();
			t_sample mul_10730 = (((int)114) * mul_11112);
			t_sample mul_10731 = (cycle_10734 * mul_10730);
			t_sample add_10733 = (((int)80) + mul_10731);
			__m_cycle_117.freq(add_10733);
			t_sample cycle_10736 = __m_cycle_117(__sinedata);
			t_sample cycleindex_10737 = __m_cycle_117.phase();
			t_sample expr_13843 = (cycle_10736 * (sub_392 >= ((int)10)));
			t_sample mul_13299 = (expr_13843 * ((t_sample)0.5));
			t_sample mul_12010 = (abs_409 * ((int)1000));
			__m_cycle_118.freq(((t_sample)4630.4));
			t_sample cycle_13850 = __m_cycle_118(__sinedata);
			t_sample cycleindex_13849 = __m_cycle_118.phase();
			t_sample mul_13852 = (((t_sample)4630.4) * mul_12010);
			t_sample mul_13848 = (cycle_13850 * mul_13852);
			t_sample add_13847 = (((int)640) + mul_13848);
			__m_cycle_119.freq(add_13847);
			t_sample cycle_13845 = __m_cycle_119(__sinedata);
			t_sample cycleindex_13846 = __m_cycle_119.phase();
			t_sample expr_13844 = (cycle_13845 * (sub_392 >= ((int)17)));
			t_sample mul_13441 = (expr_13844 * ((t_sample)0.1));
			t_sample gen_13853 = ((((mul_13110 + mul_13173) + mul_13236) + mul_13299) + mul_13441);
			t_sample out1 = ((((int)0) + gen_13853) + gen_13853);
			t_sample out2 = ((int)0);
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_JoyY(t_param _value) {
		m_JoyY_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_Reset(t_param _value) {
		m_Reset_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_JoyX(t_param _value) {
		m_JoyX_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 5;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 3; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "out3", "out4", "out5" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_JoyX(value); break;
		case 1: self->set_JoyY(value); break;
		case 2: self->set_Reset(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_JoyX_3; break;
		case 1: *value = self->m_JoyY_1; break;
		case 2: *value = self->m_Reset_2; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(3 * sizeof(ParamInfo));
	self->__commonstate.numparams = 3;
	// initialize parameter 0 ("m_JoyX_3")
	pi = self->__commonstate.params + 0;
	pi->name = "JoyX";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_JoyX_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_JoyY_1")
	pi = self->__commonstate.params + 1;
	pi->name = "JoyY";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_JoyY_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_Reset_2")
	pi = self->__commonstate.params + 2;
	pi->name = "Reset";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Reset_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // soup::
