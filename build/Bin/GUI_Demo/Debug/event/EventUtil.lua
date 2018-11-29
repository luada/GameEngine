--/*------------------------------------------------------------------------------------
 --* Module:  EventUtil define all EventID and init method
 --* Modified: 2008年3月13日 11:11:08
 --* Purpose: Define all event id, anyone change it should insure all event ID is unique
 ---------------------------------------------------------------------------------------*/

require "base.class"
require "event.EventFactory"
require "event.EventManager"

EventGroup={
Event_Group_Local=0x00000,
Event_Group_Frame=0x10000,
Event_Group_Trade=0x20000,
Event_Group_Team =0x30000,
Event_Group_Equip=0x40000,
Event_Group_Skill=0x50000,
Event_Group_Fight=0x60000,
Event_Group_Role=0x70000,
Event_Group_Task=0x80000,
Event_Group_Material=0x90000,
Event_Group_Storage=0x100000,
Event_Group_Pet=0x110000,
Event_Group_Chat=0x120000,
Event_Group_School = 0x130000,
Event_Group_DataBase = 0x140000,
Event_Group_Copy = 0x150000,
Event_Group_Friend = 0x160000,
Event_Group_Stall = 0x170000,
Event_Group_Relation = 0x180000,
Event_Group_Auction = 0x210000,
Event_Group_Debug = 0x220000,
Event_Group_Test = 0x230000,
Event_Group_PlayerState = 0x240000,
Event_Group_GM = 0x250000,
}



----------Local Event ID-------------------------
LocalEvents={
	groupID=EventGroup.Event_Group_Local,
	C_DragTradeItem = EventGroup.Event_Group_Local + 101,
	C_DropTradeItem = EventGroup.Event_Group_Local + 102,
	C_InstallEquip = EventGroup.Event_Group_Local + 103,
	C_UninstallEquip = EventGroup.Event_Group_Local + 104,
	C_SellGoods = EventGroup.Event_Group_Local + 105,
	C_BuyGoods =  EventGroup.Event_Group_Local + 106,
	C_RedeemGoods = EventGroup.Event_Group_Local + 107,
	C_SelectCommand = EventGroup.Event_Group_Local + 108,
	C_SkillItemClicked = EventGroup.Event_Group_Local + 109,
	C_MenuItemClicked = EventGroup.Event_Group_Local + 110,
	C_PlayEnd = EventGroup.Event_Group_Local + 111,
	C_PlayRound = EventGroup.Event_Group_Local + 112,
	C_RepairGoods = EventGroup.Event_Group_Local + 113,
	C_RepairEquip = EventGroup.Event_Group_Local + 114,
	C_SkillDrop =  EventGroup.Event_Group_Local + 115,
	C_DragStrengthenItem=EventGroup.Event_Group_Local + 116,
	C_PuddingEquip=EventGroup.Event_Group_Local + 117,
	C_PuddingDiamend=EventGroup.Event_Group_Local + 118,
	C_DragDrillItem=EventGroup.Event_Group_Local + 119,
	C_DragRefineItem=EventGroup.Event_Group_Local + 120,
	C_QuickBuyGoods=EventGroup.Event_Group_Local + 121,
	C_QuickSellGoods=EventGroup.Event_Group_Local + 122,
	C_QuickRedeemGoods=EventGroup.Event_Group_Local + 123,
	C_QuickInstallEquip = EventGroup.Event_Group_Local + 124,
	C_QuickUninstallEquip = EventGroup.Event_Group_Local + 125,
	C_UpdateToolTipTextIntoFixState=EventGroup.Event_Group_Local + 126,
	C_UpdateToolTipTextIntoNormalState=EventGroup.Event_Group_Local + 127,
	C_DivideGoods=EventGroup.Event_Group_Local + 128,
	C_EntityOutOfSight=EventGroup.Event_Group_Local + 129,
	C_SelcetChanged=EventGroup.Event_Group_Local + 130,
	C_PlayMusic=EventGroup.Event_Group_Local + 131,
	C_SetBoutCount=EventGroup.Event_Group_Local + 132,
	C_EntityEnterSight = EventGroup.Event_Group_Local + 133,	--某个角色进入场景(视野)
	C_WindowClosed = EventGroup.Event_Group_Local + 134,	--某个窗口关闭
}

----------Task System Event ID-------------------------
AuctionEvents = {
	groupID = EventGroup.Event_Group_Auction,

	CS_Entrust = EventGroup.Event_Group_Auction+1,
	CS_CancelEntrust = EventGroup.Event_Group_Auction+2,
	CS_RequestList = EventGroup.Event_Group_Auction+3,

	SC_EntrustResult= EventGroup.Event_Group_Auction+4,
	SC_RequestList = EventGroup.Event_Group_Auction+5,
	SC_OpenAuctionWindow = EventGroup.Event_Group_Auction+6,

	CS_RequestStorageState = EventGroup.Event_Group_Auction+7,
	SC_RequestStorageState = EventGroup.Event_Group_Auction+8,

	CS_RequestSearchInVList = EventGroup.Event_Group_Auction+9, --改动
	SC_RequestSearchInVList = EventGroup.Event_Group_Auction+10, --改动

	CS_UpdatePrice = EventGroup.Event_Group_Auction+11,
	SC_UpdatePrice = EventGroup.Event_Group_Auction+12,

	CS_AuctionDeal = EventGroup.Event_Group_Auction+13,
	SC_AuctionDeal = EventGroup.Event_Group_Auction+14,

	SC_ReleaseMatState = EventGroup.Event_Group_Auction+15,
	SC_AuctionResult = EventGroup.Event_Group_Auction+16,

	CS_RequestBuy = EventGroup.Event_Group_Auction+17, --增加 求购
	SC_ReturnBuy = EventGroup.Event_Group_Auction+18, --增加
	CS_RequestSale = EventGroup.Event_Group_Auction+19, --增加 贩卖
	SC_ReturnSale = EventGroup.Event_Group_Auction+20, --增加
	CS_RequestMyTradeList = EventGroup.Event_Group_Auction+21, --增加 贩卖列表
	SC_ReturnMyTradeList = EventGroup.Event_Group_Auction+22, --增加
	CS_RequestCancelBuy = EventGroup.Event_Group_Auction+23, --增加 取消贩卖
	SC_ReturnCancelBuy = EventGroup.Event_Group_Auction+24, --增加
	CS_RequestSearchInPList = EventGroup.Event_Group_Auction+25, --增加 搜索
	SC_ReturnSearchInPList = EventGroup.Event_Group_Auction+26, --增加
}

