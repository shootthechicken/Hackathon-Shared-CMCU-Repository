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
	Phasor __m_phasor_8;
	Phasor __m_phasor_12;
	Phasor __m_phasor_4;
	Phasor __m_phasor_10;
	Phasor __m_phasor_6;
	Phasor __m_phasor_14;
	Sah __m_sah_5;
	Sah __m_sah_11;
	Sah __m_sah_13;
	Sah __m_sah_7;
	Sah __m_sah_15;
	Sah __m_sah_9;
	SineCycle __m_cycle_24;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_JoySwitch_1;
	t_sample __m_count_20;
	t_sample __m_carry_22;
	t_sample m_JoyY_2;
	t_sample __m_carry_18;
	t_sample m_JoyX_3;
	t_sample __m_count_16;
	t_sample samplerate;
	t_sample samples_to_seconds;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_JoySwitch_1 = ((int)0);
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
		__m_phasor_14.reset(0.5);
		__m_sah_15.reset(0);
		__m_count_16 = 0;
		__m_carry_18 = 0;
		__m_count_20 = 0;
		__m_carry_22 = 0;
		__m_cycle_24.reset(samplerate, 0);
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
		int expr_485 = (m_JoySwitch_1 > ((t_sample)0.5));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample phasor_437 = __m_phasor_4(((int)2), samples_to_seconds);
			t_sample sah_446 = __m_sah_5(m_JoyX_3, phasor_437, ((t_sample)0.5));
			t_sample phasor_436 = __m_phasor_6(((int)2), samples_to_seconds);
			t_sample sah_445 = __m_sah_7(m_JoyX_3, phasor_436, ((t_sample)0.5));
			t_sample sub_444 = (sah_446 - sah_445);
			t_sample pow_443 = safepow(sub_444, ((int)2));
			t_sample phasor_440 = __m_phasor_8(((int)2), samples_to_seconds);
			t_sample sah_450 = __m_sah_9(m_JoyY_2, phasor_440, ((t_sample)0.5));
			t_sample phasor_438 = __m_phasor_10(((int)2), samples_to_seconds);
			t_sample sah_449 = __m_sah_11(m_JoyY_2, phasor_438, ((t_sample)0.5));
			t_sample sub_448 = (sah_450 - sah_449);
			t_sample pow_447 = safepow(sub_448, ((int)2));
			t_sample add_442 = (pow_443 + pow_447);
			t_sample sqrt_441 = sqrt(add_442);
			t_sample out3 = sqrt_441;
			t_sample phasor_415 = __m_phasor_12(((int)1), samples_to_seconds);
			t_sample sah_412 = __m_sah_13(sqrt_441, phasor_415, ((t_sample)0.5));
			t_sample phasor_414 = __m_phasor_14(((int)1), samples_to_seconds);
			t_sample sah_411 = __m_sah_15(sqrt_441, phasor_414, ((t_sample)0.5));
			t_sample sub_410 = (sah_412 - sah_411);
			t_sample abs_409 = fabs(sub_410);
			t_sample out4 = abs_409;
			int expr_484 = ((((t_sample)0.05) >= abs_409) && (abs_409 >= ((t_sample)0.0001)));
			int switch_398 = (expr_484 ? ((int)1) : ((int)0));
			__m_count_16 = (expr_485 ? 0 : (fixdenorm(__m_count_16 + switch_398)));
			int carry_17 = 0;
			if ((expr_485 != 0)) {
				__m_count_16 = 0;
				__m_carry_18 = 0;
				
			} else if (((((int)44000) > 0) && (__m_count_16 >= ((int)44000)))) {
				int wraps_19 = (__m_count_16 / ((int)44000));
				__m_carry_18 = (__m_carry_18 + wraps_19);
				__m_count_16 = (__m_count_16 - (wraps_19 * ((int)44000)));
				carry_17 = 1;
				
			};
			int counter_401 = __m_count_16;
			int counter_402 = carry_17;
			int counter_403 = __m_carry_18;
			int switch_391 = (expr_484 ? ((int)0) : ((int)5));
			__m_count_20 = (expr_485 ? 0 : (fixdenorm(__m_count_20 + switch_391)));
			int carry_21 = 0;
			if ((expr_485 != 0)) {
				__m_count_20 = 0;
				__m_carry_22 = 0;
				
			} else if (((((int)44000) > 0) && (__m_count_20 >= ((int)44000)))) {
				int wraps_23 = (__m_count_20 / ((int)44000));
				__m_carry_22 = (__m_carry_22 + wraps_23);
				__m_count_20 = (__m_count_20 - (wraps_23 * ((int)44000)));
				carry_21 = 1;
				
			};
			int counter_393 = __m_count_20;
			int counter_394 = carry_21;
			int counter_395 = __m_carry_22;
			int sub_392 = (counter_403 - counter_395);
			int expr_483 = ((sub_392 > ((int)0)) * sub_392);
			t_sample out5 = expr_483;
			t_sample mul_428 = (sqrt_441 * ((int)2000));
			__m_cycle_24.freq(mul_428);
			t_sample cycle_426 = __m_cycle_24(__sinedata);
			t_sample cycleindex_427 = __m_cycle_24.phase();
			t_sample add_418 = (sqrt_441 + abs_409);
			t_sample out1 = (add_418 + cycle_426);
			t_sample out2 = (((int)0) + cycle_426);
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			
		};
		return __exception;
		
	};
	inline void set_JoySwitch(t_param _value) {
		m_JoySwitch_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: self->set_JoySwitch(value); break;
		case 1: self->set_JoyX(value); break;
		case 2: self->set_JoyY(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_JoySwitch_1; break;
		case 1: *value = self->m_JoyX_3; break;
		case 2: *value = self->m_JoyY_2; break;
		
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
	// initialize parameter 0 ("m_JoySwitch_1")
	pi = self->__commonstate.params + 0;
	pi->name = "JoySwitch";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_JoySwitch_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_JoyX_3")
	pi = self->__commonstate.params + 1;
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
	// initialize parameter 2 ("m_JoyY_2")
	pi = self->__commonstate.params + 2;
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
