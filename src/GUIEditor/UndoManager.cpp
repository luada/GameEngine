#include "precompiled.h"
#include "UndoManager.h"

const int UNDO_COUNT = 64;

const std::string INSTANCE_TYPE_NAME("UndoManager");
UndoManager* UndoManager::msInstance = 0;
UndoManager* UndoManager::GetInstancePtr()
{
	return msInstance;
}
UndoManager& UndoManager::GetInstance()
{
	ASSERT(0 != msInstance, "instance " << INSTANCE_TYPE_NAME << " was not created");
	return (*msInstance);
}
UndoManager::UndoManager() :
	mIsInitialise(false),
	pos(0),
	operations(UNDO_COUNT),
	last_property(0),
	ew(nullptr),
	mUnsaved(false)
{
	ASSERT(0 == msInstance, "instance " << INSTANCE_TYPE_NAME << " is exsist");
	msInstance=this;
}
UndoManager::~UndoManager() { msInstance=0; }

void UndoManager::Initialise(EditorWidgets * w)
{
	pos = 0;
	last_property = PR_DEFAULT;
	ew = w;
	mUnsaved = false;
}

void UndoManager::Shutdown()
{
	for (size_t i=0; i<operations.GetSize(); i++)
	{
		delete operations[i];
	}
	operations.Clear();
}

void UndoManager::Undo()
{
	mUnsaved = true;

	if (pos == operations.GetSize() - 1) return;
	pos++;
	ew->Clear();
	ew->LoadxmlDocument(operations[pos]);
}

void UndoManager::Redo()
{
	mUnsaved = true;

	if (pos == 0) return;
	pos--;
	ew->Clear();
	ew->LoadxmlDocument(operations[pos]);
}

void UndoManager::AddValue(int property)
{
	mUnsaved = true;

	if ((property != PR_DEFAULT) && (property == last_property))
	{
		delete operations.Front();
		operations.PopFirst();
		operations.Push( ew->SavexmlDocument() );
		return;
	}

	last_property = property;

	if ( pos != 0 )
	{
		last_property = PR_DEFAULT;
		while (pos)
		{
			delete operations.Front();
			operations.PopFirst();
			pos--;
		}
	}

	if ( operations.IsFull() ) delete operations.Back();
	operations.Push( ew->SavexmlDocument() );
	pos = 0;
}
