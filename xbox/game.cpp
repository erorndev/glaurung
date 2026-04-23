#include "game.h"
#include "../src/position.h"
#include "../src/search.h"
#include "../src/move.h"
#include "../src/ucioption.h"
#include <hal/debug.h>
#include <hal/video.h>
#include <windows.h>
#include <cstdio>
#include <string>

extern "C" long long last_search_nodes;
extern "C" int last_search_time;
extern "C" int current_depth;

static Position *gamePosition = NULL;
const char *StartFEN =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

static void draw_board(const std::string &msg, int depth) {
  debugClearScreen();
  debugPrint("\n  Glaurung 2.2 - Xbox port by erorn\n");
  debugPrint("  ----------------------------------------\n");

  for (int rank = 7; rank >= 0; rank--) {
    debugPrint("      %d  ", rank + 1);
    for (int file = 0; file < 8; file++) {
      Square sq = make_square(File(file), Rank(rank));
      Piece pc = gamePosition->piece_on(sq);
      char c = (pc == EMPTY) ? '.' : ".PNBRQK..pnbrqk"[pc];
      debugPrint("%c ", c);
    }
    debugPrint("\n");
  }
  debugPrint("\n         a b c d e f g h\n\n");

  long long nps = (last_search_time > 0)
                      ? (last_search_nodes * 1000) / last_search_time
                      : 0;

  debugPrint("  Depth: %d | NPS: %lld\n", depth, nps);
  debugPrint("  Nodes: %lld\n", last_search_nodes);
  debugPrint("  Status: %s\n", msg.c_str());
  debugPrint("  ----------------------------------------\n");
}

void xbox_game_loop() {
  gamePosition = new Position();

  std::string myFen =
      "r1bqkbnr/pppp1ppp/2n5/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R b KQkq - 3 3";
  gamePosition->from_fen(myFen);

  set_option_value("Hash", "16");
  set_option_value("Threads", "1");

  Move searchMoves[500];

  while (true) {
    draw_board("Thinking...", 0);
    searchMoves[0] = MOVE_NONE;
    think(*gamePosition, false, false, 0, 0, 0, 10, 0, 0, searchMoves);

    if (searchMoves[0] != MOVE_NONE) {
      UndoInfo u;
      std::string moveStr = move_to_string(searchMoves[0]);

      gamePosition->do_move(searchMoves[0], u);
      draw_board("Played: " + moveStr, 10);
      Sleep(1000);
    } else {
      draw_board("Game Over / Mate", 0);
      while (1) {
        Sleep(100);
      }
    }
  }
}