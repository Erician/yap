#ifndef YAP_LOGGING_YAP_CONFIG_H_
#include "logging/yap_config.h"
#endif

#include <cstdio>
#include <iostream>
#include <fstream>
#include <iterator>

#ifndef YAP_UTILS_YAP_STRINGUTIL_
#include "utils/yap_stringutil.h"
#endif

#ifndef YAP_LOGGING_YAP_CONST_
#include "logging/yap_const.h"
#endif

Config::Config()
{
    config_items_[yap::config::kLogFilePath] = "";
}

bool Config::Init(std::string config_file_path)
{
    std::ifstream ifs(config_file_path, std::ifstream::in);
    if(!ifs.is_open())
        return false;
    std::string line;
    while(! ifs.eof())
    {
        std::getline(ifs, line);
        if(line.length() == 0 || line[0] == '\n' || line[0] == '#')
            continue;
        line = yap::utils::stringutil::strip(line, '\n');
        std::vector<std::string> pairs = yap::utils::stringutil::split(line, "=");
        for(std::vector<std::string>::iterator it = pairs.begin(); it != pairs.end(); it++)
            *it = yap::utils::stringutil::strip(*it, ' ');
        if(pairs.size() == 0 || pairs.size() > 2 || config_items_.find(pairs[0]) == config_items_.end())
            return false;
        if(pairs.size() == 2)
            config_items_[pairs[0]] = pairs[1];
    }
    return false;
}


std::string Config::GetValue(std::string key)
{
    return IsHave(key) == false ? "" : config_items_[key];
}

bool Config::IsHave(std::string key)
{
    return config_items_.find(key) == config_items_.end() ? false : true;
}
