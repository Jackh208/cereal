#pragma once
#include <vector>
#include <string>
#include <unistd.h>

#include "messaging.hpp"
#include "visionipc.h"
#include "visionbuf.h"

class VisionIpcClient {
private:
  Context * msg_ctx;
  SubSocket * sock;

  int num_buffers;
  VisionBuf buffers[VISIONIPC_MAX_FDS];
  void init(std::string name, VisionStreamType type, cl_device_id device_id, cl_context ctx);

public:
  VisionIpcClient(std::string name, VisionStreamType type, cl_device_id device_id, cl_context ctx);
  VisionIpcClient(std::string name, VisionStreamType type, bool opencl=true);
  ~VisionIpcClient();
  VisionBuf * recv();
};
