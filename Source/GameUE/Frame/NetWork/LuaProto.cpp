
#include "LuaProto.h"
#include "Public/UnLuaBase.h"

bool FLuaProto::SendPack_Impl(int32 Remote, int32 ProtoId, int32 Size, uint8* Data)
{
	TcpSender.SocketSend("Hello from LuaProto");
	return true;
}

FLuaProto *FLuaProto::Instance(nullptr);

//SendPack(int32 Remote, int32 ProtoId, int32 Size, userdata Buffer)
int FLuaProto::SendPack(lua_State* L)
{
	if (!Instance) 
	{
		UE_LOG(LogUnLua, Warning, TEXT("LuaProto not instantiated!"));
		lua_pushnil(L);
		return 1;
	}

	int NumParams = lua_gettop(L);
	if (NumParams != 2 && NumParams != 4) 
	{
		UE_LOG(LogUnLua, Warning, TEXT("%s: Invalid parameters!"), ANSI_TO_TCHAR(__FUNCTION__));
		lua_pushnil(L);
		return 1;
	}

	int32 Remote = lua_tointeger(L, 1);
	int32 ProtoId = lua_tointeger(L, 2);;
	int32 Size = 0;
	uint8* Buffer = nullptr;
	if (NumParams == 4)
	{
		Size = lua_tointeger(L, 3);
		void *UserData = UnLua::GetPointer(L, 4);
		Buffer = (uint8 *)UserData;
	}

	bool Result = Instance->SendPack_Impl(Remote, ProtoId, Size, Buffer);
	if (!Result)
	{
		lua_pushnil(L);
	}
	else
	{
		lua_pushinteger(L, 1);
	}
	return 1;
}

static luaL_Reg LuaProtoMethods[] = {
	{"SendPack",						FLuaProto::SendPack},
	{NULL, NULL},
};

//int FLuaProto::GetTypeName(lua_State* L)
//{
//{
//
//}
//
void FLuaProto::Setup(lua_State* L)
{
	lua_newtable(L);
	luaL_Reg* funcs = LuaProtoMethods;
	for (; funcs->name; funcs++)
	{
		lua_pushstring(L, funcs->name);
		lua_pushcfunction(L, funcs->func);
		lua_rawset(L, -3);
	}
	lua_setglobal(L, "ProtoC");

	TcpSender.CreateSocket("127.0.0.1", 4399);
	TcpSender.SocketReceive();
}
//
//void FLuaProto::CleanUp()
//{
//
//}

//void FLuaProto::ReceivePack(int32 Proto, uint8* Data, int32 Size)
//{
//
//}

