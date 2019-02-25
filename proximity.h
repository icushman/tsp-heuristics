#ifndef proximity_FUNC_H_
#define proximity_FUNC_H_

#include <function/ArrayFunction.h>

namespace jags {
namespace TSPHeuristics {

    class proximity : public ArrayFunction
    {
    public:
        proximity();

        void evaluate(double *value, 
		 std::vector<double const *> const &args,
		 std::vector<std::vector<unsigned int> > const &dims) const;

        unsigned int length(std::vector<unsigned int> const &parlengths,
                            std::vector<double const *> const &parvalues) const;

        // bool isDiscreteValued(std::vector<bool> const &mask) const;

         bool checkParameterDim(std::vector<std::vector<unsigned int> > const &dims) 
	        const;

         std::vector<unsigned int>  dim(std::vector <std::vector<unsigned int> > const &dims,
	    std::vector <double const *> const &values) const;
    };

}}

#endif /* proximity_FUNC_H_ */
