#pragma once
#include <cstdint>

// Manual Rust offsets. Update by hand when Rust patches.
// Last verified: 2026-10-15
// Source: dump.cs from lxraa fork, metadata v39.

namespace Offsets {

    // ── BasePlayer (extends BaseCombatEntity, extends BaseEntity) ──
    constexpr uintptr_t BasePlayer_playerModel   = 0x838;   // PlayerModel*
    constexpr uintptr_t BasePlayer_displayName   = 0xAE8;   // string
    constexpr uintptr_t BasePlayer_userIDString  = 0xAD8;   // string
    constexpr uintptr_t BasePlayer_currentTeam   = 0x958;   // ulong
    constexpr uintptr_t BasePlayer_playerFlags   = 0xA88;   // PlayerFlags
    constexpr uintptr_t BasePlayer_inventory     = 0xA98;   // PlayerInventory*
    constexpr uintptr_t BasePlayer_clActiveItem  = 0x998;   // ItemId
    constexpr uintptr_t BasePlayer_lookingAt     = 0x880;   // GameObject*

    // ── BaseCombatEntity ──
    constexpr uintptr_t BaseCombatEntity_startHealth    = 0x210;  // float
    constexpr uintptr_t BaseCombatEntity_lifestate      = 0x274;  // LifeState (0=alive)
    constexpr uintptr_t BaseCombatEntity_ShowHealthInfo = 0x270;  // bool
    constexpr uintptr_t BaseCombatEntity_baseProtection = 0x208;  // ProtectionProperties*

    // ── BaseEntity ──
    constexpr uintptr_t BaseEntity_model  = 0xC8;  // Model*
    constexpr uintptr_t BaseEntity_bounds = 0xA0;  // Bounds
    constexpr uintptr_t BaseEntity_flags  = 0xD0;  // Flags

    // ── PlayerModel ──
    constexpr uintptr_t PlayerModel_position      = 0x1D0;  // Vector3
    constexpr uintptr_t PlayerModel_headBone      = 0x48;   // GameObject*
    constexpr uintptr_t PlayerModel_neckBone      = 0x40;   // GameObject*
    constexpr uintptr_t PlayerModel_jawBone       = 0x38;   // GameObject*
    constexpr uintptr_t PlayerModel_SpineBones    = 0x60;   // Transform[]
    constexpr uintptr_t PlayerModel_leftFootBone  = 0x68;   // Transform*
    constexpr uintptr_t PlayerModel_rightFootBone = 0x70;   // Transform*

    // ── Model ──
    constexpr uintptr_t Model_boneTransforms = 0x50;  // Transform[]
    constexpr uintptr_t Model_headBone       = 0x30;  // Transform*
    constexpr uintptr_t Model_rootBone       = 0x28;  // Transform*

    // ── Unity internals (stable across Unity versions) ──
    constexpr uintptr_t Transform_position = 0x90;  // Vector3, world position (Unity 6)
    constexpr uintptr_t Transform_localPos = 0x38;  // Vector3, local position

    // ── TypeInfo (IL2CPP static class pointers) ──
    constexpr uintptr_t BaseEntity_TypeInfo   = 0x3c8df20;
    constexpr uintptr_t MainCamera_TypeInfo   = 0x3c701c8;
    constexpr uintptr_t BaseGameMode_TypeInfo = 0x3c8e188;

    // ── MANUAL — fill in yourself ──
    // Entity list anchor. Walk BaseNetworkable statics or use FindObjectsOfType<BasePlayer>.
    // constexpr uintptr_t BaseNetworkable_clientEntities = 0x??;
    //
    // View matrix. Find MainCamera's Matrix4x4 field.
    // constexpr uintptr_t MainCamera_viewMatrix = 0x??;
}
