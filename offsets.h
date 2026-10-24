#pragma once
#include <cstdint>

// Auto-generated from rustoffsets.com
// build_id:  25231061
// timestamp: 2026-10-22T20:39:33.296270+00:00
// generated: 2026-10-24T20:24:46.411963+00:00

namespace Offsets {

    // ── _root ──
    constexpr uintptr_t _root_basenetworkable_pointer = 0x10BE8EC8;
    constexpr uintptr_t _root_camera_pointer = 0x10C62B28;
    constexpr uintptr_t _root_tod_sky_pointer = 0x10CC1C90;
    constexpr uintptr_t _root_console_pointer = 0x10C08B30;
    constexpr uintptr_t _root_convar_graphics_pointer = 0x111F03E0;
    constexpr uintptr_t _root_convar_admin_pointer = 0x11239810;
    constexpr uintptr_t _root_Il2cppHandle = 0x10CA7920;
    constexpr uintptr_t _root_WorldOffset = 0x10BF80B8;
    constexpr uintptr_t _root_PhysxOffset = 0x1C3B3D0;  // engine internal
    constexpr uintptr_t _root_ListComponent_Projectile_c = 0x10C68838;
    constexpr uintptr_t _root_PlayerEyes_c = 0x10C72548;
    constexpr uintptr_t _root_HeldEntityClass = 0x10C74960;
    constexpr uintptr_t _root_convar_terrain_pointer = 0x0;

    // ── Graphic ──
    constexpr uintptr_t Graphic_fov = 0x19C;
    constexpr uintptr_t Graphic_Base = 0x10951438;
    constexpr uintptr_t Graphic_StaticFields = 0xB8;

    // ── Terrain ──
    constexpr uintptr_t Terrain_StaticFields = 0xB8;
    constexpr uintptr_t Terrain_drawTreeDistance = 0x0;
    constexpr uintptr_t Terrain_drawGrassDistance = 0x0;

    // ── ConsoleSystem ──
    constexpr uintptr_t ConsoleSystem_static_fields = 0xB8;
    constexpr uintptr_t ConsoleSystem_wrapper_class = 0x78;
    constexpr uintptr_t ConsoleSystem_name = 0x30;
    constexpr uintptr_t ConsoleSystem_allowrunfromserver = 0x99;

    // ── BaseNetworkable ──
    constexpr uintptr_t BaseNetworkable_static_fields = 0xB8;
    constexpr uintptr_t BaseNetworkable_client_entities = 0x28;
    constexpr uintptr_t BaseNetworkable_entity_list = 0x10;
    constexpr uintptr_t BaseNetworkable_object_dictionary = 0x10;
    constexpr uintptr_t BaseNetworkable_entity_content = 0x10;
    constexpr uintptr_t BaseNetworkable_entity_size = 0x18;
    constexpr uintptr_t BaseNetworkable_buffer_list = 0x10;
    constexpr uintptr_t BaseNetworkable_prefabID = 0x54;
    constexpr uintptr_t BaseNetworkable_children = 0x40;
    constexpr uintptr_t BaseNetworkable_parent_entity = 0x70;

    // ── BaseCamera ──
    constexpr uintptr_t BaseCamera_static_fields = 0xB8;
    constexpr uintptr_t BaseCamera_wrapper_class = 0x78;
    constexpr uintptr_t BaseCamera_parent_static_fields = 0x10;
    constexpr uintptr_t BaseCamera_matrix = 0x30C;
    constexpr uintptr_t BaseCamera_viewMatrix = 0x80;
    constexpr uintptr_t BaseCamera_projMatrix = 0xC0;
    constexpr uintptr_t BaseCamera_position = 0x454;
    constexpr uintptr_t BaseCamera_cullingMask = 0x43C;

