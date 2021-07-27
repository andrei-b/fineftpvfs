#include "config.h"
#include "fmt/format.h"
#include <fineftp/server.h>
#include <fineftp/fileiointerface.h>
#include "plugins/vfsfileintf.h"
#include <fineftp/fileinfo.h>
#include "plugins/vfsfileinfo.h"
#include "plugins/gcfilesystem.h"
#include <iostream>
#include <thread>
#include <string>

const std::string ConfigPath = "/etc/mantle.json";

int main() {

#ifdef WIN32
  std::string local_root =  "C:\\"; // The backslash at the end is necessary!
#else // WIN32
  std::string local_root =  "/";
#endif // WIN32

  Config config(ConfigPath);
  std::cout << fmt::format("VFS root: {}\n", config.vfsRoot());

  GCFS::GCFileSystem::instance().makeSystem(config.vfsRoot());
  fineftp::Filesystem::registerFileInterfaceFabric([](){return std::make_shared<VFSFileIntf>();});
  fineftp::Filesystem::registerFileInfoFabric([](const std::string & name) {return std::make_shared<VFSFileInfo>(name);});

  // Create an FTP Server on port 2121. We use 2121 instead of the default port
  // 21, as your application would need root privileges to open port 21.

    std::cout << fmt::format("Server port: {}\n", config.port());
  fineftp::FtpServer server(config.port());

  // Add the well known anonymous user and some normal users. The anonymous user
  // can log in with username "anonyous" or "ftp" and any password. The normal
  // users have to provide their username and password. 

  auto users = config.users();
  for(const auto & r : users) {
      std::cout << fmt::format("Adding user: {}\n", r.first);
      if (r.first == "anonymous") {
          server.addUserAnonymous(local_root, fineftp::Permission::All);
      }
      else
          server.addUser (r.first,   r.second, local_root, fineftp::Permission::ReadOnly);
  }

  // Start the FTP server with 4 threads. More threads will increase the
  // performance with multiple clients, but don't over-do it.
  server.start(2);
    std::cout << "VFSFTP is running" << std::endl;
  // Prevent the application from exiting immediatelly
  for (;;)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
