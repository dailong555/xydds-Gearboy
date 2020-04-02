/*
 * Gearboy - Nintendo Game Boy Emulator
 * Copyright (C) 2012  Ignacio Sanchez

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 *
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <SDL.h>
#define MINI_CASE_SENSITIVE
#include "mINI/ini.h"
#include "imgui/imgui.h"

#ifdef CONFIG_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

struct config_Emulator
{
    bool paused = false;
    int save_slot = 0;
    bool start_paused = false;
    bool force_dmg = false;
    bool save_in_rom_folder = false;
    bool ffwd = false;
};

struct config_Video
{
    bool fps = false;
    bool bilinear = false;
    bool mix_frames = true;
    bool matrix = true;
    ImVec4 color[4];
};

struct config_Audio
{
    bool enable = true;
    bool sync = true;
};

struct config_Input
{
    SDL_Scancode key_left = SDL_SCANCODE_LEFT;
    SDL_Scancode key_right = SDL_SCANCODE_RIGHT;
    SDL_Scancode key_up = SDL_SCANCODE_UP;
    SDL_Scancode key_down = SDL_SCANCODE_DOWN;
    SDL_Scancode key_a = SDL_SCANCODE_S;
    SDL_Scancode key_b = SDL_SCANCODE_A;
    SDL_Scancode key_start = SDL_SCANCODE_RETURN;
    SDL_Scancode key_select = SDL_SCANCODE_SPACE;

    bool gamepad = true;
    bool gamepad_invert_x_axis = false;
    bool gamepad_invert_y_axis = false;
    SDL_GameControllerButton gamepad_a = SDL_CONTROLLER_BUTTON_A;
    SDL_GameControllerButton gamepad_b = SDL_CONTROLLER_BUTTON_B;
    SDL_GameControllerButton gamepad_start = SDL_CONTROLLER_BUTTON_START;
    SDL_GameControllerButton gamepad_select = SDL_CONTROLLER_BUTTON_BACK;
    int gamepad_x_axis = 0;
    int gamepad_y_axis = 1;
};

EXTERN mINI::INIFile* config_ini_file;
EXTERN mINI::INIStructure config_ini_data;
EXTERN char* config_root_path;
EXTERN char config_emu_file_path[260];
EXTERN char config_imgui_file_path[260];
EXTERN config_Emulator config_emulator;
EXTERN config_Video config_video;
EXTERN config_Audio config_audio;
EXTERN config_Input config_input;

EXTERN void config_init(void);
EXTERN void config_destroy(void);
EXTERN void config_read(void);
EXTERN void config_write(void);

#undef CONFIG_IMPORT
#undef EXTERN
#endif	/* CONFIG_H */