    // ── TodSky ──
    constexpr uintptr_t TodSky_Class = 0x10CC1C90;
    constexpr uintptr_t TodSky_static_fields = 0xB8;
    constexpr uintptr_t TodSky_wrapper_class = 0x0;
    constexpr uintptr_t TodSky_parent_static_fields = 0x10;
    constexpr uintptr_t TodSky_unk = 0x20;
    constexpr uintptr_t TodSky_instance = 0x28;
    constexpr uintptr_t TodSky_TOD_CycleParameters = 0x40;
    constexpr uintptr_t TodSky_TOD_AtmosphereParameters = 0x50;
    constexpr uintptr_t TodSky_TOD_DayParameters = 0x58;
    constexpr uintptr_t TodSky_TOD_NightParameters = 0x60;
    constexpr uintptr_t TodSky_TOD_SunParameters = 0x68;
    constexpr uintptr_t TodSky_TOD_MoonParameters = 0x70;
    constexpr uintptr_t TodSky_TOD_StarParameters = 0x78;
    constexpr uintptr_t TodSky_TOD_CloudParameters = 0x80;
    constexpr uintptr_t TodSky_TOD_LightParameters = 0x88;
    constexpr uintptr_t TodSky_TOD_FogParameters = 0x90;
    constexpr uintptr_t TodSky_TOD_AmbientParameters = 0x98;
    constexpr uintptr_t TodSky_TOD_ReflectionParameters = 0xA0;
    constexpr uintptr_t TodSky_TOD_Initialized = 0xA8;
    constexpr uintptr_t TodSky_TOD_Components = 0x230;

    // ── TodSky::Time ──
    constexpr uintptr_t TodSky_Time_ProgressTime = 0x24;
    constexpr uintptr_t TodSky_Time_UseTimeCurve = 0x27;

    // ── TodSky::Components ──
    constexpr uintptr_t TodSky_Components_Time = 0x1A8;

    // ── TodSky::Cycle ──
    constexpr uintptr_t TodSky_Cycle_hour = 0x10;

    // ── TodSky::Night ──
    constexpr uintptr_t TodSky_Night_lightIntensity = 0x50;
    constexpr uintptr_t TodSky_Night_ambientMultiplier = 0x60;
    constexpr uintptr_t TodSky_Night_reflectionMultiplier = 0x64;

    // ── BaseCombatEntity ──
    constexpr uintptr_t BaseCombatEntity_lifestate = 0x2A8;
    constexpr uintptr_t BaseCombatEntity_model = 0x1B8;
    constexpr uintptr_t BaseCombatEntity__health = 0x2B0;
    constexpr uintptr_t BaseCombatEntity__maxHealth = 0x240;

    // ── BasePlayer ──
    constexpr uintptr_t BasePlayer_playerFlags = 0x6D8;
    constexpr uintptr_t BasePlayer_clothingBlocksAiming = 0x7BC;
    constexpr uintptr_t BasePlayer_clothingMoveSpeedReduction = 0x7C0;
    constexpr uintptr_t BasePlayer_CameraMode = 0x36C;
    constexpr uintptr_t BasePlayer_BaseMovement = 0x348;
    constexpr uintptr_t BasePlayer_ModelState = 0x4B0;
    constexpr uintptr_t BasePlayer_displayName_ = 0x520;
    constexpr uintptr_t BasePlayer_playername = 0x520;
    constexpr uintptr_t BasePlayer_playerModel = 0x2F0;
    constexpr uintptr_t BasePlayer_clactiveitem = 0x350;  // encrypted
    constexpr uintptr_t BasePlayer_inventory = 0x3A0;
    constexpr uintptr_t BasePlayer_playerInput = 0x6F0;
    constexpr uintptr_t BasePlayer_eyes = 0x718;
    constexpr uintptr_t BasePlayer_Visible = 0x170;
    constexpr uintptr_t BasePlayer_Visible1 = 0x172;
    constexpr uintptr_t BasePlayer_currentTeam = 0x558;
    constexpr uintptr_t BasePlayer_userId = 0x520;
    constexpr uintptr_t BasePlayer_VisiblePlayerList = 0x600;
    constexpr uintptr_t BasePlayer_ActiveItemDecryption = 0x366037B;
    constexpr uintptr_t BasePlayer_PlayerInventoryDecryption = 0x3634360;
    constexpr uintptr_t BasePlayer_PlayerEyesDecryption = 0x36A5D30;
    constexpr uintptr_t BasePlayer_VisiblePlayerListClassRVA = 0x0;
    constexpr uintptr_t BasePlayer_lifestate = 0x2A8;
    constexpr uintptr_t BasePlayer_metabolism = 0x308;
    constexpr uintptr_t BasePlayer_blueprints = 0x390;

