#ifndef YAP_LOGGING_YAP_CONFIG_H_
#define YAP_LOGGING_YAP_CONFIG_H_

#include <iostream>
#include <string>
#include <map>

class Config
{
public:
    Config();
    bool Init(std::string config_file_path);
    bool IsHave(std::string key);
    std::string GetValue(std::string key);
    
private:
    std::map<std::string, std::string> config_items_;

};



#endif