#pragma once

#include <CCUActions.idl.h>
#include <EAICActions.idl.h>
#include <coresrv/nk/transport-kos.h>
#include <coresrv/sl/sl_api.h>

#include <memory>

class AppConnector
{
public:
  AppConnector() = default;

  // Open IPC connection
  bool ConnectToEAIC();
  bool ConnectToCCU();

  bool StartActionAtEAIC(rtl_uint32_t task);
  bool StartActionAtCCU(rtl_uint32_t task);

private:
  NkKosTransport m_eaicTransport;
  NkKosTransport m_ccuTransport;
  ffd_EAICActions_proxy m_eaicActionsProxy;
  ffd_CCUActions_proxy m_ccuActionsProxy;
};

using AppConnectorPtr = std::shared_ptr<AppConnector>;
