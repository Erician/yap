#ifndef YAP_UTILS_YAP_STRINGUTIL_H_
#define YAP_UTILS_YAP_STRINGUTIL_H_

#include <iostream>
#include <vector>

namespace yap
{
    namespace utils
    {
        namespace stringutil
        {
            std::vector<std::string> split(std::string src, std::string str_to_find);
            std::string strip(std::string src,char c); 

        }; // namespace stringutil
    }; // namespace utils 

}; // namespace yap
#endif