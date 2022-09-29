#pragma once

#define SIGSLOT_WIN_MAIN_THREAD
#include <sigslot/signal.hpp>

class Window : public CDialog // CDialogEx, CFrameWnd, CFrameWndEx, etc
{
  SIGSLOT_MFC_DECL(Window)

  [...]

private:
  sigslot::signal<> m_signal_no_arg;
  sigslot::signal<int, float, std::wstring> m_signal_args;
}
