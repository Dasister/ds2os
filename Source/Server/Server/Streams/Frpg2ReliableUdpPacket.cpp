/*
 * Dark Souls 2 - Open Server
 * Copyright (C) 2021 Tim Leonard
 *
 * This program is free software; licensed under the MIT license.
 * You should have received a copy of the license along with this program.
 * If not, see <https://opensource.org/licenses/MIT>.
 */

#include "Server/Streams/Frpg2ReliableUdpPacket.h"

std::string ToString(Frpg2ReliableUdpOpCode OpCode)
{
    switch (OpCode)
    {
        case Frpg2ReliableUdpOpCode::SYN: return "SYN";
        case Frpg2ReliableUdpOpCode::RACK: return "RACK";
        case Frpg2ReliableUdpOpCode::DAT: return "DAT";
        case Frpg2ReliableUdpOpCode::HBT: return "HBT";
        case Frpg2ReliableUdpOpCode::FIN: return "FIN";
        case Frpg2ReliableUdpOpCode::RST: return "RST";
        case Frpg2ReliableUdpOpCode::PT_DAT_FRAG: return "PT_DAT_FRAG";
        case Frpg2ReliableUdpOpCode::ACK: return "ACK";
        case Frpg2ReliableUdpOpCode::SYN_ACK: return "SYN_ACK";
        case Frpg2ReliableUdpOpCode::DAT_ACK: return "DAT_ACK";
        case Frpg2ReliableUdpOpCode::FIN_ACK: return "FIN_ACK";
        case Frpg2ReliableUdpOpCode::PT_DAT_FRAG_ACK: return "PT_DAT_FRAG_ACK";
    }
    return "UNKNOWN";
}