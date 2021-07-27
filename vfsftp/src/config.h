//
// Created by andrey on 7/27/21.
//

#ifndef FINEFTP_CONFIG_H
#define FINEFTP_CONFIG_H

#include "../nlohmann/json.hpp"
#include <map>
#include <fstream>

class Config {
public:
    Config(const std::string & path)
    {
        std::ifstream ifs(path);
        _config = nlohmann::json::parse(ifs);
    }
    int port()
    {
        auto defPort = 21;
        if (_config.contains("vfsftp")) {
            nlohmann::json ftpc = _config.value("vfsftp", nlohmann::json());
            if (ftpc.contains("port"))
                return ftpc.value("port", defPort);
        }
        return defPort;
    }
    std::string vfsRoot()
    {
        auto defRoot = "/home/nanocore/vfsftpd";
        if (_config.contains("vfsftp")) {
            nlohmann::json ftpc = _config.value("vfsftp", nlohmann::json());
            if (ftpc.contains("fsroot"))
                return ftpc.value("fsroot", defRoot);
        }
        return defRoot;
    }
    std::map<std::string, std::string> users() {
        std::map<std::string, std::string> result;
        if (_config.contains("vfsftp")) {
            nlohmann::json ftpc = _config.value("vfsftp", nlohmann::json());
            if (ftpc.contains("users")) {
                std::vector<std::map<std::string, std::string>> array = ftpc.at("users").get<std::vector<std::map<std::string, std::string>>>();
                for (const auto & r : array)
                    result.insert({r.at("login"), r.at("pwd")});
                return result;
            }
        }
        return result;
    }
private:
    nlohmann::json _config;
};


#endif //FINEFTP_CONFIG_H
