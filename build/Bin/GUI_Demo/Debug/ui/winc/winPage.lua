require "ui.uiObject"

--------------------------------------------------------------------------------

autoImpScriptClassDim("WinPage", "UI.Window")

function WinPage:__init()
	self.triggers_["TestEvent"] = WinPage.testEvent
	self:registerTriggers_()
end

function WinPage:__onLoaded()
	self:SetCaptionWithNewLine("Hello, WinPage")
	self.btnOK = self:findChild("BtnOK")
	self.btnOK.winPage = self
end


function WinPage:__release()
	self.btnOK.winPage = nil
	self.btnOK = nil
end

function WinPage:testEvent(msg)
	self:SetCaptionWithNewLine(msg)
end

--------------------------------------------------------------------------------

autoImpScriptClassDim("WinPageBtnOK", "UI.Button")

function WinPageBtnOK:__init()
	self.triggers_["TestEvent"] = WinPageBtnOK.mmEvent
	self:registerTriggers_()
end

function WinPageBtnOK:__onLoaded()
end

function WinPageBtnOK:__release()
	self.winPage = nil
end

function WinPageBtnOK:mmEvent(msg)
	self:SetCaptionWithNewLine(msg)
end

function WinPageBtnOK:OnMouseButtonReleased(left, top, mouseBtnID)
	self:SetCaptionWithNewLine("Released")
	--self.winPage:SetCaptionWithNewLine("Released")
end

function WinPageBtnOK:OnMouseButtonPressed(left, top, mouseBtnID)
	self:SetCaptionWithNewLine("Pressed")
	--self.winPage:SetCaptionWithNewLine("Pressed")
end

function WinPageBtnOK:OnMouseSetFocus(oldUIObj)
	--self:SetCaptionWithNewLine("SetFocus")
	ECenter.fireEvent("TestEvent", "Hello, SetFocus")
	--self.winPage:SetCaptionWithNewLine("SetFocus")
end

function WinPageBtnOK:OnMouseLostFocus(newUIObj)
	ECenter.fireEvent("TestEvent", "Hello, LostFocus")
end