TaskEvents={
	groupID=EventGroup.Event_Group_Task,
	CS_DeleteTask=EventGroup.Event_Group_Task+1,
	CS_ReturnTask=EventGroup.Event_Group_Task+2,
	SC_LoadTasks=EventGroup.Event_Group_Task+3,
	SC_DeleteTaskReturn=EventGroup.Event_Group_Task+4,
	SC_TaskFinished=EventGroup.Event_Group_Task+5,
	SC_IllegalAction=EventGroup.Event_Group_Task+6,
	SC_TasksAdded=EventGroup.Event_Group_Task+7,
	SC_TaskRemoved=EventGroup.Event_Group_Task+8,
	CS_ShareTask=EventGroup.Event_Group_Task+9,
	CS_AnswerShareTask=EventGroup.Event_Group_Task+10,
	SC_SendShareTask=EventGroup.Event_Group_Task+11,
	SC_ShareTaskReturn=EventGroup.Event_Group_Task+12,
	SC_TaskTimeout=EventGroup.Event_Group_Task+13,
	CS_ReceiveTask=EventGroup.Event_Group_Task+14,
	SC_TaskDone=EventGroup.Event_Group_Task+15,
	SC_TaskFailed=EventGroup.Event_Group_Task+16,
	SC_ContentChanged=EventGroup.Event_Group_Task+17,
	S_TaskChanged=EventGroup.Event_Group_Task+18,
	SC_StatusChanged=EventGroup.Event_Group_Task+19,
	SC_ShowTaskPets=EventGroup.Event_Group_Task+20,
	CS_ReturnTalkTask=EventGroup.Event_Group_Task+21,
	S_TaskFailed=EventGroup.Event_Group_Task+22,
	S_TaskReceived=EventGroup.Event_Group_Task+23,
	S_TaskFinished=EventGroup.Event_Group_Task+24,
	SC_ChooseRewardMats=EventGroup.Event_Group_Task+25,
	SC_RetrieNpcTasks=EventGroup.Event_Group_Task+26,
	CS_TaskNpcReload=EventGroup.Event_Group_Task+27,
	CS_SetTaskMark=EventGroup.Event_Group_Task+28,
	CS_GetAllCanDoTasks=EventGroup.Event_Group_Task+29,
	SC_ReturnAllCanDoTasks=EventGroup.Event_Group_Task+30,
	CS_ScreenNpcsTaskReload=EventGroup.Event_Group_Task+31,
}
----------Framework Event ID-------------------------
FrameEvents={
	groupID=EventGroup.Event_Group_Frame,
	CS_PlayerLoaded = EventGroup.Event_Group_Frame + 1,
	SC_PlayerLoaded = EventGroup.Event_Group_Frame + 2,
	CS_MoveSys_MoveTo= EventGroup.Event_Group_Frame + 3,
	SS_MoveSys_MoveStart = EventGroup.Event_Group_Frame + 4,
	SS_MoveSys_MoveStop = EventGroup.Event_Group_Frame + 5,
	SS_EnterScene = EventGroup.Event_Group_Frame + 6,
	SS_QuitScene = EventGroup.Event_Group_Frame + 7,
	S_PlayerExit = EventGroup.Event_Group_Frame + 8,
	CS_NPC_Dialog = EventGroup.Event_Group_Frame + 9,
	SC_NPC_Dialog = EventGroup.Event_Group_Frame + 10,
	CS_DialogAction = EventGroup.Event_Group_Frame + 11,
	S_DialogClosed = EventGroup.Event_Group_Frame + 12,
	CS_Shell_Command = EventGroup.Event_Group_Frame + 13,
	CS_WorldChat = EventGroup.Event_Group_Frame + 14,
	SC_WorldChat = EventGroup.Event_Group_Frame + 15,
	CS_Task_Dialog = EventGroup.Event_Group_Frame + 16,
	SC_Task_Dialog = EventGroup.Event_Group_Frame + 17,
	SC_Mat_Changed = EventGroup.Event_Group_Frame + 18,
	CS_PlayerAttributePointChanged = EventGroup.Event_Group_Frame + 19,
	SS_PackUpdate = EventGroup.Event_Group_Frame + 20,
	SC_PackUpdate = EventGroup.Event_Group_Frame + 21,
	SC_Restore = EventGroup.Event_Group_Frame + 22,
	SC_OpenConfirmRestoreDlg = EventGroup.Event_Group_Frame + 23,
	CS_ConfirmRestore = EventGroup.Event_Group_Frame + 24,
	SC_CouldNotTalk = EventGroup.Event_Group_Frame + 25,
	CS_GetRoleAttributes = EventGroup.Event_Group_Frame + 26,
	SC_ResultRoleAttributes = EventGroup.Event_Group_Frame + 27,
	SS_MoveSys_SendTo = EventGroup.Event_Group_Frame + 28,
	SC_PlayerBusDataUpdate = EventGroup.Event_Group_Frame + 29,
	SS_PlayerLifeSkillProduce = EventGroup.Event_Group_Frame + 30,
	SS_PlayerLifeSkillUpgrade = EventGroup.Event_Group_Frame + 31,
	SS_PlayerGroupLoaded = EventGroup.Event_Group_Frame + 32,	--尚未完成
	SS_PlayerBusDataLoaded = EventGroup.Event_Group_Frame + 33,	--已经完成，可以发送给玩家
	SS_PlayerEnterHotArea = EventGroup.Event_Group_Frame + 34,
	SS_GameStateChanged = EventGroup.Event_Group_Frame + 35,	--业务层做了某件事,某个全局状态触发
	SS_EnterPlayerSight = EventGroup.Event_Group_Frame + 36,
	SS_LeavePlayerSight = EventGroup.Event_Group_Frame + 37,
	S_DialogOpened = EventGroup.Event_Group_Frame + 38,

	CS_EnterActionState = EventGroup.Event_Group_Frame + 39,
	CS_LeaveActionState = EventGroup.Event_Group_Frame + 40,
	S_PlayerFacadeExit = EventGroup.Event_Group_Frame + 41,
	CS_DialogClosed = EventGroup.Event_Group_Frame + 42,
}

