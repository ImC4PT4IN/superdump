#pragma once
#include <cstdint>

// Auto-generated from mapping.json, validated against rust.h.
// Generated: 2026-10-15T12:29:48.520100+00:00

namespace Offsets {
    // ── BaseCombatEntity ──
    constexpr uintptr_t BaseCombatEntity_startHealth = 0x210;  // float
    constexpr uintptr_t BaseCombatEntity_lifestate = 0x274;  // BaseCombatEntity.LifeState
    constexpr uintptr_t BaseCombatEntity_ShowHealthInfo = 0x270;  // bool
    constexpr uintptr_t BaseCombatEntity_baseProtection = 0x208;  // ProtectionProperties

    // ── BaseEntity ──
    constexpr uintptr_t BaseEntity_model = 0xc8;  // Model
    constexpr uintptr_t BaseEntity_bounds = 0xa0;  // Bounds
    constexpr uintptr_t BaseEntity_flags = 0xd0;  // BaseEntity.Flags

    // ── BasePlayer ──
    constexpr uintptr_t BasePlayer_playerModel = 0x838;  // PlayerModel
    constexpr uintptr_t BasePlayer_displayName = 0xae8;  // string
    constexpr uintptr_t BasePlayer_userIDString = 0xad8;  // string
    constexpr uintptr_t BasePlayer_currentTeam = 0x958;  // ulong
    constexpr uintptr_t BasePlayer_playerFlags = 0xa88;  // BasePlayer.PlayerFlags
    constexpr uintptr_t BasePlayer_inventory = 0xa98;  // %d350490b07bc1b1d855ecf0a8c8d1355e4382d2e<PlayerInventory>
    constexpr uintptr_t BasePlayer_clActiveItem = 0x998;  // BasePlayer.%70b3f71e35ad742e4d06db7f548b51eef7ff4323<ItemId>

    // ── Model ──
    constexpr uintptr_t Model_boneTransforms = 0x50;  // Transform[]
    constexpr uintptr_t Model_headBone = 0x30;  // Transform
    constexpr uintptr_t Model_rootBone = 0x28;  // Transform

    // ── PlayerModel ──
    constexpr uintptr_t PlayerModel_position = 0x1d0;  // Vector3
    constexpr uintptr_t PlayerModel_headBone = 0x48;  // GameObject
    constexpr uintptr_t PlayerModel_neckBone = 0x40;  // GameObject
    constexpr uintptr_t PlayerModel_jawBone = 0x38;  // GameObject
    constexpr uintptr_t PlayerModel_SpineBones = 0x60;  // Transform[]
    constexpr uintptr_t PlayerModel_leftFootBone = 0x68;  // Transform
    constexpr uintptr_t PlayerModel_rightFootBone = 0x70;  // Transform

    // ── TypeInfo ──
    constexpr uintptr_t BaseEntity_TypeInfo = 0x3c8df20;
    constexpr uintptr_t MainCamera_TypeInfo = 0x3c701c8;
    constexpr uintptr_t BaseGameMode_TypeInfo = 0x3c8e188;

}