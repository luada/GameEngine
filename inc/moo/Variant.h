#ifndef ___Variant_H__
#define ___Variant_H__

#include <boost/any.hpp>

namespace MM
{

    typedef boost::any Variant;

    template<typename ValueType>
    ValueType * VariantCast(Variant * operand)
    {
        return boost::any_cast<ValueType>(operand);
    }

    template<typename ValueType>
    const ValueType * VariantCast(const Variant * operand)
    {
        return boost::any_cast<ValueType>(operand);
    }

    template<typename ValueType>
    ValueType VariantCast(const Variant & operand)
    {
        return boost::any_cast<ValueType>(operand);
    }

}

#endif 