    // ── BaseProjectile ──
    constexpr uintptr_t BaseProjectile_recoilProperties = 0x408;
    constexpr uintptr_t BaseProjectile_automatic = 0x398;
    constexpr uintptr_t BaseProjectile_isBurstWeapon = 0x43F;
    constexpr uintptr_t BaseProjectile_internalBurstFireRateScale = 0x448;
    constexpr uintptr_t BaseProjectile_viewModel = 0x250;
    constexpr uintptr_t BaseProjectile_is_reloading = 0x0;  // obfuscated — find via IDA
    constexpr uintptr_t BaseProjectile_reloadDuration = 0x3D8;
    constexpr uintptr_t BaseProjectile_primaryMagazine = 0x3E0;
    constexpr uintptr_t BaseProjectile_sightAimConeScale = 0x410;
    constexpr uintptr_t BaseProjectile_hipAimConeScale = 0x0;  // obfuscated
    constexpr uintptr_t BaseProjectile_projectileVelocityScale = 0x394;
    constexpr uintptr_t BaseProjectile_NoiseRadius = 0x380;
    constexpr uintptr_t BaseProjectile_damageScale = 0x384;
    constexpr uintptr_t BaseProjectile_distanceScale = 0x388;
    constexpr uintptr_t BaseProjectile_usableByTurret = 0x399;
    constexpr uintptr_t BaseProjectile_turretDamageScale = 0x39C;
    constexpr uintptr_t BaseProjectile_reloadTime = 0x3D8;
    constexpr uintptr_t BaseProjectile_canUnloadAmmo = 0x3DC;
    constexpr uintptr_t BaseProjectile_fractionalReload = 0x3E8;
    constexpr uintptr_t BaseProjectile_aimSway = 0x400;
    constexpr uintptr_t BaseProjectile_aimSwaySpeed = 0x404;
    constexpr uintptr_t BaseProjectile_aimconeCurve = 0x410;
    constexpr uintptr_t BaseProjectile_aimCone = 0x418;
    constexpr uintptr_t BaseProjectile_hipAimCone = 0x41C;
    constexpr uintptr_t BaseProjectile_aimconePenaltyPerShot = 0x420;
    constexpr uintptr_t BaseProjectile_aimConePenaltyMax = 0x424;
    constexpr uintptr_t BaseProjectile_stancePenaltyScale = 0x430;
    constexpr uintptr_t BaseProjectile_hasADS = 0x434;
    constexpr uintptr_t BaseProjectile_noAimingWhileCycling = 0x435;
    constexpr uintptr_t BaseProjectile_manualCycle = 0x436;
    constexpr uintptr_t BaseProjectile_aiming = 0x0;  // obfuscated
    constexpr uintptr_t BaseProjectile_internalBurstRecoilScale = 0x444;
    constexpr uintptr_t BaseProjectile_internalBurstAimConeScale = 0x44C;
    constexpr uintptr_t BaseProjectile_numShotsFired = 0x454;
    constexpr uintptr_t BaseProjectile_repeatDelay = 0x2EC;
    constexpr uintptr_t BaseProjectile_deployDelay = 0x2E8;
    constexpr uintptr_t BaseProjectile_noHeadshots = 0x33E;
    constexpr uintptr_t BaseProjectile_canChangeFireModes = 0x440;

    // ── BaseProjectile::viewModels ──
    constexpr uintptr_t BaseProjectile_viewModels_baseviewModel = 0x28;

    // ── BaseProjectile::viewModels::baseViewModel ──
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_Animator = 0xA0;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_ViewmodelBob = 0xE0;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_viewmodelSway = 0xA8;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_viewmodelLower = 0x100;

