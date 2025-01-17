//
// File: HL20_Aerodynamics.h
//
// Code generated for Simulink model 'HL20_Aerodynamics'.
//
// Model version                  : 1.13
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Sun Dec 19 09:34:21 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. MISRA C:2012 guidelines
//    2. Safety precaution
//    3. Traceability
// Validation result: Not run
//
#ifndef RTW_HEADER_HL20_Aerodynamics_h_
#define RTW_HEADER_HL20_Aerodynamics_h_
#include <cmath>
#include "rtwtypes.h"
#include "HL20_Aerodynamics_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model HL20_Aerodynamics
class HL20_AerodynamicsModelClass {
  // public data and function members
 public:
  // Block states (default storage) for system '<S2>/Actuator_Increments'
  typedef struct {
    int_T AlphaLookup_MODE;            // '<S4>/AlphaLookup'
  } DW_Actuator_Increments_HL20_A_T;

  // Block states (default storage) for system '<S2>/Body_Rate_Damping'
  typedef struct {
    int_T AlphaLookup_MODE;            // '<S5>/AlphaLookup'
  } DW_Body_Rate_Damping_HL20_Aer_T;

  // Block states (default storage) for system '<S2>/Datum_Coefficients'
  typedef struct {
    int_T AlphaLookup_MODE;            // '<S6>/AlphaLookup'
    int_T BetaLookup_MODE;             // '<S6>/BetaLookup'
  } DW_Datum_Coefficients_HL20_Ae_T;

  // Block signals for system '<S1>/Aerodynamic_Coefficients'
  typedef struct {
    real_T alpha_deg;                  // '<S2>/r-->d2'
    real_T beta_deg;                   // '<S2>/r-->d1'
  } B_Aerodynamic_Coefficients_HL_T;

  // Block states (default storage) for system '<S1>/Aerodynamic_Coefficients'
  typedef struct {
    DW_Datum_Coefficients_HL20_Ae_T Datum_Coefficients;// '<S2>/Datum_Coefficients' 
    DW_Body_Rate_Damping_HL20_Aer_T Body_Rate_Damping;// '<S2>/Body_Rate_Damping' 
    DW_Actuator_Increments_HL20_A_T Actuator_Increments;// '<S2>/Actuator_Increments' 
  } DW_Aerodynamic_Coefficients_H_T;

  // Block signals (default storage)
  typedef struct {
    B_Aerodynamic_Coefficients_HL_T Aerodynamic_Coefficients;// '<S1>/Aerodynamic_Coefficients' 
  } B_HL20_Aerodynamics_T;

  // Block states (default storage) for system '<Root>'
  typedef struct {
    DW_Aerodynamic_Coefficients_H_T Aerodynamic_Coefficients;// '<S1>/Aerodynamic_Coefficients' 
  } DW_HL20_Aerodynamics_T;

