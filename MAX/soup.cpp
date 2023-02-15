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
	Phasor __m_phasor_7;
	Phasor __m_phasor_11;
	Phasor __m_phasor_9;
	Phasor __m_phasor_3;
	Phasor __m_phasor_5;
	Phasor __m_phasor_13;
	Sah __m_sah_6;
	Sah __m_sah_4;
	Sah __m_sah_10;
	Sah __m_sah_14;
	Sah __m_sah_12;
	Sah __m_sah_8;
	SineCycle __m_cycle_20;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample samplerate;
	t_sample __m_carry_17;
	t_sample m_JoyX_1;
	t_sample __m_count_15;
	t_sample m_JoyY_2;
	t_sample samples_to_seconds;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_JoyX_1 = ((int)0);
		m_JoyY_2 = ((int)0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_3.reset(0);
		__m_sah_4.reset(0);
		__m_phasor_5.reset(0.5);
		__m_sah_6.reset(0);
		__m_phasor_7.reset(0);
		__m_sah_8.reset(0);
		__m_phasor_9.reset(0.5);
		__m_sah_10.reset(0);
		__m_phasor_11.reset(0);
		__m_sah_12.reset(0);
		__m_phasor_13.reset(0.5);
		__m_sah_14.reset(0);
		__m_count_15 = 0;
		__m_carry_17 = 0;
		__m_cycle_20.reset(samplerate, 0);
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
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample xValue_75 = (m_JoyX_1 + in1);
			t_sample yValue_74 = (m_JoyY_2 + in2);
			t_sample phasor_100 = __m_phasor_3(((int)2), samples_to_seconds);
			t_sample sah_109 = __m_sah_4(xValue_75, phasor_100, ((t_sample)0.5));
			t_sample phasor_99 = __m_phasor_5(((int)2), samples_to_seconds);
			t_sample sah_108 = __m_sah_6(xValue_75, phasor_99, ((t_sample)0.5));
			t_sample sub_107 = (sah_109 - sah_108);
			t_sample pow_106 = safepow(sub_107, ((int)2));
			t_sample phasor_103 = __m_phasor_7(((int)2), samples_to_seconds);
			t_sample sah_113 = __m_sah_8(yValue_74, phasor_103, ((t_sample)0.5));
			t_sample phasor_101 = __m_phasor_9(((int)2), samples_to_seconds);
			t_sample sah_112 = __m_sah_10(yValue_74, phasor_101, ((t_sample)0.5));
			t_sample sub_111 = (sah_113 - sah_112);
			t_sample pow_110 = safepow(sub_111, ((int)2));
			t_sample add_105 = (pow_106 + pow_110);
			t_sample sqrt_104 = sqrt(add_105);
			t_sample out3 = sqrt_104;
			t_sample phasor_95 = __m_phasor_11(((int)1), samples_to_seconds);
			t_sample sah_92 = __m_sah_12(sqrt_104, phasor_95, ((t_sample)0.5));
			t_sample phasor_94 = __m_phasor_13(((int)1), samples_to_seconds);
			t_sample sah_91 = __m_sah_14(sqrt_104, phasor_94, ((t_sample)0.5));
			t_sample sub_90 = (sah_92 - sah_91);
			t_sample abs_89 = fabs(sub_90);
			t_sample out4 = abs_89;
			int gte_115 = (abs_89 >= ((t_sample)0.05));
			int switch_87 = (gte_115 ? ((int)1) : ((int)0));
			int eq_117 = (abs_89 == ((t_sample)0.001));
			int switch_80 = (eq_117 ? ((int)1) : ((int)0));
			__m_count_15 = ((switch_80 + switch_87) ? 0 : (fixdenorm(__m_count_15 + ((int)1))));
			int carry_16 = 0;
			int count_reset_18 = (switch_80 + switch_87);
			if ((count_reset_18 != 0)) {
				__m_count_15 = 0;
				__m_carry_17 = 0;
				
			} else if (((((int)44000) > 0) && (__m_count_15 >= ((int)44000)))) {
				int wraps_19 = (__m_count_15 / ((int)44000));
				__m_carry_17 = (__m_carry_17 + wraps_19);
				__m_count_15 = (__m_count_15 - (wraps_19 * ((int)44000)));
				carry_16 = 1;
				
			};
			int counter_81 = __m_count_15;
			int counter_82 = carry_16;
			int counter_83 = __m_carry_17;
			t_sample out5 = counter_83;
			int mul_67 = (counter_83 * ((int)200));
			__m_cycle_20.freq(mul_67);
			t_sample cycle_65 = __m_cycle_20(__sinedata);
			t_sample cycleindex_66 = __m_cycle_20.phase();
			t_sample out1 = cycle_65;
			t_sample out2 = cycle_65;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_JoyX(t_param _value) {
		m_JoyX_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_JoyY(t_param _value) {
		m_JoyY_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
int num_params() { return 2; }

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
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_JoyX_1; break;
		case 1: *value = self->m_JoyY_2; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(2 * sizeof(ParamInfo));
	self->__commonstate.numparams = 2;
	// initialize parameter 0 ("m_JoyX_1")
	pi = self->__commonstate.params + 0;
	pi->name = "JoyX";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_JoyX_1;
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // soup::
