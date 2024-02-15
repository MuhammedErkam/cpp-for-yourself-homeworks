#include <no_strings_attached/string_trim.h>

#include <iostream>

namespace no_strings_attached {
namespace trim {
std::string Trim(const std::string& str, char char_to_trim, Side side) {
    std::string::size_type n{0};
    std::string result_str{};
    std::vector<int> result_vec;

    auto lindex = 0;
    auto rindex = 0;
    auto pos = 0;
    while (true) {
        n = str.find(char_to_trim, pos);
        if (n == std::string::npos) { break; }
        else{
            result_vec.emplace_back(n);
        }

        pos++;
    }
    if(side == Side::kLeft){
        for (int i = 0; i < result_vec.size()-1; i++)
        {
            if(result_vec[i+1] == (result_vec[i] + 1)){
                continue;
            }
            else{
                result_str = str.substr(result_vec[i]+1);
                lindex = i;
                break;
            }
        }    
    }

    else if(side == Side::kRight){
        for (int i = result_vec.size()-1; i > 1; i--)
        {
            if(result_vec[i] == (result_vec[i-1] + 1)){
                continue;
            }
            else{
                result_str = str.substr(0,result_vec[i]);
                rindex = i;
                break;
            }
        }    
    }
    else{
        for (int i = 0; i < result_vec.size()-1; i++)
        {
            if(result_vec[i+1] == (result_vec[i] + 1)){
                continue;
            }
            else{
                lindex = i;
                break;
            }
        }          
        for (int i = result_vec.size()-1; i > 1; i--)
        {
            if(result_vec[i] == (result_vec[i-1] + 1)){
                continue;
            }
            else{
                rindex = i;
                break;
            }
        }
        result_str = str.substr(lindex+1, rindex - lindex - 1);  
    }

    // std::cout << "result: " << result_str << "*qqqq" << std::endl;
    return result_str;
}
std::string Trim(const std::string& str) {
    std::string::size_type n{0};
    std::string result_str{};
    std::vector<int> result_vec;

    auto lindex = 0;
    auto rindex = 0;
    auto pos = 0;

    while (true) {
        n = str.find(' ', pos);
        if (n == std::string::npos) { break; }
        else{
            result_vec.emplace_back(n);
        }
        pos++;
    }

    for (int i = 0; i < result_vec.size()-1; i++)
    {
        if(result_vec[i+1] == (result_vec[i] + 1)){
            continue;
        }
        else{
            lindex = i;
            break;
        }
    }          
    for (int i = result_vec.size()-1; i > 1; i--)
    {
        if(result_vec[i] == (result_vec[i-1] + 1)){
            continue;
        }
        else{
            rindex = i;
            break;
        }
    }
    result_str = str.substr(lindex+1, rindex - lindex - 1);  
    return result_str;
}
}  // namespace trim
}  // namespace no_strings_attached