    // ── BaseProjectile::viewModels::baseViewModel::ViewmodelLower ──
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_ViewmodelLower_lowerOnSprint = 0x20;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_ViewmodelLower_lowerWhenCantAttack = 0x21;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_ViewmodelLower_shouldLower = 0x28;

    // ── BaseProjectile::viewModels::baseViewModel::ViewmodelSway ──
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_ViewmodelSway_positionalSwaySpeed = 0x20;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_ViewmodelSway_rotationSwayAmount = 0x2C;

    // ── BaseProjectile::viewModels::baseViewModel::viewmodelBob ──
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_viewmodelBob_bobAmountRun = 0x2C;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_viewmodelBob_bobAmountWalk = 0x28;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_viewmodelBob_bobSpeedRun = 0x24;
    constexpr uintptr_t BaseProjectile_viewModels_baseViewModel_viewmodelBob_bobSpeedWalk = 0x20;

    // ── RecoilProperties ──
    constexpr uintptr_t RecoilProperties_newRecoilOverride = 0x80;
    constexpr uintptr_t RecoilProperties_movementPenalty = 0x34;
    constexpr uintptr_t RecoilProperties_recoilYawMin = 0x18;
    constexpr uintptr_t RecoilProperties_recoilYawMax = 0x1C;
    constexpr uintptr_t RecoilProperties_recoilPitchMin = 0x20;
    constexpr uintptr_t RecoilProperties_recoilPitchMax = 0x24;
    constexpr uintptr_t RecoilProperties_aimconeCurveScale = 0x60;

    // ── PlayerInput ──
    constexpr uintptr_t PlayerInput_bodyAngles = 0x44;

    // ── PlayerEyes ──
    constexpr uintptr_t PlayerEyes_view_offset = 0x40;
    constexpr uintptr_t PlayerEyes_body_rotation = 0x50;
    constexpr uintptr_t PlayerEyes_eye_rotation = 0x0;
    constexpr uintptr_t PlayerEyes_eye_offset = 0x28;

    // ── ItemContainer ──
    constexpr uintptr_t ItemContainer_itemlist = 0x38;
    constexpr uintptr_t ItemContainer_capacity = 0x14;

    // ── PlayerInventory ──
    constexpr uintptr_t PlayerInventory_belt = 0x60;
    constexpr uintptr_t PlayerInventory_containerMain = 0x28;
    constexpr uintptr_t PlayerInventory_clothingbelt = 0x78;

    // ── item ──
    constexpr uintptr_t item_item_definition = 0x60;
    constexpr uintptr_t item_item_uid = 0xA8;
    constexpr uintptr_t item_held_entity = 0x30;
    constexpr uintptr_t item_held_entity_2 = 0x58;
    constexpr uintptr_t item_max_health = 0x90;
    constexpr uintptr_t item_health = 0x84;
    constexpr uintptr_t item_amount = 0x94;
    constexpr uintptr_t item_parent_container = 0x48;

    // ── BaseProjectileExploits ──
    constexpr uintptr_t BaseProjectileExploits_automatic = 0x398;
    constexpr uintptr_t BaseProjectileExploits_FlintStrikeWeapon = 0x4C0;
    constexpr uintptr_t BaseProjectileExploits_DidShitTick = 0x468;

    // ── ItemDefinition ──
    constexpr uintptr_t ItemDefinition_ItemDisplayName = 0x40;
    constexpr uintptr_t ItemDefinition_ShortName = 0x28;
    constexpr uintptr_t ItemDefinition_ItemDisplayEnglish = 0x20;
    constexpr uintptr_t ItemDefinition_category = 0x58;
    constexpr uintptr_t ItemDefinition_itemid = 0x20;
    constexpr uintptr_t ItemDefinition_itemMods = 0x1C0;

