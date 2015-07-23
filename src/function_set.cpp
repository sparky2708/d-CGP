#include "function_set.h"
#include "wrapped_functions.h"
#include "exceptions.h"

namespace dcgp {

function_set::function_set() : m_functions() {};

function_set::function_set(const std::vector<std::string>& list)
{
    for (auto function_name : list)
    {
        push_back(function_name);
    }
}

void function_set::push_back(const std::string& function_name)
{
    if (function_name=="sum")
        m_functions.emplace_back(my_sum,d_my_sum,print_my_sum);
    else if (function_name=="diff")
        m_functions.emplace_back(my_diff,d_my_diff,print_my_diff);
    else if (function_name=="mul")
        m_functions.emplace_back(my_mul,d_my_mul,print_my_mul);
    else if (function_name=="div")
        m_functions.emplace_back(my_div,d_my_div,print_my_div);
    else if (function_name=="sqrt")
        m_functions.emplace_back(my_sqrt,d_my_sqrt,print_my_sqrt);
    else 
        throw input_error("Unimplemented function " + function_name);
}

std::vector<basis_function> function_set::operator()() const
{
    return m_functions;
}


} // end of namespace dcgp
