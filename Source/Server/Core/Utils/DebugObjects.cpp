/*
 * Dark Souls 2 - Open Server
 * Copyright (C) 2021 Tim Leonard
 *
 * This program is free software; licensed under the MIT license.
 * You should have received a copy of the license along with this program.
 * If not, see <https://opensource.org/licenses/MIT>.
 */

#include "Core/Utils/DebugObjects.h"

namespace Debug
{
#define TIMER(Name, Description) DebugTimer Name(Description);
#define COUNTER(Name, Description) DebugCounter Name(Description);

#include "Core/Utils/DebugObjects.inc"

#undef TIMER
#undef COUNTER
};
