#include <gtest/gtest.h>
// #include "../core/BestMoveFinder.hpp"
// #include "../core/GameState.hpp"
#include "../core/polyglotHash.hpp"

TEST(PolyGlot, startpos) { 
    GameState game;
    game.fromFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    EXPECT_EQ(polyglotHash(game), 0x463b96181691fc9c);
}

TEST(PolyGlot, NoPossibleCaptureEnPassant) { 
    GameState game;
    game.fromFen("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
    EXPECT_EQ(polyglotHash(game), 0x823c9b50fd114196);
}

TEST(PolyGlot, CaptureEnPassantWhite) { 
    GameState game;
    game.fromFen("rnbqkbnr/ppp1p1pp/8/3pPp2/8/8/PPPP1PPP/RNBQKBNR w KQkq f6 0 3");
    EXPECT_EQ(polyglotHash(game), 0x22a48b5a8e47ff78);
}

TEST(PolyGlot, CaptureEnPassantBlack) { 
    GameState game;
    game.fromFen("rnbqkbnr/p1pppppp/8/8/PpP4P/8/1P1PPPP1/RNBQKBNR b KQkq c3 0 3");
    EXPECT_EQ(polyglotHash(game), 0x3c8123ea7b067637);
}

TEST(PolyGlot, WhiteNoQueenSideCastle) { 
    GameState game;
    game.fromFen("rnbqkbnr/p1pppppp/8/8/P6P/R1p5/1P1PPPP1/1NBQKBNR b Kkq - 0 4");
    EXPECT_EQ(polyglotHash(game), 0x5c3f9b829b279560);
}

TEST(PolyGlot, WhiteNoCastle) { 
    GameState game;
    game.fromFen("rnbqkbnr/ppp1p1pp/8/3pPp2/8/8/PPPPKPPP/RNBQ1BNR b kq - 0 3");
    EXPECT_EQ(polyglotHash(game), 0x652a607ca3f242c1);
}

