#include <config.h>
#include "proximity.h" // class header file
#include <util/nainf.h> // provides na and inf functions

#include <cmath> // basic math operations
#include <iostream>
#include <typeinfo>

#include <algorithm>

#include <util/dim.h>
#include <util/logical.h>

using std::vector; // vector is used in the code
using std::string; // string is used in the code

#define step (*args[0]) // time step in problem
#define npoints (*args[1]) // number of points in problem
#define coords (args[2]) // ordered points array as (x, y) tuples
 
namespace jags {
namespace TSPHeuristics {

    proximity::proximity() :ArrayFunction ("proximity", 3)
    {}

    void proximity::evaluate(double *value, 
		 std::vector<double const *> const &args,
		 std::vector<std::vector<unsigned int> > const &dims) const
    {
        int step_num = int (step) - 1;

        double coordPair [2];

        float currentX = coords[step_num*2];
        float currentY = coords[step_num*2+1];

        float targetX;
        float targetY;

        for (unsigned int i = 0; i <= step_num; i++) {
            value[i] = 0;
           // value[i] = coords[i];
            
        }

        for (unsigned int i = step_num + 1; i < npoints; i++) {
            targetX = coords[i*2];
            targetY = coords[i*2+1];


            value[i] = 1.4143-sqrt(pow((currentY - targetY),2) + pow((currentX - targetX),2));
            // value[i] = targetY;//targetX;//i;//step_num;//currentY;

        }
    }

    unsigned int proximity::length (vector<unsigned int> const &parlengths,
                               vector<double const *> const &parvalues) const
    {
        return (parvalues[1][0]);
    }




   bool proximity::checkParameterDim(std::vector<std::vector<unsigned int> > const &dims) 
	        const {
                return true;
            }

    std::vector<unsigned int>  proximity::dim(std::vector <std::vector<unsigned int> > const &dims,
	    std::vector <double const *> const &values) const {
            std::vector<unsigned int> v(1);
            v[0] = dims[2][0]/2;
            //v[1] = 3;
            return v;
    }

}}


//Because theJAGSprogramming  structure  inC++does  not  handle  matrices,  the  covariance  matrixshould be returned in a (1×n2)-dimensional vector
//http://www.est.ufmg.br/~posgrad/mestrado/dissertacao_Magno_Severino.pdf