  // Constant parameters (default storage)
  typedef struct {
    // Pooled Parameter (Expression: bpData)
    //  Referenced by:
    //    '<S4>/AlphaLookup'
    //    '<S6>/AlphaLookup'

    real_T pooled2[41];

    // Expression: table
    //  Referenced by: '<S7>/Cl'

    real_T Cl_tableData[41];

    // Expression: table
    //  Referenced by: '<S7>/Cm'

    real_T Cm_tableData[41];

    // Expression: table
    //  Referenced by: '<S7>/Cn'

    real_T Cn_tableData[41];

    // Expression: table
    //  Referenced by: '<S7>/Cx'

    real_T Cx_tableData[41];

    // Expression: table
    //  Referenced by: '<S7>/Cy'

    real_T Cy_tableData[41];

    // Expression: table
    //  Referenced by: '<S7>/Cz'

    real_T Cz_tableData[41];

    // Expression: table
    //  Referenced by: '<S8>/Cm'

    real_T Cm_tableData_j[41];

    // Expression: table
    //  Referenced by: '<S8>/Cx'

    real_T Cx_tableData_b[41];

    // Expression: table
    //  Referenced by: '<S8>/Cz'

    real_T Cz_tableData_o[41];

    // Expression: table
    //  Referenced by: '<S9>/Cl'

    real_T Cl_tableData_k[41];

    // Expression: table
    //  Referenced by: '<S9>/Cn'

    real_T Cn_tableData_a[41];

    // Expression: table
    //  Referenced by: '<S9>/Cx'

    real_T Cx_tableData_p[41];

    // Expression: table
    //  Referenced by: '<S9>/Cy'

    real_T Cy_tableData_g[41];

    // Expression: table
    //  Referenced by: '<S10>/Cm'

    real_T Cm_tableData_k[41];

    // Expression: table
    //  Referenced by: '<S10>/Cx'

    real_T Cx_tableData_n[41];

    // Expression: table
    //  Referenced by: '<S10>/Cz'

    real_T Cz_tableData_e[41];

    // Expression: table
    //  Referenced by: '<S11>/Cm'

    real_T Cm_tableData_jp[41];

    // Expression: table
    //  Referenced by: '<S11>/Cx'

    real_T Cx_tableData_f[41];

    // Expression: table
    //  Referenced by: '<S11>/Cz'

    real_T Cz_tableData_a[41];

    // Expression: table
    //  Referenced by: '<S12>/Cl'

    real_T Cl_tableData_f[41];

    // Expression: table
    //  Referenced by: '<S12>/Cm'

    real_T Cm_tableData_p[41];

    // Expression: table
    //  Referenced by: '<S12>/Cn'

    real_T Cn_tableData_h[41];

    // Expression: table
    //  Referenced by: '<S12>/Cx'

    real_T Cx_tableData_o[41];

    // Expression: table
    //  Referenced by: '<S12>/Cy'

    real_T Cy_tableData_h[41];

    // Expression: table
    //  Referenced by: '<S12>/Cz'

    real_T Cz_tableData_c[41];

    // Expression: bpData
    //  Referenced by: '<S5>/AlphaLookup'

    real_T AlphaLookup_bpData[11];

    // Expression: table
    //  Referenced by: '<S13>/Cl'

    real_T Cl_tableData_j[11];

    // Expression: table
    //  Referenced by: '<S13>/Cn'

    real_T Cn_tableData_i[11];

    // Expression: table
    //  Referenced by: '<S14>/Cmq'

    real_T Cmq_tableData[11];

    // Expression: table
    //  Referenced by: '<S15>/Clr'

    real_T Clr_tableData[11];

    // Expression: table
    //  Referenced by: '<S15>/Cnr'

    real_T Cnr_tableData[11];

    // Expression: bpData
    //  Referenced by: '<S6>/BetaLookup'

    real_T BetaLookup_bpData[21];

    // Expression: table
    //  Referenced by: '<S6>/Cm'

    real_T Cm_tableData_i[861];

    // Expression: table
    //  Referenced by: '<S6>/Cx'

    real_T Cx_tableData_a[861];

    // Expression: table
    //  Referenced by: '<S6>/Cz'

    real_T Cz_tableData_b[861];

    // Expression: Cn0
    //  Referenced by: '<S6>/ Cn'

    real_T Cn_tableData_l[36];

    // Expression: alpha_vec_Cn0
    //  Referenced by: '<S6>/ Cn'

    real_T Cn_bp01Data[9];

    // Expression: beta_vec_Cn0
    //  Referenced by: '<S6>/ Cn'

    real_T Cn_bp02Data[4];

    // Computed Parameter: Cn_maxIndex
    //  Referenced by: '<S6>/ Cn'

    uint32_T Cn_maxIndex[2];
  } ConstP_HL20_Aerodynamics_T;

  // External inputs (root inport signals with default storage)
  typedef struct {
    ActuatorBus Actuators;             // '<Root>/Actuators'
    real_T airspeed;                   // '<Root>/airspeed'
    real_T wb_bn_body[3];              // '<Root>/wb_bn_body'
    real_T Alpha;                      // '<Root>/Alpha'
    real_T Beta;                       // '<Root>/Beta'
    real_T qbar;                       // '<Root>/qbar'
  } ExtU_HL20_Aerodynamics_T;

  // External outputs (root outports fed by signals with default storage)
  typedef struct {
    real_T ftot_body[3];               // '<Root>/ftot_body'
    real_T mtot_body[3];               // '<Root>/mtot_body'
  } ExtY_HL20_Aerodynamics_T;

  // Real-time Model Data Structure
  struct RT_MODEL_HL20_Aerodynamics_T {
    const char_T * volatile errorStatus;
  };

  // External inputs
  ExtU_HL20_Aerodynamics_T HL20_Aerodynamics_U;

  // External outputs
  ExtY_HL20_Aerodynamics_T HL20_Aerodynamics_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  HL20_AerodynamicsModelClass();

  // Destructor
  ~HL20_AerodynamicsModelClass();

  // Real-Time Model get method
  HL20_AerodynamicsModelClass::RT_MODEL_HL20_Aerodynamics_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_HL20_Aerodynamics_T HL20_Aerodynamics_B;

  // Block states
  DW_HL20_Aerodynamics_T HL20_Aerodynamics_DW;