----------Team System Event ID-------------------------
TeamEvents={
	groupID=EventGroup.Event_Group_Team,
	CS_AnswerChangeLeader=EventGroup.Event_Group_Team+1,
	CS_AnswerInvite=EventGroup.Event_Group_Team+2,
	CS_AnswerRequest=EventGroup.Event_Group_Team+3,
	CS_ChangeLeader=EventGroup.Event_Group_Team+4,
	CS_ClearRequestQuery=EventGroup.Event_Group_Team+5,
	CS_ClearInvites=EventGroup.Event_Group_Team+6,
	CS_Create=EventGroup.Event_Group_Team+7,
	CS_Dismiss=EventGroup.Event_Group_Team+8,
	CS_InviteJion=EventGroup.Event_Group_Team+9,
	CS_KickMember=EventGroup.Event_Group_Team+10,
	CS_LeaveTeam=EventGroup.Event_Group_Team+11,
	CS_RequestJoin=EventGroup.Event_Group_Team+12,
	S_MemberLeft=EventGroup.Event_Group_Team+13,
	S_MemberJoined=EventGroup.Event_Group_Team+14,
	SC_ChangeLeaderReturn=EventGroup.Event_Group_Team+15,
	SC_IllegalAction=EventGroup.Event_Group_Team+16,
	SC_InviteReturn=EventGroup.Event_Group_Team+17,
	SC_LeaderChanged=EventGroup.Event_Group_Team+18,
	SC_MemberJoined=EventGroup.Event_Group_Team+19,
	SC_MemberLeft=EventGroup.Event_Group_Team+20,
	SC_RequestReturn=EventGroup.Event_Group_Team+21,
	SC_SendChangeLeader=EventGroup.Event_Group_Team+22,
	SC_SendInvite=EventGroup.Event_Group_Team+23,
	SC_SendRequest=EventGroup.Event_Group_Team+24,
	SC_TeamCreated=EventGroup.Event_Group_Team+25,
	SC_TeamDismissed=EventGroup.Event_Group_Team+26,
	SC_ClearRequestReturn=EventGroup.Event_Group_Team+27,
	SC_LeaveTeamReturn=EventGroup.Event_Group_Team+28,
	SC_KickMemberReturn=EventGroup.Event_Group_Team+29,
	SC_LeaderLeft=EventGroup.Event_Group_Team+30,
	SC_DismissReturn=EventGroup.Event_Group_Team+31,
	SC_ClearInvitesReturn=EventGroup.Event_Group_Team+32,
	S_TeamCreated=EventGroup.Event_Group_Team+33,
	S_TeamDismissed=EventGroup.Event_Group_Team+34,
	S_TeamStatusChanged=EventGroup.Event_Group_Team+35,
	S_TeamFollow=EventGroup.Event_Group_Team+36,
	S_TeamLeave=EventGroup.Event_Group_Team+37,
	S_TeamLeaderChanged=EventGroup.Event_Group_Team+38,
	S_TeamStepOut=EventGroup.Event_Group_Team+39,
	S_TeamComeback=EventGroup.Event_Group_Team+40,

	CS_StepOutOfTeam=EventGroup.Event_Group_Team+41,
	CS_ComebackTeam=EventGroup.Event_Group_Team+42,
	SC_StepOutOfTeamReturn=EventGroup.Event_Group_Team+43,
	SC_ComebackTeamReturn=EventGroup.Event_Group_Team+44,
	SC_TeammatePosition=EventGroup.Event_Group_Team+45,
	SC_RemoveQuery=EventGroup.Event_Group_Team+46,
	SC_InviteJionReturn=EventGroup.Event_Group_Team+47,
	S_TryToComeback=EventGroup.Event_Group_Team+48,
	CS_TryToComeback=EventGroup.Event_Group_Team+49,
	SC_TryToComebackRetrun=EventGroup.Event_Group_Team+50,
	CS_GetTeamMembercount=EventGroup.Event_Group_Team+51,
	SC_ReturnTeamMemberCount=EventGroup.Event_Group_Team+52,
}

----------Trade System Event ID-------------------------
TradeEvents={
	groupID=EventGroup.Event_Group_Trade,
	CS_AnswerRequest=EventGroup.Event_Group_Trade+1,    --回答交易请求 接受/拒绝    OK
	CS_ClearQuerys=EventGroup.Event_Group_Trade+2,      --清空交易列表          OK
	CS_ConfirmTrade=EventGroup.Event_Group_Trade+3,     --确定交易          OK
	CS_Request=EventGroup.Event_Group_Trade+4,      --发出交易请求          OK
	CS_CancelTrade=EventGroup.Event_Group_Trade+5,      --取消交易          OK
	CS_ChangeItems=EventGroup.Event_Group_Trade+6,      --改变交易物品          OK

	SC_ClearQuerysReturn=EventGroup.Event_Group_Trade+7,    --清空交易列表          OK
	SC_IllegalAction=EventGroup.Event_Group_Trade+8,    --非法请求          OK
	SC_ChangeItemReturn=EventGroup.Event_Group_Trade+9, --改变交易物品          OK
	SC_RequestAnswered=EventGroup.Event_Group_Trade+10, --返回交易请求结果      OK
	SC_SendRequest=EventGroup.Event_Group_Trade+11,     --收到交易请求          OK
	SC_TradeCanceled=EventGroup.Event_Group_Trade+12,   --对方取消交易          OK
	SC_TradeConfirmed=EventGroup.Event_Group_Trade+13,  --对方确定交易          OK
	SC_TradeDone=EventGroup.Event_Group_Trade+14,       --交易完成          OK
	SC_TradeFailed=EventGroup.Event_Group_Trade+15  ,   --交易失败          OK
	SC_CancelConfirm=EventGroup.Event_Group_Trade+16,        --取消确认

	C_PushPet=EventGroup.Event_Group_Trade+17,      --选择宠物到交易栏
	C_TakeoutPet=EventGroup.Event_Group_Trade+18,       --把宠物撤下交易栏

	CS_TradeRefuse=EventGroup.Event_Group_Trade+20,  --拒绝某个人的交易
	SC_TradeRefuse=EventGroup.Event_Group_Trade+21,  --收到某人拒绝和你交易
	SC_RemoveQuery = EventGroup.Event_Group_Trade+22, --删除某人的交易请求
	SC_RequestReturn=EventGroup.Event_Group_Trade+23,	--请求已经接收
}