    // ── PlayerModel ──
    constexpr uintptr_t PlayerModel_HeadBone = 0xF8;
    constexpr uintptr_t PlayerModel_BoneTransforms = 0x120;
    constexpr uintptr_t PlayerModel_position = 0x1F8;
    constexpr uintptr_t PlayerModel_SkinnedMultiMesh = 0x488;
    constexpr uintptr_t PlayerModel_SkinnedRenderersList = 0x4B8;
    constexpr uintptr_t PlayerModel_new_velocity = 0x0;
    constexpr uintptr_t PlayerModel_velocity = 0x21C;
    constexpr uintptr_t PlayerModel_rotation = 0x228;
    constexpr uintptr_t PlayerModel_isVisible = 0x160;
    constexpr uintptr_t PlayerModel_InGesture = 0x1E8;
    constexpr uintptr_t PlayerModel_CurrentGestureConfig = 0x3D0;
    constexpr uintptr_t PlayerModel_IsNpc = 0x3DD;

    // ── GestureConfig ──
    constexpr uintptr_t GestureConfig_PlayerModelLayer = 0x68;

    // ── Projectile ──
    constexpr uintptr_t Projectile_drag = 0x34;
    constexpr uintptr_t Projectile_gravityModifier = 0x38;
    constexpr uintptr_t Projectile_mod = 0x1D0;
    constexpr uintptr_t Projectile_thickness = 0x3C;
    constexpr uintptr_t Projectile_currentVelocity = 0x28;
    constexpr uintptr_t Projectile_currentPosition = 0x48;
    constexpr uintptr_t Projectile_sentPosition = 0x178;
    constexpr uintptr_t Projectile_owner = 0x110;
    constexpr uintptr_t Projectile_itemModProjectile = 0x110;

    // ── ItemModProjectile ──
    constexpr uintptr_t ItemModProjectile_projectileVelocity = 0x40;
    constexpr uintptr_t ItemModProjectile_projectileSpread = 0x3C;

    // ── Magazine ──
    constexpr uintptr_t Magazine_definition = 0x10;
    constexpr uintptr_t Magazine_capacity = 0x18;
    constexpr uintptr_t Magazine_contents = 0x1C;
    constexpr uintptr_t Magazine_ammoType = 0x20;

    // ── CompoundBowWeapon ──
    constexpr uintptr_t CompoundBowWeapon_stringHoldDurationMax = 0x4E8;
    constexpr uintptr_t CompoundBowWeapon_stringBonusVelocity = 0x4F4;
    constexpr uintptr_t CompoundBowWeapon_currentHoldProgress = 0x4EC;

    // ── ModelState ──
    constexpr uintptr_t ModelState_flags = 0x1C;
    constexpr uintptr_t ModelState_Ducked = 0x1;
    constexpr uintptr_t ModelState_Jumped = 0x2;
    constexpr uintptr_t ModelState_OnGround = 0x4;
    constexpr uintptr_t ModelState_Sleeping = 0x8;
    constexpr uintptr_t ModelState_Sprinting = 0x10;
    constexpr uintptr_t ModelState_OnLadder = 0x20;
    constexpr uintptr_t ModelState_Flying = 0x40;
    constexpr uintptr_t ModelState_Aiming = 0x80;

    // ── PlayerLoot ──
    constexpr uintptr_t PlayerLoot_loot = 0x48;
    constexpr uintptr_t PlayerLoot_entitySource = 0x28;

    // ── PlayerFlags ──
    constexpr uintptr_t PlayerFlags_IsAdmin = 0x4;
    constexpr uintptr_t PlayerFlags_Sleeping = 0x10;
    constexpr uintptr_t PlayerFlags_Wounded = 0x40;
    constexpr uintptr_t PlayerFlags_NoSprint = 0x2000;

    // ── PlayerWalkMovement ──
    constexpr uintptr_t PlayerWalkMovement_spiderman = 0x214;

    // ── BaseMelee ──
    constexpr uintptr_t BaseMelee_maxDistance = 0x3A0;
    constexpr uintptr_t BaseMelee_attackRadius = 0x3A4;
    constexpr uintptr_t BaseMelee_blockSprintOnAttack = 0x3A9;

    // ── HeldEntity ──
    constexpr uintptr_t HeldEntity_ownerItemUID = 0x224;
    constexpr uintptr_t HeldEntity_viewModel = 0x250;
    constexpr uintptr_t HeldEntity_list = 0x218;
    constexpr uintptr_t HeldEntity_items = 0x90;

