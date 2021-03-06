/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * runge_kutta_4.c
 *
 * Code generation for function 'runge_kutta_4'
 *
 */

/* Include files */
#include "runge_kutta_4.h"
#include "nonlinear_differential_model.h"
#include "rt_nonfinite.h"
#include "runge_kutta_4_data.h"
#include "runge_kutta_4_types.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 17,    /* lineNo */
  "runge_kutta_4",                     /* fcnName */
  "/home/jonas/matlab/21-03-03 Online Robot Ident Git/ident_functions/runge_kutta_4.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 35,  /* lineNo */
  "runge_kutta_4",                     /* fcnName */
  "/home/jonas/matlab/21-03-03 Online Robot Ident Git/ident_functions/runge_kutta_4.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 37,  /* lineNo */
  "runge_kutta_4",                     /* fcnName */
  "/home/jonas/matlab/21-03-03 Online Robot Ident Git/ident_functions/runge_kutta_4.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 39,  /* lineNo */
  "runge_kutta_4",                     /* fcnName */
  "/home/jonas/matlab/21-03-03 Online Robot Ident Git/ident_functions/runge_kutta_4.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 41,  /* lineNo */
  "runge_kutta_4",                     /* fcnName */
  "/home/jonas/matlab/21-03-03 Online Robot Ident Git/ident_functions/runge_kutta_4.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 47,  /* lineNo */
  "runge_kutta_4",                     /* fcnName */
  "/home/jonas/matlab/21-03-03 Online Robot Ident Git/ident_functions/runge_kutta_4.m"/* pathName */
};

/* Function Definitions */
void runge_kutta_4(runge_kutta_4StackData *SD, const emlrtStack *sp, const
                   real_T time_cont[8001], const real_T x0[12], const real_T
                   optVec[31], const struct0_T *b_static, struct1_T *dyn, real_T
                   xSim[96012], real_T uSim[48006])
{
  emlrtStack st;
  struct1_T unusedU0;
  real_T z[48];
  real_T dx0[12];
  real_T tau0[6];
  real_T a;
  real_T a_tmp;
  real_T dt;
  int32_T i;
  int32_T k1;
  st.prev = sp;
  st.tls = sp->tls;

  /*  Jonas Weigand */
  /*  07.12.2017 */
  /*  jonas.weigand@mv.uni-kl.de */
  /*  initialise */
  /*  get the number of timesteps */
  /*  get the length of a timestep */
  dt = time_cont[1] - time_cont[0];

  /*  define an aribitry vector for extra outputs */
  unusedU0 = *dyn;
  st.site = &emlrtRSI;
  nonlinear_differential_model(&st, x0, optVec, b_static, &unusedU0, dx0, tau0);
  memset(&SD->f0.xSim[0], 0, 96012U * sizeof(real_T));
  memset(&SD->f0.uSim[0], 0, 48006U * sizeof(real_T));

  /*  by definition, first entry of xAll is x0 */
  memcpy(&SD->f0.xSim[0], &x0[0], 12U * sizeof(real_T));

  /*  initialise temporary matrix z */
  memset(&z[0], 0, 48U * sizeof(real_T));

  /*  Core loop */
  /*  for all timesteps but the last one */
  a_tmp = dt / 2.0;
  a = dt / 6.0;
  for (k1 = 0; k1 < 8000; k1++) {
    st.site = &b_emlrtRSI;
    b_nonlinear_differential_model(&st, (real_T)k1 + 1.0, *(real_T (*)[12])&
      SD->f0.xSim[12 * k1], optVec, b_static, dyn, *(real_T (*)[12])&z[0],
      *(real_T (*)[6])&SD->f0.uSim[6 * k1]);
    for (i = 0; i < 12; i++) {
      dx0[i] = SD->f0.xSim[i + 12 * k1] + a_tmp * z[i];
    }

    st.site = &c_emlrtRSI;
    b_nonlinear_differential_model(&st, (real_T)k1 + 1.0, dx0, optVec, b_static,
      dyn, *(real_T (*)[12])&z[12], tau0);
    for (i = 0; i < 12; i++) {
      dx0[i] = SD->f0.xSim[i + 12 * k1] + a_tmp * z[i + 12];
    }

    st.site = &d_emlrtRSI;
    b_nonlinear_differential_model(&st, (real_T)k1 + 1.0, dx0, optVec, b_static,
      dyn, *(real_T (*)[12])&z[24], tau0);
    for (i = 0; i < 12; i++) {
      dx0[i] = SD->f0.xSim[i + 12 * k1] + dt * z[i + 24];
    }

    st.site = &e_emlrtRSI;
    b_nonlinear_differential_model(&st, (real_T)k1 + 1.0, dx0, optVec, b_static,
      dyn, *(real_T (*)[12])&z[36], tau0);
    for (i = 0; i < 12; i++) {
      SD->f0.xSim[i + 12 * (k1 + 1)] = SD->f0.xSim[i + 12 * k1] + a * (((z[i] +
        2.0 * z[i + 12]) + 2.0 * z[i + 24]) + z[i + 36]);
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  unusedU0 = *dyn;
  st.site = &f_emlrtRSI;
  c_nonlinear_differential_model(&st, *(real_T (*)[12])&SD->f0.xSim[96000],
    optVec, b_static, &unusedU0, dx0, *(real_T (*)[6])&SD->f0.uSim[48000]);
  for (i = 0; i < 12; i++) {
    for (k1 = 0; k1 < 8001; k1++) {
      xSim[k1 + 8001 * i] = SD->f0.xSim[i + 12 * k1];
    }
  }

  for (i = 0; i < 6; i++) {
    for (k1 = 0; k1 < 8001; k1++) {
      uSim[k1 + 8001 * i] = SD->f0.uSim[i + 6 * k1];
    }
  }
}

/* End of code generation (runge_kutta_4.c) */