----------Mat System Event ID-------------------------
MaterialEvents={
	groupID=EventGroup.Event_Group_Material,
	CS_ExchangeGrid=EventGroup.Event_Group_Material+1,
	CS_OpenPkg=EventGroup.Event_Group_Material+2,
	CS_UpPkg=EventGroup.Event_Group_Material+3,
	CS_DownPkg=EventGroup.Event_Group_Material+4,
	CS_ExchangePkg=EventGroup.Event_Group_Material+5,
	SC_IllegalAction=EventGroup.Event_Group_Material+6,
	SC_OpenPkg=EventGroup.Event_Group_Material+7,
	C_ExchangePack=EventGroup.Event_Group_Material+8,
	C_UpDownPack=EventGroup.Event_Group_Material+9,
	C_PackDeal=EventGroup.Event_Group_Material+10,
	C_UseMaterial=EventGroup.Event_Group_Material + 11,
	C_ItemMoved=EventGroup.Event_Group_Material + 12,
	SC_PkgChanged=EventGroup.Event_Group_Material + 13,
	CS_PackUpdate=EventGroup.Event_Group_Material+14,
	--Liu:物品整理
	CS_MaterialSort=EventGroup.Event_Group_Material+17,
	CS_CureByRButton=EventGroup.Event_Group_Material+18,
	SC_CureByRButton=EventGroup.Event_Group_Material+19,
}
----------Fight System Event ID--------------------------
FightEvents = {
	groupID=EventGroup.Event_Group_Fight,
	C_PlayRound=EventGroup.Event_Group_Fight+1,
	CS_ActionPlayed=EventGroup.Event_Group_Fight+2,
	CS_AnswerRequestFight=EventGroup.Event_Group_Fight+3,
	CS_ChooseAction=EventGroup.Event_Group_Fight+4,
	CS_RequestFight=EventGroup.Event_Group_Fight+5,
	CS_SetSetting=EventGroup.Event_Group_Fight+6,
	CS_PlayerDead=EventGroup.Event_Group_Fight+7,
	CS_ArenaEntered=EventGroup.Event_Group_Fight+8,
	S_PlayerOffline=EventGroup.Event_Group_Fight+9,
	S_RoleExitFight=EventGroup.Event_Group_Fight+10,
	S_FightStart=EventGroup.Event_Group_Fight+11,
	S_RoundFinished=EventGroup.Event_Group_Fight+12,
	S_RoundStart=EventGroup.Event_Group_Fight+13,
	S_StatusChanged=EventGroup.Event_Group_Fight+14,
	SC_ActionPerformed=EventGroup.Event_Group_Fight+15,
	SC_ChooseActionReturn=EventGroup.Event_Group_Fight+16,
	SC_EnterArena=EventGroup.Event_Group_Fight+17,
	SC_FightEnd=EventGroup.Event_Group_Fight+18,
	SC_FightStart=EventGroup.Event_Group_Fight+19,
	SC_LeaveArena=EventGroup.Event_Group_Fight+20,
	SC_PlayerRevivaled=EventGroup.Event_Group_Fight+21,
	SC_RequestFightReturn=EventGroup.Event_Group_Fight+22,
	SC_RoundStart=EventGroup.Event_Group_Fight+23,
	SC_SendRequestFight=EventGroup.Event_Group_Fight+24,
	SC_SetSettingReturn=EventGroup.Event_Group_Fight+25,
	SC_IllegalAction=EventGroup.Event_Group_Fight+26,
	SC_FighterLeft=EventGroup.Event_Group_Fight+27,
	SC_FightClose=EventGroup.Event_Group_Fight+28,
	SC_FighterEscape=EventGroup.Event_Group_Fight+29,
	SC_FighterDead=EventGroup.Event_Group_Fight+30,
	S_FighterRevival=EventGroup.Event_Group_Fight+31,
	S_FighterDead=EventGroup.Event_Group_Fight+32,
	S_FighterGBH=EventGroup.Event_Group_Fight+33,
	S_FighterEscape=EventGroup.Event_Group_Fight+34,
	CS_MonsterDead=EventGroup.Event_Group_Fight+35,
	CS_FightEnd=EventGroup.Event_Group_Fight+36,
	CS_BackToPublicScene=EventGroup.Event_Group_Fight+37,
	C_ArenaEntered=EventGroup.Event_Group_Fight+38,
	S_FightEnd=EventGroup.Event_Group_Fight+39,
	S_MatsDroped=EventGroup.Event_Group_Fight+40,
	S_PetFight=EventGroup.Event_Group_Fight+41,
	S_PetBack=EventGroup.Event_Group_Fight+42,
	SC_ActionFailed=EventGroup.Event_Group_Fight+43,
	SC_StartChoose=EventGroup.Event_Group_Fight+44,
	SC_FighterReviable=EventGroup.Event_Group_Fight+45,
	SC_ActionChose=EventGroup.Event_Group_Fight+46,
	S_MineOccured=EventGroup.Event_Group_Fight+47,
	S_RolePropChanged=EventGroup.Event_Group_Fight+48,
	SC_RolePropChanged=EventGroup.Event_Group_Fight+49,
	SC_EscapeFailed=EventGroup.Event_Group_Fight+50,
	SC_RoundFinished=EventGroup.Event_Group_Fight+51,
	S_StartAutoMeet=EventGroup.Event_Group_Fight+52,
	S_EndAutoMeet=EventGroup.Event_Group_Fight+53,
	S_ActionPerformed=EventGroup.Event_Group_Fight+54,
	S_BeatStoped=EventGroup.Event_Group_Fight+55,
	S_FightActionMsg=EventGroup.Event_Group_Fight+56,
}

