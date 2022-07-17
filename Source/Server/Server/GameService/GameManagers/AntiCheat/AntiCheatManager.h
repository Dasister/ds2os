/*
 * Dark Souls 2 - Open Server
 * Copyright (C) 2021 Tim Leonard
 *
 * This program is free software; licensed under the MIT license.
 * You should have received a copy of the license along with this program.
 * If not, see <https://opensource.org/licenses/MIT>.
 */

#pragma once

#include "Server/GameService/GameManager.h"
#include "Protobuf/Protobufs.h"

#include <memory>

struct Frpg2ReliableUdpMessage;
class Server;
class GameService;
class AntiCheatTrigger;

// Snoops player state changes and flags anyone appearing to be cheating.

class AntiCheatManager
    : public GameManager
{
public:    
    AntiCheatManager(Server* InServerInstance, GameService* InGameServiceInstance);

    virtual void Poll() override;
    
    virtual std::string GetName() override;

private:
    Server* ServerInstance;
    GameService* GameServiceInstance;

    std::vector<std::shared_ptr<AntiCheatTrigger>> Triggers;

};