--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"

local BP_PlayerStateBase_Lua_C = Class()

BP_PlayerStateBase_Lua_C.MsgList = {}

--function BP_PlayerStateBase_Lua_C:Initialize(Initializer)
--end

function BP_PlayerStateBase_Lua_C:UserConstructionScript()
    self.MsgList = {}
end

--function BP_PlayerStateBase_Lua_C:ReceiveBeginPlay()
--end

--function BP_PlayerStateBase_Lua_C:ReceiveEndPlay()
--end

-- function BP_PlayerStateBase_Lua_C:ReceiveTick(DeltaSeconds)
-- end

--function BP_PlayerStateBase_Lua_C:ReceiveAnyDamage(Damage, DamageType, InstigatedBy, DamageCauser)
--end

--function BP_PlayerStateBase_Lua_C:ReceiveActorBeginOverlap(OtherActor)
--end

--function BP_PlayerStateBase_Lua_C:ReceiveActorEndOverlap(OtherActor)
--end

return BP_PlayerStateBase_Lua_C