----------Equip System Event ID-------------------------
EquipEvents={
	groupID=EventGroup.Event_Group_Equip,
	CS_Install=EventGroup.Event_Group_Equip+1,
	CS_Uninstall=EventGroup.Event_Group_Equip+2,
	CS_DrillByNPC=EventGroup.Event_Group_Equip+3,
	CS_Fix =EventGroup.Event_Group_Equip+4,
	CS_Pudding=EventGroup.Event_Group_Equip+5,
	CS_RefineByNPC= EventGroup.Event_Group_Equip+6,
	CS_StrengthenByNPC=EventGroup.Event_Group_Equip+7,
	SC_DrillResult=EventGroup.Event_Group_Equip+8,
	SC_FixResult=EventGroup.Event_Group_Equip+9,
	SC_InstallResult=EventGroup.Event_Group_Equip+10,
	SC_PuddingResult=EventGroup.Event_Group_Equip+11,
	SC_RefineResult=EventGroup.Event_Group_Equip+12,
	SC_StrengthenResult=EventGroup.Event_Group_Equip+13,
	SC_UninstallResult=EventGroup.Event_Group_Equip+14,
	CS_LoadPack=EventGroup.Event_Group_Equip+15,
	SC_PackLoaded=EventGroup.Event_Group_Equip+16,
	CS_StrengthenBySelf=EventGroup.Event_Group_Equip+17,
	CS_DrillBySelf=EventGroup.Event_Group_Equip+18,
	CS_RefineBySelf=EventGroup.Event_Group_Equip+19,
	CS_UseMaterial=EventGroup.Event_Group_Equip+20,
	SC_UseMaterialResults=EventGroup.Event_Group_Equip+21,
	SC_OpenAlterEquipGUI=EventGroup.Event_Group_Equip+22,
	CS_InitEquipInstance=EventGroup.Event_Group_Equip+23,
	SC_InitEquipInstance=EventGroup.Event_Group_Equip+24,
	CS_GoodsDivide=EventGroup.Event_Group_Equip+25,
	SC_GoodsDivide=EventGroup.Event_Group_Equip+26,
	CS_DestroyPackItem=EventGroup.Event_Group_Equip+27,
	SC_DestroyPackItem=EventGroup.Event_Group_Equip+28,
	CS_AlterationReady=EventGroup.Event_Group_Equip+29,
	SC_AlterationReady=EventGroup.Event_Group_Equip+30,
	SC_IllegalAction=EventGroup.Event_Group_Equip+31,
	CS_SetShowSuit=EventGroup.Event_Group_Equip+32,
}

----------Skill System Event ID-------------------------
SkillEvents={
	groupID=EventGroup.Event_Group_Skill,
	CS_LearnSkill = EventGroup.Event_Group_Skill+1,
	CS_UseSkill = EventGroup.Event_Group_Skill+2,
	SC_UsePlayerLifeSkillSuccess = EventGroup.Event_Group_Skill+3,
	SC_UsePlayerLifeSkillFailure = EventGroup.Event_Group_Skill+4,
	SC_LearnSkillSuccess = EventGroup.Event_Group_Skill+5,
	SC_LearnSkillFailure = EventGroup.Event_Group_Skill+6,
	SC_AvailbleSkillList=EventGroup.Event_Group_Skill+7,
}

----------Storage System Event ID-------------------------
StorageEvents={
	groupID=EventGroup.Event_Group_Storage,
	SC_IllegalAction=EventGroup.Event_Group_Storage+1,
	CS_OpenStorage=EventGroup.Event_Group_Storage+2,
	CS_PutIn=EventGroup.Event_Group_Storage+3,
	CS_TakeOut=EventGroup.Event_Group_Storage+4,
	CS_Exchange=EventGroup.Event_Group_Storage+5,
	CS_SetMoney=EventGroup.Event_Group_Storage+6,
	SC_StorageUpdate=EventGroup.Event_Group_Storage+7,
	SC_CouldNotStorage=EventGroup.Event_Group_Storage+8,
	S_StorageUpdate=EventGroup.Event_Group_Storage+9,
	C_StorageDeal=EventGroup.Event_Group_Storage+10,
	SC_GridUpdate=EventGroup.Event_Group_Storage+11,
	CS_MaterialSort=EventGroup.Event_Group_Storage+12, --Liu 仓库整理
	CS_GoodsDivide=EventGroup.Event_Group_Storage+13, --Liu 物品拆分
	CS_Extend=EventGroup.Event_Group_Storage+14, --Liu 扩充格子
	SC_Extend=EventGroup.Event_Group_Storage+15, --Liu 扩充格子
	S_Extend=EventGroup.Event_Group_Storage+16, --Liu 扩充格子
	SC_OpenStorage=EventGroup.Event_Group_Storage+17, --Liu 打开仓库,不传输数据
	C_ShowNotify=EventGroup.Event_Group_Storage+18, --zl 处理客户端提示
	CS_GetStorageData=EventGroup.Event_Group_Storage+19,
	SC_GetStorageData=EventGroup.Event_Group_Storage+20,
}

