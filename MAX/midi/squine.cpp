#include "squine.h"

namespace squine {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
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
	Delta __m_delta_16;
	Phasor __m_phasor_15;
	int __exception;
	int vectorsize;
	t_sample m_cv4_vca_11;
	t_sample m_history_1;
	t_sample m_cv3_skew_10;
	t_sample m_history_12;
	t_sample m_history_14;
	t_sample m_history_13;
	t_sample samples_to_seconds;
	t_sample samplerate;
	t_sample m_cv2_square_9;
	t_sample m_history_6;
	t_sample m_history_2;
	t_sample m_cv1_pitch_8;
	t_sample m_history_3;
	t_sample m_history_5;
	t_sample m_history_4;
	t_sample m_history_7;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_cv1_pitch_8 = ((int)0);
		m_cv2_square_9 = ((int)0);
		m_cv3_skew_10 = ((int)0);
		m_cv4_vca_11 = ((t_sample)0.5);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_15.reset(0);
		__m_delta_16.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample add_59 = (m_cv1_pitch_8 + ((int)0));
		t_sample add_55 = (add_59 + ((t_sample)0.25));
		t_sample fastpow_57 = fasterpow(((int)2), add_55);
		t_sample mul_58 = (fastpow_57 * ((t_sample)27.5));
		t_sample gen_147 = mul_58;
		samples_to_seconds = (1 / samplerate);
		int min_17 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mix_479 = (m_history_14 + (((t_sample)0.0042742627044161) * (m_cv4_vca_11 - m_history_14)));
			t_sample mix_39 = mix_479;
			t_sample mix_480 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_39 - m_history_13)));
			t_sample mix_37 = mix_480;
			t_sample mix_481 = (m_history_12 + (((t_sample)0.0042742627044161) * (mix_37 - m_history_12)));
			t_sample mix_35 = mix_481;
			t_sample gen_144 = mix_35;
			t_sample history_40_next_42 = fixdenorm(mix_39);
			t_sample history_38_next_43 = fixdenorm(mix_37);
			t_sample history_36_next_44 = fixdenorm(mix_35);
			t_sample mix_482 = (m_history_7 + (((t_sample)0.0042742627044161) * (m_cv2_square_9 - m_history_7)));
			t_sample mix_191 = mix_482;
			t_sample mix_483 = (m_history_6 + (((t_sample)0.0042742627044161) * (mix_191 - m_history_6)));
			t_sample mix_190 = mix_483;
			t_sample mix_484 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_190 - m_history_5)));
			t_sample mix_192 = mix_484;
			t_sample gen_145 = mix_192;
			t_sample history_40_next_195 = fixdenorm(mix_191);
			t_sample history_38_next_194 = fixdenorm(mix_190);
			t_sample history_36_next_193 = fixdenorm(mix_192);
			t_sample mix_485 = (m_history_4 + (((t_sample)0.0042742627044161) * (m_cv3_skew_10 - m_history_4)));
			t_sample mix_205 = mix_485;
			t_sample mix_486 = (m_history_3 + (((t_sample)0.0042742627044161) * (mix_205 - m_history_3)));
			t_sample mix_204 = mix_486;
			t_sample mix_487 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_204 - m_history_2)));
			t_sample mix_210 = mix_487;
			t_sample gen_146 = mix_210;
			t_sample history_40_next_206 = fixdenorm(mix_205);
			t_sample history_38_next_208 = fixdenorm(mix_204);
			t_sample history_36_next_209 = fixdenorm(mix_210);
			t_sample phasor_148 = __m_phasor_15(gen_147, samples_to_seconds);
			t_sample mul_149 = (phasor_148 * ((t_sample)6.2831853071796));
			t_sample sin_150 = sin(mul_149);
			t_sample delta_174 = __m_delta_16(phasor_148);
			t_sample wrap_173 = wrap(delta_174, (-0.5), ((t_sample)0.5));
			t_sample mul_172 = (wrap_173 * samplerate);
			t_sample abs_171 = fabs(mul_172);
			int gt_170 = (abs_171 > m_history_1);
			t_sample mix_488 = (abs_171 + (((t_sample)0.999) * (m_history_1 - abs_171)));
			t_sample mix_167 = mix_488;
			t_sample switch_168 = (gt_170 ? abs_171 : mix_167);
			t_sample clamp_180 = ((gen_146 <= min_17) ? min_17 : ((gen_146 >= ((int)1)) ? ((int)1) : gen_146));
			t_sample mul_179 = (clamp_180 * ((t_sample)0.5));
			t_sample rsub_178 = (((t_sample)0.5) - mul_179);
			t_sample mul_166 = (switch_168 * safediv(20, samplerate));
			t_sample mul_165 = (mul_166 * ((t_sample)0.5));
			t_sample clamp_164 = ((mul_165 <= ((int)0)) ? ((int)0) : ((mul_165 >= ((t_sample)0.5)) ? ((t_sample)0.5) : mul_165));
			t_sample rsub_163 = (((int)1) - clamp_164);
			t_sample rsub_175 = (((int)1) - rsub_178);
			t_sample clamp_183 = ((gen_145 <= ((int)0)) ? ((int)0) : ((gen_145 >= ((int)1)) ? ((int)1) : gen_145));
			t_sample rsub_182 = (((t_sample)1.00001) - clamp_183);
			t_sample rdiv_181 = safediv(((int)1), rsub_182);
			t_sample div_177 = safediv(rsub_178, rdiv_181);
			t_sample clamp_162 = ((div_177 <= clamp_164) ? clamp_164 : ((div_177 >= rsub_163) ? rsub_163 : div_177));
			t_sample div_158 = safediv(phasor_148, clamp_162);
			t_sample clamp_155 = ((div_158 <= ((int)0)) ? ((int)0) : ((div_158 >= ((int)1)) ? ((int)1) : div_158));
			t_sample div_176 = safediv(rsub_175, rdiv_181);
			t_sample clamp_161 = ((div_176 <= clamp_164) ? clamp_164 : ((div_176 >= rsub_163) ? rsub_163 : div_176));
			t_sample rsub_159 = (((int)1) - clamp_161);
			t_sample clamp_160 = ((rsub_178 <= clamp_162) ? clamp_162 : ((rsub_178 >= rsub_159) ? rsub_159 : rsub_178));
			int lte_152 = (phasor_148 <= clamp_160);
			t_sample sub_156 = (phasor_148 - clamp_160);
			t_sample div_157 = safediv(sub_156, clamp_161);
			t_sample clamp_154 = ((div_157 <= ((int)0)) ? ((int)0) : ((div_157 >= ((int)1)) ? ((int)1) : div_157));
			t_sample rsub_153 = (((int)1) - clamp_154);
			t_sample switch_151 = (lte_152 ? clamp_155 : rsub_153);
			t_sample mul_184 = (switch_151 * ((t_sample)3.1415926535898));
			t_sample cos_185 = cos(mul_184);
			t_sample history_169_next_186 = fixdenorm(switch_168);
			t_sample mul_143 = (cos_185 * gen_144);
			t_sample out1 = mul_143;
			t_sample mul_142 = (sin_150 * gen_144);
			t_sample out2 = mul_142;
			m_history_14 = history_40_next_42;
			m_history_12 = history_36_next_44;
			m_history_13 = history_38_next_43;
			m_history_7 = history_40_next_195;
			m_history_5 = history_36_next_193;
			m_history_6 = history_38_next_194;
			m_history_4 = history_40_next_206;
			m_history_2 = history_36_next_209;
			m_history_3 = history_38_next_208;
			m_history_1 = history_169_next_186;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_cv1_pitch(t_param _value) {
		m_cv1_pitch_8 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
	inline void set_cv2_square(t_param _value) {
		m_cv2_square_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cv3_skew(t_param _value) {
		m_cv3_skew_10 = (_value < -1 ? -1 : (_value > 1 ? 1 : _value));
	};
	inline void set_cv4_vca(t_param _value) {
		m_cv4_vca_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 4; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

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
		case 0: self->set_cv1_pitch(value); break;
		case 1: self->set_cv2_square(value); break;
		case 2: self->set_cv3_skew(value); break;
		case 3: self->set_cv4_vca(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_cv1_pitch_8; break;
		case 1: *value = self->m_cv2_square_9; break;
		case 2: *value = self->m_cv3_skew_10; break;
		case 3: *value = self->m_cv4_vca_11; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(4 * sizeof(ParamInfo));
	self->__commonstate.numparams = 4;
	// initialize parameter 0 ("m_cv1_pitch_8")
	pi = self->__commonstate.params + 0;
	pi->name = "cv1_pitch";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv1_pitch_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cv2_square_9")
	pi = self->__commonstate.params + 1;
	pi->name = "cv2_square";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv2_square_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_cv3_skew_10")
	pi = self->__commonstate.params + 2;
	pi->name = "cv3_skew";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv3_skew_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -1;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_cv4_vca_11")
	pi = self->__commonstate.params + 3;
	pi->name = "cv4_vca";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv4_vca_11;
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


} // squine::
