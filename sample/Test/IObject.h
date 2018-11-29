#pragma once

class IObject
{
	virtual int GetPeer() const = 0;
	virtual void SetPeer(int peer)  = 0;
	virtual void TestFn(int a) = 0;
};