----------Pet System Event ID-------------------------
PetEvents = {
	groupID=EventGroup.Event_Group_Pet,
	CS_GetPetAttributes=EventGroup.Event_Group_Pet+1,
	SC_ResultPetAttributes=EventGroup.Event_Group_Pet+2,
	CS_PetAttributePointChange=EventGroup.Event_Group_Pet+3,
	CS_PetFight=EventGroup.Event_Group_Pet+5,
	CS_PetBack=EventGroup.Event_Group_Pet+6,
	CS_PetFollow=EventGroup.Event_Group_Pet+7,
	CS_PetFeed=EventGroup.Event_Group_Pet+8,
	CS_PetRename=EventGroup.Event_Group_Pet+9,
	CS_PetFree=EventGroup.Event_Group_Pet+10,
	CS_PetRefine=EventGroup.Event_Group_Pet+11,
	CS_PetAddLife=EventGroup.Event_Group_Pet+12,
	CS_PetSkillLock=EventGroup.Event_Group_Pet+13,
	CS_GetPetListData=EventGroup.Event_Group_Pet+14,
	SC_ResultPetListData=EventGroup.Event_Group_Pet+15,
	SC_PetEnhance=EventGroup.Event_Group_Pet+16,
	SC_CommandResult=EventGroup.Event_Group_Pet+17,
	S_PetCaught=EventGroup.Event_Group_Pet+18,
	CS_GetPetEnhanceData=EventGroup.Event_Group_Pet+19,
	SC_GetPetEnhanceData=EventGroup.Event_Group_Pet+20,
}

----------Chat System Event ID-------------------------
ChatEvents = {
	groupID=EventGroup.Event_Group_Chat,
	CS_SendMsg          =       EventGroup.Event_Group_Chat+1,
	CS_CloseChannels    =       EventGroup.Event_Group_Chat+2,
	CS_AddBlackMember   =       EventGroup.Event_Group_Chat+3,
	CS_RemoveBlackMember=       EventGroup.Event_Group_Chat+4,
	CS_GetRecentMsgs    =       EventGroup.Event_Group_Chat+5,
	SC_IllegalAction    =       EventGroup.Event_Group_Chat+6,
	SC_ReceiveMsg       =       EventGroup.Event_Group_Chat+7,
	SC_ChannelsClosed   =       EventGroup.Event_Group_Chat+8,
	SC_AllBlackMemberReturn     =   EventGroup.Event_Group_Chat+9,
	SC_RemoveBlackMemberReturn  =   EventGroup.Event_Group_Chat+10,
	SC_SendRecentMsgs   =       EventGroup.Event_Group_Chat+11,
	SC_LoadChatData     =       EventGroup.Event_Group_Chat+12,
	C_TextAccepted      =       EventGroup.Event_Group_Chat+13,
	C_ChatLocked        =       EventGroup.Event_Group_Chat+14,
	C_ChatSwitch        =       EventGroup.Event_Group_Chat+15,
	SC_SendJestMsg        =       EventGroup.Event_Group_Chat+16,
}

SchoolEvents = {
	groupID         = EventGroup.Event_Group_School,
	S_EnterSchool       = EventGroup.Event_Group_School + 1,
	SC_EnterSchool      = EventGroup.Event_Group_School + 2,
	SC_IllegalAction    = EventGroup.Event_Group_School + 3,
}

----------Role System Event ID-------------------------
RoleEvents={
	groupID=EventGroup.Event_Group_Role,
	S_RoleCreate=			EventGroup.Event_Group_Role+1,
	S_RoleDead=			EventGroup.Event_Group_Role+2,
	S_PropChanged=			EventGroup.Event_Group_Role+3,
	CS_GetData=			EventGroup.Event_Group_Role+4,
	SC_GetData=			EventGroup.Event_Group_Role+5,
	SS_RequestRoleData=		EventGroup.Event_Group_Role+6,
	SS_SendRoleData=		EventGroup.Event_Group_Role+7,
	CS_SaveShortcutKeys=		EventGroup.Event_Group_Role+8,
}


CopyEvents={
	groupID=EventGroup.Event_Group_Copy,
	S_CopyRoleCreate=           EventGroup.Event_Group_Copy+1,
	SC_IllegalAction=           EventGroup.Event_Group_Copy+2,
}

FriendEvents={
	groupID=EventGroup.Event_Group_Friend,
	CS_AddFriend            = EventGroup.Event_Group_Friend+1,
	CS_RemoveFriend         = EventGroup.Event_Group_Friend+2,
	SC_AddFriendResult      = EventGroup.Event_Group_Friend+3,
	SC_RemoveFriendResult   = EventGroup.Event_Group_Friend+4,
	CS_AddBlackList         = EventGroup.Event_Group_Friend+5,
	CS_RemoveBlackList      = EventGroup.Event_Group_Friend+6,
	SC_AddBlackListResult   = EventGroup.Event_Group_Friend+7,
	SC_RemoveBlackListResult= EventGroup.Event_Group_Friend+8,
	CS_MoveToBlackList      = EventGroup.Event_Group_Friend+9,
	CS_MoveToFriend         = EventGroup.Event_Group_Friend+10,
	SC_MoveToBlackListResult= EventGroup.Event_Group_Friend+11,
	SC_MoveToFriendResult   = EventGroup.Event_Group_Friend+12,
	CS_SendMessage          = EventGroup.Event_Group_Friend+13,
	SC_ReceiveMessage       = EventGroup.Event_Group_Friend+14,
	SC_FriendGoOnline       = EventGroup.Event_Group_Friend+15,
	SC_FriendGoOffline      = EventGroup.Event_Group_Friend+16,
	SC_IllegalAction        = EventGroup.Event_Group_Friend+17,
	CS_DeleteMessage        = EventGroup.Event_Group_Friend+18,
	SC_GetMessages          = EventGroup.Event_Group_Friend+19,
}

