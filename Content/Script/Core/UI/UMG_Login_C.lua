--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

require "UnLua"
local BlueprintEnum = require "Core.Enum.BlueprintEnum"

local UMG_Login_C = Class()

UMG_Login_C.FirstInto = false

function UMG_Login_C:Initialize(Initializer)
    print("UMG_Login_C:Initialize()")
end

function UMG_Login_C:PreConstruct(IsDesignTime)
    print("UMG_Login_C:PreConstruct()")
end

function UMG_Login_C:Construct()
    print("UMG_Login_C:Construct")
    self.FirstInto = true
    self.Button_Login.OnClicked:Add(self, UMG_Login_C.OnClicked_Button_Login)
    -- self:PlayAnimation(self.Foreground_Login)
end

function UMG_Login_C:OnClicked_Button_Login()
    print("Clicked")
    self:PlayAnimation(self.ButtonHidden)
    UE4.UGameplayStatics.OpenLevel(self, BlueprintEnum.Level.MainLevel)
end

function UMG_Login_C:Tick(MyGeometry, InDeltaTime)
    if self.FirstInto then
        self:PlayAnimation(self.ForegroundHidden)
        self.FirstInto = false
    end
end

return UMG_Login_C
