#pragma once

#include "fineftp/fileinfo.h"
#include <chrono>
#include <regex>
#include <iostream>
#include <map>

#include <sys/stat.h>

////////////////////////////////////////////////////////////////////////////////
/// Filesystem
////////////////////////////////////////////////////////////////////////////////

namespace fineftp
{
  namespace Filesystem
  {

    std::string cleanPath(const std::string& path, bool windows_path, const char output_separator);

    std::string cleanPathNative(const std::string& path);
  }
}