StallEvents = {
	groupID=EventGroup.Event_Group_Stall,
	CS_OpenStall=EventGroup.Event_Group_Stall+1,
	CS_CloseStall=EventGroup.Event_Group_Stall+2,
	CS_ModifyStallName=EventGroup.Event_Group_Stall+3,
	CS_PutUpGoods=EventGroup.Event_Group_Stall+4,
	CS_PutDownGoods=EventGroup.Event_Group_Stall+5,
	CS_PutUpPet=EventGroup.Event_Group_Stall+6,
	CS_PutDownPet=EventGroup.Event_Group_Stall+7,
	CS_ChangeGoodsPrice=EventGroup.Event_Group_Stall+8,
	CS_ChangePetPrice=EventGroup.Event_Group_Stall+9,
	CS_BuyGoods=EventGroup.Event_Group_Stall+10,
	CS_BuyPet=EventGroup.Event_Group_Stall+11,
	CS_RequestStall=EventGroup.Event_Group_Stall+12,
	SC_IllegalAction=EventGroup.Event_Group_Stall+13,
	SC_ActionReturn=EventGroup.Event_Group_Stall+14,
	C_StallDeal=EventGroup.Event_Group_Stall+15,
	CS_LeaveStall=EventGroup.Event_Group_Stall+16,
}

----------Relation System Event ID-------------------------
RelationEvents={
	groupID                 =EventGroup.Event_Group_Relation,
	CS_AnswerChangeLeader   =EventGroup.Event_Group_Relation+1,
	CS_AnswerInvite         =EventGroup.Event_Group_Relation+2,
	CS_AnswerRequest        =EventGroup.Event_Group_Relation+3,
	CS_ChangeLeader         =EventGroup.Event_Group_Relation+4,
	CS_ClearRequestQuery    =EventGroup.Event_Group_Relation+5,
	CS_ClearInvites         =EventGroup.Event_Group_Relation+6,
	CS_Create               =EventGroup.Event_Group_Relation+7,
	CS_Dismiss              =EventGroup.Event_Group_Relation+8,
	CS_InviteJion           =EventGroup.Event_Group_Relation+9,
	CS_KickMember           =EventGroup.Event_Group_Relation+10,
	CS_LeaveTeam            =EventGroup.Event_Group_Relation+11,
	CS_RequestJoin          =EventGroup.Event_Group_Relation+12,
	CS_ContributeMoney      =EventGroup.Event_Group_Relation+13,
	CS_Appoint              =EventGroup.Event_Group_Relation+14,
	CS_RenameDuty           =EventGroup.Event_Group_Relation+15,
	S_MemberLeft            =EventGroup.Event_Group_Relation+16,
	S_MemberJoined          =EventGroup.Event_Group_Relation+17,
	SC_ChangeLeaderReturn   =EventGroup.Event_Group_Relation+18,
	SC_IllegalAction        =EventGroup.Event_Group_Relation+19,
	SC_InviteReturn         =EventGroup.Event_Group_Relation+20,
	SC_LeaderChanged        =EventGroup.Event_Group_Relation+21,
	SC_MemberJoined         =EventGroup.Event_Group_Relation+22,
	SC_MemberLeft           =EventGroup.Event_Group_Relation+23,
	SC_RequestReturn        =EventGroup.Event_Group_Relation+24,
	SC_SendChangeLeader     =EventGroup.Event_Group_Relation+25,
	SC_SendInvite           =EventGroup.Event_Group_Relation+26,
	SC_SendRequest          =EventGroup.Event_Group_Relation+27,
	SC_TeamCreated          =EventGroup.Event_Group_Relation+28,
	SC_TeamDismissed        =EventGroup.Event_Group_Relation+29,
	SC_ClearRequestReturn   =EventGroup.Event_Group_Relation+30,
	SC_LeaveTeamReturn      =EventGroup.Event_Group_Relation+31,
	SC_KickMemberReturn     =EventGroup.Event_Group_Relation+32,
	SC_LeaderLeft           =EventGroup.Event_Group_Relation+33,
	SC_DismissReturn        =EventGroup.Event_Group_Relation+34,
	SC_ClearInvitesReturn   =EventGroup.Event_Group_Relation+35,
	S_TeamCreated           =EventGroup.Event_Group_Relation+36,
	S_TeamDismissed         =EventGroup.Event_Group_Relation+37,
	S_TeamStatusChanged     =EventGroup.Event_Group_Relation+38,
	SC_DoerSuccess          =EventGroup.Event_Group_Relation+39,
	S_DBDataReceived        =EventGroup.Event_Group_Relation+40,
	S_GroupCreated          =EventGroup.Event_Group_Relation+41,
	S_RoleDataReceived      =EventGroup.Event_Group_Relation+42,
	CS_GetRoleData          =EventGroup.Event_Group_Relation+43,
	SC_GetRoleDataReturn    =EventGroup.Event_Group_Relation+44,
	CS_JoinBattle           =EventGroup.Event_Group_Relation+45,
}

DataBaseEvents = {
	groupID             = EventGroup.Event_Group_DataBase,
	S_PlayerOnLoaded    = EventGroup.Event_Group_DataBase + 1,
	SC_ActionInfoReturn = EventGroup.Event_Group_DataBase + 2,
}

DebugEvents = {
	groupID			= EventGroup.Event_Group_Debug,
	CS_WhyTask		= EventGroup.Event_Group_Debug + 1,
	SC_WhyTask		= EventGroup.Event_Group_Debug + 2,
	CS_PlayRecords	= EventGroup.Event_Group_Debug + 3,
}

