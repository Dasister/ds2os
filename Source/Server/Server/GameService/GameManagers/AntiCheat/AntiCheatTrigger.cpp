/*
 * Dark Souls 2 - Open Server
 * Copyright (C) 2021 Tim Leonard
 *
 * This program is free software; licensed under the MIT license.
 * You should have received a copy of the license along with this program.
 * If not, see <https://opensource.org/licenses/MIT>.
 */

#include "Server/GameService/GameManagers/AntiCheat/AntiCheatTrigger.h"

AntiCheatTrigger::AntiCheatTrigger(AntiCheatManager* InCheatManager, Server* InServerInstance, GameService* InGameServiceInstance)
    : Manager(InCheatManager)
    , ServerInstance(InServerInstance)
    , GameServiceInstance(InGameServiceInstance)
{
}