  // Real-Time Model
  RT_MODEL_HL20_Aerodynamics_T HL20_Aerodynamics_M;

  // private member function(s) for subsystem '<S2>/Actuator_Increments'
  static void HL20_Aerody_Actuator_Increments(real_T rtu_Alpha, real_T
    rtu_ActuatorDeflections, real_T rtu_ActuatorDeflections_e, real_T
    rtu_ActuatorDeflections_d, real_T rtu_ActuatorDeflections_k, real_T
    rtu_ActuatorDeflections_m, real_T rtu_ActuatorDeflections_c, real_T
    rty_Actuator_Increments[6], real_T *rty_AeroBus, real_T *rty_AeroBus_e,
    real_T *rty_AeroBus_d, real_T *rty_AeroBus_k, real_T *rty_AeroBus_m, real_T *
    rty_AeroBus_c, real_T *rty_AeroBus_d1, real_T *rty_AeroBus_dt, real_T
    *rty_AeroBus_e5, DW_Actuator_Increments_HL20_A_T *localDW);

  // private member function(s) for subsystem '<S2>/Body_Rate_Damping'
  static void HL20_Aerodyna_Body_Rate_Damping(real_T rtu_V, const real_T
    rtu_wb_bn_body[3], real_T rtu_Alpha, real_T rty_Body_Rate_Damping_Coefs[6],
    DW_Body_Rate_Damping_HL20_Aer_T *localDW);

  // private member function(s) for subsystem '<S2>/Datum_Coefficients'
  static void HL20_Aerodyn_Datum_Coefficients(real_T rtu_Alpha, real_T rtu_Beta,
    real_T *rty_DatumCoefs, real_T *rty_DatumCoefs_o, real_T *rty_DatumCoefs_f,
    real_T *rty_DatumCoefs_i, real_T *rty_DatumCoefs_iy, real_T
    *rty_DatumCoefs_c, DW_Datum_Coefficients_HL20_Ae_T *localDW);

  // private member function(s) for subsystem '<S1>/Aerodynamic_Coefficients'
  static void HL20_A_Aerodynamic_Coefficients(real_T rtu_Actuators, real_T
    rtu_Actuators_f, real_T rtu_Actuators_c, real_T rtu_Actuators_f2, real_T
    rtu_Actuators_k, real_T rtu_Actuators_l, real_T rtu_airspeed, const real_T
    rtu_wb_bn_body[3], real_T rtu_Alpha, real_T rtu_Beta, real_T rty_AeroCoefs[6],
    B_Aerodynamic_Coefficients_HL_T *localB, DW_Aerodynamic_Coefficients_H_T
    *localDW);

  // private member function(s) for subsystem '<S1>/Forces_Moments'
  static void HL20_Aerodynamic_Forces_Moments(const real_T rtu_Coeff[6], real_T
    rtu_qbar, real_T rty_ftot_body[3], real_T rty_mtot_body[3]);
};

// Constant parameters (default storage)
extern const HL20_AerodynamicsModelClass::ConstP_HL20_Aerodynamics_T
  HL20_Aerodynamics_ConstP;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'HL20_Aerodynamics'
//  '<S1>'   : 'HL20_Aerodynamics/HL20_Aerodynamics'
//  '<S2>'   : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients'
//  '<S3>'   : 'HL20_Aerodynamics/HL20_Aerodynamics/Forces_Moments'
//  '<S4>'   : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Actuator_Increments'
//  '<S5>'   : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Body_Rate_Damping'
//  '<S6>'   : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Datum_Coefficients'
//  '<S7>'   : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Actuator_Increments/Aileron'
//  '<S8>'   : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Actuator_Increments/Elevator'
//  '<S9>'   : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Actuator_Increments/Flap(diff)'
//  '<S10>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Actuator_Increments/Flap(neg)'
//  '<S11>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Actuator_Increments/Flap(pos)'
//  '<S12>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Actuator_Increments/Rudder'
//  '<S13>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Body_Rate_Damping/p'
//  '<S14>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Body_Rate_Damping/q'
//  '<S15>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Aerodynamic_Coefficients/Body_Rate_Damping/r'
//  '<S16>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Forces_Moments/3x3 Cross Product'
//  '<S17>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Forces_Moments/3x3 Cross Product/Subsystem'
//  '<S18>'  : 'HL20_Aerodynamics/HL20_Aerodynamics/Forces_Moments/3x3 Cross Product/Subsystem1'


//-
//  Requirements for '<Root>': HL20_Aerodynamics

#endif                                 // RTW_HEADER_HL20_Aerodynamics_h_

//
// File trailer for generated code.
//
// [EOF]
//