TestEvents = {
	groupID				= EventGroup.Event_Group_Test,
	C_ConStatus			= EventGroup.Event_Group_Test + 1,
	C_Login				= EventGroup.Event_Group_Test + 2,
	C_EntityEnter			= EventGroup.Event_Group_Test + 3,
	C_EntityExit			= EventGroup.Event_Group_Test + 4,
	C_EntityPropChang		= EventGroup.Event_Group_Test + 5,
	C_AIClean			= EventGroup.Event_Group_Test + 6,
	C_FSM_Start			= EventGroup.Event_Group_Test + 7,
	C_FSM_Stop			= EventGroup.Event_Group_Test + 8,
	C_FSM_Finded			= EventGroup.Event_Group_Test + 9,
	C_FSM_NonFinded			= EventGroup.Event_Group_Test + 10,
	C_FSM_NonTask			= EventGroup.Event_Group_Test + 11,
	C_FSM_Task			= EventGroup.Event_Group_Test + 12,
	C_FSM_FinishTask		= EventGroup.Event_Group_Test + 13,
	C_FSM_NonfinishTask		= EventGroup.Event_Group_Test + 14,
	C_FSM_FindedPaths		= EventGroup.Event_Group_Test + 15,
	C_FSM_Input			= EventGroup.Event_Group_Test + 16,
	C_FSM_FindedMap			= EventGroup.Event_Group_Test + 17,

	C_FSM_SwitchScene		= EventGroup.Event_Group_Test + 18,
	C_FSM_FightStart		= EventGroup.Event_Group_Test + 19,
	C_FSM_FightEnd			= EventGroup.Event_Group_Test + 20,
	C_FSM_DoDialog			= EventGroup.Event_Group_Test + 21,
	C_FSM_CouldnotTalk		= EventGroup.Event_Group_Test + 22,
	C_FSM_Action			= EventGroup.Event_Group_Test + 23,
	C_FSM_TimeOut			= EventGroup.Event_Group_Test + 24,
	C_FSM_TaskAdded			= EventGroup.Event_Group_Test + 25,
	C_FSM_NoTaskAction		= EventGroup.Event_Group_Test + 26,
	C_FSM_TaskAction		= EventGroup.Event_Group_Test + 27,
	C_FSM_DoTalkNPC			= EventGroup.Event_Group_Test + 28,
	C_FSM_TaskTargetMonster		= EventGroup.Event_Group_Test + 29,
	C_FSM_TaskTargetNPC		= EventGroup.Event_Group_Test + 30,
	C_FSM_TaskTargetType		= EventGroup.Event_Group_Test + 31,

	C_FSM_DoStartFight		= EventGroup.Event_Group_Test + 32,
	C_FSM_DoFightAgain		= EventGroup.Event_Group_Test + 33,
	C_FSM_DoAutoFight		= EventGroup.Event_Group_Test + 34,
	C_FSM_DoAttackFight		= EventGroup.Event_Group_Test + 35,
	C_FSM_DoDefendFight		= EventGroup.Event_Group_Test + 36,
	C_FSM_FightClose		= EventGroup.Event_Group_Test + 37,
	C_FSM_DoCatch			= EventGroup.Event_Group_Test + 38,
	C_FSM_DoRoundEnd		= EventGroup.Event_Group_Test + 39,
	C_FSM_FightWin			= EventGroup.Event_Group_Test + 40,
	C_FSM_FightLost			= EventGroup.Event_Group_Test + 41,
	C_FSM_DoCatchFight		= EventGroup.Event_Group_Test + 42,
	C_FSM_MoveStop			= EventGroup.Event_Group_Test + 43,
	C_FSM_StartTrade		= EventGroup.Event_Group_Test + 44,
	C_FSM_WantBuy			= EventGroup.Event_Group_Test + 45,
	C_FSM_WantSell			= EventGroup.Event_Group_Test + 46,
	C_FSM_WantTradeAgain		= EventGroup.Event_Group_Test + 47,
	C_FSM_PkgChanged		= EventGroup.Event_Group_Test + 48,
	C_FSM_StallDone			= EventGroup.Event_Group_Test + 49,

	C_FSM_SkillChoosed		= EventGroup.Event_Group_Test + 50,
	C_FSM_UseSkillFailed		= EventGroup.Event_Group_Test + 51,
	C_FSM_PlayAction		= EventGroup.Event_Group_Test + 52,
	C_FSM_ActionPlayed		= EventGroup.Event_Group_Test + 53,
	C_FSM_SkillUsed			= EventGroup.Event_Group_Test + 54,
	C_FSM_FightAgain		= EventGroup.Event_Group_Test + 55,
	C_FSM_RequestJoin		= EventGroup.Event_Group_Test + 56,

	C_FSM_ExitStall			= EventGroup.Event_Group_Test + 57,
	C_FSM_PutUpGoods		= EventGroup.Event_Group_Test + 58,
	C_FSM_ExitTeam			= EventGroup.Event_Group_Test + 59,
	C_FSM_ExitFight			= EventGroup.Event_Group_Test + 60,
	C_FSM_FinishGoods		= EventGroup.Event_Group_Test + 61,
	C_FSM_DoPetFight		= EventGroup.Event_Group_Test + 62,
	C_SceneInfo			= EventGroup.Event_Group_Test + 63,
}

---------------GM Events------------------------------------------------
GMEvents ={
	groupID = EventGroup.Event_Group_GM,
	SC_RollBroadcast = EventGroup.Event_Group_GM+1,
}
---------------------------------------------------------------------------
EventSets={
	LocalEvents,
	FrameEvents,
	TeamEvents,
	TradeEvents,
	EquipEvents,
	SkillEvents,
	FightEvents,
	TaskEvents,
	MaterialEvents,
	StorageEvents,
	PetEvents,
	ChatEvents,
	SchoolEvents,
	RoleEvents,
	CopyEvents,
	DataBaseEvents,
	FriendEvents,
	StallEvents,
	AuctionEvents,
	RelationEvents,
	DebugEvents,
	TestEvents,
	PlayerStateEvents,
	GMEvents,
}

EventUtil=class()

local factory = EventFactory.getInstance()
local eventMgr= EventManager.getInstance()

function EventUtil.init()
	--define all events:
	for _, v in pairs(EventSets) do
		for i,w in pairs(v) do
			if (i~="groupID") then
				factory:defineEvent(w,v.groupID)
			end
		end
	end
end

function fireEvent(eventID,source,...)
	eventMgr:fireEvent(factory:getEvent(eventID, source,...))
end

EventUtil().init()