#include "filesystem.h"

#include <list>
#include <sstream>
#include <mutex>
#include <iomanip>

#ifdef WIN32

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#else // WIN32

#include <dirent.h>

#endif // WIN32

////////////////////////////////////////////////////////////////////////////////
/// Filesystem
////////////////////////////////////////////////////////////////////////////////

namespace fineftp
{
namespace Filesystem
{


  std::string cleanPath(const std::string& path, bool windows_path, const char output_separator)
  {
    if (path.empty())
    {
      return ".";
    }

    // Find the root for absolute paths

    std::string absolute_root;

    if (windows_path)
    {
      /* On Windows, a root folder can be:
       *    C:\
       *    //Host
       *    \\Host
       */

      std::regex win_local_drive("^[a-zA-Z]\\:");                // Local drive
      std::regex win_network_drive("^[/\\\\]{2}[^/\\\\]+");      // Network path starting with two slashes or backslashes followed by a hostname

      if (std::regex_search(path, win_local_drive))
      {
        // Windows local drive, consisting of drive-letter and colon
        absolute_root = path.substr(0, 2);
      }
      else if (std::regex_search(path, win_network_drive))
      {
        // Window network drive, consisting of \\ and hostname
        size_t sep_pos = path.find_first_of("/\\", 2);
        absolute_root = path.substr(0, sep_pos); // If no seperator was found, this will return the entire string
      }
    }
    else
    {
      // On Unix there is only one root and it is '/'
      if (path[0] == '/')
      {
        absolute_root = '/';
      }
    }

    // Split the path
    std::list<std::string> components;

    if (path.size() >= (absolute_root.size() + 1))
    {
      size_t start, end;
      
      if (absolute_root.empty())
        start = 0;
      else
        start = absolute_root.size();

      do
      {
        if (windows_path)
          end = path.find_first_of("/\\", start);
        else
          end = path.find_first_of("/", start);

        std::string this_component;
        if (end == std::string::npos)
          this_component = path.substr(start);
        else
          this_component = path.substr(start, end - start);
        
        // The components-stack that will increase and shrink depending on the folders and .. elements in the splitted path
        if (this_component.empty() || (this_component == "."))
        {
        }
        else if (this_component == "..")
        {
          if (!absolute_root.empty())
          {
            if (!components.empty())
            {
              // Move one folder up if we are not already at the root
              components.pop_back();
            }
          }
          else
          {
            if (!components.empty() && (components.back() != ".."))
            {
              // Move one folder up by removing it. We must not remove ".." elements that we were not able to resolve previously.
              components.pop_back();
            }
            else
            {
              components.push_back("..");
            }
          }
        }
        else
        {
          components.push_back(this_component);
        }

        if (end == std::string::npos)
          break;
        else
          start = end + 1;

      } while (start < path.size());

      // Join the components again
      if (components.size() == 0 && absolute_root.empty())
      {
          return ".";
      }
    }

    std::stringstream path_ss;
    path_ss << absolute_root;

    if (windows_path && !absolute_root.empty())
    {
      path_ss << output_separator; // The windows drive must be followed by a separator. When referencing a network drive.
    }

    auto comp_it = components.begin();
    while (comp_it != components.end())
    {
      if (comp_it != components.begin())
        path_ss << output_separator;
      
      path_ss << *comp_it;

      comp_it++;
    }

    return path_ss.str();
  }

  std::string cleanPathNative(const std::string& path)
  {
#ifdef WIN32
    bool windows_path = true;
    char separator = '\\';
#else // WIN32
    bool windows_path = false;
    char separator = '/';
#endif // WIN32
    return cleanPath(path, windows_path, separator);
  }
}
}
