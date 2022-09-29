#include "mfc-gui.h"

SIGSLOT_MFC_IMPL(Window)

BEGIN_MESSAGE_MAP(Window, CDialog)
  [...]
  ON_WM_SIGSLOT_WIN_MAIN_THREAD()
  [...]
END_MESSAGE_MAP()

[...]

BOOL Window::OnInitDialog()
{
  [...]

  SIGSLOT_MFC_INIT(this)

  m_signal_no_arg.connect([&]() -> void
  {
    // this function will be executed on main thread
  });

  m_signal_args.connect([&](int v1, float v2, std::wstring v3) -> void
  {
    // this function will be executed on main thread
  });

  [...]
}

void this_is_function_that_running_in_worker_thread(...)
{
  [...]

  auto window = (Window*)[window pointer];
  window->m_signal_no_arg();
  window->m_signal_args(1609, 16.09F, L"string");

  [...]
}
