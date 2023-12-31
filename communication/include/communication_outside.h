#pragma once

#include "HTTPRequest.h"
#include <Communication.edl.h>
#include <coresrv/nk/transport-kos.h>
#include <coresrv/sl/sl_api.h>
#include <exception>

class CommunicationOutsideHandler : ffd_CommunicationOutside_ops
{
public:
  static ffd_CommunicationOutside* CreateImpl();
  rtl_uint32_t Outside();

  CommunicationOutsideHandler() = delete;
  ~CommunicationOutsideHandler() = default;

  // private:
  //     CommunicationOutsideHandler();
};
