#include "xbox.h"
#include <hal/video.h>
#include <hal/debug.h>
#include <windows.h>

static const char *glaurung_ascii = R"(
   _____ _
  / ____| |
 | |  __| | __ _ _   _ _ __ _   _ _ __   __ _
 | | |_ | |/ _` | | | | '__| | | | '_ \ / _` |
 | |__| | | (_| | |_| | |  | |_| | | | | (_| |
  \_____|_|\__,_|\__,_|_|   \__,_|_| |_|\__, |
                                         __/ |
                                        |___/
)";

void xbox_init() {
  XVideoSetMode(720, 480, 32, REFRESH_DEFAULT);

  debugClearScreen();
  debugPrint("%s", glaurung_ascii);

  debugPrint("\n  Glaurung 2.2\n");
  debugPrint("  A UCI Chess Playing Engine\n");
  debugPrint("  Copyright (C) 2004-2008 Tord Romstad\n");
  debugPrint("\n");
  debugPrint("  Xbox Port by erorn\n");
  debugPrint("\n");
  debugPrint("  Engine initializing...\n");
  debugPrint("\n");
}