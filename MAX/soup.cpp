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
	Phasor __m_phasor_46;
	Phasor __m_phasor_60;
	Phasor __m_phasor_28;
	Phasor __m_phasor_30;
	Phasor __m_phasor_76;
	Phasor __m_phasor_32;
	Phasor __m_phasor_78;
	Phasor __m_phasor_66;
	Phasor __m_phasor_26;
	Phasor __m_phasor_80;
	Phasor __m_phasor_24;
	Phasor __m_phasor_22;
	Phasor __m_phasor_50;
	Phasor __m_phasor_74;
	Phasor __m_phasor_42;
	Phasor __m_phasor_70;
	Phasor __m_phasor_44;
	Phasor __m_phasor_34;
	Phasor __m_phasor_48;
	Phasor __m_phasor_72;
	Phasor __m_phasor_40;
	Phasor __m_phasor_36;
	Phasor __m_phasor_38;
	Phasor __m_phasor_68;
	Phasor __m_phasor_52;
	Phasor __m_phasor_82;
	Phasor __m_phasor_4;
	Phasor __m_phasor_56;
	Phasor __m_phasor_6;
	Phasor __m_phasor_20;
	Phasor __m_phasor_90;
	Phasor __m_phasor_58;
	Phasor __m_phasor_92;
	Phasor __m_phasor_62;
	Phasor __m_phasor_94;
	Phasor __m_phasor_8;
	Phasor __m_phasor_88;
	Phasor __m_phasor_10;
	Phasor __m_phasor_14;
	Phasor __m_phasor_64;
	Phasor __m_phasor_84;
	Phasor __m_phasor_16;
	Phasor __m_phasor_54;
	Phasor __m_phasor_12;
	Phasor __m_phasor_18;
	Phasor __m_phasor_86;
	Sah __m_sah_65;
	Sah __m_sah_63;
	Sah __m_sah_67;
	Sah __m_sah_57;
	Sah __m_sah_77;
	Sah __m_sah_71;
	Sah __m_sah_89;
	Sah __m_sah_87;
	Sah __m_sah_91;
	Sah __m_sah_95;
	Sah __m_sah_93;
	Sah __m_sah_69;
	Sah __m_sah_85;
	Sah __m_sah_81;
	Sah __m_sah_73;
	Sah __m_sah_83;
	Sah __m_sah_75;
	Sah __m_sah_79;
	Sah __m_sah_61;
	Sah __m_sah_49;
	Sah __m_sah_19;
	Sah __m_sah_59;
	Sah __m_sah_17;
	Sah __m_sah_21;
	Sah __m_sah_25;
	Sah __m_sah_23;
	Sah __m_sah_29;
	Sah __m_sah_15;
	Sah __m_sah_11;
	Sah __m_sah_5;
	Sah __m_sah_13;
	Sah __m_sah_7;
	Sah __m_sah_9;
	Sah __m_sah_31;
	Sah __m_sah_27;
	Sah __m_sah_45;
	Sah __m_sah_55;
	Sah __m_sah_47;
	Sah __m_sah_33;
	Sah __m_sah_51;
	Sah __m_sah_43;
	Sah __m_sah_39;
	Sah __m_sah_41;
	Sah __m_sah_35;
	Sah __m_sah_37;
	Sah __m_sah_53;
	SineCycle __m_cycle_112;
	SineCycle __m_cycle_111;
	SineCycle __m_cycle_110;
	SineCycle __m_cycle_108;
	SineCycle __m_cycle_109;
	SineCycle __m_cycle_119;
	SineCycle __m_cycle_113;
	SineCycle __m_cycle_117;
	SineCycle __m_cycle_107;
	SineCycle __m_cycle_118;
	SineCycle __m_cycle_114;
	SineCycle __m_cycle_116;
	SineCycle __m_cycle_115;
	SineCycle __m_cycle_106;
	SineCycle __m_cycle_121;
	SineCycle __m_cycle_104;
	SineCycle __m_cycle_105;
	SineCycle __m_cycle_120;
	SineData __sinedata;
	int vectorsize;
	int __exception;
	t_sample __m_carry_98;
	t_sample samplerate;
	t_sample __m_carry_102;
	t_sample __m_count_96;
	t_sample m_Reset_1;
	t_sample m_JoyX_3;
	t_sample m_JoyY_2;
	t_sample __m_count_100;
	t_sample samples_to_seconds;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_Reset_1 = ((int)0);
		m_JoyY_2 = ((int)0);
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
		__m_phasor_12.reset(0);
		__m_sah_13.reset(0);
		__m_phasor_14.reset(0.1);
		__m_sah_15.reset(0);
		__m_phasor_16.reset(0.2);
		__m_sah_17.reset(0);
		__m_phasor_18.reset(0.3);
		__m_sah_19.reset(0);
		__m_phasor_20.reset(0.4);
		__m_sah_21.reset(0);
		__m_phasor_22.reset(0.5);
		__m_sah_23.reset(0);
		__m_phasor_24.reset(0.6);
		__m_sah_25.reset(0);
		__m_phasor_26.reset(0.7);
		__m_sah_27.reset(0);
		__m_phasor_28.reset(0.8);
		__m_sah_29.reset(0);
		__m_phasor_30.reset(0.9);
		__m_sah_31.reset(0);
		__m_phasor_32.reset(0.05);
		__m_sah_33.reset(0);
		__m_phasor_34.reset(0.15);
		__m_sah_35.reset(0);
		__m_phasor_36.reset(0.25);
		__m_sah_37.reset(0);
		__m_phasor_38.reset(0.35);
		__m_sah_39.reset(0);
		__m_phasor_40.reset(0.45);
		__m_sah_41.reset(0);
		__m_phasor_42.reset(0.55);
		__m_sah_43.reset(0);
		__m_phasor_44.reset(0.65);
		__m_sah_45.reset(0);
		__m_phasor_46.reset(0.75);
		__m_sah_47.reset(0);
		__m_phasor_48.reset(0.85);
		__m_sah_49.reset(0);
		__m_phasor_50.reset(0.95);
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
		__m_cycle_120.reset(samplerate, 0);
		__m_cycle_121.reset(samplerate, 0);
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
		int expr_29100 = (m_Reset_1 > ((t_sample)0.001));
		t_sample add_14133 = (m_JoyX_3 + ((t_sample)0.2));
		t_sample sub_29792 = (add_14133 - ((t_sample)0.2));
		t_sample scale_29789 = ((safepow((sub_29792 * ((t_sample)1)), ((int)1)) * ((t_sample)0.8)) + ((t_sample)0.2));
		t_sample mul_25660 = (m_JoyX_3 * (-1));
		t_sample add_28563 = (mul_25660 + ((t_sample)1.3));
		t_sample sub_29796 = (add_28563 - ((t_sample)0.3));
		t_sample scale_29793 = ((safepow((sub_29796 * ((t_sample)1)), ((int)1)) * ((t_sample)0.7)) + ((t_sample)0.3));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample phasor_14311 = __m_phasor_4(((int)20), samples_to_seconds);
			t_sample sah_14320 = __m_sah_5(m_JoyX_3, phasor_14311, ((t_sample)0.5));
			t_sample phasor_14310 = __m_phasor_6(((int)20), samples_to_seconds);
			t_sample sah_14319 = __m_sah_7(m_JoyX_3, phasor_14310, ((t_sample)0.5));
			t_sample sub_14318 = (sah_14320 - sah_14319);
			t_sample pow_14317 = safepow(sub_14318, ((int)2));
			t_sample phasor_14314 = __m_phasor_8(((int)20), samples_to_seconds);
			t_sample sah_14324 = __m_sah_9(m_JoyY_2, phasor_14314, ((t_sample)0.5));
			t_sample phasor_14312 = __m_phasor_10(((int)20), samples_to_seconds);
			t_sample sah_14323 = __m_sah_11(m_JoyY_2, phasor_14312, ((t_sample)0.5));
			t_sample sub_14322 = (sah_14324 - sah_14323);
			t_sample pow_14321 = safepow(sub_14322, ((int)2));
			t_sample add_14316 = (pow_14317 + pow_14321);
			t_sample sqrt_14315 = sqrt(add_14316);
			t_sample div_14307 = (sqrt_14315 * ((t_sample)2));
			t_sample phasor_14301 = __m_phasor_12(((int)1), samples_to_seconds);
			t_sample sah_14290 = __m_sah_13(div_14307, phasor_14301, ((t_sample)0.5));
			t_sample phasor_14300 = __m_phasor_14(((int)1), samples_to_seconds);
			t_sample sah_14289 = __m_sah_15(div_14307, phasor_14300, ((t_sample)0.5));
			t_sample phasor_14299 = __m_phasor_16(((int)1), samples_to_seconds);
			t_sample sah_14288 = __m_sah_17(div_14307, phasor_14299, ((t_sample)0.5));
			t_sample phasor_14298 = __m_phasor_18(((int)1), samples_to_seconds);
			t_sample sah_14287 = __m_sah_19(div_14307, phasor_14298, ((t_sample)0.5));
			t_sample phasor_14297 = __m_phasor_20(((int)1), samples_to_seconds);
			t_sample sah_14286 = __m_sah_21(div_14307, phasor_14297, ((t_sample)0.5));
			t_sample phasor_14296 = __m_phasor_22(((int)1), samples_to_seconds);
			t_sample sah_14285 = __m_sah_23(div_14307, phasor_14296, ((t_sample)0.5));
			t_sample phasor_14295 = __m_phasor_24(((int)1), samples_to_seconds);
			t_sample sah_14284 = __m_sah_25(div_14307, phasor_14295, ((t_sample)0.5));
			t_sample phasor_14294 = __m_phasor_26(((int)1), samples_to_seconds);
			t_sample sah_14283 = __m_sah_27(div_14307, phasor_14294, ((t_sample)0.5));
			t_sample phasor_14293 = __m_phasor_28(((int)1), samples_to_seconds);
			t_sample sah_14282 = __m_sah_29(div_14307, phasor_14293, ((t_sample)0.5));
			t_sample phasor_14292 = __m_phasor_30(((int)1), samples_to_seconds);
			t_sample sah_14281 = __m_sah_31(div_14307, phasor_14292, ((t_sample)0.5));
			t_sample expr_14305 = (((((((((sah_14290 + sah_14289) + sah_14288) + sah_14287) + sah_14286) + sah_14285) + sah_14284) + sah_14283) + sah_14282) + sah_14281);
			t_sample phasor_14278 = __m_phasor_32(((int)1), samples_to_seconds);
			t_sample sah_14267 = __m_sah_33(div_14307, phasor_14278, ((t_sample)0.5));
			t_sample phasor_14277 = __m_phasor_34(((int)1), samples_to_seconds);
			t_sample sah_14266 = __m_sah_35(div_14307, phasor_14277, ((t_sample)0.5));
			t_sample phasor_14276 = __m_phasor_36(((int)1), samples_to_seconds);
			t_sample sah_14265 = __m_sah_37(div_14307, phasor_14276, ((t_sample)0.5));
			t_sample phasor_14275 = __m_phasor_38(((int)1), samples_to_seconds);
			t_sample sah_14264 = __m_sah_39(div_14307, phasor_14275, ((t_sample)0.5));
			t_sample phasor_14274 = __m_phasor_40(((int)1), samples_to_seconds);
			t_sample sah_14263 = __m_sah_41(div_14307, phasor_14274, ((t_sample)0.5));
			t_sample phasor_14273 = __m_phasor_42(((int)1), samples_to_seconds);
			t_sample sah_14262 = __m_sah_43(div_14307, phasor_14273, ((t_sample)0.5));
			t_sample phasor_14272 = __m_phasor_44(((int)1), samples_to_seconds);
			t_sample sah_14261 = __m_sah_45(div_14307, phasor_14272, ((t_sample)0.5));
			t_sample phasor_14271 = __m_phasor_46(((int)1), samples_to_seconds);
			t_sample sah_14260 = __m_sah_47(div_14307, phasor_14271, ((t_sample)0.5));
			t_sample phasor_14270 = __m_phasor_48(((int)1), samples_to_seconds);
			t_sample sah_14259 = __m_sah_49(div_14307, phasor_14270, ((t_sample)0.5));
			t_sample phasor_14269 = __m_phasor_50(((int)1), samples_to_seconds);
			t_sample sah_14258 = __m_sah_51(div_14307, phasor_14269, ((t_sample)0.5));
			t_sample expr_14304 = (((((((((sah_14267 + sah_14266) + sah_14265) + sah_14264) + sah_14263) + sah_14262) + sah_14261) + sah_14260) + sah_14259) + sah_14258);
			t_sample add_14254 = (expr_14305 + expr_14304);
			t_sample phasor_14253 = __m_phasor_52(((int)1), samples_to_seconds);
			t_sample sah_14242 = __m_sah_53(div_14307, phasor_14253, ((t_sample)0.5));
			t_sample phasor_14252 = __m_phasor_54(((int)1), samples_to_seconds);
			t_sample sah_14241 = __m_sah_55(div_14307, phasor_14252, ((t_sample)0.5));
			t_sample phasor_14251 = __m_phasor_56(((int)1), samples_to_seconds);
			t_sample sah_14240 = __m_sah_57(div_14307, phasor_14251, ((t_sample)0.5));
			t_sample phasor_14250 = __m_phasor_58(((int)1), samples_to_seconds);
			t_sample sah_14239 = __m_sah_59(div_14307, phasor_14250, ((t_sample)0.5));
			t_sample phasor_14249 = __m_phasor_60(((int)1), samples_to_seconds);
			t_sample sah_14238 = __m_sah_61(div_14307, phasor_14249, ((t_sample)0.5));
			t_sample phasor_14248 = __m_phasor_62(((int)1), samples_to_seconds);
			t_sample sah_14237 = __m_sah_63(div_14307, phasor_14248, ((t_sample)0.5));
			t_sample phasor_14247 = __m_phasor_64(((int)1), samples_to_seconds);
			t_sample sah_14236 = __m_sah_65(div_14307, phasor_14247, ((t_sample)0.5));
			t_sample phasor_14246 = __m_phasor_66(((int)1), samples_to_seconds);
			t_sample sah_14235 = __m_sah_67(div_14307, phasor_14246, ((t_sample)0.5));
			t_sample phasor_14245 = __m_phasor_68(((int)1), samples_to_seconds);
			t_sample sah_14234 = __m_sah_69(div_14307, phasor_14245, ((t_sample)0.5));
			t_sample phasor_14244 = __m_phasor_70(((int)1), samples_to_seconds);
			t_sample sah_14233 = __m_sah_71(div_14307, phasor_14244, ((t_sample)0.5));
			t_sample expr_14303 = (((((((((sah_14242 + sah_14241) + sah_14240) + sah_14239) + sah_14238) + sah_14237) + sah_14236) + sah_14235) + sah_14234) + sah_14233);
			t_sample phasor_14230 = __m_phasor_72(((int)1), samples_to_seconds);
			t_sample sah_14219 = __m_sah_73(div_14307, phasor_14230, ((t_sample)0.5));
			t_sample phasor_14229 = __m_phasor_74(((int)1), samples_to_seconds);
			t_sample sah_14218 = __m_sah_75(div_14307, phasor_14229, ((t_sample)0.5));
			t_sample phasor_14228 = __m_phasor_76(((int)1), samples_to_seconds);
			t_sample sah_14217 = __m_sah_77(div_14307, phasor_14228, ((t_sample)0.5));
			t_sample phasor_14227 = __m_phasor_78(((int)1), samples_to_seconds);
			t_sample sah_14216 = __m_sah_79(div_14307, phasor_14227, ((t_sample)0.5));
			t_sample phasor_14226 = __m_phasor_80(((int)1), samples_to_seconds);
			t_sample sah_14215 = __m_sah_81(div_14307, phasor_14226, ((t_sample)0.5));
			t_sample phasor_14225 = __m_phasor_82(((int)1), samples_to_seconds);
			t_sample sah_14214 = __m_sah_83(div_14307, phasor_14225, ((t_sample)0.5));
			t_sample phasor_14224 = __m_phasor_84(((int)1), samples_to_seconds);
			t_sample sah_14213 = __m_sah_85(div_14307, phasor_14224, ((t_sample)0.5));
			t_sample phasor_14223 = __m_phasor_86(((int)1), samples_to_seconds);
			t_sample sah_14212 = __m_sah_87(div_14307, phasor_14223, ((t_sample)0.5));
			t_sample phasor_14222 = __m_phasor_88(((int)1), samples_to_seconds);
			t_sample sah_14211 = __m_sah_89(div_14307, phasor_14222, ((t_sample)0.5));
			t_sample phasor_14221 = __m_phasor_90(((int)1), samples_to_seconds);
			t_sample sah_14210 = __m_sah_91(div_14307, phasor_14221, ((t_sample)0.5));
			t_sample expr_14302 = (((((((((sah_14219 + sah_14218) + sah_14217) + sah_14216) + sah_14215) + sah_14214) + sah_14213) + sah_14212) + sah_14211) + sah_14210);
			t_sample add_14207 = (expr_14303 + expr_14302);
			t_sample add_14206 = (add_14254 + add_14207);
			t_sample div_14255 = (add_14206 * ((t_sample)0.025));
			t_sample out3 = div_14255;
			t_sample phasor_13974 = __m_phasor_92(((int)10), samples_to_seconds);
			t_sample sah_13971 = __m_sah_93(div_14255, phasor_13974, ((t_sample)0.5));
			t_sample phasor_13973 = __m_phasor_94(((int)10), samples_to_seconds);
			t_sample sah_13970 = __m_sah_95(div_14255, phasor_13973, ((t_sample)0.5));
			t_sample sub_13969 = (sah_13971 - sah_13970);
			t_sample abs_13968 = fabs(sub_13969);
			t_sample out4 = abs_13968;
			int expr_29101 = ((((t_sample)0.01) >= abs_13968) && (div_14255 >= ((t_sample)0.001)));
			int switch_13958 = (expr_29101 ? ((int)1) : ((int)0));
			__m_count_96 = (expr_29100 ? 0 : (fixdenorm(__m_count_96 + switch_13958)));
			int carry_97 = 0;
			if ((expr_29100 != 0)) {
				__m_count_96 = 0;
				__m_carry_98 = 0;
				
			} else if (((((int)48000) > 0) && (__m_count_96 >= ((int)48000)))) {
				int wraps_99 = (__m_count_96 / ((int)48000));
				__m_carry_98 = (__m_carry_98 + wraps_99);
				__m_count_96 = (__m_count_96 - (wraps_99 * ((int)48000)));
				carry_97 = 1;
				
			};
			int counter_13961 = __m_count_96;
			int counter_13962 = carry_97;
			int counter_13963 = __m_carry_98;
			int switch_13951 = (expr_29101 ? ((int)0) : ((int)5));
			__m_count_100 = (expr_29100 ? 0 : (fixdenorm(__m_count_100 + switch_13951)));
			int carry_101 = 0;
			if ((expr_29100 != 0)) {
				__m_count_100 = 0;
				__m_carry_102 = 0;
				
			} else if (((((int)48000) > 0) && (__m_count_100 >= ((int)48000)))) {
				int wraps_103 = (__m_count_100 / ((int)48000));
				__m_carry_102 = (__m_carry_102 + wraps_103);
				__m_count_100 = (__m_count_100 - (wraps_103 * ((int)48000)));
				carry_101 = 1;
				
			};
			int counter_13953 = __m_count_100;
			int counter_13954 = carry_101;
			int counter_13955 = __m_carry_102;
			int sub_13952 = (counter_13963 - counter_13955);
			t_sample out5 = sub_13952;
			t_sample out2 = ((int)0);
			t_sample noise_14135 = noise();
			t_sample mul_14134 = (scale_29789 * noise_14135);
			t_sample expr_29685 = (mul_14134 * (sub_13952 >= ((int)-50)));
			t_sample mul_14072 = (expr_29685 * ((t_sample)0.2));
			__m_cycle_104.freq(((t_sample)640.64));
			t_sample cycle_15287 = __m_cycle_104(__sinedata);
			t_sample cycleindex_15288 = __m_cycle_104.phase();
			t_sample mul_15284 = (cycle_15287 * ((t_sample)640.64));
			t_sample add_15286 = (((int)640) + mul_15284);
			__m_cycle_105.freq(add_15286);
			t_sample cycle_15289 = __m_cycle_105(__sinedata);
			t_sample cycleindex_15290 = __m_cycle_105.phase();
			t_sample expr_28953 = ((sub_13952 >= ((int)13)) * cycle_15289);
			__m_cycle_106.freq(((t_sample)40.04));
			t_sample cycle_28956 = __m_cycle_106(__sinedata);
			t_sample cycleindex_28960 = __m_cycle_106.phase();
			t_sample mul_28954 = (cycle_28956 * ((t_sample)40.04));
			t_sample add_28955 = (((int)40) + mul_28954);
			__m_cycle_107.freq(add_28955);
			t_sample cycle_28958 = __m_cycle_107(__sinedata);
			t_sample cycleindex_28957 = __m_cycle_107.phase();
			t_sample expr_28948 = ((sub_13952 >= ((int)1)) * cycle_28958);
			__m_cycle_108.freq(((t_sample)360.36));
			t_sample cycle_28967 = __m_cycle_108(__sinedata);
			t_sample cycleindex_28963 = __m_cycle_108.phase();
			t_sample mul_28962 = (cycle_28967 * ((t_sample)360.36));
			t_sample add_28965 = (((int)360) + mul_28962);
			__m_cycle_109.freq(add_28965);
			t_sample cycle_28969 = __m_cycle_109(__sinedata);
			t_sample cycleindex_28966 = __m_cycle_109.phase();
			t_sample expr_28952 = ((sub_13952 >= ((int)12)) * cycle_28969);
			__m_cycle_110.freq(((t_sample)80.08));
			t_sample cycle_28976 = __m_cycle_110(__sinedata);
			t_sample cycleindex_28971 = __m_cycle_110.phase();
			t_sample mul_28970 = (cycle_28976 * ((t_sample)80.08));
			t_sample add_28974 = (((int)80) + mul_28970);
			__m_cycle_111.freq(add_28974);
			t_sample cycle_28973 = __m_cycle_111(__sinedata);
			t_sample cycleindex_28975 = __m_cycle_111.phase();
			t_sample expr_28949 = ((sub_13952 >= ((int)1)) * cycle_28973);
			__m_cycle_112.freq(((t_sample)160.16));
			t_sample cycle_14840 = __m_cycle_112(__sinedata);
			t_sample cycleindex_14841 = __m_cycle_112.phase();
			t_sample mul_14837 = (cycle_14840 * ((t_sample)160.16));
			t_sample add_14839 = (((int)160) + mul_14837);
			__m_cycle_113.freq(add_14839);
			t_sample cycle_14842 = __m_cycle_113(__sinedata);
			t_sample cycleindex_14843 = __m_cycle_113.phase();
			t_sample expr_28950 = ((sub_13952 >= ((int)5)) * cycle_14842);
			__m_cycle_114.freq(((t_sample)240.24));
			t_sample cycle_28979 = __m_cycle_114(__sinedata);
			t_sample cycleindex_28982 = __m_cycle_114.phase();
			t_sample mul_28980 = (cycle_28979 * ((t_sample)240.24));
			t_sample add_28981 = (((int)240) + mul_28980);
			__m_cycle_115.freq(add_28981);
			t_sample cycle_28978 = __m_cycle_115(__sinedata);
			t_sample cycleindex_28983 = __m_cycle_115.phase();
			t_sample expr_28951 = ((sub_13952 >= ((int)8)) * cycle_28978);
			t_sample mul_24940 = (expr_28948 * scale_29793);
			t_sample mul_25060 = (expr_28949 * scale_29793);
			t_sample mul_25180 = (expr_28950 * scale_29793);
			t_sample mul_25300 = (expr_28951 * scale_29793);
			t_sample mul_25420 = (expr_28952 * scale_29793);
			t_sample mul_25540 = (expr_28953 * scale_29793);
			t_sample gen_28986 = (((((mul_25540 + mul_25420) + mul_25300) + mul_25180) + mul_25060) + mul_24940);
			t_sample expr_29687 = (gen_28986 * (sub_13952 >= ((int)1)));
			t_sample mul_22863 = (expr_29687 * ((int)1));
			t_sample mul_14028 = (abs_13968 * ((int)1000));
			__m_cycle_116.freq(((t_sample)4630.4));
			t_sample cycle_29692 = __m_cycle_116(__sinedata);
			t_sample cycleindex_29697 = __m_cycle_116.phase();
			t_sample mul_29698 = (((t_sample)4630.4) * mul_14028);
			t_sample mul_29695 = (cycle_29692 * mul_29698);
			t_sample add_29693 = (((int)640) + mul_29695);
			__m_cycle_117.freq(add_29693);
			t_sample cycle_29694 = __m_cycle_117(__sinedata);
			t_sample cycleindex_29696 = __m_cycle_117.phase();
			t_sample expr_29690 = (cycle_29694 * (sub_13952 >= ((int)22)));
			t_sample mul_29191 = (expr_29690 * ((t_sample)0.15));
			t_sample mul_14044 = (div_14255 * ((int)8));
			__m_cycle_118.freq(((int)240));
			t_sample cycle_14035 = __m_cycle_118(__sinedata);
			t_sample cycleindex_14036 = __m_cycle_118.phase();
			t_sample mul_14031 = (((int)240) * mul_14044);
			t_sample mul_14032 = (cycle_14035 * mul_14031);
			t_sample add_14034 = (((int)240) + mul_14032);
			__m_cycle_119.freq(add_14034);
			t_sample cycle_14037 = __m_cycle_119(__sinedata);
			t_sample cycleindex_14038 = __m_cycle_119.phase();
			t_sample expr_29688 = (cycle_14037 * (sub_13952 >= ((int)10)));
			t_sample mul_14068 = (expr_29688 * ((t_sample)0.5));
			t_sample mul_14043 = (div_14255 * ((int)10));
			__m_cycle_120.freq(((int)114));
			t_sample cycle_29699 = __m_cycle_120(__sinedata);
			t_sample cycleindex_29704 = __m_cycle_120.phase();
			t_sample mul_29703 = (((int)114) * mul_14043);
			t_sample mul_29702 = (cycle_29699 * mul_29703);
			t_sample add_29701 = (((int)80) + mul_29702);
			__m_cycle_121.freq(add_29701);
			t_sample cycle_29700 = __m_cycle_121(__sinedata);
			t_sample cycleindex_29706 = __m_cycle_121.phase();
			t_sample expr_29689 = (cycle_29700 * (sub_13952 >= ((int)16)));
			t_sample mul_14049 = (expr_29689 * ((t_sample)0.5));
			t_sample gen_29707 = ((((mul_29191 + mul_14072) + mul_14068) + mul_14049) + mul_22863);
			t_sample out1 = ((gen_29707 + gen_29707) + ((int)0));
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_Reset(t_param _value) {
		m_Reset_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_JoyY(t_param _value) {
		m_JoyY_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 1: *value = self->m_JoyY_2; break;
		case 2: *value = self->m_Reset_1; break;
		
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
	// initialize parameter 1 ("m_JoyY_2")
	pi = self->__commonstate.params + 1;
	pi->name = "JoyY";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_JoyY_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_Reset_1")
	pi = self->__commonstate.params + 2;
	pi->name = "Reset";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Reset_1;
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