    // ── ViewModel ──
    constexpr uintptr_t ViewModel_instance = 0x28;

    // ── BaseViewModel ──
    constexpr uintptr_t BaseViewModel_useViewModelCamera = 0x40;
    constexpr uintptr_t BaseViewModel_model = 0x98;
    constexpr uintptr_t BaseViewModel_ironSights = 0xC8;
    constexpr uintptr_t BaseViewModel_lower = 0x100;
    constexpr uintptr_t BaseViewModel_viewmodelBob = 0xE0;
    constexpr uintptr_t BaseViewModel_viewmodelSway = 0xA8;
    constexpr uintptr_t BaseViewModel_animationEvents = 0xB8;
    constexpr uintptr_t BaseViewModel_ViewmodelPunch = 0x108;
    constexpr uintptr_t BaseViewModel_Class = 0x10C027E8;
    constexpr uintptr_t BaseViewModel_instanse = 0x98;
    constexpr uintptr_t BaseViewModel_targetEntity = 0x28;

    // ── HackableLockedCrate ──
    constexpr uintptr_t HackableLockedCrate_timerText = 0x400;

    // ── Text ──
    constexpr uintptr_t Text_m_Text = 0xD8;

    // ── Renderer ──
    constexpr uintptr_t Renderer_materialList = 0x148;

    // ── BuildingBlock ──
    constexpr uintptr_t BuildingBlock_grade = 0x350;

    // ── BaseEntity ──
    constexpr uintptr_t BaseEntity_baseModel = 0x1B8;
    constexpr uintptr_t BaseEntity_SkinnedMultiMesh = 0x3E0;
    constexpr uintptr_t BaseEntity_position = 0x1F8;
    constexpr uintptr_t BaseEntity_Visible = 0x191;

    // ── Entity ──
    constexpr uintptr_t Entity_baseObject = 0x10;
    constexpr uintptr_t Entity_entityObject = 0x30;
    constexpr uintptr_t Entity_transform = 0x8;
    constexpr uintptr_t Entity_visualState = 0x38;
    constexpr uintptr_t Entity_position = 0x1F8;
    constexpr uintptr_t Entity_rotation = 0xA0;
    constexpr uintptr_t Entity_prefabId = 0x30;

    // ── Model ──
    constexpr uintptr_t Model_boneTransforms = 0x50;
    constexpr uintptr_t Model_rootBone = 0x28;
    constexpr uintptr_t Model_headBone = 0x30;
    constexpr uintptr_t Model_eyeBone = 0x38;
    constexpr uintptr_t Model_skeleton = 0x48;
    constexpr uintptr_t Model_bonePosition = 0x90;

    // ── TranslatePhrase ──
    constexpr uintptr_t TranslatePhrase_legacyEnglish = 0x20;
    constexpr uintptr_t TranslatePhrase_english = 0x20;
    constexpr uintptr_t TranslatePhrase_legacyEnglish2 = 0x18;

    // ── FlintStrikeWeapon ──
    constexpr uintptr_t FlintStrikeWeapon_successFraction = 0x4C0;
    constexpr uintptr_t FlintStrikeWeapon_didSparkThisFrame = 0x468;

    // ── World ──
    constexpr uintptr_t World_seed = 0x48;
    constexpr uintptr_t World_size = 0x350;

    // ── GameManager ──
    constexpr uintptr_t GameManager_Class = 0x11181780;
    constexpr uintptr_t GameManager_instance = 0x38;
    constexpr uintptr_t GameManager_prefab_pool_collection = 0x10;

    // ── Decryption RVAs ──
    constexpr uintptr_t Decryption_PlayerEyesDecryption = 0x36A5D30;
    constexpr uintptr_t Decryption_PlayerInventoryDecryption = 0x3634360;
    constexpr uintptr_t Decryption_ActiveItemDecryption = 0x366037B;
    constexpr uintptr_t Decryption_client_entities_decrypt = 0x256A013;
    constexpr uintptr_t Decryption_entity_list_decrypt = 0x259050D;

}