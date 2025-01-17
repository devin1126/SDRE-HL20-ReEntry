#include "mex.hpp"
#include "mexAdapter.hpp"

#include "HL20_Aerodynamics.h"

using namespace matlab::data;
using namespace std;

class MexFunction : public matlab::mex::Function
{
public:
    
    //####################################################################//
    // Constructor
    MexFunction()
    {
        init_complete = false;        
    }
    
    //####################################################################//
    // Destructor
    ~MexFunction()
    {
    }
    
    //####################################################################//
    void operator()(matlab::mex::ArgumentList outputs, matlab::mex::ArgumentList inputs)
    {

        if(!init_complete)
        {
            HL20_Aero.initialize();
            init_complete = true;
        }
        
        // Checking Validity of Arguments
        checkArguments(outputs, inputs);
        
        // Reading in Inputs
        double qbar = inputs[0][0];
        double airspeed = inputs[1][0];
        double alpha_deg = inputs[2][0];
        double beta_deg = inputs[3][0];
        double pp = inputs[4][0];
        double qq = inputs[5][0];
        double rr = inputs[6][0];
        double da = inputs[7][0];
        double de = inputs[8][0];
        double dr = inputs[9][0];
        double dfp = inputs[10][0];
        double dfn = inputs[11][0];
        double ddf = inputs[12][0];
        double x_cg = inputs[13][0];
        
        // Actuator Inputs
        HL20_Aero.HL20_Aerodynamics_U.Actuators.Aileron = da;
        HL20_Aero.HL20_Aerodynamics_U.Actuators.Elevator = de;
        HL20_Aero.HL20_Aerodynamics_U.Actuators.Rudder = dr;
        HL20_Aero.HL20_Aerodynamics_U.Actuators.Flap_Pos = dfp;
        HL20_Aero.HL20_Aerodynamics_U.Actuators.Flap_Neg = dfn;
        HL20_Aero.HL20_Aerodynamics_U.Actuators.Flap_Dif = ddf;
        
        // Flight Condition Input
        HL20_Aero.HL20_Aerodynamics_U.airspeed = airspeed;
        HL20_Aero.HL20_Aerodynamics_U.wb_bn_body[0] = pp;
        HL20_Aero.HL20_Aerodynamics_U.wb_bn_body[1] = qq;
        HL20_Aero.HL20_Aerodynamics_U.wb_bn_body[2] = rr;
        HL20_Aero.HL20_Aerodynamics_U.Alpha = alpha_deg*1.0/57.3;
        HL20_Aero.HL20_Aerodynamics_U.Beta = beta_deg*1.0/57.3;
        HL20_Aero.HL20_Aerodynamics_U.qbar = qbar;
        
        // Step Function
        HL20_Aero.step();
        
        // Assigning Outputs
        outputs[0] = factory.createScalar(HL20_Aero.HL20_Aerodynamics_Y.ftot_body[0]);
        outputs[1] = factory.createScalar(HL20_Aero.HL20_Aerodynamics_Y.ftot_body[1]);
        outputs[2] = factory.createScalar(HL20_Aero.HL20_Aerodynamics_Y.ftot_body[2]);
        outputs[3] = factory.createScalar(HL20_Aero.HL20_Aerodynamics_Y.mtot_body[0]);
        outputs[4] = factory.createScalar(HL20_Aero.HL20_Aerodynamics_Y.mtot_body[1]);
        outputs[5] = factory.createScalar(HL20_Aero.HL20_Aerodynamics_Y.mtot_body[2]);
    }    
    
    //####################################################################//
    void checkArguments(matlab::mex::ArgumentList outputs, matlab::mex::ArgumentList inputs)
    {
        
        // Getting Matlab Engine and Factory
        matlabPtr = getEngine();
        
        //[Fx,Fy,Fz, Mx,My,Mz] = Aerodynamics6(Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg)
        
        
        // Checking Outputs
        if (outputs.size() != 6)
        {
            matlabPtr->feval(u"error",
                    0, std::vector<Array>({ factory.createScalar("Six Outputs required: Fx,Fy,Fz, Mx,My,Mz") }));
        }
        
        // Checking Inputs
        if (inputs.size() != 14)
        {
            matlabPtr->feval(u"error",
                    0, std::vector<Array>({ factory.createScalar("Fourteen inputs required: Qbar, Airspeed, alpha_deg, beta_deg, pp,qq,rr, da,de,dr, dfp,dfn, ddf, x_cg") }));
        }
        
        // Checking Elements to ensure they are all double
        for(int i = 0; i < 14; i++)
        {
            if (inputs[i].getNumberOfElements() != 1) {
                matlabPtr->feval(u"error",
                        0, std::vector<Array>({ factory.createScalar("Input multiplier must be a scalar") }));
            }
            
            if (inputs[i].getType() != ArrayType::DOUBLE ||
                    inputs[i].getType() == ArrayType::COMPLEX_DOUBLE) {
                matlabPtr->feval(u"error",
                        0, std::vector<Array>({ factory.createScalar("Input multiplier must be a noncomplex scalar double") }));
            }
        }
    }
    
private:
    HL20_AerodynamicsModelClass HL20_Aero;
    bool init_complete;
    ArrayFactory factory;
    std::shared_ptr<matlab::engine::MATLABEngine> matlabPtr;
    
};