/* RetroArch - A frontend for libretro.
 * Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 * Copyright (C) 2011-2014 - Daniel De Matteis
 * Copyright (C) 2012-2014 - Michael Lelli
 *
 * RetroArch is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Found-
 * ation, either version 3 of the License, or (at your option) any later version.
 *
 * RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with RetroArch.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <emscripten/emscripten.h>
#include "../../general.h"
#include "../../conf/config_file.h"
#include "../../file.h"
#include "../frontend.h"

#ifdef HAVE_MENU
#include "../../frontend/menu/menu_common.h"
#endif

static void emscripten_mainloop(void)
{
   if (frontend_loop || (frontend_loop && frontend_loop(0, NULL, NULL)))
   {
      main_exit(NULL);
      exit(0);
   }
}

int main(int argc, char *argv[])
{
   emscripten_set_canvas_size(800, 600);
   rarch_main(argc, argv);
   emscripten_set_main_loop(emscripten_mainloop,
         g_settings.video.vsync ? 0 : INT_MAX, 1);

   return 0;
}
