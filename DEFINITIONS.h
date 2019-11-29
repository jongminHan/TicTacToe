#pragma once

const int SCRREN_WIDTH = 768;
const int SCREEN_HEIGHT = 1136;

const float SPLASH_STATE_SHOW_TIME = 3.f;

static const char* SPLASH_SCENE_BACKGROUND_FILEPATH = "Resources\\res\\Splash Background.png";

static const char* MAIN_MENU_BACKGROUND_FILEPATH = "Resources\\res\\Main Menu Background.png";

static const char* GAME_BACKGROUND_FILEPATH = "Resources\\res\\Main Menu Background.png";

static const char* MAIN_MENU_TITLE_PATH = "Resources\\res\\Game Title.png";

static const char* MAIN_MENU_PLAY_BUTTON = "Resources\\res\\Play Button.png";

static const char* MAIN_MENU_PLAY_BUTTON_OUTER = "Resources\\res\\Play Button Outer.png";

static const char* PAUSE_BUTTON = "Resources\\res\\Pause Button.png";

static const char* X_PIECE_FILEPATH = "Resources\\res\\X.png";

static const char* O_PIECE_FILEPATH = "Resources\\res\\O.png";

static const char* X_WINNING_PIECE_FILEPATH = "Resources\\res\\X Win.png";

static const char* O_WINNING_PIECE_FILEPATH = "Resources\\res\\O Win.png";

const int X_PIECE = 8;

const int O_PIECE = 0;

const int EMPTY_PIECE = -1;

const int PLAYER_PIECE = X_PIECE;

const int AI_PIECE = O_PIECE;

const int STATE_PLAYING = 98;
const int STATE_PAUSED = 97;
const int STATE_WON = 96;
const int STATE_LOSE = 95;
const int STATE_PLACING_PIECE = 94;
const int STATE_AI_PLAYING = 93;
const int STATE_DRAW = 92;
