/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef TRINITY_SPAWNDATA_H
#define TRINITY_SPAWNDATA_H

#include "Position.h"

enum SpawnObjectType
{
    SPAWN_TYPE_CREATURE = 0,
    SPAWN_TYPE_GAMEOBJECT = 1,
};
enum SpawnObjectTypeMask
{
    SPAWN_TYPEMASK_CREATURE = (1 << SPAWN_TYPE_CREATURE),
    SPAWN_TYPEMASK_GAMEOBJECT = (1 << SPAWN_TYPE_GAMEOBJECT),

    SPAWN_TYPEMASK_ALL = (SPAWN_TYPEMASK_CREATURE | SPAWN_TYPEMASK_GAMEOBJECT)
};

enum SpawnGroupFlags
{
    SPAWNGROUP_FLAG_NONE = 0x00000000,
    SPAWNGROUP_FLAG_COMPATIBILITY_MODE = 0x00000001,
    SPAWNGROUP_FLAG_MANUAL_SPAWN = 0x00000002,
    SPAWNGROUP_FLAG_DYNAMIC = 0x00000004,
    SPAWNGROUP_FLAG_ESCORTQUESTNPC = 0x00000008,
};

struct SpawnGroupTemplateData
{
    uint32 groupId;
    uint32 mapId;
    uint32 flags;
    bool isActive;
};

struct SpawnData : public WorldLocation
{
  uint32 id = 0; // entry in respective _template table
  uint32 phaseMask = 0;
  int32 spawntimesecs = 0;
  uint8 spawnMask = 0;
  SpawnGroupTemplateData const* spawnGroupData = nullptr;
  uint32 scriptId = 0;
  bool dbData = true;
};

#endif
